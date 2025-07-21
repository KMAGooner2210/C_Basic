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
</details> 

<details>
	<summary><strong>PHẦN 2: Mảng và chuỗi</strong></summary>

## **PHẦN 2: Mảng và chuỗi**

### **1.Mảng**

#### **1.1.Định nghĩa:** 

  * Mảng là một tập hợp các phần tử cùng kiểu dữ liệu, được lưu trữ liên tiếp trong bộ nhớ

  * Mỗi phần tử trong mảng được truy cập thông qua **chỉ số(index)**, bắt đầu từ 0 
  
#### **1.2.Khai báo và khởi tạo:**

  * Cú pháp khai báo
  ```
  kiểu_dữ_liệu tên_mảng[kích_thước];
  ```
  ```
  VD: int arr[5];
  ```
  
  * Khởi tạo
  ```
  Khởi tạo trực tiếp :
  int arr[5]={1, 2, 3, 4, 5};

  Khởi tạo một phần (các phần tử còn lại mặc định là 0):
  int arr[5]={1, 2}; // arr = {1, 2, 0, 0, 0}

  Không chỉ định kích thước (trình biên dịch tự suy ra):
  int arr[]={1, 2, 3, 4, 5}; //Tự động là arr[5]

  ```

   * Truy cập phần tử
   ```
   Sử dụng chỉ số truy cập
   arr[0]; //phần tử đầu tiên
   arr[4]; //phần tử cuối cùng (kích thước = 5)


   ```
#### **1.4.Mảng đa chiều:**

   * Mảng đa chiều là mảng của các mảng, thường dùng để biểu diễn ma trận hoặc dữ liệu dạng lưới

   * Khai báo

   ```
   kiểu_dữ_liệu tên_mảng[số_hàng][số_cột];
   ```
   ```
   int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
   ```
   * Truy cập

   ```
   matrix[0][0]; // phần tử hàng 0, cột 0 (giá trị 1)
   matrix[1][2]; // phần tử hàng 1, cột 2 (giá trị 6)
   ```

   * Khởi tạo từng hàng
   
   ```
   int matrix[2][3] = {
     {1, 2, 3},  // Hàng 0
     {4, 5, 6}   // Hàng 1
   }
   ```
   
#### **1.5.Lưu trữ trong bộ nhớ:**

   * Mảng được lưu trữ liên tiếp trong bộ nhớ,giúp truy cập nhanh qua chỉ số_cột

   * Với mảng đa chiều, các phần tử được lưu theo **row-major order (ưu tiên hàng): các phần tử của hàng 0 được lưu trước, tiếp theo là hàng 1**

#### **1.6.Ứng dụng:**

   * Lưu trữ danh sách dữ liệu 

   * Xử lý ma trận trong đồ họa, toán học, hoặc xử lý dữ liệu

   * Tối ưu hóa bộ nhớ

#### **1.7.Lưu ý:**

   * **Kích thước mảng** phải là hằng số tại thời điểm biên dịch (trừ mảng động được cấp phát bằng `malloc`)

   * **Truyền mảng vào hàm:** Mảng được truyền dưới dạng con trỏ, hàm nhận địa chỉ của phần tử đầu tiên

   ```
   void print_array(int arr[], int size){
     for(int i = 0; i < size; i++){
       printf("%d", arr[i]);
     }
   }

   ``` 

### **2.Chuỗi**

#### **2.1.Định nghĩa**

   * Chuỗi trong C là một mảng ký tự (char) kết thúc bằng ký tự null(`\0`),đánh dấu điểm kết thúc của Chuỗi

   * Chuỗi được sử dụng để lưu trữ văn bản hoặc dữ liệu dạng ký tự 

#### **2.2.Khai báo và khởi tạo**

   * **Khai báo chuỗi:**
   
    char str[] = "Hello"; \\tự động thêm \0
  ◦ Kích thước thực tế là `strlen(str) + 1` bao gồm `\0`

   * **Khai báo mảng ký tự:**

    char str[6] = {'H','e','l','l','o','\0'};

   * **Khai báo với kích thước rõ ràng:**

    char str[10] = "Hello"; //Các phần tử còn lại là \0

#### **2.3.Thư viện <string.h>**  

   * **strlen(str)** :Trả về độ dài chuỗi (không tính `\0`)
   ```
   char str[] = "Hello";
   printf("%lu\n", strlen(str)); //In 5
   ```

   * **strcpy(dest, src)** : Sao chép chuỗi `src` (bao gồm `\0`) vào `dest`
   ```
   char dest[10];
   strcpy(dest, "Hello");
   prinf("%s\n", dest);  // In Hello
   ```

   * **strcat(dest, src)** : Nối chuỗi `src` vào cuối chuỗi `dest` (đảm bảo `dest` đủ lớn)

   ```
   char dest[10] = "Hello";
   strcat(dest, "!");
   printf("%s\n", dest); //In Hello!
   ```

   * **strcmp(str1, str2)** : So sánh 2 Chuỗi

   ◦  Trả về `0` nếu bằng nhau

   ◦  Trả về `<0` nếu `str1 < str2` (theo thứ tự từ điển)

   ◦  Trả về `>0` nếu `str1 > str2`
   ```
   char str1[] = "apple";
   char str2[] = "banana";
   printf("%d\n", strcmp(str1, str2)); // In <0 (apple < banana)

   ```
   * **strncmp(str1, str2, n):** So sánh n ký tự đầu

   * **strchr(str, c):** Tìm ký tự c đầu tiên trong Chuỗi

   * **strstr(str, substr):** Tìm chuỗi con `substr` trong `str`


#### **2.4.Nhập/xuất chuỗi**  

   * **Nhập chuỗi:**

   ◦ Sử dụng `scanf`

   ```
   char str[100];
   scanf("%s", str);  //Không cần &str, chỉ đọc đến dấu cách 
   ``` 
   ◦ Sử dụng `fgets`(tốt hơn)

   ```
   char str[100];
   fgets(str, 100, stdin); //Đọc cả dòng, bao gồm dấu cách
   ```

   * **Xuất chuỗi:**

   ◦ Sử dụng `printf` với `%s`

   ```
   printf("%sƯ, str);
   ```

   ◦ Sử dụng `puts`

   ```
   puts(str); //tự động thêm \n
   ```

#### **2.5.Thao tác thủ công trên chuỗi**

   * Vì chuỗi là mảng ký tự, có thể thao tác từng ký Tự
   
   ```
   char str[] = "Hello";
   str[0] = 'h';
   printf("%s", str); // In hello
   ```

   * Tính độ dài chuỗi thủ công

   ```
   int len = 0;
   while (str[len] != '\0') len++;
   printf("Do dai: %d\n", len);
   ```

#### **2.6.Ứng dụng**

   * Xử lý văn bản: Tìm kiếm, thay thế, phân tích chuỗi

   * Lưu trữ dự liệu dạng ký tự

   * Giao tiếp với người dùng

#### **2.7.Lưu ý**

   * Đảm bảo chuỗi đích đủ lớn khi dùng strcpy, strcat để tránh lỗi buffer overflow.

   * Luôn đảm bảo chuỗi kết thúc bằng `\0`, nếu không các hàm chuỗi có thể hoạt động sai.

   * `scanf` vs `fgets`

     ◦ scanf("%s") chỉ đọc đến dấu cách, không phù hợp cho chuỗi có khoảng trắng.

     ◦ fgets là lựa chọn tốt hơn cho nhập chuỗi đầy đủ.

#### **VD**

   * **Mảng**
   ```
   #include <stdio.h>
   int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    // In mảng
        for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
        }
    // Ma trận 2x3
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
        for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
       }
      return 0;
    }
    
    

   ```
    10 20 30 40 50
    1 2 3
    4 5 6
    
   * **Chuỗi**

    
    #include <stdio.h>
    #include <string.h>
    int main() {
    char str[] = "Hello";
    printf("Chuoi: %s\n", str);
    printf("Do dai: %lu\n", strlen(str));

    // Nối chuỗi
    char dest[20] = "Hi, ";
    strcat(dest, str);
    printf("Sau khi noi: %s\n", dest);

    // So sánh
    char str2[] = "Hello";
    if (strcmp(str, str2) == 0) {
        printf("Hai chuoi bang nhau\n");
    }
    return 0;
    }
    
   ```
   Chuoi: Hello
   Do dai: 5
   Sau khi noi: Hi, Hello
   Hai chuoi bang nhau
   ``` 

### **3.Ma trận**

#### **3.1.Định nghĩa**

   * Ma trận là một mảng 2 chiều được sử dụng để lưu trữ dữ liệu dạng lưới thường biểu diên dưới dạng các hàng và cột

   * Mỗi phần tử trong ma trận được truy cập thông qua 2 chỉ số: chỉ số hàng(`i`) và chỉ số cột(`j`),bắt đầu từ 0 

#### **3.2.Khai báo và khởi tạo**

   * **Cú pháp khai báo:**
    
    kiểu_dữ_liệu  tên_ma_trận[số_hàng][số_cột];
    
    VD:
    int matrix[3][3];
    

   * **Khởi tạo:**

◦ Khởi tạo trực tiếp:
    
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
◦ Khởi tạo một phần (các phần tử còn lại mặc định là 0):
    
    int matrix[2][3] = {{1, 2}}; //matrix = {{1, 2, 0}, {0, 0, 0}}
    
◦ Khởi tạo từng hàng:

    int matrix[2][3] = {
        {1, 2, 3}, //Hàng 0
        {4, 5, 6} //Hàng 1
    };

◦ Không chỉ định kích thước:

    int matrix[][] = {{1, 2}, {3, 4}}; //Tự động là matrix[2][2]

#### **3.3.Truy cập phần tử**

* **Sử dụng 2 chỉ số để truy cập:**
```
matrix[0][0]; //Phần tử hàng 0, cột 0
matrix[1][2]; //Phần tử hàng 1, cột 2
```
    
#### **3.4.Lưu trữ trong bộ nhớ**

* Ma trận trong C được lưu trữ liên tiếp trong bộ nhớ theo `row-major-order` (ưu tiên hàng):

    ◦ Các phần tử của hàng 0 được lưu trước, tiếp theo là hàng 1, 2,...

    ◦ VD: với ma trận int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}, thứ tự lưu trong bộ nhớ là: 1, 2, 3, 4, 5, 6

* Điều này giúp truy cập phần tử nhanh qua chỉ số, vì địa chỉ bộ nhớ của matrix[i][j] có thể được tính bằng công thức

    ◦ Địa chỉ matrix[i][j] = địa chỉ cơ sở + (i * số_cột + j) * kích_thước_kiểu_dữ_liệu
</details> 
