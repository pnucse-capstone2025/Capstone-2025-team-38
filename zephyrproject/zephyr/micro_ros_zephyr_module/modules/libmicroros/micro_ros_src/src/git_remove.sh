#!/bin/bash

# 이 스크립트는 현재 위치의 모든 하위 폴더를 대상으로
# Git 서브모듈을 일반 폴더로 변환하는 작업을 시도합니다.

echo "현재 폴더의 모든 하위 폴더를 대상으로 변환을 시작합니다."
echo "==============================================="

# 현재 위치의 모든 하위 폴더 목록을 대상으로 반복 작업 수행
# '*/'는 현재 위치의 모든 디렉터리를 의미하는 패턴입니다.
for FOLDER_PATH in */; do
    # glob 패턴이 일치하는 항목이 없을 때를 대비한 확인
    [ -d "${FOLDER_PATH}" ] || continue

    # 경로 마지막의 '/' 문자 제거하여 순수 폴더명만 추출
    FOLDER="${FOLDER_PATH%/}"

    echo "[처리 중] ==> $FOLDER"

    # .git 폴더는 Git 저장소 자체이므로 건너뛰기
    if [ "$FOLDER" == ".git" ]; then
        echo "  [정보] '.git' 폴더는 건너뜁니다."
        continue
    fi

    # 서브모듈의 .git 폴더를 삭제 (보다 확실한 방법)
    if [ -d "$FOLDER/.git" ]; then
        rm -rf "$FOLDER/.git"
        echo "  - '$FOLDER/.git' 폴더를 삭제했습니다."
    fi

    # 서브모듈 비활성화 및 등록 해제
    # 오류가 발생할 수 있으나, 이미 Git에 등록되지 않은 일반 폴더인 경우이므로 괜찮습니다.
    git submodule deinit -f "$FOLDER" &>/dev/null
    git rm --cached "$FOLDER" &>/dev/null

    # .gitmodules 파일에서 해당 서브모듈 항목 제거
    git config -f .gitmodules --remove-section "submodule.$FOLDER" &>/dev/null

    # 일반 폴더로 다시 추가
    git add "$FOLDER"

    echo "  [완료] ==> '$FOLDER' 변환 완료."
done

echo "==============================================="
echo "모든 작업이 완료되었습니다."
echo "이제 git status 로 변경사항을 확인하고 커밋하세요:"
echo "git commit -m \"Convert all submodules to regular directories\""
