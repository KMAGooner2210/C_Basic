# C_Basic
<details>
	<summary><strong>PHẦN 1: PREPROCESSOR DIRECTIVES</strong></summary>

## **PHẦN 1: PREPROCESSOR DIRECTIVES**

### **I. Preprocessor Directives**

#### **1. Định nghĩa**

* **Preprocessor Directives (chỉ thị tiền xử lý)** là các lệnh bắt đầu bằng ký tự # trong mã nguồn C/C++.

* Chúng được xử lý bởi **preprocessor (bộ tiền xử lý)** trước khi mã nguồn được biên dịch thành mã máy

* Preprocessor không phải là một phần của trình biên dịch mà là một công cụ riêng biệt, thực hiện các tác vụ như thay thế văn bản, nhúng tệp, hoặc kiểm tra điều kiện biên dịch.

#### **2. Vai trò**

* Thay thế các macro (thay văn bản đơn giản).

* Nhúng các tệp header hoặc mã nguồn khác.

* Kiểm tra điều kiện biên dịch (ví dụ, chỉ biên dịch một đoạn mã nếu điều kiện đúng).

* Tùy chỉnh hành vi biên dịch dựa trên cấu hình hoặc môi trường.

#### **3. Các Preprocessor Directives phổ biến**

* **`#include`**

  ◦ Chức năng: Nhúng nội dung của một tệp (thường là tệp header `.h`) vào mã nguồn tại vị trí chỉ thị.

  ◦ Cú pháp:

        #include <tên_tệp>  // Dùng cho thư viện chuẩn (stdio.h, stdlib.h,...)
        #include "tên_tệp"  // Dùng cho tệp do người dùng định nghĩa

  ◦ Ứng dụng:

        Nhúng các hàm thư viện chuẩn như printf (<stdio.h>), quản lý bộ nhớ động (<stdlib.h>), toán học (<math.h>).

        Nhúng các tệp header do người dùng viết để tái sử dụng mã.


* **`#define`**

  ◦ Chức năng: Định nghĩa macro, có thể là hằng số hoặc hàm macro. Macro là một đoạn văn bản được thay thế trực tiếp vào mã nguồn trước khi biên dịch.

  ◦ Cú pháp:

        #define TÊN GIÁ_TRỊ
        #define TÊN(param) biểu_thức

  ◦ Ứng dụng:

        Định nghĩa hằng số (ví dụ: #define PI 3.14159).

        Tạo các hàm macro để thay thế các đoạn mã lặp lại.

  ◦ Lưu ý:

        Macro không kiểm tra kiểu dữ liệu, dễ gây lỗi nếu không cẩn thận.

        Nên dùng ngoặc để tránh lỗi ưu tiên toán tử.

  ◦ VD:

        #define PI 3.14159
        #define SQUARE(x) ((x) * (x))
        int main() {
            printf("PI: %.5f\n", PI);          // In: 3.14159
            printf("Square of 5: %d\n", SQUARE(5)); // In: 25
            return 0;
        }

* **`#ifdef, #ifndef, #else, #endif`**

  ◦ Chức năng: Kiểm tra điều kiện biên dịch, chỉ biên dịch một đoạn mã nếu điều kiện được thỏa mãn.

  ◦ Cú pháp:

        #ifdef TÊN_MACRO
            // Mã được biên dịch nếu TÊN_MACRO đã được định nghĩa
        #endif
        #ifndef TÊN_MACRO
            // Mã được biên dịch nếu TÊN_MACRO chưa được định nghĩa
        #endif

  ◦ Ứng dụng:

        Bật/tắt các đoạn mã trong quá trình debug.

        Hỗ trợ biên dịch có điều kiện dựa trên nền tảng hoặc cấu hình.


  ◦ VD:

        #define DEBUG 1
        int main() {
            #ifdef DEBUG
                printf("Debug mode is ON\n");
            #else
                printf("Debug mode is OFF\n");
            #endif
            return 0;
        }

  ◦ Có thể định nghĩa macro DEBUG khi biên dịch bằng lệnh:

        gcc -DDEBUG file.c.

* **`#pragma`**

  ◦ Chức năng: Cung cấp các chỉ thị đặc biệt cho trình biên dịch, phụ thuộc vào trình biên dịch cụ thể.

  ◦ Ví dụ phổ biến:

        #pragma once: Ngăn tệp header được nhúng nhiều lần (tương tự header guards).

        #pragma pack: Điều chỉnh cách trình biên dịch căn chỉnh dữ liệu trong bộ nhớ.

* **`#error`** và **`#warning`**

  ◦ Chức năng: 
  
        #error "Thông báo": Dừng quá trình biên dịch và hiển thị thông báo lỗi.

        #warning "Thông báo": Hiển thị cảnh báo nhưng vẫn tiếp tục biên dịch.

  ◦ VD:

        #if __STDC_VERSION__ < 201112L
            #error "Yêu cầu C11 trở lên"
        #else
            #warning "Kiểm tra cấu hình trước khi chạy"
        #endif
        
### **II. Header Guards & Macro Safety**

#### **1. Header Guards**

* **Định nghĩa:**

  ◦ Header Guards là kỹ thuật sử dụng các chỉ thị `#ifndef`, `#define`, và `#endif` để ngăn tệp header được nhúng nhiều lần, tránh lỗi redefinition (định nghĩa lại hàm, biến, hoặc kiểu dữ liệu).   

* **Cú pháp:**

        /* file: myheader.h */
        #ifndef MYHEADER_H
        #define MYHEADER_H
        // Nội dung của header
        void my_function(void);
        #endif 

* **Cách hoạt động:**

  ◦ `#ifndef MYHEADER_H`: Kiểm tra xem macro `MYHEADER_H` có được định nghĩa chưa.  

  ◦ Nếu chưa, định nghĩa `MYHEADER_H` và nhúng nội dung header.

  ◦ Nếu đã được định nghĩa (do tệp header đã được nhúng trước đó), bỏ qua nội dung giữa `#ifndef` và `#endif.`

* **Thay thế bằng cách khác:**

  ◦ `#pragma once:` Đơn giản hơn header guards, chỉ cần một dòng để đảm bảo tệp header chỉ được nhúng một lần.

  ◦ VD:

        #pragma once
        void my_function(void);

#### **2. Macro Safety**

* **Vấn đề với macro:**

  ◦ Macro là thay thế văn bản thuần túy, không kiểm tra kiểu dữ liệu hoặc ngữ nghĩa.  

  ◦ Dễ gây lỗi do ưu tiên toán tử nếu không sử dụng ngoặc hợp lý.

* **Nguyên tắc an toàn khi viết macro:**

  ◦ Dùng ngoặc cho tham số và toàn bộ biểu thức 

        #define MAX(a, b) ((a) > (b) ? (a) : (b))

  ◦ Macro dài hoặc phức tạp khó debug. Thay vào đó, sử dụng hàm inline (C99 trở lên) để đảm bảo an toàn kiểu dữ liệu.

        inline int max(int a, int b) {
                return a > b ? a : b;
        }

  ◦ Sử dụng #undef khi cần hủy định nghĩa macro nếu không còn cần thiết

        #define TEMP 100
        // Sử dụng TEMP
        #undef TEMP



* **Cách hoạt động:**

  ◦ `#ifndef MYHEADER_H`: Kiểm tra xem macro `MYHEADER_H` có được định nghĩa chưa.  

  ◦ Nếu chưa, định nghĩa `MYHEADER_H` và nhúng nội dung header.

  ◦ Nếu đã được định nghĩa (do tệp header đã được nhúng trước đó), bỏ qua nội dung giữa `#ifndef` và `#endif.`

* **Thay thế bằng cách khác:**

  ◦ `#pragma once:` Đơn giản hơn header guards, chỉ cần một dòng để đảm bảo tệp header chỉ được nhúng một lần.

  ◦ VD:

        #pragma once
        void my_function(void);

### **III. VD TỔNG HỢP**


        /* file: myheader.h */
        #pragma once
        #define MAX(a, b) ((a) > (b) ? (a) : (b))
        void print_max(int a, int b);

        /* file: myheader.c */
        #include "myheader.h"
        #include <stdio.h>
        void print_max(int a, int b) {
            printf("Max of %d and %d is %d\n", a, b, MAX(a, b));
        }

        /* file: main.c */
        #include <stdio.h>
        #include "myheader.h"

        #define DEBUG 1

        int main() {
            #if DEBUG
                printf("Debug mode is ON\n");
            #endif

            print_max(10, 20); // In: Max of 10 and 20 is 20

            #if __STDC_VERSION__ < 201112L
                #error "This program requires C11 or later"
            #else
                #warning "Check your configuration before running"
            #endif

            return 0;
        }


</details>

<details>
	<summary><strong>PHẦN 2: CÚ PHÁP CƠ BẢN</strong></summary>

## **PHẦN 2: CÚ PHÁP CƠ BẢN**

### **I. Biến và kiểu dữ liệu**

#### **1. Biến**

* Là một tên gọi đại diện cho một vùng nhớ, được sử dụng để lưu trữ giá trị.

* Mỗi biến có một kiểu dữ liệu xác định kích thước và cách lưu trữ trong bộ nhớ

#### **2. Kiểu dữ liệu**

##### **2.1. Phân loại kiểu dữ liệu**

* C hỗ trợ các kiểu dữ liệu cơ bản (primitive), kiểu dữ liệu dẫn xuất (derived như mảng, con trỏ), và kiểu dữ liệu do người dùng định nghĩa (user-defined như struct, union, enum).

##### **2.2. Kiểu dữ liệu cơ bản (Primitive Types)**

*  **`int (Integer):`** Lưu trữ số nguyên (có dấu hoặc không dấu).

    ◦ Kích thước: Thường 4 byte (32-bit) trên hệ thống 32/64-bit, nhưng phụ thuộc vào kiến trúc máy (xem <limits.h> để kiểm tra).

    ◦ Phạm vi: -2^31 đến 2^31-1 (-2147483648 đến 2147483647); Unsigned: 0 đến 2^32-1.

    ◦ Ứng dụng: Đếm, chỉ số mảng, vòng lặp.

*  **`char (Character):`** Lưu trữ ký tự đơn hoặc số nguyên nhỏ.

    ◦ Kích thước: Luôn 1 byte (8-bit).

    ◦ Phạm vi: -128 đến 127; Unsigned: 0 đến 255.

    ◦ Mã hóa: Thường dùng ASCII (ví dụ: 'A' = 65), hỗ trợ Unicode trong C11 với wchar_t.

    ◦ Ứng dụng: Xử lý chuỗi ký tự, dữ liệu byte.

*  **`float (Floating-point):`** Lưu trữ số thực dấu chấm động đơn chính xác

    ◦ Kích thước: 4 byte.

    ◦ Phạm vi: Khoảng 1.2E-38 đến 3.4E+38.

    ◦ Độ chính xác: Khoảng 6-7 chữ số thập phân (IEEE 754 single-precision).

    ◦ Ứng dụng: Tính toán khoa học cơ bản, đồ họa.

*  **`double (Double-precision floating-point):`** Lưu trữ số thực độ chính xác cao.

    ◦ Kích thước: 8 byte.

    ◦ Phạm vi: Khoảng 2.3E-308 đến 1.7E+308.

    ◦ Độ chính xác: Khoảng 15-16 chữ số thập phân (IEEE 754 double-precision).

    ◦ Ứng dụng: Tính toán chính xác cao, mô phỏng khoa học.

##### **2.3. Bộ sửa đổi kiểu dữ liệu (Type Modifiers)**

*  **`short`** và **`long`**: Điều chỉnh kích thước của `int`.

    ◦ `short int:` Thường 2 byte (-32768 đến 32767).

    ◦ `long int:` 4 byte (trên 32-bit) hoặc 8 byte (trên 64-bit).

    ◦ `long long int:` 8 byte (-2^63 đến 2^63-1).

*  **`unsigned`**: Chỉ lưu giá trị không âm, tăng gấp đôi phạm vi dương.

    ◦  Ví dụ: unsigned int: 0 đến 4,294,967,295.

    ◦  Lưu ý: Tránh sử dụng với số âm để tránh lỗi undefined behavior.

*  **`signed`**: Mặc định cho hầu hết kiểu, cho phép giá trị âm.

##### **2.4. Constants và Qualifiers**

*  **`const (Constant)`**: Biến không thể thay đổi giá trị sau khi khởi tạo.

    ◦ Ứng dụng: Định nghĩa hằng số (constants) để tăng tính an toàn và đọc mã.

    ◦ Ví dụ: `const int MAX_USERS = 100`;.

    ◦ Lưu ý: Có thể dùng với con trỏ (ví dụ: const int* ptr - con trỏ trỏ đến dữ liệu không thay đổi).

*  **`volatile (Volatile)`**: Chỉ thị rằng giá trị biến có thể thay đổi bất ngờ (ngoài luồng chương trình, như từ phần cứng hoặc đa luồng).

    ◦  Ứng dụng: Lập trình nhúng, giao tiếp phần cứng (ví dụ: thanh ghi CPU).

    ◦  Ví dụ: volatile int sensor_value; - Trình biên dịch không tối ưu hóa đọc/ghi biến này.

    ◦  Lưu ý: Ngăn trình biên dịch cache giá trị trong thanh ghi.

*  **`restrict (C99 trở lên)`**: Gợi ý rằng con trỏ là cách duy nhất truy cập dữ liệu, giúp trình biên dịch tối ưu hóa mã tốt hơn (giảm aliasing).

    ◦  Ứng dụng: Trong hàm với nhiều con trỏ, tăng hiệu suất.

    ◦  Ví dụ: void copy(int *restrict dest, const int *restrict src);.

    ◦  Lưu ý: Chỉ là gợi ý, không thay đổi hành vi chương trình nếu sai.

##### **2.5. Lưu ý**


    ◦  Kích thước và phạm vi phụ thuộc vào trình biên dịch và kiến trúc (sử dụng sizeof() để kiểm tra).

    ◦  Tràn số (overflow): Ví dụ, int vượt quá phạm vi dẫn đến undefined behavior.

    ◦  Thư viện `<limits.h>` và `<float.h>` cung cấp macro cho phạm vi tối đa/min (ví dụ: `INT_MAX`).

#### **3. Khai báo và khởi tạo**

* **Khai báo:** Xác định kiểu và tên biến mà không gán giá trị ban đầu (giá trị mặc định là rác - garbage value).

* **Khởi tạo:** Khai báo và gán giá trị ban đầu cùng lúc.

* **Cú pháp:** 

        kiểu_dữ_liệu tên_biến = giá_trị;

* **VD:**

        const float PI = 3.14159f; // f chỉ rõ literal là float, tránh cast ngầm.

        volatile int sensor_value = 0; // Khởi tạo để tránh giá trị rác.

        int age = 25; // Số nguyên.

        float height = 1.75f; // Số thực float.

        double large_num = 1.23e-4; // Ký hiệu khoa học (exponential notation): 1.23 * 10^-4.

        char grade = 'A'; // Ký tự đơn, dùng dấu nháy đơn.

        unsigned long long big_num = 18446744073709551615ULL; // ULL chỉ rõ unsigned long long literal.

* **Lưu ý:** 

    ◦ Khởi tạo biến cục bộ để tránh lỗi (giá trị rác).

    ◦ Biến toàn cục/toàn cục tĩnh mặc định là 0.

#### **4. Phạm vi và thời gian sống**

* **Phạm vi (Scope):** Vùng mã nơi biến có thể được truy cập.

  ◦ **Cục bộ (Local Scope):** Trong hàm hoặc khối lệnh (block) { }. Chỉ tồn tại trong phạm vi đó.

  ◦ **Toàn cục (Global Scope):** Khai báo ngoài hàm, có thể truy cập toàn chương trình.

  ◦ **Tĩnh (Static Scope):** Sử dụng static để giữ phạm vi cục bộ nhưng thời gian sống toàn cục.

  ◦ **Hàm (Function Scope):** Áp dụng cho nhãn (labels) trong goto.


* **Thời gian sống (Lifetime):** Thời gian biến tồn tại trong bộ nhớ.

  ◦ **Cục bộ (Automatic):** Tạo khi vào phạm vi, hủy khi thoát (stack allocation).

  ◦ **Toàn cục/Toàn cục tĩnh:** Tồn tại suốt chương trình (data segment).

  ◦ **Tĩnh cục bộ:** Giống toàn cục, nhưng chỉ truy cập trong hàm.

  ◦ **Động (Dynamic):** Sử dụng `malloc()` để cấp phát, tồn tại đến khi `free()` (heap allocation).


* **VD:**

        #include <stdio.h>

        int global_var = 10;       // Toàn cục, thời gian sống suốt chương trình
        static int global_static = 20; // Toàn cục tĩnh, tương tự nhưng chỉ trong tệp này

        void counter() {
            static int count = 0;  // Tĩnh cục bộ: Phạm vi trong hàm, thời gian sống suốt chương trình
            int local_var = 5;     // Cục bộ: Phạm vi trong hàm, hủy khi thoát hàm
            count++;
            printf("Count: %d, Local: %d\n", count, local_var);
        }

        int main() {
            counter();  // In: Count: 1, Local: 5
            counter();  // In: Count: 2, Local: 5 (local_var được tạo mới mỗi lần)
            printf("Global: %d\n", global_var);  // In: 10
            return 0;
        }


#### **5.Typedef và Enum**

##### **5.1. Typedef**

* **Định nghĩa:** Tạo bí danh (alias) cho kiểu dữ liệu hiện có, tăng tính đọc và bảo trì mã. Không tạo kiểu mới, chỉ đổi tên.

* **Cú pháp:** `typedef kiểu_cũ tên_mới`;

* **Ứng dụng:** Rút gọn kiểu phức tạp (ví dụ: struct, union), tăng tính portable.

* **VD:**

        typedef unsigned long ulong_t;
        ulong_t large_num = 123456789UL;  // UL: Unsigned long literal

##### **5.2. Enum (Enumeration)**

* **Định nghĩa:** Định nghĩa tập hợp hằng số nguyên có tên, bắt đầu từ 0 mặc định.

* **Cú pháp:** `enum { TEN1, TEN2, ... }; hoặc typedef enum { ... } ten_enum;`

* **Ứng dụng:** Đại diện trạng thái, lựa chọn (ví dụ: ngày trong tuần), tăng tính đọc thay vì dùng số nguyên trực tiếp.

* **VD:**

        typedef enum { 
            FALSE = 0, TRUE = 1 
            } bool_t;

        bool_t flag = TRUE;
        printf("Flag: %d\n", flag);  // In: 1

        enum Weekday { 
            MON = 1, 
            TUE, 
            WED,
            THU, 
            FRI, 
            SAT, 
            SUN 
            };
        enum Weekday today = WED;    // Giá trị: 3

### **II. Nhập/Xuất cơ bản**

#### **1. Hàm printf**

*  **Định nghĩa:** Hàm printf (print formatted) dùng để xuất dữ liệu ra thiết bị đầu ra chuẩn (thường là màn hình) với định dạng được chỉ định.

*  **Cú pháp:** 

        int printf(const char *format, ...);

        ◦ `format`: Chuỗi định dạng, chứa văn bản và các đặc tả định dạng (format specifiers) như %d, %f.

        ◦ `...`: Các tham số tương ứng với các đặc tả định dạng.

        ◦ Giá trị trả về: Số ký tự được in (thành công) hoặc giá trị âm (lỗi).

*  **Đặc tả định dạng (Format Specifiers):** 


        ◦ `%d` hoặc `%i`: Số nguyên (int).

        ◦ `%u`: Số nguyên không dấu (unsigned int).

        ◦ `%f`: Số thực (float hoặc double, mặc định 6 chữ số thập phân).

        ◦ `%lf`: Số thực double (dùng trong scanf, không cần trong printf)

        ◦ `%c`: Ký tự (char).

        ◦ `%s`: Chuỗi ký tự (string, kết thúc bằng \0).

        ◦ `%p`: Con trỏ (địa chỉ, thường in dạng hex).

        ◦ `%x` hoặc `%X`: Số nguyên dạng hex (chữ thường hoặc hoa).

        ◦ `%o`: Số nguyên dạng bát phân (octal).

        ◦ `%%`: In dấu %.       

*  **Ký tự điều khiển đặc biệt:** 


    ◦ Width: Chỉ định số ký tự tối thiểu để hiển thị

        %10d: In số nguyên, chiếm 10 ký tự, căn phải (điền khoảng trắng bên trái).

        %-10d: Căn trái, chiếm 10 ký tự.

    ◦ Precision: Chỉ định số chữ số thập phân cho số thực hoặc độ dài chuỗi

        %.2f: In float/double với 2 chữ số thập phân.

        %.5s: In tối đa 5 ký tự của chuỗi.

    ◦ Flags

        -: Căn trái.

        +: Luôn hiển thị dấu (+/-) cho số.

        0: Điền số 0 thay vì khoảng trắng cho số.

        #: Thêm tiền tố (ví dụ: 0x cho hex, 0 cho octal).

    ◦ Dynamic width/precision

        %*d: Độ rộng được cung cấp qua tham số (printf("%*d", 5, 42) in 42 với 5 ký tự).

        %.*f: Độ chính xác được cung cấp qua tham số (printf("%.*f", 2, 3.14159) in 3.14).

*  **VD:**

        #include <stdio.h>
        int main() {
            int num = 123;
            float pi = 3.14159;
            printf("%-10s %10d\n", "Tên", num);     // In: Tên          123
            printf("%+d %.2f\n", 42, pi);           // In: +42 3.14
            printf("%*d\n", 5, num);                // In:    123
            printf("%08d\n", num);                  // In: 00000123
            printf("%#x\n", num);                   // In: 0x7b
            return 0;
        }

#### **2. Hàm scanf**

*  **Định nghĩa:** Hàm scanf (scan formatted) dùng để đọc dữ liệu từ đầu vào chuẩn (thường là bàn phím) dựa trên định dạng được chỉ định.

*  **Cú pháp:** 

        int scanf(const char *format, ...);

        ◦ `format`: Chuỗi định dạng, tương tự printf nhưng yêu cầu địa chỉ biến (&biến).

        ◦ `...`: Các con trỏ đến biến lưu giá trị nhập.

        ◦ Giá trị trả về: Số lượng tham số được gán thành công, hoặc EOF (-1) nếu gặp lỗi hoặc hết dữ liệu.

*  **Đặc tả định dạng (Format Specifiers):** 


        ◦ `%d` hoặc `%i`: Số nguyên (int).

        ◦ `%u`: Số nguyên không dấu (unsigned int).

        ◦ `%f`: Số thực (float hoặc double, mặc định 6 chữ số thập phân).

        ◦ `%lf`: bắt buộc cho double trong scanf.

        ◦ `%c`: Đọc một ký tự, kể cả khoảng trắng hoặc \n.

        ◦ `%s`: Đọc chuỗi đến khi gặp khoảng trắng hoặc \n (thêm \0 vào cuối).

        ◦ `%p`: Con trỏ (địa chỉ, thường in dạng hex).

        ◦ `%x` hoặc `%X`: Số nguyên dạng hex (chữ thường hoặc hoa).

        ◦ `%o`: Số nguyên dạng bát phân (octal).

        ◦ `%%`: In dấu %.       

*  **Lưu ý:** 

    ◦ Luôn sử dụng toán tử `&` để truyền địa chỉ biến (trừ `%s` với chuỗi vì mảng đã là con trỏ).

    ◦ Kiểm tra giá trị trả về của scanf để xác nhận nhập thành công.

    ◦ Ký tự khoảng trắng trong chuỗi định dạng (" %d %f") bỏ qua khoảng trắng hoặc ký tự xuống dòng..

*  **Xử lý lỗi nhập:** 

    ◦ Nhập sai định dạng (ví dụ: nhập chuỗi cho %d) khiến scanf trả về số lượng tham số nhỏ hơn mong đợi.

    ◦ Bộ đệm (buffer) có thể giữ lại ký tự như \n, gây lỗi ở lần nhập tiếp theo.

*  **Khắc phục bộ đệm:** 

    ◦ Dùng vòng lặp để xóa bộ đệm:

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

    ◦ Hoặc thêm khoảng trắng vào định dạng: scanf(" %d", &num); (bỏ qua ký tự trắng).

        #include <stdio.h>
        int main() {
            int num;
            char ch;
            printf("Nhập số và ký tự: ");
            if (scanf("%d", &num) == 1) {
                while ((ch = getchar()) != '\n' && ch != EOF); // Xóa bộ đệm
                scanf("%c", &ch);
                printf("Số: %d, Ký tự: %c\n", num, ch);
            }
            return 0;
        }

*  **VD:**

        #include <stdio.h>
        int main() {
            int age;
            float height;
            printf("Nhập tuổi và chiều cao: ");
            if (scanf("%d %f", &age, &height) == 2) {
                printf("Tuổi: %d, Chiều cao: %.2f\n", age, height);
            } else {
                printf("Nhập lỗi!\n");
            }
            return 0;
        }

#### **3. Hàm getline**

*  **Định nghĩa:** Hàm `getline` là một hàm POSIX (không thuộc chuẩn C, nhưng phổ biến trên Linux/Unix) dùng để đọc toàn bộ một dòng từ đầu vào (bao gồm cả khoảng trắng), tránh lỗi tràn bộ đệm khi dùng `%s` với `scanf`.

*  **Cú pháp:** 

        #include <stdio.h>
        ssize_t getline(char **lineptr, size_t *n, FILE *stream);

        ◦ `lineptr`: Con trỏ tới bộ đệm động (tự cấp phát nếu NULL).

        ◦ `n`: Kích thước bộ đệm (cập nhật nếu cấp phát lại).

        ◦ `stream`: Luồng đầu vào (thường là stdin).

        ◦ Giá trị trả về: Số ký tự đọc được (bao gồm \n), hoặc -1 nếu lỗi/hết dữ liệu.

*  **Ưu điểm:** 

    ◦ Tự động cấp phát bộ nhớ, tránh tràn bộ đệm (buffer overflow).

    ◦ Đọc cả dòng, bao gồm khoảng trắng, không giống %s trong scanf.

        #include <stdio.h>
        #include <stdlib.h>
        int main() {
            char *line = NULL;  // Bộ đệm động
            size_t len = 0;     // Kích thước bộ đệm
            printf("Nhập chuỗi: ");
            if (getline(&line, &len, stdin) != -1) {
                printf("Bạn nhập: %s", line);
            } else {
                printf("Lỗi đọc dòng!\n");
            }
            free(line);  // Giải phóng bộ nhớ
            return 0;
        }

*  **Lưu ý:** 


    ◦ Luôn giải phóng bộ nhớ bằng free(line) sau khi dùng.

    ◦ Thay thế: Dùng fgets trong chuẩn C để đọc dòng với kích thước cố định



#### **4. Lỗi phổ biến và cách khắc phục**

*  **Nhập sai định dạng:** 

    ◦ Vấn đề: Người dùng nhập chuỗi (ví dụ: "abc") khi scanf mong đợi %d.

    ◦ Hậu quả: scanf trả về số lượng tham số nhỏ hơn mong đợi, biến không được gán giá trị.

    ◦ Khắc phục

        int num;
        while (scanf("%d", &num) != 1) {
            printf("Vui lòng nhập số nguyên: ");
            while (getchar() != '\n' && getchar() != EOF); // Xóa bộ đệm
        }    

*  **Bộ đệm lưu ký tự thừa:** 

    ◦ Vấn đề: Ký tự \n hoặc khoảng trắng từ lần nhập trước còn sót trong bộ đệm, gây lỗi cho scanf hoặc getchar.

    ◦ Hậu quả: Chương trình bỏ qua hoặc đọc sai dữ liệu.

    ◦ Khắc phục: Xóa bộ đệm trước khi đọc

        int c;
        while ((c = getchar()) != '\n' && c != EOF);  

*  **Tràn bộ đệm khi đọc chuỗi:** 

    ◦ Vấn đề: `%s` trong `scanf` không giới hạn độ dài chuỗi, gây tràn bộ đệm.

    ◦ Khắc phục: Chỉ định độ dài tối đa: scanf("%99s", str); (cho mảng char str[100]), sử dụng fgets hoặc getline thay thế.

*  **Không kiểm tra giá trị trả về:** 

    ◦ Vấn đề: Không kiểm tra kết quả của scanf hoặc getline, dẫn đến xử lý dữ liệu không hợp lệ.

    ◦ Khắc phục: Luôn kiểm tra giá trị trả về (số tham số gán hoặc -1).


### **III. Toán tử**

#### **1. Định nghĩa**

* Là các ký hiệu hoặc từ khóa đặc biệt trong C dùng để thực hiện các phép toán trên biến hoặc giá trị (gọi là toán hạng - operands)

* Toán tử giúp thao tác dữ liệu, từ các phép tính số học cơ bản đến xử lý logic, so sánh, gán giá trị, hoặc thao tác trực tiếp trên bit.

#### **2. Toán tử Số học (Arithmetic Operators)**

##### **2.1. Định nghĩa:**

* Toán tử số học thực hiện các phép toán cơ bản trên các kiểu dữ liệu số (như int, float, double)

##### **2.2. Danh sách toán tử số học**

*  **`+:`** Cộng hai toán hạng (ví dụ: `a + b`).

*  **`-:`** Trừ hai toán hạng (ví dụ: `a - b`).

*  **`*:`** Nhân hai toán hạng (ví dụ: `a * b`).

*  **`/:`** Chia hai toán hạng (ví dụ: `a / b`).

*  **`%:`** Chia lấy dư (chỉ áp dụng cho kiểu nguyên int, ví dụ: `a % b`).

*  **`++:`** Tăng giá trị toán hạng lên 1 (tiền tố: `++i`, hậu tố: `i++`).

*  **`--:`** Giảm giá trị toán hạng đi 1 (tiền tố: `--i`, hậu tố: `i--`).

##### **2.3. Lưu ý**

*  **Phép chia (/):**

    ◦ Với `int / int`, kết quả là số nguyên, phần thập phân bị bỏ (ví dụ: `7 / 2 = 3`).

    ◦ Với `float` hoặc `double`, kết quả bao gồm phần thập phân (ví dụ: `7.0 / 2 = 3.5`).

    ◦ Chia cho 0 gây lỗi undefined behavior (cho `int`) hoặc trả về giá trị đặc biệt như `inf`/`nan` (cho `float`/`double`).


*  **Toán tử tăng/giảm (++, --):** 

    ◦ **Tiền tố (++i, --i):** Tăng/giảm giá trị trước, rồi sử dụng giá trị mới.

    ◦ **Hậu tố (i++, i--):** Sử dụng giá trị hiện tại, rồi tăng/giảm sau.

        int i = 5;
        printf("%d\n", ++i); // In: 6 (tăng trước, in sau)
        printf("%d\n", i++); // In: 6 (in trước, tăng sau)
        printf("%d\n", i);   // In: 7


*  **Tràn số (Overflow):** 

    ◦ Với kiểu int, nếu kết quả vượt quá phạm vi (INT_MAX hoặc INT_MIN), hành vi không xác định. Sử dụng kiểu lớn hơn như long hoặc long long nếu cần.

#### **3. Toán tử Logic (Logical Operators)**

##### **3.1. Định nghĩa:**

* Toán tử logic thực hiện các phép toán logic trên giá trị boolean (thường được biểu diễn bằng 0 - sai, hoặc khác 0 - đúng). Kết quả của toán tử logic luôn là `0` (sai) hoặc `1` (đúng).

##### **3.2. Danh sách toán tử logic**

*  **`&&:`** AND logic (và) - Đúng nếu cả hai vế đều đúng.

*  **`||:`** OR logic (hoặc) - Đúng nếu ít nhất một vế đúng.

*  **`!:`** NOT logic (phủ định) - Đảo ngược giá trị logic (0 thành 1, khác 0 thành 0)

##### **3.3. Short-circuit Evaluation**

*  **Với &&:** Nếu vế trái sai (0), vế phải không được đánh giá (vì kết quả đã là sai).

*  **Với ||:** Nếu vế trái đúng (khác 0), vế phải không được đánh giá (vì kết quả đã là đúng).

        #include <stdio.h>
        int main() {
            int a = 5, b = 0;
            if (a && b) {
                printf("Cả hai đúng\n"); // Không in vì b = 0
            }
            if (a || b) {
                printf("Một trong hai đúng\n"); // In vì a = 5
            }
            if (!b) {
                printf("b là sai\n"); // In vì !0 = 1
            }
            // Short-circuit ví dụ
            int *ptr = NULL;
            if (ptr != NULL && *ptr == 5) { // Vế phải không chạy nếu ptr là NULL
                printf("Không in\n");
            }
            return 0;
        }

#### **4. Toán tử so sánh (Relational Operators)**

##### **4.1. Định nghĩa:**

* Toán tử so sánh dùng để so sánh hai toán hạng, trả về `1 (đúng)` hoặc `0 (sai)`. Chúng thường được sử dụng trong các câu lệnh điều kiện (`if, while`) hoặc vòng lặp.

##### **4.2. Danh sách toán tử logic**

*  **`==:`** Bằng

*  **`!=:`** Không bằng

*  **`<:`** Nhỏ hơn

*  **`>:`** Lớn hơn

*  **`<=:`** Nhỏ hơn hoặc bằng

*  **`>=:`** Lớn hơn hoặc bằng

##### **4.3. Đặc điểm**

*  Kết quả luôn là `0` hoặc `1`.

*  Có thể so sánh các kiểu số (`int`, `float`, `double`) và ký tự (`char`, so sánh mã ASCII).

*  Với số thực (`float`, `double`), cẩn thận với lỗi làm tròn (rounding error).

        #include <stdio.h>
        int main() {
            int a = 10, b = 20;
            printf("a == b: %d\n", a == b); // 0 (sai)
            printf("a != b: %d\n", a != b); // 1 (đúng)
            printf("a < b: %d\n", a < b);   // 1 (đúng)
            printf("a >= b: %d\n", a >= b); // 0 (sai)
            return 0;
        }

#### **5. Toán tử gán (Assignment Operators)**

##### **5.1. Định nghĩa:**

* Toán tử gán dùng để gán giá trị cho biến. Toán tử gán cơ bản là `=`, nhưng C cũng hỗ trợ các toán tử gán kết hợp (compound assignment) để thực hiện phép toán và gán cùng lúc.

##### **5.2. Danh sách toán tử gán**

*  **`&`:** AND bitwise - Lấy bit 1 nếu cả hai bit tương ứng là 1.

*  **`|`:** OR bitwise - Lấy bit 1 nếu ít nhất một bit tương ứng là 1.

*  **`^`:** XOR bitwise - Lấy bit 1 nếu hai bit tương ứng khác nhau.

*  **`~:`** NOT bitwise - Đảo ngược tất cả bit (0 thành 1, 1 thành 0).

*  **`<<`:** Dịch trái - Dịch các bit sang trái, thêm 0 vào bên phải.

*  **`>>`:** Dịch phải - Dịch các bit sang phải, thêm bit dấu (cho signed) hoặc 0 (cho unsigned).


        #include <stdio.h>
        int main() {
            unsigned int a = 5;  // 0101
            unsigned int b = 3;  // 0011
            printf("a & b: %d\n", a & b);    // 0001 = 1
            printf("a | b: %d\n", a | b);    // 0111 = 7
            printf("a ^ b: %d\n", a ^ b);    // 0110 = 6
            printf("~a: %u\n", ~a);          // ~0101 = 1111...1010 (phụ thuộc kích thước)
            printf("a << 2: %d\n", a << 2);  // 0101 << 2 = 10100 = 20
            printf("b >> 1: %d\n", b >> 1);  // 0011 >> 1 = 0001 = 1
            return 0;
        }

##### **5.3. Lưu ý**

*  Toán tử bitwise chỉ áp dụng cho kiểu nguyên, không dùng cho `float/double`.

*  Dịch phải (`>>`) với số có dấu phụ thuộc vào trình biên dịch (sign extension).

#### **6. Toán tử điều kiện (Ternary Operator: `?:`)**

##### **6.1. Định nghĩa:**

* Toán tử điều kiện (`?:`) là toán tử ba ngôi (ternary) duy nhất trong C, hoạt động như một câu lệnh `if-else` ngắn gọn.

* Nó đánh giá một biểu thức logic và trả về một trong hai giá trị dựa trên kết quả của biểu thức đó.

##### **6.2. Cú pháp**

        biểu_thức ? giá_trị_1 : giá_trị_2;

*  **biểu_thức:** Điều kiện logic, trả về `0` (sai) hoặc khác `0` (đúng).

*  **giá_trị_1:** Giá trị được trả về nếu biểu thức đúng.

*  **giá_trị_2:** Giá trị được trả về nếu biểu thức sai.

##### **6.3. Cách hoạt động**

*  Nếu `biểu_thức` đúng (khác `0`), toán tử trả về `giá_trị_1`.

*  Nếu `biểu_thức` sai (`0`), toán tử trả về `giá_trị_2`.

* Toán tử này có thể được sử dụng trong biểu thức hoặc gán giá trị, thay thế cho câu lệnh `if-else` trong các trường hợp đơn giản.

        #include <stdio.h>
        int main() {
            int a = 10, b = 20;
            int max = (a > b) ? a : b; // Nếu a > b đúng, chọn a; ngược lại chọn b
            printf("Max: %d\n", max);   // In: 20

            // Sử dụng trong printf
            printf("Số %d là %s\n", a, (a % 2 == 0) ? "chẵn" : "lẻ"); // In: Số 10 là chẵn
            return 0;
        }


#### **7. Toán tử sizeof**

##### **7.1. Định nghĩa:**

* Toán tử `sizeof` trả về kích thước (tính bằng byte) của một kiểu dữ liệu hoặc một biến

* Đây là toán tử một ngôi , được xử lý tại thời điểm biên dịch (compile-time), không phải runtime, trừ trường hợp mảng kích thước biến đổi (VLA) trong C99.

##### **7.2. Cú pháp**

        sizeof(biến);
        sizeof(kiểu_dữ_liệu);

*  **Kết quả:** Trả về giá trị kiểu `size_t` (thường là `unsigned long` hoặc `unsigned int`, định nghĩa trong `<stddef.h>`).

*  Dùng với `%zu` trong printf để in giá trị `size_t`.

##### **7.3. Cách hoạt động**

*  Với biến: Trả về kích thước vùng nhớ mà biến chiếm.

*  Với kiểu dữ liệu: Trả về kích thước của kiểu (ví dụ: `sizeof(int)`).

*  Với mảng: Trả về kích thước tổng cộng của mảng (trừ khi mảng bị suy biến thành con trỏ trong hàm).

        #include <stdio.h>
        int main() {
            int x = 10;
            double d = 3.14;
            char arr[5] = "abcd";
            
            printf("sizeof(int): %zu\n", sizeof(int));         // Thường in: 4
            printf("sizeof(x): %zu\n", sizeof x);             // In: 4
            printf("sizeof(double): %zu\n", sizeof(double));   // Thường in: 8
            printf("sizeof(arr): %zu\n", sizeof(arr));         // In: 5 (kích thước mảng)
            return 0;
        }    

##### **7.4. Lưu ý**

*  **Mảng trong hàm:** Khi truyền mảng vào hàm, sizeof trả về kích thước con trỏ, không phải mảng.

        void func(int arr[]) {
            printf("%zu\n", sizeof(arr)); // In kích thước con trỏ (4 hoặc 8)
        }

*  **Không áp dụng cho void:** sizeof(void) không hợp lệ, nhưng sizeof(void*) trả về kích thước con trỏ (4 hoặc 8 byte).


        #include <stdio.h>
        struct Point {
            int x;
            double y;
        };
        int main() {
            struct Point p;
            printf("sizeof(struct Point): %zu\n", sizeof(struct Point)); // In: 16 (4 + 8 + padding)
            printf("sizeof(p.x): %zu\n", sizeof(p.x));                  // In: 4
            return 0;
        }


#### **8. Toán tử dấu phẩy (Comma Operator)**

##### **8.1. Định nghĩa:**

* Toán tử dấu phẩy (,) cho phép thực hiện nhiều biểu thức tuần tự trong một dòng, trả về giá trị của biểu thức cuối cùng. Đây là toán tử có ưu tiên thấp nhất trong C.


##### **8.2. Cú pháp**

        biểu_thức_1, biểu_thức_2, ..., biểu_thức_n;

*  Các biểu thức được thực hiện từ trái sang phải.

*  Giá trị của toàn bộ biểu thức dấu phẩy là giá trị của biểu thức cuối cùng.


        #include <stdio.h>
        int main() {
            int a = 5, x;
            x = (a = a + 1, a * 2, a + 3); // Thực hiện: a = 6, 6*2, 6+3
            printf("x: %d, a: %d\n", x, a); // In: x: 9, a: 6
            return 0;
        } 

#### **9. Toán tử con trỏ (`*` và `&`)**

##### **9.1. Định nghĩa:**

* Toán tử con trỏ (`*` và `&`) dùng để làm việc với con trỏ, một khái niệm quan trọng trong C để quản lý địa chỉ bộ nhớ và truy cập dữ liệu gián tiếp.

    ◦ `&` **(Address-of):** Lấy địa chỉ bộ nhớ của một biến.

    ◦ `*` **(Dereference):** Truy cập giá trị tại địa chỉ mà con trỏ trỏ tới.

##### **9.2. Cú pháp**


*  `&biến`: Trả về địa chỉ của biến (kiểu con trỏ).

*  `*con_trỏ`: Truy cập hoặc sửa đổi giá trị tại địa chỉ mà con trỏ trỏ tới.

##### **9.3. Cách hoạt động**

*  Mỗi biến trong C được lưu tại một địa chỉ bộ nhớ duy nhất.

*  `&` tạo con trỏ trỏ đến biến.

*  `*` lấy hoặc gán giá trị tại địa chỉ đó.

        #include <stdio.h>
        int main() {
            int x = 10;
            int *ptr = &x; // ptr trỏ đến địa chỉ của x
            printf("Địa chỉ của x: %p\n", (void*)&x); // In địa chỉ
            printf("Giá trị ptr trỏ tới: %d\n", *ptr); // In: 10
            *ptr = 20; // Thay đổi giá trị x qua con trỏ
            printf("x sau khi thay đổi: %d\n", x); // In: 20
            return 0;
        }

##### **9.4. Lưu ý**

*  **Con trỏ null:** Tránh sử dụng `*` trên con trỏ `NULL`, gây lỗi segmentation fault.

*  **Kiểu con trỏ:** Con trỏ phải khớp với kiểu của biến (trừ `void*`, con trỏ tổng quát).

*  **Dùng %p trong printf:** Luôn ép kiểu con trỏ sang `void*` khi in.
 
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
<details>
	<summary><strong>PHẦN 3: Con trỏ</strong></summary>

## **PHẦN 3: Con trỏ**

### **1.Định nghĩa**

  * Con trỏ là một biến đặc biệt **lưu trữ địa chỉ bộ nhớ** của một biến hoặc đối tượng khác trong bộ nhớ

  * Mỗi con trỏ được liên kết với một **kiểu dữ liệu** cụ thể( vd: `int *`, `char *`), xác định kiểu của dữ liệu mà con trỏ trỏ tới

  * Con trỏ cho phép thao tác trực tiếp với địa chỉ bộ nhớ, giúp quản lý tài nguyên hiệu quả và thực hiện các thao tác cấp thấp
  

### **2.Khai báo và khởi tạo**

#### **2.1.Cú pháp khai báo**

```
kiểu_dữ_liệu  *tên_con_trỏ;
```

VD:
```
int *ptr; //Con trỏ trỏ tới dữ liệu kiểu int
char *ptr; //Con trỏ trỏ tới dư liệu kiểu char
float *ptr; //Con trỏ trỏ tới dữ liệu kiểu float
```
#### **2.2.Toán tử con trỏ**

   * **&(Toán tử lấy địa chỉ):** Trả về địa chỉ bộ nhớ của 1 biến
    
    int x = 10;
    int *ptr = &x; //ptr lưu địa chỉ của 
    
   * **`*`(Toán tử giải tham chiếu):** Truy cập hoặc sủa đổi giá trị tại địa chỉ mà con trỏ trỏ tới 
   ```
   *ptr = 20; //Thay đổi giá trị của x thành 20
   ```

#### **2.3.Khởi tạo**  

   * **Khởi tạo với địa chỉ của biến:**
   ```
   int x = 10;
   int *ptr = &x;  //ptr trỏ tới địa chỉ của x
   ```

   * **Khởi tạo với NULL (tránh lỗi truy cập bộ nhớ không hợp lệ:**
   ```
   int *ptr = NULL;
   ```

   * **Khởi tạo với chuỗi ký tự hằng:**
   ```
   char *str = "Hello";
   ```
   
#### **2.4.Con trỏ void**

   * Con trỏ kiểu `void*` là con trỏ có thể trỏ tới bất kỳ kiểu dữ liệu nào

   * Cần ép kiểu trước khi giải tham chiếu
   ```
   void *ptr;
   int x = 10;
   ptr = &x;
   printf("%d\n", *(int*)ptr); // Ép kiểu void* thành int* để truy cập giá trị
   ```

### **3.Lưu trữ và cách hoạt động trong bộ nhớ**

   * Con trỏ lưu trữ **địa chỉ bộ nhớ**

   * Kích thước con trỏ phụ thuộc vào kiến trúc hệ thống

     32-bit: Con trỏ thường chiếm 4 byte
     64-bit: Con trỏ thường chiếm 8 byte

   * Khi giải tham chiếu (`*ptr`), chương trình truy cập giá trị tại địa chỉ mà con trỏ lưu trữ 

### **4. Thao tác với con trỏ**

#### **4.1. Truy cập và sửa đổi giá trị**

   * **Truy cập giá trị:**
    
    int x = 10;
    int *ptr = &x;
    printf("Gia tri tai ptr: %d\n", *ptr);
    

   * **Sửa đổi giá trị:**

    *ptr = 20; // Giá trị của x thay đổi thành 20
    printf("Gia tri cua x: %d\n", x); // In 20


#### **4.2. Con trỏ và mảng**

* Tên mảng là con trỏ trỏ tới **phần tử đầu tiên** của mảng: `arr` tương đương `&arr[0]`

* **Truy cập phần tử mảng:**
`arr[i]` tương đương `*(arr + i)`

  VD: 
```
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
printf("%d\n", *(ptr + 2)); // In 3 (phần tử arr[2])
```

* **Duyệt mảng bằng con trỏ:**
```
for (int i = 0; i < 5; i++) {
    printf("%d ", *(ptr + i)); // In 1 2 3 4 5
}
```
#### **4.3. Con trỏ và chuỗi**

* Chuỗi trong C là mảng ký tự kết thúc bằng `\0`, và con trỏ kiểu `char*` 

* **Khởi tạo chuỗi:**
```
char *str = "Hello"; // str trỏ tới chuỗi hằng
```
* **Truy cập ký tự:**
```
printf("%c\n", *(str + 1)); // In 'e'
```
* **Lưu ý: Không thể sửa đổi chuỗi hằng**
```
str[0] = 'h'; // LỖI: Chuỗi hằng không thể sửa đổi
```
* **Để sửa đổi chuỗi, cần khai báo mảng ký tự:**
```
char str[] = "Hello"; // Mảng ký tự, có thể sửa đổi
str[0] = 'h';
printf("%s\n", str); // In "hello"
```
#### **4.4. Con trỏ và hàm**

* Con trỏ có thể được truyền vào hàm để sửa đổi giá trị của biến bên ngoài (pass-by-reference).
```
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y); // In: x = 20, y = 10
}

=> Con trỏ a và b trỏ tới địa chỉ của x và y, cho phép hàm swap thay đổi giá trị của chúng.
```
#### **4.5. Con trỏ và bộ nhớ động**

* Con trỏ thường được dùng để cấp phát bộ nhớ động bằng malloc và giải phóng bằng free
```
#include<stdio.h>
int *ptr = malloc(sizeof(int)); // Cấp phát bộ nhớ cho 1 số nguyên
if(ptr == NULL){
    printf("Cap phat that bai!\n");
    return 1;
}
*ptr = 42;
printf("Gia tri: %d\n", *ptr); //In: 42
free(ptr);
```
#### **4.6. Lỗi phổ biến khi dùng con trỏ**

* **Truy cập con trỏ NULL**
```
int *ptr = NULL;
printf("%d\n", *ptr);  // LỖI: Truy cập con trỏ NULL
```

* **Con trỏ không khởi tạo**
```
int *ptr; // Không khởi tạo
*ptr = 10; // LỖI: Truy cập địa chỉ ngẫu nhiên
```

* **Con trỏ lơ lửng (dangling pointer)**
```
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 10; // LỖI: Truy cập bộ nhớ đã giải phóng
```
</details>

<details>
	<summary><strong>PHẦN 4: Quản lý bộ nhớ cơ bản</strong></summary>

## **PHẦN 4: Quản lý bộ nhớ cơ bản**

### **1.Stack và Heap**

  * **Stack:**

    ◦ Là vùng bộ nhớ dùng để lưu trữ các biến cục bộ và thông tin gọi hàm

    ◦ Bộ nhớ trên stack được cấp phát và giải phóng tự động bởi trình biên dịch khi biến ra khỏi phạm vi (scope)

    ◦ Kích thước stack thường cố định, giới hạn bởi hệ thống, do đó không phù hợp cho dữ liệu lớn hoặc tồn tại lâu dài
    ```
    void function() {
    int x = 10; // Biến x được lưu trên stack, tự động giải phóng khi hàm kết thúc
    }
    ``` 

  * **Heap:** 
    
    ◦ Là vùng bộ nhớ động, được sử dụng để lưu trữ dữ liệu cần tồn tại lâu hơn hoặc kích thước không xác định trước

    ◦ Bộ nhớ trên heap phải được cấp phát và giải phóng thủ công bởi coder

    ◦ Nếu không quản lý đúng cách có thể dẫn tới memory leak hoặc truy cập bộ nhớ không hợp lệ
    ```
    int *ptr = malloc(sizeof(int)); // Cấp phát bộ nhớ trên heap cho một số nguyên
    *ptr = 10; // Gán giá trị
    free(ptr); // Giải phóng bộ nhớ
    ```  

### **2.Cấp phát và giải phóng bộ nhớ**


   * Thư viện `<stdlib.h>` cung cấp các hàm để quản lý bộ nhớ động trên heap
    
    ◦ malloc(size): Cấp phát một khối bộ nhớ có kích thước `size` byte, trả về con trỏ void* trỏ đến khối bộ nhớ này.Nội dung bộ nhớ không được khởi tạo

    ◦ calloc(n, size): Cấp phát bộ nhớ cho n phần tử, mỗi phần tử có kích thước size byte, và khởi tạo tất cả giá trị bằng 0

    ◦ realloc(ptr, new_size): Thay đổi kích thước của bộ nhớ đã được cấp phát trước đó, bảo toàn dữ liệu nếu có thể

    ◦ free(ptr): Giải phóng bộ nhớ được cấp phát bởi `malloc`,`calloc` hoặc `realloc`
```    
#include<stdlib.h>
int main(){

    //Cấp phát mảng 5 số nguyên trên heap
    int *arr = malloc(sizeof(int) * 5);
    if (arr == NULL){
        return -1;
    }
    for(int i = 0; i < 5; i++){
        arr[i] = i + 1;
    }

    // Thay đổi kích thước mảng thành 10 số nguyên
    arr = realloc(arr, sizeof(int) * 10);
    if(arr == NULL){
        return -1;
    }

    //Giải phóng bộ nhớ
    free(arr);
    arr = NULL;
    return 0;
}


```
    
### **3. Lỗi phổ biến trong quản lý bộ nhớ**

**Memory leak:**

 ◦ Xảy ra khi bộ nhớ được cấp phát trên heap nhưng không được giải phóng, dẫn đến lãng phí tài nguyên.
```
int *ptr = malloc(sizeof(int));
ptr = malloc(sizeof(int)); // Lỗi: mất con trỏ đến bộ nhớ được cấp phát trước đó
```
 => **Cách khắc phục: Luôn gọi free() cho bộ nhớ đã cấp phát khi không còn sử dụng.**

**Dangling pointer:**

 ◦ Xảy ra khi con trỏ vẫn trỏ đến vùng bộ nhớ đã được giải phóng, dẫn đến hành vi không xác định nếu truy cập.
```
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 10; // Lỗi: truy cập bộ nhớ đã giải phóng
```

=> **Cách khắc phục: Gán con trỏ về NULL sau khi giải phóng bộ nhớ.**

**Truy cập ngoài vùng bộ nhớ cấp phát:**

 ◦ Xảy ra khi truy cập bộ nhớ ngoài phạm vi đã cấp phát, gây lỗi nghiêm trọng như crash chương trình.
```
int *arr = malloc(sizeof(int) * 5);
arr[5] = 10; // Lỗi: truy cập ngoài giới hạn mảng
```

### **4. Nguyên tắc quản lý bộ nhớ hiệu quả**

* Luôn kiểm tra giá trị trả về của malloc, calloc, realloc để đảm bảo cấp phát thành công (trả về NULL nếu thất bại).

* Gọi free() đúng cách và chỉ gọi một lần cho mỗi khối bộ nhớ.

* Gán con trỏ về NULL sau khi giải phóng để tránh dangling pointer.

* Sử dụng các công cụ như Valgrind để phát hiện rò rỉ bộ nhớ và lỗi truy cập không hợp lệ.

* Hiểu rõ phạm vi và vòng đời của biến để chọn giữa stack và heap một cách phù hợp.
</details>

<details>
	<summary><strong>PHẦN 5: Nhập/xuất cơ bản</strong></summary>

## **PHẦN 5: Nhập/xuất cơ bản**

### **1.Nhập/xuất với printf và scanf**

  * **Thư viện:** `<stdio.h>`
  * **printf(format,args):**

    ◦ Chức năng: In dữ liệu ra màn hình theo định dạng được chỉ định.

    ◦ Các định dạng phổ biến:

    ```
    %d: Số nguyên (int).
    %f: Số thực (float).
    %lf: Số thực (double).
    %c: Ký tự (char).
    %s: Chuỗi (string).
    ``` 
    ◦ Ký tự đặc biệt: `\n`(xuống dòng) ,'\t`(tab)

    ```
    int age = 25;
    float height = 1.75;
    printf("Age: %d, Height: %.2f\n", age, height); // In: Age: 25, Height: 1.75

    ```
  
  * **scanf(format, &args):** 
    
    ◦ Chức năng: Nhập dữ liệu từ bàn phím theo định dạng được chỉ định.

    ◦ Sử dụng & trước tên biến để truyền địa chỉ (trừ chuỗi %s, không cần &).

    ◦ Kiểm tra giá trị trả về của scanf để đảm bảo dữ liệu nhập hợp lệ (trả về số lượng tham số được nhập thành công).

    ```
    int age;
    char name[50];
    printf("Enter age and name: ");
    scanf("%d %s", &age, name);
    printf("Age: %d, Name: %s\n", age, name);
    ```  

    ◦ Lưu ý khi sử dụng scanf:
    ```
    Dữ liệu nhập phải khớp với định dạng, nếu không có thể gây lỗi hoặc hành vi không xác định.

    Để nhập chuỗi chứa dấu cách, sử dụng fgets thay vì %s trong scanf.
    ```
    ```
    char buffer[100];
    printf("Enter a sentence: ");
    fgets(buffer, sizeof(buffer), stdin); // Nhập cả dòng, kể cả dấu cách
    printf("You entered: %s", buffer);
    ```
### **2.Xử lý file cơ bản**


* Thư viện: <stdio.h>

* **fopen(filename, mode):** Mở file với chế độ được chỉ định

    * **Các chế độ phổ biến:**
    ```
    ◦ "r": Đọc file (file phải tồn tại)

    ◦ "w": Ghi file (tạo mới hoặc ghi đè)

    ◦ "a": Thêm vào cuối file (tạo mới nếu file không tồn tại)

    ◦ "r+": Đọc và ghi (file phải tồn tại)

    ◦ "w+": Đọc và ghi (tạo mới hoặc ghi đè)
    ```
    * **Trả về con trỏ `FILE*` hoặc NULL nếu mở thất bại**

* **fclose(file):** Đóng file, giải phóng tài nguyên
* **fprintf(file, format, args):** Ghi dữ liệu vào file theo định dạng
* **fscanf(file, format, &args):** Đọc dữ liệu từ file vào theo định dạng
* **fgets(str, size, file):** Đọc 1 dòng từ file vào chuỗi `str` (tối đa `size-1` ký tự)
* **fputs(str, file):** Ghi chuỗi str vào file
* **feof(file):** Kiểm tra xem đã đến cuối file chưa (trả về giá trị khác 0 nếu đúng)


* **VD GHI FILE**
```    
FILE *file = fopen("data.txt", "w");
if(file == NULL){
    printf("Error opening file!\n");
    return -1;
}
fprintf(file, "Hello, File! Number: %d\n", 42);
fclose(file);

```

* **VD ĐỌC FILE**
```
FILE *file = fopen("data.txt", "r");
if(file == NULL){
    printf("Error opening file!\n");
    return -1;
}
char buffer[100];
while(fgets(buffer,sizeof(buffer),file)){
    printf("%s", buffer);
}
fclose(file);
```
### **3. Lỗi phổ biến khi xử lý nhập/xuất**

**Lỗi nhập liệu với scanf:**

 ◦ Nhập sai định dạng (ví dụ: nhập chuỗi vào %d) gây hành vi không xác định.

 ◦ Không làm sạch bộ đệm nhập (stdin) sau khi nhập, dẫn đến lỗi khi sử dụng fgets sau scanf.

 => **Cách khắc phục: Sử dụng getchar() hoặc fflush(stdin) (lưu ý: fflush(stdin) không chuẩn trên một số hệ thống).**
```
int c;
while ((c = getchar()) != '\n' && c != EOF); // Xóa bộ đệm

```

**Lỗi xử lý file:**

 ◦ Không kiểm tra `NULL` khi mở file bằng `fopen`

 ◦ Quên đóng file bằng `fclose`, dẫn đến rò rỉ tài nguyên

 ◦ Đọc/ghi ngoài phạm vi file hoặc khi file đã đóng



=> **Cách khắc phục:**

    Luôn kiểm tra giá trị trả về của fopen.

    Đảm bảo gọi fclose sau khi hoàn tất.

    Kiểm tra feof hoặc giá trị trả về của fscanf/fgets khi đọc file.

### **4. Nguyên tắc nhập/xuất hiệu quả**

* **Kiểm tra lỗi:** Luôn kiểm tra giá trị trả về của scanf, fopen, fscanf, v.v., để phát hiện lỗi sớm.

* **Quản lý bộ đệm:** Xóa bộ đệm nhập khi cần thiết, đặc biệt khi kết hợp scanf và fgets.

* **Đóng file:** Đảm bảo gọi fclose sau khi hoàn tất thao tác với file.

* **Sử dụng định dạng phù hợp:** Chọn đúng định dạng (%d, %f, %s, v.v.) để tránh lỗi nhập/xuất.

* **Xử lý chuỗi an toàn:** Sử dụng fgets thay vì gets (đã bị loại bỏ) để đọc chuỗi an toàn.

* **Kiểm tra giới hạn:** Đảm bảo không ghi/đọc ngoài kích thước bộ đệm hoặc file.
</details>


