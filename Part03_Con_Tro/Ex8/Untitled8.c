//**Bài 8: Kiểm tra lỗi con trỏ NULL** 
//•	Yêu cầu: Viết chương trình khởi tạo con trỏ NULL, kiểm tra trước khi giải tham chiếu để tránh lỗi.
//•	Hướng dẫn: 
//o	Chạy và kiểm tra đầu ra.
//o	Thử bỏ điều kiện kiểm tra NULL và giải tham chiếu *ptr để quan sát lỗi (thường là access violation trên Windows).


#include <stdio.h>
int main() {
    int *ptr = NULL;
    if (ptr == NULL) {
        printf("Con tro NULL, khong the truy cap!\n");
    } else {
        printf("Gia tri: %d\n", *ptr);
    }
    return 0;
}
