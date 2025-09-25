// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <uxr/agent/participant/Participant.hpp>
#include <uxr/agent/client/ProxyClient.hpp>
#include <uxr/agent/types/XRCETypes.hpp>

#ifdef __cplusplus
extern "C" {
#endif

#include <iat/iat_wrapper.h>

#ifdef __cplusplus
}
#endif

#include <chrono>

extern std::chrono::high_resolution_clock::time_point startTime_1;
extern std::chrono::high_resolution_clock::time_point startTime_2;
extern std::chrono::high_resolution_clock::time_point startTime_3;
extern std::chrono::high_resolution_clock::time_point endTime_1;
extern std::chrono::high_resolution_clock::time_point endTime_2;
extern std::chrono::high_resolution_clock::time_point endTime_3;

extern uint32_t nonce;
namespace eprosima {
namespace uxr {

std::unique_ptr<Participant> Participant::create(
        const dds::xrce::ObjectId& object_id,
        const std::shared_ptr<ProxyClient>& proxy_client,
        const dds::xrce::OBJK_PARTICIPANT_Representation& representation)
{
    // DDS Participant 엔티티가 성공적으로 생성되었는지 여부를 추적하는 플래그입니다.
    bool created_entity = false;
    // XRCE ObjectId를 미들웨어에서 사용할 원시(raw) ID(uint16_t)로 변환합니다.
    uint16_t raw_object_id = conversion::objectid_to_raw(object_id);

    // 클라이언트가 Participant를 어떻게 정의했는지(참조, XML, 바이너리)에 따라 분기합니다.
    switch (representation.representation()._d())
    {
        // 1. 참조(Reference)를 이용한 생성 방식
        case dds::xrce::REPRESENTATION_BY_REFERENCE:
        {
            // 미리 정의된 프로필 이름(참조 문자열)을 가져옵니다.
            const std::string& ref_rep = representation.representation().object_reference();
            // 미들웨어에게 참조 이름을 전달하여 Participant를 생성하도록 요청합니다.
            created_entity = proxy_client->get_middleware().create_participant_by_ref(raw_object_id, representation.domain_id(), ref_rep);
            break;
        }
        // 2. XML 문자열을 이용한 생성 방식
        case dds::xrce::REPRESENTATION_AS_XML_STRING:
        {
            // Participant의 QoS 및 설정을 담은 XML 문자열을 가져옵니다.
            const std::string& xml_rep = representation.representation().xml_string_representation();
            // 미들웨어에게 XML 문자열을 전달하여 Participant를 생성하도록 요청합니다.
            created_entity = proxy_client->get_middleware().create_participant_by_xml(raw_object_id, representation.domain_id(), xml_rep);
            break;
        }
        // 3. 바이너리(Binary) 표현을 이용한 생성 방식
        case dds::xrce::REPRESENTATION_IN_BINARY:
        {
            auto rep = representation.representation();
            dds::xrce::OBJK_DomainParticipant_Binary participant_xrce;
            participant_xrce.domain_id(representation.domain_id());

            // FastCDR 라이브러리를 사용하여 바이너리 데이터를 역직렬화(deserialize)합니다.
            // 먼저, 수신한 바이너리 데이터로 fastbuffer를 생성합니다.
            fastcdr::FastBuffer fastbuffer{reinterpret_cast<char*>(const_cast<uint8_t*>(rep.binary_representation().data())), rep.binary_representation().size()};
            // 데이터의 엔디안(endianness)을 설정합니다.
            eprosima::fastcdr::Cdr::Endianness endianness = static_cast<eprosima::fastcdr::Cdr::Endianness>(representation.endianness());
            eprosima::fastcdr::Cdr cdr(fastbuffer, endianness);
            // Cdr 스트림으로부터 participant_xrce 객체로 역직렬화를 수행합니다.
            participant_xrce.deserialize(cdr);

            // 역직렬화된 바이너리 객체를 미들웨어에 전달하여 Participant를 생성합니다.
            // participant_xrce의 주요 정보 출력 (한국어 주석 포함)
            // printf("participant_xrce 정보 출력:\n");
            // printf("  domain_id: %d\n", participant_xrce.domain_id());
            // printf("  endianness: %d\n", participant_xrce.endianness());
            // printf("  participant_name: %s\n", participant_xrce.participant_name().c_str());
            // printf("  qos_profile: %s\n", participant_xrce.qos_profile().c_str());
            // printf("  user_data 크기: %zu\n", participant_xrce.user_data().size());
 
            //////////////////////////////////////////////////////////////////////////////////////////
            //////////              IAT Main Flow Start              ////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////////////

            // endTime_2 = std::chrono::high_resolution_clock::now();
            // auto duration = endTime_2 - startTime_2;
            // std::cout << "Nonce to IAT duration: " << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() << " microseconds" << std::endl;
            // startTime_3 = std::chrono::high_resolution_clock::now();

            int iat_attest_return = 0;

            char *custom_argv[] = {
                "main_executable",
                "-t",
                "PSA-IoT-Profile1-token",
                "-k",
                "iat/tfm_initial_attestation_key.pem",
                "iat/attestation_token.dat"
            };
            int custom_argc = sizeof(custom_argv) / sizeof(char *);
        
            iat_attest_return = run_check_iat(custom_argc, custom_argv);


            //////////////////////////////////////////////////////////////////////////////////////////
            //////////              IAT Main Flow End                ////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////////////

            if(iat_attest_return)
            {
                printf("TF-M PSA IAT Remote Attestation Failed\n");
                return (nullptr);
            }
            created_entity = proxy_client->get_middleware().create_participant_by_bin(raw_object_id, participant_xrce);
            break;
        }
        default:
            // 지원되지 않는 표현 방식인 경우 아무 작업도 하지 않습니다.
            break;
    }

    // Participant 엔티티 생성이 성공한 경우에만,
    // 에이전트 내부에서 사용하는 Participant 래퍼 객체를 생성하여 반환합니다.
    // 실패 시 nullptr를 반환합니다.

    // endTime_3 = std::chrono::high_resolution_clock::now();
    // auto duration = endTime_3 - startTime_3;
    // std::cout << "IAT to Session duration: " << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() << " microseconds" << std::endl;

    printf("================================================\n");
    return (created_entity ? std::unique_ptr<Participant>(new Participant(object_id, proxy_client)) : nullptr);
}

Participant::Participant(
        const dds::xrce::ObjectId& id,
        const std::shared_ptr<ProxyClient>& proxy_client)
    : XRCEObject(id)
    , proxy_client_{proxy_client}
{}

Participant::~Participant()
{
    proxy_client_->get_middleware().delete_participant(get_raw_id());
}

bool Participant::matched(const dds::xrce::ObjectVariant& new_object_rep) const
{
    /* Check ObjectKind. */
    if ((get_id().at(1) & 0x0F) != new_object_rep._d())
    {
        return false;
    }

    bool rv = false;
    switch (new_object_rep.participant().representation()._d())
    {
        case dds::xrce::REPRESENTATION_BY_REFERENCE:
        {
            const std::string& ref = new_object_rep.participant().representation().object_reference();
            const int16_t domain_id = new_object_rep.participant().domain_id();
            rv = proxy_client_->get_middleware().matched_participant_from_ref(get_raw_id(), domain_id, ref);
            break;
        }
        case dds::xrce::REPRESENTATION_AS_XML_STRING:
        {
            const std::string& xml = new_object_rep.participant().representation().xml_string_representation();
            const int16_t domain_id = new_object_rep.participant().domain_id();
            rv = proxy_client_->get_middleware().matched_participant_from_xml(get_raw_id(), domain_id, xml);
            break;
        }
        case dds::xrce::REPRESENTATION_IN_BINARY:
        {
            auto rep = new_object_rep.participant().representation();
            dds::xrce::OBJK_DomainParticipant_Binary participant_xrce;
            int16_t domain_id = new_object_rep.participant().domain_id();
            participant_xrce.domain_id(domain_id);

            fastcdr::FastBuffer fastbuffer{reinterpret_cast<char*>(const_cast<uint8_t*>(rep.binary_representation().data())), rep.binary_representation().size()};
            eprosima::fastcdr::Cdr::Endianness endianness = static_cast<eprosima::fastcdr::Cdr::Endianness>(new_object_rep.endianness());
            eprosima::fastcdr::Cdr cdr(fastbuffer, endianness);
            participant_xrce.deserialize(cdr);

            rv = proxy_client_->get_middleware().matched_participant_from_bin(get_raw_id(), domain_id, participant_xrce);
            break;
        }
        default:
            break;
    }
    return rv;
}

} // namespace uxr
} // namespace eprosima
