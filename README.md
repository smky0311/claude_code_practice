# claude_code_practice
private use only

## 📚 도서관 도서 관리 시스템

C언어로 구현한 도서관 도서 관리 시스템입니다.

### 주요 기능

1. **도서 등록**: 새로운 도서를 시스템에 등록
2. **도서 검색**: 제목으로 도서 검색 (포인터 활용)
3. **전체 목록 출력**: 등록된 모든 도서 목록 확인

### 구조체 정의

```c
struct Book {
    int id;              // 도서 번호
    char title[100];     // 제목
    char author[50];     // 저자
};
```

### 컴파일 및 실행

```bash
# 컴파일
gcc -o library_management library_management.c -Wall

# 실행
./library_management
```

### 기술적 특징

- **포인터 활용**: 도서 검색 기능에서 구조체 포인터를 활용하여 효율적인 데이터 처리
- **구조체 배열**: 최대 100권의 도서 정보를 배열로 관리
- **자동 ID 부여**: bookCount를 활용한 자동 도서 번호 생성
