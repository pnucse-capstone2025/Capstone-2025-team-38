#[[
add_library(hash STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hash.c
)

target_include_directories(hash PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${ZEPHYR_BASE}/../modules/crypto/tinycrypt/lib/include
)
]]

# < lib/hash/CMakeLists.txt >

add_library(hash STATIC src/hash.c)

target_include_directories(hash PUBLIC
    include
    # tinycrypt 경로는 절대 경로를 유지하는 것이 더 안정적일 수 있습니다.
    ${ZEPHYR_BASE}/../modules/crypto/tinycrypt/lib/include
)
