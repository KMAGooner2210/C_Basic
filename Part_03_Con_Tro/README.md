
# **Con trỏ**
**Bài 1: In địa chỉ và giá trị của biến qua con trỏ**
```
•	Yêu cầu: Viết chương trình khai báo một biến kiểu int, một con trỏ trỏ tới biến đó, sau đó in: 
o	Địa chỉ của biến.
o	Giá trị của biến qua con trỏ.
o	Địa chỉ của chính con trỏ.
•	Hướng dẫn: 
o	Chạy chương trình và quan sát đầu ra.
o	Thử thay đổi giá trị của x qua *ptr (ví dụ: *ptr = 20;) và in lại x để kiểm tra.
```
**Bài 2: Hoán đổi hai số bằng con trỏ**
```
•	Yêu cầu: Viết hàm swap(int *a, int *b) để hoán đổi giá trị của hai biến, gọi hàm trong main và in kết quả.
•	Hướng dẫn: 
o	Chạy và kiểm tra kết quả (x = 10, y = 5).
o	Thử viết lại hàm swap mà không dùng con trỏ (pass-by-value) và giải thích tại sao không hoán đổi được.
```
**Bài 3: Truy cập mảng bằng con trỏ**
```
•	Yêu cầu: Viết chương trình khai báo mảng int với 5 phần tử, dùng con trỏ để truy cập và in từng phần tử thay vì dùng chỉ số (arr[i]).
•	Hướng dẫn: 
o	Chạy và kiểm tra đầu ra (1 2 3 4 5).
o	Thử thay đổi một phần tử qua con trỏ (ví dụ: *(ptr + 2) = 10;) và in lại mảng.
```
**Bài 4: In từng ký tự của chuỗi bằng con trỏ**
```
•	Yêu cầu: Viết chương trình khai báo chuỗi (dùng mảng ký tự hoặc chuỗi hằng), dùng con trỏ để in từng ký tự của chuỗi.
•	Mã nguồn mẫu: 
•	Hướng dẫn: 
o	Chạy và kiểm tra đầu ra (H e l l o).
o	Thử sửa đổi một ký tự (ví dụ: *ptr = 'h'; với str[]) và in lại chuỗi.
o	Thử dùng chuỗi hằng (char *str = "Hello";) và giải thích tại sao không sửa được.
```
**Bài 5: Tính tổng các phần tử mảng bằng con trỏ**
```
•	Yêu cầu: Viết chương trình khai báo mảng int với 5 phần tử, dùng con trỏ để tính và in tổng các phần tử.
•	Hướng dẫn: 
o	Chạy và kiểm tra kết quả (Tổng: 15).
o	Thử thay đổi giá trị mảng và tính lại tổng.
```
**Bài 6: Sao chép chuỗi bằng con trỏ**
``` 
•	Yêu cầu: Viết hàm sao chép chuỗi bằng con trỏ, không dùng strcpy.
•	Hướng dẫn: 
o	Chạy và kiểm tra kết quả (Chuỗi sao chép: Hello).
Thử sao chép chuỗi dài hơn (nhưng đảm bảo dest đủ lớn).
```
**Bài 7: Cấp phát bộ nhớ động bằng con trỏ**
``` 
Yêu cầu: Viết chương trình cấp phát bộ nhớ động cho một biến int, gán giá trị, in giá trị, sau đó giải phóng bộ nhớ.
•	Hướng dẫn: 
o	Chạy và kiểm tra kết quả (Giá trị: 50).
o	Thử không gọi free(ptr) và giải thích tại sao điều này gây rò rỉ bộ nhớ.
```
**Bài 8: Kiểm tra lỗi con trỏ NULL**
``` 
•	Yêu cầu: Viết chương trình khởi tạo con trỏ NULL, kiểm tra trước khi giải tham chiếu để tránh lỗi.
•	Hướng dẫn: 
o	Chạy và kiểm tra đầu ra.
o	Thử bỏ điều kiện kiểm tra NULL và giải tham chiếu *ptr để quan sát lỗi (thường là access violation trên Windows).
```
**Bài 9: Sử dụng con trỏ đến con trỏ**
``` 
•	Yêu cầu: Khai báo một con trỏ đến con trỏ (int**), in giá trị của biến gốc và địa chỉ của con trỏ cấp một.
•	Hướng dẫn: 
o	Chạy và kiểm tra đầu ra.
o	Thử thay đổi giá trị x qua **pptr (ví dụ: **pptr = 100;) và in lại x.
```

