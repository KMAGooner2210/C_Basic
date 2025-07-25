
# **Bài tập**

* **Bài tập 1: Cấp phát và in mảng động**
``` 
Yêu cầu: Viết chương trình sử dụng malloc để cấp phát mảng động, nhập các phần tử từ người dùng, sau đó in mảng ra màn hình.
Hướng dẫn kiểm tra:
•	Nhập n = 5, sau đó nhập các giá trị như 1 2 3 4 5. Đầu ra: Mang vua nhap: 1 2 3 4 5.
•	Thử với n = 0 hoặc giá trị âm để kiểm tra xử lý lỗi.
•	Thử với n rất lớn (ví dụ: 1000000000) để kiểm tra lỗi cấp phát bộ nhớ.
```
* **Bài tập 2: Sử dụng calloc và kiểm tra khởi tạo**
``` 
Yêu cầu: Viết chương trình sử dụng calloc để cấp phát mảng động, kiểm tra tất cả phần tử có được khởi tạo bằng 0 hay không, sau đó in mảng.
Hướng dẫn kiểm tra:
•	Nhập n = 5. Đầu ra: Mang sau khi cap phat bang calloc: 0 0 0 0 0.
•	Thử với n lớn để kiểm tra lỗi cấp phát.
•	Thêm đoạn mã để thay đổi giá trị mảng và kiểm tra lại.
```
* **Bài tập 3: Thay đổi kích thước mảng động với realloc**
``` 
Yêu cầu: Viết chương trình cấp phát mảng động bằng malloc, nhập các phần tử, sau đó dùng realloc để tăng kích thước mảng, nhập thêm phần tử, và in mảng.
Hướng dẫn kiểm tra:
•	Nhập n = 3, nhập mảng 1 2 3, sau đó nhập new_size = 5 và thêm 4 5. Đầu ra: Mang sau khi mo rong: 1 2 3 4 5.
•	Thử với new_size nhỏ hơn n để kiểm tra xử lý lỗi.
•	Thử với new_size rất lớn để kiểm tra lỗi cấp phát.
```
* **Bài tập 4: Mô phỏng memory leak**
``` 
Yêu cầu: Viết chương trình cấp phát mảng động trong một vòng lặp nhưng không giải phóng, gây rò rỉ bộ nhớ.
Hướng dẫn kiểm tra:
•	Chạy chương trình và quan sát đầu ra: Da cap phat mang thu ....
•	Sử dụng công cụ như Valgrind (nếu có) để xác nhận rò rỉ bộ nhớ.
•	Sửa mã bằng cách thêm free(arr) trong vòng lặp và kiểm tra lại.
```
* **Bài tập 5: Phát hiện lỗi dangling pointer**
``` 
Yêu cầu: Viết chương trình cấp phát bộ nhớ, giải phóng, sau đó cố tình truy cập để mô phỏng lỗi dangling pointer.
Hướng dẫn kiểm tra:
•	Chạy chương trình, quan sát giá trị in ra sau khi giải phóng (có thể không xác định).
•	Sử dụng công cụ như Valgrind để phát hiện lỗi truy cập bộ nhớ không hợp lệ.
•	Sửa mã bằng cách kiểm tra ptr != NULL trước khi truy cập.
```
* **Bài tập 6: Kiểm tra lỗi cấp phát bộ nhớ**
```
Yêu cầu: Cấp phát mảng động, kiểm tra lỗi cấp phát, và in các phần tử.
Hướng dẫn kiểm tra:
•	Nhập n = 5. Đầu ra: Mang: 1 2 3 4 5.
•	Thử với n rất lớn để mô phỏng lỗi cấp phát.
•	Thêm đoạn mã để nhập giá trị từ người dùng thay vì gán mặc định.
```
* **Bài tập 7: Quản lý mảng động phức tạp**
``` 
Yêu cầu: Cấp phát mảng động, nhập giá trị, sắp xếp tăng dần bằng thuật toán bubble sort, và in kết quả.
Hướng dẫn kiểm tra:
•	Nhập n = 5, nhập mảng 5 3 1 4 2. Đầu ra: Mang sau khi sap xep: 1 2 3 4 5.
•	Thử với mảng lớn hoặc mảng đã sắp xếp sẵn để kiểm tra hiệu suất.
•	Thử thêm kiểm tra lỗi nhập liệu (ví dụ: giá trị không hợp lệ).
```
* **Bài tập 8: Sử dụng const để bảo vệ bộ nhớ**
``` 
Yêu cầu: Viết hàm in mảng với tham số const int* để ngăn sửa đổi dữ liệu, kiểm tra lỗi biên dịch nếu cố sửa.
Hướng dẫn kiểm tra:
•	Nhập n = 5, nhập mảng 1 2 3 4 5. Đầu ra: 1 2 3 4 5.
•	Thử bỏ comment dòng arr[0] = 10; trong hàm print_array để kiểm tra lỗi biên dịch.
•	Thử truyền mảng tĩnh (int arr[] = {1, 2, 3, 4, 5};) để kiểm tra tính linh hoạt.
```
* **Bài tập 9: Quản lý mảng 2D động**
``` 
Yêu cầu: Viết chương trình cấp phát mảng 2D động, nhập giá trị, tính tổng các phần tử, và giải phóng bộ nhớ.
Hướng dẫn kiểm tra:
•	Nhập rows = 2, cols = 3, ma trận 1 2 3 4 5 6. Đầu ra: Tong cac phan tu: 21.
•	Thử với kích thước lớn hoặc kích thước không hợp lệ.
•	Thêm hàm in ma trận để kiểm tra dữ liệu.
```
