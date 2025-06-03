# C_Basic
<details>
	<summary><strong>PHẦN 1: Cú pháp cơ bản</strong></summary>

## **PHẦN 1: Cú pháp cơ bản**

### **Lý thuyết**

#### **1.Biến và kiểu dữ liệu**

* **1.1.Biến:** 

  ◦ Là một tên gọi đại diện cho một vùng nhớ, được sử dụng để lưu trữ giá trị.
  
  ◦ Mỗi biến có một kiểu dữ liệu xác định kích thước và cách lưu trữ trong bộ nhớ

* **1.2.Kiểu dữ liệu:**

  ◦ `int`: Lưu trữ số nguyên (4 byte với hệ 32/64 bit) 

  ◦ `char`:Lưu ký tự (1 byte), biểu diễn dưới dạng mã ASCII

  ◦ `float`: Số thực dấu chấm động (thường 4 byte),độ chính xác khoảng 6-7 chữ số thập phân

  ◦ `double`: Số thực (thường 8 byte),độ chính xác khoảng 15-16 chữ số thập phân

  ◦ `void`: Không chứa giá trị,dùng cho hàm không trả về hoặc con trỏ tổng quát `void*`

  ◦ `short/long`: Mở rộng kích thước của `int` (`short int` thường 2byte, `long int` có thể 4 hoặc 8 byte)

  ◦ `unsigned`: Chỉ lưu giá trị không âm

* **1.3.Khai báo và khởi tạo:**

  ```
  int age = 25;
  float pi = 3.14f;
  double large_num = 1.23e-4;
  ```

* **1.4.Phạm vi và thời gian sống:**

  ◦ **Phạm vi:** Biến cục bộ (trong hàm), biến toàn cục (ngoài hàm), biến tĩnh(`static`) lưu giữ giá trị giữa các lần gọi hàm

  ◦ **Thời gian sống:** Biến cục bộ bị hủy khi thoát hàm, biến tĩnh/toàn cục tồn tại suốt chương trình


#### **2.Toán tử**

* **2.1.Toán tử số học:**

  ◦ `+, -, *, /`: Cộng, trừ, nhân, chia. Lưu ý: Chia nguyên (int / int) cho kết quả nguyên, bỏ phần thập phân.

  ◦ `%`: Lấy nguyên chia dư
    ```
	10 % 3 = 1
    ```
  ◦ Tăng,giảm : `++ (tăng 1)`, `-- (giảm 1)`. Có thể dùng `tiền tố (++i)` hoặc `hậu tố (i++)`

* **2.2.Toán tử logic:**

  ◦ `&&`:AND, đúng khi cả hai vế đúng

  ◦ `||`:OR, đúng khi ít nhất một vế đúng.

  ◦ `!`: NOT, đảo ngược giá trị logic.

  ◦ `Short-circuit evaluation:` 

    Với **&&**, nếu vế trái sai vế phải không được kiểm tra

	Với **||**, nếu vế trái đúng vế phải không kiểm tra

  ```
  int x = 0; y = 5;
  if (x && y++) //y không tăng vì x = 0
	printf("%d\n", y); // In 5
  ```

* **2.3.Toán tử so sánh:**

  ◦ `==`,`!=`,`<`,`>`,`<=`, `>=` : Trả về 1 (đúng) , 0 (sai) 

* **2.4.Toán tử gán:**

  ◦ `=`: Gán giá trị

  ◦ Toán tử ghép: `+=` , `-=`, `*=`, `/=`, `%=`

* **2.5.Toán tử ưu tiên:**

  ◦ Ưu tiên: `()` > `++`,`--` > `*`,`/`,`%` > `+`,`-` > so sánh > logic > gán

  ◦ Dùng ngoặc `()` để điều chỉnh ưu tiên


#### **3.Câu lệnh điều kiện**

* **3.1.if-else**

  ◦ Thực thi mã dựa trên điều kiện.Có thể lồng nhau hoặc dùng else if để kiểm tra nhiều trường hợp.

   ```
	if (score >= 90) {
    printf("A\n");
	} else if (score >= 70) {
    printf("B\n");
	} else {
    printf("C\n");
	}
	```

  ◦ Lưu ý: Tránh lỗi lặp lại điều kiện (VD: **if (x > 0) { if (x < 10) { ... } }** có thể gộp thành **if (x > 0 && x < 10)**).
  
* **3.2.switch-case**

  ◦ Dùng để xử lý nhiều trường hợp dựa trên giá trị nguyên hoặc ký tự

  ◦ **break:** Ngăn các case thực thi liên tiếp

  ◦ **default:** Xử lý các trường hợp không khớp
  
  ```
  switch (day) {
    case 1: printf("Monday\n"); break;
    case 2: printf("Tuesday\n"); break;
    default: printf("Invalid\n");
	}
  ```

  ◦ Lưu ý: Nếu thiếu `break`, chương trình sẽ tiếp tục thực thi các case tiếp theo ("fall-through").

* **3.3.Toán tử điều kiện**

  ◦ C cung cấp **toán tử ba ngôi (?:)** để thay thế cho các câu lệnh if-else đơn giản.

  ◦ Cú pháp
  ```
  condition ? expression1 : expression2
  ```
  VD:
  ```
  int age = 20;
  printf("%s\n", age >= 18 ? "Adult" : "Minor"); // In Adult
  ```

#### **4.Vòng lặp**

* **4.1.for:**

  ◦ Dùng khi biết số lần lặp

  ◦ Cú pháp: 
  ```
  for(khởi tạo; điều kiện; bước nhảy)
  ```
  
  ```
  for (int i = 0; i < 5; i++) {
  printf("%d\n", i); // In 0, 1, 2, 3, 4
  }
  ```

* **4.2.while:**

  ◦ Lặp khi điều kiện đúng, kiểm tra trước khi thực thi

  ```
  	int i = 0;
	while (i < 5) {
    printf("%d\n", i);
    i++;
	}
  ```
* **4.3.do-while:**  

  ◦ Lặp ít nhất một lần, kiểm tra điều kiện sau khi thực thi.
  
  ```
  	int i = 0;
	do {
    printf("%d\n", i);
    i++;
	} while (i < 5);
  ```

* **4.4.Điều khiển vòng lặp:**

  ◦ **break:** Thoát vòng lặp ngay lập tức.

  ◦ **continue:** Bỏ qua phần còn lại của vòng lặp hiện tại, chuyển sang lần lặp tiếp theo.

  ```
  for (int i = 0; i < 5; i++) {
    if (i == 3) continue; // Bỏ qua i = 3
    printf("%d\n", i); // In 0, 1, 2, 4
	}
  ```

#### **5.Hàm**

* **Định nghĩa:** Hàm là khối mã thực hiện nhiệm vụ cụ thể,giúp tái sử dụng và tổ chức mã tốt hơn

* **Cú pháp:** 
```
return_type function_name(parameter_type parameter1, parameter_type parameter2) {
    // Code
    return value; // Nếu return_type không phải void
}
```

vd:
```
int add(int a, int b) {
    return a + b;
}
int main() {
    printf("Sum: %d\n", add(3, 4)); // In 7
    return 0;
}
```

* **Tham số:**

 ◦ **Pass-by-value:** Tham số được sao chép, hàm không thay đổi giá trị gốc
 
 ◦ **Pass-by-reference:** Dùng con trỏ để thay đổi giá trị gốc

* **Hàm không tham số:**

```
void say_hello() {
    printf("Hello, World!\n");
}
```

* **Khai báo hàm(prototype):** Định nghĩa hàm trước main hoặc khai báo prototype ở đầu file

```
int add(int, int); // Prototype
int main() {
    printf("%d\n", add(3, 4));
    return 0;
}
int add(int a, int b) {
    return a + b;
}
```

* **Biến tĩnh trong hàm:**

 ◦ Dùng `static` để giữ giá trị giữa các lần gọi hàm.

```
void counter() {
    static int count = 0;
    count++;
    printf("Count: %d\n", count);
}
int main() {
    counter(); // In 1
    counter(); // In 2
    return 0;
}
```

* **Hàm đệ quy:**

 ◦ Hàm gọi chính nó để giải quyết vấn đề. Cần điều kiện dừng để tránh lặp vô hạn.

 ```
 int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
 }
  int main() {
    printf("5! = %d\n", factorial(5)); // In 120
    return 0;
  }
 ```

* **Hàm inline:**

 ◦ Dùng từ khóa `inline` để gợi ý trình biên dịch chèn mã hàm trực tiếp vào nơi gọi, giảm chi phí gọi hàm.

 ```
 inline int square(int x) {
    return x * x;
 }
 ```
