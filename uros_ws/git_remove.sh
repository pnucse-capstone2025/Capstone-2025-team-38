#!/bin/bash
#
# 이 스크립트는 지정된 서브모듈들을 일반 폴더로 변환합니다.
# 사용법: ./convert_submodules.sh 폴더1 폴더2 ...
#

# 스크립트에 전달된 폴더 목록을 변수에 저장
FOLDERS_TO_CONVERT=("$@")

# 폴더 목록이 비어있으면 사용법 안내 후 종료
if [ ${#FOLDERS_TO_CONVERT[@]} -eq 0 ]; then
    echo "오류: 변환할 서브모듈 폴더명을 입력해주세요."
    echo "사용법: $0 <폴더1> <폴더2> ..."
    exit 1
fi

echo "다음 서브모듈들을 일반 폴더로 변환합니다: ${FOLDERS_TO_CONVERT[@]}"
echo "==============================================="

# 각 폴더에 대해 반복 작업 수행
for FOLDER in "${FOLDERS_TO_CONVERT[@]}"; do
    echo "[처리 중] ==> $FOLDER"

    # 1. 서브모듈 폴더 내의 .git 폴더 삭제
    if [ -d "$FOLDER/.git" ]; then
        rm -rf "$FOLDER/.git"
        echo "  - '$FOLDER/.git' 폴더를 삭제했습니다."
    else
        echo "  - '$FOLDER/.git' 폴더가 없어 삭제를 건너뜁니다."
    fi

    # 2. 서브모듈 비활성화
    git submodule deinit -f "$FOLDER"
    echo "  - 서브모듈을 비활성화했습니다."

    # 3. Git 인덱스에서 서브모듈 링크 제거
    git rm --cached "$FOLDER"
    echo "  - 캐시된 서브모듈 링크를 삭제했습니다."

    # 4. 일반 폴더로 다시 추가
    git add -f "$FOLDER"
    echo "  - 일반 폴더로 다시 추가했습니다."

    echo "  [완료] ==> '$FOLDER' 변환 완료."
done

echo "==============================================="
echo "모든 작업이 완료되었습니다."
echo "이제 변경사항을 커밋하여 작업을 마무리하세요:"
echo "git commit -m \"Convert specified submodules to regular directories\""
