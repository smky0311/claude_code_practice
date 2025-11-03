#include <stdio.h>
#include <string.h>

// 구조체 정의
struct Book {
    int id;                 // 도서 번호
    char title[100];        // 제목
    char author[50];        // 저자
};

// 전역 변수
struct Book library[100];   // 최대 100권의 도서 정보 저장
int bookCount = 0;          // 현재 저장된 도서 수

// 함수 선언
void registerBook();
void searchBook();
void displayAllBooks();
void clearInputBuffer();

int main() {
    int choice;

    printf("====================================\n");
    printf("   도서관 도서 관리 시스템\n");
    printf("====================================\n\n");

    while (1) {
        printf("\n========== 메뉴 ==========\n");
        printf("1. 도서 등록\n");
        printf("2. 도서 검색\n");
        printf("3. 전체 목록 출력\n");
        printf("0. 종료\n");
        printf("========================\n");
        printf("선택: ");

        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                registerBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                displayAllBooks();
                break;
            case 0:
                printf("\n프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("\n잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}

// 입력 버퍼 정리 함수
void clearInputBuffer() {
    while (getchar() != '\n');
}

// 도서 등록 함수
void registerBook() {
    if (bookCount >= 100) {
        printf("\n더 이상 도서를 등록할 수 없습니다. (최대 100권)\n");
        return;
    }

    printf("\n========== 도서 등록 ==========\n");

    // 도서 번호 자동 부여
    library[bookCount].id = bookCount + 1;

    // 제목 입력
    printf("도서 제목: ");
    fgets(library[bookCount].title, sizeof(library[bookCount].title), stdin);
    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0;  // 개행 문자 제거

    // 저자 입력
    printf("저자: ");
    fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0;  // 개행 문자 제거

    printf("\n도서가 등록되었습니다! (도서 번호: %d)\n", library[bookCount].id);

    bookCount++;
}

// 도서 검색 함수 (포인터 활용)
void searchBook() {
    if (bookCount == 0) {
        printf("\n등록된 도서가 없습니다.\n");
        return;
    }

    char searchTitle[100];
    printf("\n========== 도서 검색 ==========\n");
    printf("검색할 도서 제목: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;  // 개행 문자 제거

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            // 포인터에 도서 주소 저장
            struct Book *p = &library[i];

            printf("\n----- 검색 결과 -----\n");
            printf("도서 번호: %d\n", p->id);
            printf("제목: %s\n", p->title);
            printf("저자: %s\n", p->author);
            printf("---------------------\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n'%s' 제목의 도서를 찾을 수 없습니다.\n", searchTitle);
    }
}

// 전체 목록 출력 함수
void displayAllBooks() {
    if (bookCount == 0) {
        printf("\n등록된 도서가 없습니다.\n");
        return;
    }

    printf("\n========== 전체 도서 목록 ==========\n");
    printf("%-5s %-30s %-20s\n", "번호", "제목", "저자");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-30s %-20s\n",
               library[i].id,
               library[i].title,
               library[i].author);
    }

    printf("-------------------------------------------------------\n");
    printf("총 %d권의 도서가 등록되어 있습니다.\n", bookCount);
}
