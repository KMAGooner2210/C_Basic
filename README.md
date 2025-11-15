# C_Basic
<details>
	<summary><strong>PHẦN 1: PREPROCESSOR DIRECTIVES</strong></summary>

## **PHẦN 1: PREPROCESSOR DIRECTIVES**

### **I. Preprocessor Directives**

#### **1. Định nghĩa**

* **Preprocessor Directives (chỉ thị tiền xử lý)** là các lệnh bắt đầu bằng ký tự `#` trong mã nguồn C/C++.

* Chúng được xử lý bởi **preprocessor (bộ tiền xử lý)** trước khi mã nguồn được biên dịch thành mã máy

* Preprocessor không phải là một phần của trình biên dịch mà là một công cụ riêng biệt, thực hiện các tác vụ như thay thế văn bản, nhúng tệp, hoặc kiểm tra điều kiện biên dịch.

#### **2. Vai trò**

* Thay thế các macro (thay văn bản đơn giản).

* Nhúng các tệp header hoặc mã nguồn khác.

* Kiểm tra điều kiện biên dịch (ví dụ, chỉ biên dịch một đoạn mã nếu điều kiện đúng).

* Tùy chỉnh hành vi biên dịch dựa trên cấu hình hoặc môi trường.

#### **3. Các Preprocessor Directives phổ biến**

* **`#include`**

    ◦ **Chức năng:** Nhúng nội dung của một tệp (thường là tệp header `.h`) vào mã nguồn tại vị trí chỉ thị.

    ◦ **Cú pháp:**

        #include <tên_tệp>  // Dùng cho thư viện chuẩn (stdio.h, stdlib.h,...)
        #include "tên_tệp"  // Dùng cho tệp do người dùng định nghĩa

    ◦ **Ứng dụng:**

        Nhúng các hàm thư viện chuẩn như printf (<stdio.h>), quản lý bộ nhớ động (<stdlib.h>), toán học (<math.h>).

        Nhúng các tệp header do người dùng viết để tái sử dụng mã.


* **`#define`**

    ◦ **Chức năng:** Định nghĩa macro, có thể là hằng số hoặc hàm macro. Macro là một đoạn văn bản được thay thế trực tiếp vào mã nguồn trước khi biên dịch.

    ◦ **Cú pháp:**

        #define TÊN GIÁ_TRỊ
        #define TÊN(param) biểu_thức

    ◦ **Ứng dụng:**

        Định nghĩa hằng số (ví dụ: #define PI 3.14159).

        Tạo các hàm macro để thay thế các đoạn mã lặp lại.

    ◦ **Lưu ý:**

        Macro không kiểm tra kiểu dữ liệu, dễ gây lỗi nếu không cẩn thận.

        Nên dùng ngoặc để tránh lỗi ưu tiên toán tử.

    ◦ **VD:**

        #define PI 3.14159
        #define SQUARE(x) ((x) * (x))
        int main() {
            printf("PI: %.5f\n", PI);          // In: 3.14159
            printf("Square of 5: %d\n", SQUARE(5)); // In: 25
            return 0;
        }

* **`#ifdef, #ifndef, #else, #endif`**

    ◦ **Chức năng:** Kiểm tra điều kiện biên dịch, chỉ biên dịch một đoạn mã nếu điều kiện được thỏa mãn.

    ◦ **Cú pháp:**

        #ifdef TÊN_MACRO
            // Mã được biên dịch nếu TÊN_MACRO đã được định nghĩa
        #endif
        #ifndef TÊN_MACRO
            // Mã được biên dịch nếu TÊN_MACRO chưa được định nghĩa
        #endif

    ◦ **Ứng dụng:**

        Bật/tắt các đoạn mã trong quá trình debug.

        Hỗ trợ biên dịch có điều kiện dựa trên nền tảng hoặc cấu hình.


    ◦ **VD:**

        #define DEBUG 1
        #include <stdio.h>
        int main() {
            #if DEBUG
                printf("Debug mode is ON\n");
            #elif !DEBUG
                printf("Release mode\n");
            #else
                printf("Debug mode is OFF\n");
            #endif
            return 0;
        }

    ◦ Có thể định nghĩa macro DEBUG khi biên dịch bằng lệnh:

        gcc -DDEBUG file.c.

* **#undef**

    ◦ **Chức năng:** 
  
        Hủy định nghĩa macro để tránh xung đột.

    ◦ **Cú pháp:**

        #undef TÊN_MACRO

    ◦ **VD:**

        #define TEMP 100
        // Sử dụng TEMP...
        #undef TEMP  // Hủy để tránh dùng nhầm sau này

* **`#pragma`**

    ◦ **Chức năng:** Cung cấp các chỉ thị đặc biệt cho trình biên dịch, phụ thuộc vào trình biên dịch cụ thể.

    ◦ **Ví dụ phổ biến:**

        #pragma once: Ngăn tệp header được nhúng nhiều lần (tương tự header guards).

        #pragma pack: Điều chỉnh cách trình biên dịch căn chỉnh dữ liệu trong bộ nhớ.

        #pragma message("Note")  // Hiển thị thông báo trong quá trình biên dịch.

* **`#error`** và **`#warning`**

    ◦ **Chức năng:** 
  
        #error "Thông báo": Dừng quá trình biên dịch và hiển thị thông báo lỗi.

        #warning "Thông báo": Hiển thị cảnh báo nhưng vẫn tiếp tục biên dịch.

    ◦ **VD:**

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

    ◦ Nếu đúng, định nghĩa và nhúng nội dung.

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

### **I.Biến và kiểu dữ liệu**

#### **1.Biến**

#### **1.1. Định nghĩa**

* Biến là một tên gọi (identifier) đại diện cho một vùng nhớ trong bộ nhớ, dùng để lưu trữ giá trị thay đổi trong chương trình.

#### **1.2. Quy tắc đặt tên (Identifiers)**

* Bắt đầu bằng chữ cái (a-z, A-Z) hoặc dấu gạch dưới (_).

* Tiếp theo có thể là chữ cái, số (0-9), hoặc _.

* Không dùng keyword (như `int`, `if`), không phân biệt hoa/thường (case-sensitive).

        myVar, _count, user_age (hợp lệ)

        2var, if (lỗi).


#### **2.Kiểu dữ liệu**

##### **2.1. Phân loại kiểu dữ liệu**

* C hỗ trợ các kiểu dữ liệu:

    ◦ **Kiểu cơ bản (Primitive):** int, char, float, double, void.

    ◦ **Kiểu dẫn xuất (Derived):** Mảng, con trỏ, hàm

    ◦ **Kiểu do người dùng định nghĩa (User-defined):** struct, union, enum, typedef.

##### **2.2. Kiểu dữ liệu cơ bản (Primitive Types)**

*  **`int (Integer):`** Lưu trữ số nguyên (có dấu hoặc không dấu).

    ◦ **Kích thước:** Thường 4 byte (32-bit) trên hệ thống 32/64-bit, , kiểm tra bằng `sizeof(int)`.

    ◦ **Phạm vi:** Signed: -2^31 đến 2^31-1; Unsigned: 0 đến 2^32-1.

    ◦ **Ứng dụng:** Đếm, chỉ số mảng, vòng lặp.

*  **`char (Character):`** Lưu trữ ký tự đơn hoặc số nguyên nhỏ.

    ◦ **Kích thước:** Luôn 1 byte (8-bit).

    ◦ **Phạm vi:** -128 đến 127; Unsigned: 0 đến 255.

    ◦ **Mã hóa:** Thường dùng ASCII (ví dụ: 'A' = 65), hỗ trợ Unicode trong C11 với wchar_t.

    ◦ **Ứng dụng:** Xử lý chuỗi ký tự, dữ liệu byte.

*  **`float (Floating-point):`** Lưu trữ số thực dấu chấm động đơn chính xác

    ◦ **Kích thước:** 4 byte.

    ◦ **Phạm vi:** Khoảng 1.2E-38 đến 3.4E+38.

    ◦ **Độ chính xác:** Khoảng 6-7 chữ số thập phân (IEEE 754 single-precision).

    ◦ **Ứng dụng:** Tính toán khoa học cơ bản, đồ họa.

*  **`double (Double-precision floating-point):`** Lưu trữ số thực độ chính xác cao.

    ◦ **Kích thước:** 8 byte.

    ◦ **Phạm vi:** Khoảng 2.3E-308 đến 1.7E+308.

    ◦ **Độ chính xác:** Khoảng 15-16 chữ số thập phân (IEEE 754 double-precision).

    ◦ **Ứng dụng:** Tính toán chính xác cao, mô phỏng khoa học.

*  **`void:`** Không có giá trị (không lưu trữ dữ liệu).

    ◦ **Ứng dụng:** Hàm không trả về (void func()), con trỏ chung (void*).

##### **2.3. Bộ sửa đổi kiểu dữ liệu (Type Modifiers)**

*  **`short`** và **`long`**: Điều chỉnh kích thước của `int`.

    ◦ `short int:` Thường 2 byte (-32768 đến 32767).

    ◦ `long int:` 4 byte (trên 32-bit) hoặc 8 byte (trên 64-bit).

    ◦ `long long int:` 8 byte (-2^63 đến 2^63-1).

*  **`unsigned`**: Chỉ lưu giá trị không âm, tăng gấp đôi phạm vi dương.

    ◦  **Ví dụ:** unsigned int: 0 đến 4,294,967,295.

    ◦  **Lưu ý:** Tránh sử dụng với số âm để tránh lỗi undefined behavior.

*  **`signed`**: Mặc định cho hầu hết kiểu, cho phép giá trị âm.

##### **2.4. Constants và Qualifiers**

*  **`const (Constant)`**: Biến không thể thay đổi giá trị sau khi khởi tạo.

    ◦ **Ứng dụng:** Định nghĩa hằng số (constants) để tăng tính an toàn và đọc mã.

    ◦ **Ví dụ:** `const int MAX_USERS = 100`;.

    ◦ **Lưu ý:** Có thể dùng với con trỏ (ví dụ: const int* ptr - con trỏ trỏ đến dữ liệu không thay đổi).

*  **`volatile (Volatile)`**: Chỉ thị rằng giá trị biến có thể thay đổi bất ngờ (ngoài luồng chương trình, như từ phần cứng hoặc đa luồng).

    ◦  **Ứng dụng:** Lập trình nhúng, giao tiếp phần cứng (ví dụ: thanh ghi CPU).

    ◦  **Ví dụ:** volatile int sensor_value; - Trình biên dịch không tối ưu hóa đọc/ghi biến này.

    ◦  **Lưu ý:** Ngăn trình biên dịch cache giá trị trong thanh ghi.

*  **`restrict (C99 trở lên)`**: Gợi ý rằng con trỏ là cách duy nhất truy cập dữ liệu, giúp trình biên dịch tối ưu hóa mã tốt hơn (giảm aliasing).

    ◦  **Ứng dụng:** Trong hàm với nhiều con trỏ, tăng hiệu suất.

    ◦  **Ví dụ:** void copy(int *restrict dest, const int *restrict src);.

    ◦  **Lưu ý:** Chỉ là gợi ý, không thay đổi hành vi chương trình nếu sai.

##### **2.5. Lưu ý**

*  Kích thước và phạm vi phụ thuộc vào trình biên dịch và kiến trúc (sử dụng sizeof() để kiểm tra).

*  Tràn số (overflow): Ví dụ, int vượt quá phạm vi dẫn đến undefined behavior.

*  Thư viện `<limits.h>` và `<float.h>` cung cấp macro cho phạm vi tối đa/min (ví dụ: `INT_MAX`).

#### **3. Khai báo và khởi tạo**

* **Khai báo:** `kiểu tên;`

* **Khởi tạo:** `kiểu tên = giá_trị;`

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

#### **4. Hàm fgets**

*  **Định nghĩa:** Đọc dòng với kích thước cố định, an toàn hơn `%s`.

*  **Cú pháp:** 

        char *fgets(char *str, int n, FILE *stream);

    ◦ `char *str`: Địa chỉ của vùng nhớ (thường là mảng ký tự) nơi mà dữ liệu đọc được sẽ được lưu trữ.

        char buffer[100]; // Khai báo mảng để chứa dữ liệu
        fgets(buffer, 100, stdin); // 'buffer' chính là tham số str

    ◦ `int n`:  Kích thước tối đa của chuỗi ký tự sẽ được đọc, bao gồm cả ký tự kết thúc chuỗi '\0'.

        Hàm sẽ dừng đọc khi:

            Đã đọc được (n-1) ký tự.

            Gặp ký tự xuống dòng ('\n').

            Gặp end-of-file (EOF).

        Sau khi đọc, hàm sẽ tự động thêm ký tự '\0' vào cuối chuỗi.


            char buffer[5];
            fgets(buffer, 5, stdin);
            // Nếu nhập "Hello", buffer sẽ chứa "Hell" + '\0' (vì 5-1=4 ký tự được đọc).


    ◦ `FILE *stream`: Luồng (stream) đầu vào để đọc dữ liệu.

        Con trỏ đến cấu trúc FILE (FILE*)

        Đọc từ một file đã được mở bằng fopen().

            // Đọc từ bàn phím
            fgets(str, n, stdin);

            // Đọc từ file
            FILE *filePtr = fopen("data.txt", "r");
            fgets(str, n, filePtr);

    ◦ Giá trị trả về: 

        Trả về chính con trỏ str.

        Thất bại (ví dụ: gặp lỗi hoặc end-of-file ngay khi chưa đọc được ký tự nào): Trả về NULL.



#### **5. Lỗi phổ biến và cách khắc phục**

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

</details>


<details>
	<summary><strong>PHẦN 3: MẢNG VÀ CHUỖI</strong></summary>

## **PHẦN 3: MẢNG VÀ CHUỖI**

### **I.Mảng**

#### **1.1.Định nghĩa** 

*   Mảng là tập hợp các phần tử cùng kiểu dữ liệu, lưu trữ liên tiếp trong bộ nhớ để truy cập hiệu quả.

*   Mỗi phần tử trong mảng được truy cập thông qua **chỉ số(index)**, bắt đầu từ 0 (arr[0] là phần tử đầu tiên).

*   Kích thước mảng cố định tại thời điểm biên dịch

  
#### **1.2.Khai báo và khởi tạo**

*   **Cú pháp khai báo:**

        kiểu_dữ_liệu tên_mảng[kích_thước];
  
    ◦  **VD:**

        int arr[5];
  
  
*   **Khởi tạo:**

    ◦  **Khởi tạo trực tiếp:**

        int arr[5]={1, 2, 3, 4, 5};

    ◦  **Khởi tạo một phần (các phần tử còn lại mặc định là 0):**

        int arr[5]={1, 2}; // arr = {1, 2, 0, 0, 0}

    ◦  **Không chỉ định kích thước (trình biên dịch tự suy ra):**

        int arr[]={1, 2, 3, 4, 5}; //Tự động là arr[5]

    ◦  **Toàn cục/static: Mặc định tất cả 0 nếu không khởi tạo.**

*   **Truy cập phần tử:**


    ◦  **Sử dụng chỉ số truy cập**

        arr[0]; //phần tử đầu tiên
        arr[4]; //phần tử cuối cùng (kích thước = 5)

#### **1.3.Duyệt và xử lý mảng**

*   **Sử dụng vòng lặp để duyệt (for, while, do-while)**
  
    ◦  **VD(in mảng):**

        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        // Hoặc dùng sizeof: for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) { ... }

    ◦  **While:**

        int i = 0; while (i < 5) { 
            printf("%d ", arr[i++]); 
            }

*   **Truyền mảng vào hàm:**
  
    ◦  Mảng suy biến thành con trỏ (`arr → arr[]` hoặc `int *arr`)

    ◦  Không truyền kích thước (phải truyền riêng).

        void print_array(int arr[], int size) {  // Hoặc void print_array(int *arr, int size)
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
        }
        // Gọi: print_array(arr, 5);

#### **1.4.Mảng đa chiều**

* Mảng của mảng, dùng cho dữ liệu lưới (ma trận m x n).

* **Khai báo**


        kiểu_dữ_liệu tên_mảng[số_hàng][số_cột];

    ◦ VD:

        int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

* **Khởi tạo:**

    ◦ **Trực tiếp:**

        int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

    ◦ **Một phần:**

        int matrix[2][3] = {{1, 2}}; (còn lại 0).

    ◦ **Không chỉ định:**

        int matrix[][3] = {{1, 2, 3}, {4, 5, 6}}; (suy ra 2 hàng).

    ◦ **Từng hàng rõ ràng:**

        int matrix[2][3] = {
            {1, 2, 3},  // Hàng 0
            {4, 5, 6}   // Hàng 1
        };


* **Truy cập:**

    ◦ matrix[i][j] (i: hàng, j: cột, từ 0).

        matrix[0][0] = 1; matrix[1][2] = 6.

* **Duyệt ma trận:**


        for (int i = 0; i < 2; i++) {  // Hàng
            for (int j = 0; j < 3; j++) {  // Cột
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

* **Lưu trữ bộ nhớ:**

    ◦ Liên tiếp theo row-major order (ưu tiên hàng): Hàng 0 trước, rồi hàng 1 (VD: 1,2,3,4,5,6).

    ◦ Địa chỉ `matrix[i][j]` = cơ sở + (i * cột + j) * sizeof(kiểu).

#### **1.5.Mảng động (Dynamic Arrays)**

* Sử dụng `malloc/calloc` từ `<stdlib.h>` để cấp phát runtime (kích thước không cố định).

    ◦ malloc

        #include <stdlib.h>
        int *arr = malloc(5 * sizeof(int));  // Cấp phát 5 int
        if (arr == NULL) { /* Xử lý lỗi */ }
        arr[0] = 10;  // Sử dụng như mảng tĩnh
        free(arr);    // Giải phóng

    ◦ calloc

        calloc(5, sizeof(int)): Cấp phát và khởi tạo 0.


#### **1.6.Ứng dụng:**

   * Lưu trữ danh sách dữ liệu 

   * Xử lý ma trận trong đồ họa, toán học, hoặc xử lý dữ liệu

   * Tối ưu hóa bộ nhớ

#### **1.7.Lưu ý:**

   * **Kích thước mảng** phải là hằng số tại thời điểm biên dịch (trừ mảng động được cấp phát bằng `malloc`)

   * **Truyền mảng vào hàm:** Mảng được truyền dưới dạng con trỏ, hàm nhận địa chỉ của phần tử đầu tiên

   
        void print_array(int arr[], int size){
            for(int i = 0; i < size; i++){
            printf("%d", arr[i]);
            }
        }

    

### **II.Chuỗi**

#### **2.1.Định nghĩa**

* Chuỗi là mảng ký tự (char) kết thúc bằng null terminator `\0`(ASCII 0), đánh dấu kết thúc (không phải phần của nội dung).

* **Kích thước thực:** strlen(str) + 1 (bao gồm \0).

#### **2.2.Khai báo và khởi tạo**

* **Cú pháp:** `char str[kích_thước];`
   
        char str[] = "Hello"; (tự thêm \0, kích thước 6).

    ◦ Rõ ràng: `char str[10] = "Hello";` (còn lại \0).

    ◦ Thủ công: char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};


#### **2.3.Thư viện <string.h>**  

* **strlen(str)** :Trả về độ dài chuỗi (không tính `\0`)

        char str[] = "Hello";
        printf("%lu\n", strlen(str)); //In 5
   

* **strcpy(dest, src)** : Sao chép chuỗi `src` (bao gồm `\0`) vào `dest`
   

        char dest[10];
        strcpy(dest, "Hello");
        prinf("%s\n", dest);  // In Hello
   

* **strcat(dest, src)** : Nối chuỗi `src` vào cuối chuỗi `dest` (đảm bảo `dest` đủ lớn)

   
        char dest[10] = "Hello";
        strcat(dest, "!");
        printf("%s\n", dest); //In Hello!
   

* **strcmp(str1, str2)** : So sánh 2 Chuỗi

    ◦  Trả về `0` nếu bằng nhau

    ◦  Trả về `<0` nếu `str1 < str2` (theo thứ tự từ điển)

    ◦  Trả về `>0` nếu `str1 > str2`

        char str1[] = "apple";
        char str2[] = "banana";
        printf("%d\n", strcmp(str1, str2)); // In <0 (apple < banana)


* **strncmp(str1, str2, n):** So sánh n ký tự đầu

* **strchr(str, c):** Tìm ký tự c đầu tiên trong Chuỗi

* **strstr(str, substr):** Tìm chuỗi con `substr` trong `str`


#### **2.4.Nhập/xuất chuỗi**  

* **Nhập chuỗi:**

   ◦ Sử dụng `scanf`

        char str[100];
        scanf("%s", str);  //Không cần &str, chỉ đọc đến dấu cách 
   
   ◦ Sử dụng `fgets`(tốt hơn)

   
        char str[100];
        fgets(str, 100, stdin); //Đọc cả dòng, bao gồm dấu cách


  **Xuất chuỗi:**

   ◦ Sử dụng `printf` với `%s`

        printf("%s", str); (không tự thêm \n).

   ◦ Sử dụng `puts`

        puts(str); //tự động thêm \n


#### **2.5.Thao tác thủ công trên chuỗi**

* Vì chuỗi là mảng ký tự, có thể thao tác từng ký Tự
   

        char str[] = "Hello";
        str[0] = 'h';
        printf("%s", str); // In hello


* Tính độ dài chuỗi thủ công


        int len = 0;
        while (str[len] != '\0') len++;
        printf("Do dai: %d\n", len);


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

#### **2.8.VD**

* **Mảng**
   
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


            //Output

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
    
        // Output
        Chuoi: Hello
        Do dai: 5
        Sau khi noi: Hi, Hello
        Hai chuoi bang nhau
   
### **III.Ma trận**

#### **3.1.Định nghĩa**

* Ma trận là một mảng 2 chiều được sử dụng để lưu trữ dữ liệu dạng lưới thường biểu diên dưới dạng các hàng và cột

* Mỗi phần tử trong ma trận được truy cập thông qua 2 chỉ số: chỉ số hàng(`i`) và chỉ số cột(`j`),bắt đầu từ 0 

#### **3.2.Khai báo và khởi tạo**

* **Cú pháp khai báo:**
    
        kiểu_dữ_liệu  tên_ma_trận[số_hàng][số_cột];
    
    ◦ VD:

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

#### **3.3.Truy cập và duyệt**

* **matrix[i][j] (i: 0 đến số_hàng-1; j: 0 đến số_cột-1).**


        matrix[0][0]; //Phần tử hàng 0, cột 0
        matrix[1][2]; //Phần tử hàng 1, cột 2

* **Duyệt (In/ Xử lý):** Sử dụng vòng lặp lồng nhau (nested loops).


        int rows = 2, cols = 3;
        for (int i = 0; i < rows; i++) {  // Duyệt hàng
            for (int j = 0; j < cols; j++) {  // Duyệt cột
                printf("%d ", matrix[i][j]);
            }
            printf("\n");  // Xuống hàng mới
        }
        // Kết quả:
        // 1 2 3 
        // 4 5 6 

#### **3.4.Lưu trữ trong bộ nhớ**

* Ma trận trong C được lưu trữ liên tiếp trong bộ nhớ theo `row-major-order` (ưu tiên hàng):

    ◦ Các phần tử của hàng 0 được lưu trước, tiếp theo là hàng 1, 2,...

    ◦ VD: với ma trận int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}, thứ tự lưu trong bộ nhớ là: 1, 2, 3, 4, 5, 6

* Điều này giúp truy cập phần tử nhanh qua chỉ số, vì địa chỉ bộ nhớ của matrix[i][j] có thể được tính bằng công thức

    ◦ Địa chỉ matrix[i][j] = địa chỉ cơ sở + (i * số_cột + j) * kích_thước_kiểu_dữ_liệu

        VD: Giả sử cơ sở = 1000, sizeof(int)=4: &matrix[1][2] = 1000 + (1*3 + 2)*4 = 1020.

#### **3.5.Truyền ma trận vào hàm**

* Ma trận suy biến thành con trỏ 2D::

    ◦ `int (*matrix)[số_cột] hoặc int **matrix (cho động).`

    ◦ VD (truyền mảng tĩnh): 

        void print_matrix(int matrix[][3], int rows) {  // Số cột cố định
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
        }
        // Gọi: print_matrix(matrix, 2);

* Lưu ý: Phải truyền số hàng/cột riêng (không dùng sizeof trong hàm).

#### **3.6.Dynamic Matrix**

* Sử dụng malloc cho kích thước runtime (hữu ích cho dữ liệu lớn).

    ◦ VD (ma trận 2D với con trỏ mảng con trỏ):

        #include <stdlib.h>
        int rows = 2, cols = 3;
        int **matrix = malloc(rows * sizeof(int*));  // Mảng con trỏ
        for (int i = 0; i < rows; i++) {
            matrix[i] = malloc(cols * sizeof(int));  // Mỗi hàng
        }
        matrix[0][0] = 1;  // Sử dụng
        // Giải phóng:
        for (int i = 0; i < rows; i++) free(matrix[i]);
        free(matrix);


</details> 

<details>
	<summary><strong>PHẦN 4: CON TRỎ</strong></summary>

## **PHẦN 4: CON TRỎ**

### **I.Định nghĩa**

* Con trỏ là một biến đặc biệt **lưu trữ địa chỉ bộ nhớ** của một biến hoặc đối tượng khác trong bộ nhớ

* Mỗi con trỏ được liên kết với một **kiểu dữ liệu** cụ thể( vd: `int *`, `char *`), xác định kiểu của dữ liệu mà con trỏ trỏ tới

* Vai trò: Thao tác trực tiếp với bộ nhớ (cấp thấp), quản lý tài nguyên động, truyền tham chiếu (pass-by-reference), tối ưu hiệu suất (mảng, chuỗi).
  

### **II.Khai báo và khởi tạo**

#### **2.1.Cú pháp khai báo**


        kiểu_dữ_liệu  *tên_con_trỏ;


* **VD:**

        int *ptr; //Con trỏ trỏ tới dữ liệu kiểu int
        char *ptr; //Con trỏ trỏ tới dư liệu kiểu char
        float *ptr; //Con trỏ trỏ tới dữ liệu kiểu float


#### **2.2.Toán tử con trỏ**

* **&(Toán tử lấy địa chỉ):** Trả về địa chỉ bộ nhớ của 1 biến
    
        int x = 10;
        int *ptr = &x; //ptr lưu địa chỉ của 
    
* **`*`(Toán tử giải tham chiếu):** Truy cập hoặc sủa đổi giá trị tại địa chỉ mà con trỏ trỏ tới 
   
        *ptr = 20; //Thay đổi giá trị của x thành 20
   

#### **2.3.Khởi tạo**  

* **Khởi tạo với địa chỉ của biến:**
   
        int x = 10;
        int *ptr = &x;  //ptr trỏ tới địa chỉ của x

* **Khởi tạo với NULL (tránh lỗi truy cập bộ nhớ không hợp lệ:**
   
        int *ptr = NULL;
        if (ptr != NULL) *ptr = 5;.
   

* **Khởi tạo với chuỗi ký tự hằng:**
   
        char *str = "Hello"; (str trỏ đến vùng bộ nhớ chỉ đọc).
   
   
#### **2.4.Con trỏ void**

* Con trỏ kiểu `void*` là con trỏ có thể trỏ tới bất kỳ kiểu dữ liệu nào

* Cần ép kiểu trước khi giải tham chiếu
   

        void *ptr;
        int x = 10;
        ptr = &x;
        printf("%d\n", *(int*)ptr); // Ép kiểu void* thành int* để truy cập giá trị


### **III.Lưu trữ và cách hoạt động trong bộ nhớ**

* Con trỏ lưu trữ **địa chỉ bộ nhớ**: (số nguyên unsigned, dạng hex như 0x7fff...).

* Kích thước con trỏ phụ thuộc vào kiến trúc hệ thống

        32-bit: Con trỏ thường chiếm 4 byte
        64-bit: Con trỏ thường chiếm 8 byte

* Khi giải tham chiếu (`*ptr`), chương trình truy cập giá trị tại địa chỉ mà con trỏ lưu trữ 

        int x = 10;
        int *ptr = &x;
        printf("Địa chỉ x: %p\n", (void*)&x);   // VD: 0x7ffd1234
        printf("Giá trị ptr: %p\n", (void*)ptr); // Giống địa chỉ x
        printf("Giá trị *ptr: %d\n", *ptr);     // 10

### **IV.Thao tác với con trỏ**

#### **4.1. Truy cập và sửa đổi giá trị**

* **Truy cập giá trị:**

    ◦ Truy cập: printf("%d\n", *ptr); (in giá trị tại ptr).

    ◦ Sửa đổi: *ptr = 20; (thay đổi giá trị gốc).

        int x = 10;
        int *ptr = &x;
        printf("Giá trị tại ptr: %d\n", *ptr);  // 10
        *ptr = 20;
        printf("Giá trị của x: %d\n", x);       // 20
    

#### **4.2. Con trỏ và mảng**

* Tên mảng là con trỏ trỏ tới **phần tử đầu tiên** của mảng: `arr` tương đương `&arr[0]`

* **Truy cập phần tử mảng:**

        arr[i] ` tương đương `*(arr + i)`


        int arr[5] = {1, 2, 3, 4, 5};
        int *ptr = arr;
        printf("%d\n", *(ptr + 2)); // In 3 (phần tử arr[2])


* **Duyệt mảng bằng con trỏ:**


        int arr[5] = {1, 2, 3, 4, 5};
        int *ptr = arr;  // ptr = &arr[0]
        printf("%d\n", *(ptr + 2));  // 3
        for (int i = 0; i < 5; i++) {
            printf("%d ", *(ptr + i));  // 1 2 3 4 5
        }


#### **4.3. Con trỏ và chuỗi**

* Chuỗi là `char*` trỏ đến mảng char kết thúc \0.

* **Khởi tạo chuỗi:**

        char *str = "Hello"; // str trỏ tới chuỗi hằng

* **Truy cập ký tự:**

        printf("%c\n", *(str + 1)); // In 'e'

* **Lưu ý: Không thể sửa đổi chuỗi hằng**

        str[0] = 'h'; // LỖI: Chuỗi hằng không thể sửa đổi

* **Để sửa đổi chuỗi, cần khai báo mảng ký tự:**

        char str[] = "Hello"; // Mảng ký tự, có thể sửa đổi
        str[0] = 'h';
        printf("%s\n", str); // In "hello"

#### **4.4. Con trỏ và hàm**

* Con trỏ có thể được truyền vào hàm để sửa đổi giá trị của biến bên ngoài (pass-by-reference).


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

#### **4.5. Con trỏ và bộ nhớ động**

* Con trỏ thường được dùng để cấp phát bộ nhớ động bằng malloc và giải phóng bằng free

        #include<stdio.h>
        int *ptr = malloc(sizeof(int)); // Cấp phát bộ nhớ cho 1 số nguyên
        if(ptr == NULL){
            printf("Cap phat that bai!\n");
            return 1;
        }
        *ptr = 42;
        printf("Gia tri: %d\n", *ptr); //In: 42
        free(ptr);

#### **4.6. Lỗi phổ biến khi dùng con trỏ**

* **Truy cập con trỏ NULL**

        int *ptr = NULL;
        printf("%d\n", *ptr);  // LỖI: Truy cập con trỏ NULL

* **Con trỏ không khởi tạo**

        int *ptr; // Không khởi tạo
        *ptr = 10; // LỖI: Truy cập địa chỉ ngẫu nhiên


* **Con trỏ lơ lửng (dangling pointer)**

        int *ptr = malloc(sizeof(int));
        free(ptr);
        *ptr = 10; // LỖI: Truy cập bộ nhớ đã giải phóng

</details>

<details>
	<summary><strong>PHẦN 5: QUẢN LÝ BỘ NHỚ</strong></summary>

## **PHẦN 5: QUẢN LÝ BỘ NHỚ**

### **I.Stack (Bộ Nhớ Tự Động)**

#### **1.1. Định nghĩa**

* Vùng bộ nhớ dùng cho biến cục bộ (local variables), tham số hàm, và thông tin gọi hàm (return address, frame pointer).

* Hoạt động theo cơ chế LIFO (Last In, First Out).

#### **1.2. Cấp phát/Giải phóng**

* Tự động bởi compiler/runtime khi vào/ra phạm vi (scope) hoặc hàm kết thúc. 

* Không cần thủ công.

* Nhược điểm: Kích thước cố định (thường 1-8 MB, tùy hệ thống/OS), dễ gây stack overflow nếu đệ quy sâu hoặc mảng lớn.
    
        void recursive(int n) {
            if (n <= 0) return;
            int arr[1000000];  // Mảng lớn trên stack → dễ overflow
            recursive(n - 1);
        }
        // Gọi recursive(1000) có thể crash (stack overflow).

### **II.Heap (Bộ Nhớ Động)**

#### **2.1. Định nghĩa**

* Vùng bộ nhớ lớn, linh hoạt cho dữ liệu tồn tại qua nhiều hàm/scope, kích thước runtime.

#### **2.2. Cấp phát/Giải phóng**

* Thủ công qua hàm như `malloc/free`.

* Sử dụng con trỏ để truy cập (liên kết với phần con trỏ).

### **2.3. Data Segment**

* Lưu biến global/static đã khởi tạo (VD: int global = 10;). 

* Tồn tại suốt chương trình, cấp phát tĩnh.

### **2.4. BSS Segment**

* Lưu biến global/static chưa khởi tạo (mặc định 0). 

* Tương tự Data nhưng tiết kiệm không gian.


    
### **III. Cấp phát và giải phóng bộ nhớ**

* **Thư viện <stdlib.h> cung cấp các hàm quản lý heap (trả về void* – dùng con trỏ void).**

    ◦ 1. malloc(size): Cấp phát size byte, không khởi tạo (giá trị rác). Trả về NULL nếu thất bại.

        int *ptr = malloc(sizeof(int));

    ◦ 2. calloc(n, size): Cấp phát cho n phần tử kích thước size byte, khởi tạo tất cả = 0.

        int *arr = calloc(5, sizeof(int)); // arr = {0,0,0,0,0}.

    ◦ 3. realloc(ptr, new_size): Thay đổi kích thước khối tại ptr thành new_size.Bảo toàn dữ liệu cũ; trả về con trỏ mới (có thể khác ptr cũ). Nếu thất bại, giữ nguyên ptr cũ và trả về NULL.

        int *new_arr = realloc(arr, sizeof(int) * 10);
        if (new_arr == NULL) {
            // Thất bại: Giữ arr cũ, copy nếu cần
            printf("Realloc thất bại!\n");
        } else {
            arr = new_arr;  // Cập nhật con trỏ
        }

    ◦ 4. free(ptr): Giải phóng khối tại ptr. Chỉ gọi một lần; không free NULL.

        #include <stdlib.h>
        int main() {
            // malloc + gán
            int *ptr = malloc(sizeof(int));
            if (ptr == NULL) return -1;
            *ptr = 10;

            // calloc cho mảng
            int *arr = calloc(5, sizeof(int));  // {0,0,0,0,0}
            if (arr == NULL) return -1;
            for (int i = 0; i < 5; i++) arr[i] = i + 1;  // {1,2,3,4,5}

            // realloc
            int *new_arr = realloc(arr, sizeof(int) * 10);
            if (new_arr == NULL) {
                free(arr);  // Giải phóng cũ
                return -1;
            }
            arr = new_arr;
            arr[5] = 6;  // Thêm phần tử mới

            free(arr);  // Giải phóng cuối
            arr = NULL;
            return 0;
        }


### **IV. Lỗi phổ biến**

* **Memory Leak:** Cấp phát nhưng không free, lãng phí RAM (tích tụ qua nhiều lần chạy).

        ptr = malloc(...); ptr = malloc(...);

    ◦ VD: ptr = malloc(...); ptr = malloc(...); // Mất con trỏ đến khối đầu.

    ◦ Khắc phục: Free trước khi gán con trỏ mới; dùng công cụ theo dõi (RAII ở C++ nhưng thủ công ở C).

* **Dangling Pointer:** Con trỏ trỏ đến bộ nhớ đã free.

        free(ptr); *ptr = 10; // Undefined behavior (có thể crash hoặc sai dữ liệu).

    ◦ Khắc phục: free(ptr); ptr = NULL; (tránh dereference)

* **Truy cập ngoài vùng:** Đọc/ghi ngoài khối cấp phát.

        int *arr = malloc(5 * sizeof(int)); arr[5] = 10; // Viết ngoài mảng.

    ◦ Khắc phục: Kiểm tra index; dùng bounds checking (ít tự động ở C).

### **V. Nguyên tắc quản lý bộ nhớ hiệu quả**

* Luôn kiểm tra NULL sau malloc/calloc/realloc (xử lý lỗi: return/exit).

* Free đúng: Một lần/khối, theo thứ tự LIFO (giải phóng con trước mẹ trong struct).

* Set con trỏ = NULL sau free để tránh dangling.

* Ưu tiên stack cho dữ liệu nhỏ/tạm thời; heap cho lớn/động.

</details>

<details>
	<summary><strong>PHẦN 6: XỬ LÝ FILE</strong></summary>

## **PHẦN 6: XỬ LÝ FILE**

### **I. Mở và đóng file**

#### **1.1.fopen(filename, mode)**

* Mở file với chế độ chỉ định, trả về con trỏ `FILE*` (hoặc NULL nếu thất bại).

* Chế độ phổ biến:

        "r": Đọc text (file phải tồn tại).
        "w": Ghi text (tạo mới hoặc ghi đè).
        "a": Thêm vào cuối text (tạo mới nếu không tồn tại).
        "r+": Đọc/ghi text (file phải tồn tại).
        "w+": Đọc/ghi text (tạo mới hoặc ghi đè).

* Thêm "t" cho text (mặc định trên Windows), "b" cho binary (không chuyển \n thành \r\n).

* VD:

        fopen("data.bin", "wb") – ghi binary.

#### **1.2.fclose(file):**

* Đóng file, giải phóng tài nguyên.

* Luôn gọi sau khi dùng để tránh leak.

* **Kiểm tra lỗi:** 
    
        if (file == NULL) { 
            perror("Lỗi fopen"); 
            return -1; 
            } (perror in thông báo lỗi hệ thống).


### **II. Đọc và ghi FILE**

#### **2.1. Ghi File**

* `fprintf(file, format, args)`: Ghi định dạng vào file (tương tự printf).

* `fputs(str, file):` Ghi chuỗi (không tự thêm \n).

* **VD ghi text:**

        FILE *file = fopen("data.txt", "w");
        if (file == NULL) return -1;
        fprintf(file, "Hello, File! Number: %d\n", 42);
        fputs("Dòng thêm.\n", file);
        fclose(file);


#### **2.2. Đọc File**

* `fscanf(file, format, &args)`: Đọc định dạng từ file (tương tự scanf, trả về số item đọc).

* `fgets(str, size, file):` Đọc một dòng (tối đa size-1 ký tự, bao gồm \n)

* **VD đọc text:**

        FILE *file = fopen("data.txt", "r");
        if (file == NULL) return -1;
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {  // Kiểm tra != NULL thay feof
            printf("%s", buffer);
        }
        fclose(file);

#### **2.3. Xử lý binary**

* `fwrite(ptr, size, count, file)`: Ghi count phần tử kích thước size từ ptr.

* `fread(ptr, size, count, file):` Đọc tương tự, trả về số item đọc thành công.

* **VD ghi/đọc struct binary:**

        typedef struct { int id; char name[20]; } Person;
        Person p = {1, "Alice"};
        FILE *file = fopen("data.bin", "wb");
        if (file) {
            fwrite(&p, sizeof(Person), 1, file);  // Ghi 1 struct
            fclose(file);
        }
        // Đọc:
        FILE *file2 = fopen("data.bin", "rb");
        Person p2;
        if (file2 && fread(&p2, sizeof(Person), 1, file2) == 1) {
            printf("ID: %d, Name: %s\n", p2.id, p2.name);  // 1 Alice
        }
        fclose(file2);

* **Kiểm tra cuối file:** Dùng return của fgets/fscanf/fread (0 hoặc NULL khi hết). Tránh feof() vì nó kiểm tra sau khi đọc thất bại.

### **III. Điều hướng File**

#### **3.1. seek(file, offset, whence)**

* Di chuyển vị trí đọc/ghi.
    
*  whence: SEEK_SET (từ đầu), SEEK_CUR (từ hiện tại), SEEK_END (từ cuối).

*  fseek(file, -10, SEEK_END); – lùi 10 byte từ cuối

#### **3.2. ftell(file):**

* Trả về vị trí hiện tại (long type).

        FILE *file = fopen("data.txt", "r+");
        if (file) {
            fseek(file, 0, SEEK_END);  // Đến cuối
            long pos = ftell(file);    // Vị trí cuối
            printf("File size: %ld\n", pos);
            fclose(file);
        }

### **IV. Lỗi xử lý file**

* Không kiểm tra NULL từ fopen: Gây crash khi dùng file NULL.

    ◦ Khắc phục: 

        if (file == NULL) { 
            perror("fopen"); 
            return -1; 
        }.

* Quên fclose: Dẫn đến resource leak (file không đóng, handle hết giới hạn).

    ◦ Khắc phục: Gọi fclose luôn; dùng cleanup block hoặc atexit.


* Đọc/ghi ngoài phạm vi: fgets/fread vượt size → buffer overflow; fseek sai offset → đọc sai.

    ◦ Khắc phục: Kiểm tra return của fread/fgets; dùng ftell kiểm tra vị trí.

* feof sai: feof() chỉ true sau đọc thất bại, không dùng làm điều kiện while.

    ◦ Khắc phục: while (fgets(...) != NULL).

### **V. Nguyên tắc nhập/xuất hiệu quả**

* **Kiểm tra lỗi:** Luôn kiểm tra giá trị trả về của scanf, fopen, fscanf, v.v., để phát hiện lỗi sớm.

* **Quản lý bộ đệm:** Xóa bộ đệm nhập khi cần thiết, đặc biệt khi kết hợp scanf và fgets.

* **Đóng file:** Đảm bảo gọi fclose sau khi hoàn tất thao tác với file.

* **Sử dụng định dạng phù hợp:** Chọn đúng định dạng (%d, %f, %s, v.v.) để tránh lỗi nhập/xuất.

* **Xử lý chuỗi an toàn:** Sử dụng fgets thay vì gets (đã bị loại bỏ) để đọc chuỗi an toàn.

* **Kiểm tra giới hạn:** Đảm bảo không ghi/đọc ngoài kích thước bộ đệm hoặc file.
</details>
