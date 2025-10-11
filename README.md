# C_Basic

<details>
	<summary><strong>CHƯƠNG 1: GIỚI THIỆU PREPROCESSOR DIRECTIVES</strong></summary>

## **CHƯƠNG 1: GIỚI THIỆU PREPROCESSOR DIRECTIVES**

### **I. Preprocessor Directives**

#### **1.1. Định nghĩa**

* **Preprocessor Directives (chỉ thị tiền xử lý)** là các lệnh bắt đầu bằng ký tự `#` trong mã nguồn C/C++.

* Chúng được xử lý bởi preprocessor (trình tiền xử lý) trước khi mã nguồn được biên dịch thành mã máy

* **Preprocessor** không phải là một phần của trình biên dịch mà hoạt động như một bước riêng biệt, thực hiện các thao tác như thay thế văn bản, nhúng tệp, hoặc kiểm tra điều kiện trước khi mã được biên dịch.

#### **1.2. Vai trò**

* **Tái sử dụng code:** Cho phép nhúng các tệp mã nguồn hoặc định nghĩa hằng số/macro.

* **Tối ưu hóa:** Hỗ trợ điều kiện biên dịch để tạo các phiên bản mã khác nhau (ví dụ: debug hoặc release).

* **Tăng tính portable:** Cho phép điều chỉnh mã theo các nền tảng hoặc trình biên dịch khác nhau.

* **Quản lý mã nguồn:** Ngăn lỗi trùng lặp định nghĩa thông qua các kỹ thuật như header guards.

#### **1.3. Các Preprocessor Directives phổ biến**

* **`#include`**

  ◦ **Chức năng:** Nhúng nội dung của một tệp (thường là tệp header `.h`) vào mã nguồn tại vị trí chỉ thị.

  ◦ **Cú pháp:**

        #include <tên_tệp>  // Dùng cho thư viện chuẩn (stdio.h, stdlib.h,...)
        #include "tên_tệp"  // Dùng cho tệp do người dùng định nghĩa

  ◦ **Ứng dụng:**

        Nhúng các hàm thư viện chuẩn như printf (<stdio.h>), quản lý bộ nhớ động (<stdlib.h>), toán học (<math.h>).

        Nhúng các tệp header do người dùng viết để tái sử dụng mã.

  ◦ **VD:**

        #include <stdio.h>   // Nhúng hàm nhập/xuất chuẩn như printf, scanf
        #include <stdlib.h>  // Nhúng hàm quản lý bộ nhớ động như malloc, free
        #include "myheader.h" // Nhúng tệp header do người dùng tạo    


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

        #ifdef MACRO_NAME
        // Mã được biên dịch nếu MACRO_NAME đã được định nghĩa
        #else
        // Mã được biên dịch nếu MACRO_NAME không được định nghĩa
        #endif

        #ifndef MACRO_NAME
        // Mã được biên dịch nếu MACRO_NAME chưa được định nghĩa
        #endif

  ◦ **Ứng dụng:**

        Bật/tắt các đoạn mã trong quá trình debug.

        Hỗ trợ biên dịch có điều kiện dựa trên nền tảng hoặc cấu hình.


  ◦ **VD:**

        #define DEBUG 1
        int main() {
            #ifdef DEBUG
                printf("Debug mode is ON\n");
            #else
                printf("Debug mode is OFF\n");
            #endif
            return 0;
        }

  ◦ **Có thể định nghĩa macro DEBUG khi biên dịch bằng lệnh:**

        gcc -DDEBUG file.c.

* **`#undef`**

  ◦ **Chức năng:** Hủy định nghĩa của một macro đã được định nghĩa trước đó bằng `#define`. Điều này cho phép định nghĩa lại macro với giá trị mới hoặc đảm bảo macro không ảnh hưởng đến mã nguồn.

  ◦ **Cú pháp:**

        #undef TÊN_MACRO

  ◦ **Ứng dụng:**

        Định nghĩa lại macro cho các mục đích khác nhau trong cùng một chương trình.

        Tránh xung đột với các macro từ thư viện bên ngoài.

  ◦ **VD:**

        #define DEBUG_LEVEL 2
        printf("Debug level: %d\n", DEBUG_LEVEL); // In ra: Debug level: 2
        #undef DEBUG_LEVEL
        #define DEBUG_LEVEL 0
        printf("New debug level: %d\n", DEBUG_LEVEL); // In ra: New debug level: 0

* **`#if, #elif, #else, #endif`**

  ◦ **Chức năng:** Cung cấp cơ chế điều kiện biên dịch mạnh mẽ hơn so với #ifdef và #ifndef. Các chỉ thị này cho phép kiểm tra giá trị của biểu thức hằng số, không chỉ sự tồn tại của macro.

  ◦ **Cú pháp:**

        #if biểu_thức_hằng
        // Mã được biên dịch nếu biểu_thức_hằng là true
        #elif biểu_thức_hằng_khác
        // Mã được biên dịch nếu biểu_thức_hằng_khác là true
        #else
        // Mã được biên dịch nếu không điều kiện nào thỏa mãn
        #endif

  ◦ **Ứng dụng:**

        Quản lý các phiên bản build khác nhau (ví dụ: build cho Windows, Linux, hoặc các cấu hình tối ưu hóa).

        Tùy chỉnh mã dựa trên giá trị của macro (ví dụ: phiên bản phần mềm).


  ◦ **VD:**

        #define VERSION 3
        #if VERSION > 2
        #define FEATURE "Advanced Feature Enabled"
        #elif VERSION == 2
        #define FEATURE "Basic Feature Enabled"
        #else
        #define FEATURE "No Feature Available"
        #endif
        printf("Feature: %s\n", FEATURE);

* **`Toán tử defined()`**

  ◦ **Chức năng:** Kiểm tra xem một macro đã được định nghĩa hay chưa, thường được sử dụng trong `#if` hoặc `#elif` để kết hợp với các toán tử logic (`&&, ||, !`).

  ◦ **Cú pháp:**

        #if defined(MACRO_NAME)
        // Mã được biên dịch nếu MACRO_NAME đã được định nghĩa
        #endif

  ◦ **VD:**

        #define WINDOWS 1
        #define X64_ARCHITECTURE 1
        #if defined(WINDOWS) && defined(X64_ARCHITECTURE)
        printf("Running on Windows 64-bit\n");
        #elif defined(WINDOWS)
        printf("Running on Windows 32-bit\n");
        #else
        printf("Running on non-Windows platform\n");
        #endif

* **`#pragma`**

  ◦ **Chức năng:** Cung cấp các chỉ thị đặc biệt cho trình biên dịch, phụ thuộc vào trình biên dịch cụ thể.

  ◦ **Ví dụ phổ biến:**

        #pragma once: Ngăn tệp header được nhúng nhiều lần (tương tự header guards).

        #pragma pack: Điều chỉnh cách trình biên dịch căn chỉnh dữ liệu trong bộ nhớ.



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

### **II. Kỹ thuật với Macro**

#### **2.1. Stringizing Operator (#)**

* **Mục đích:**

  ◦ Chuyển đổi một đối số của macro thành chuỗi ký tự (string literal). 

* **Cú pháp:**

        #define TO_STRING(x) #x

* **Cách hoạt động:**

  ◦ Toán tử `#` đặt trước một đối số macro sẽ chuyển đối số đó thành chuỗi ký tự được bao quanh bởi dấu ngoặc kép.


* **Ứng dụng:**

  ◦ In tên biến, biểu thức hoặc thông báo debug.

  ◦ Tạo chuỗi động trong mã nguồn.

        #define TO_STRING(x) #x
        int main() {
            printf("%s\n", TO_STRING(Hello World)); // In ra: Hello World
            printf("%s\n", TO_STRING(123));         // In ra: 123
            return 0;
        }

#### **2.2. Token Pasting Operator (##)**

* **Mục đích:**

  ◦ Nối hai token (mã thông báo) lại với nhau để tạo thành một token mới.

* **Cú pháp:**

        #define CONCAT(a, b) a##b

* **Cách hoạt động:**

  ◦ Toán tử `##` nối hai đối số macro thành một token hợp lệ (ví dụ: tên biến, tên hàm).


* **Ứng dụng:**

  ◦ Tạo tên biến hoặc hàm tự động.

  ◦ Hỗ trợ viết mã tổng quát (generic code) hoặc tạo các định danh động.

        #define CONCAT(a, b) a##b
        int main() {
            int CONCAT(var, 1) = 10; // Trở thành: int var1 = 10;
            int CONCAT(var, 2) = 20; // Trở thành: int var2 = 20;
            printf("var1 = %d, var2 = %d\n", var1, var2); // In ra: var1 = 10, var2 = 20
            return 0;
        }

#### **2.3. Kết hợp Stringizing và Token Pasting (##)**

* **Mục đích:**

  ◦ Có thể kết hợp cả hai toán tử trong một macro để tạo ra mã nguồn phức tạp hơn.


        #define LOG_VAR(x) printf("Variable " #x " = %d\n", x)
        #define CREATE_VAR(n) int CONCAT(var, n) = n * 10
        int main() {
            CREATE_VAR(1); // Trở thành: int var1 = 1 * 10;
            CREATE_VAR(2); // Trở thành: int var2 = 2 * 10;
            LOG_VAR(var1); // In ra: Variable var1 = 10
            LOG_VAR(var2); // In ra: Variable var2 = 20
            return 0;
        }


### **III. Predefined Macros**

#### **3.1. __FILE__**

* **Mục đích:**

  ◦ Trả về tên của tệp nguồn hiện tại dưới dạng chuỗi ký tự.

* **Ứng dụng:**

  ◦ Dùng trong debug để ghi lại vị trí của mã trong tệp nguồn.

* **VD:**

        printf("This code is in file: %s\n", __FILE__); // In ra tên tệp, ví dụ: main.c

#### **3.2. __LINE__**

* **Mục đích:**

  ◦ Trả về số dòng hiện tại trong tệp nguồn dưới dạng số nguyên.

* **Ứng dụng:**

  ◦ Hữu ích khi ghi log hoặc báo lỗi để xác định vị trí chính xác trong mã.

* **VD:**

        printf("Error at line %d in file %s\n", __LINE__, __FILE__);

#### **3.3. __DATE__**

* **Mục đích:**

  ◦ Trả về ngày biên dịch mã nguồn dưới dạng chuỗi theo định dạng `"Mmm dd yyyy".`

* **Ứng dụng:**

  ◦ Dùng để ghi log thời điểm biên dịch hoặc hiển thị thông tin phiên bản.

* **VD:**

        printf("Code compiled on: %s\n", __DATE__); // Ví dụ: Oct 08 2025

#### **3.4. __TIME__**

* **Mục đích:**

  ◦ Trả về thời gian biên dịch mã nguồn dưới dạng chuỗi theo định dạng `"hh:mm:ss"`

* **Ứng dụng:**

  ◦ Kết hợp với __DATE__ để ghi log hoặc theo dõi thời gian build.

* **VD:**

        printf("Code compiled at: %s\n", __TIME__); // Ví dụ: 21:10:00

#### **3.5. __STDC_VERSION__**

* **Mục đích:**

  ◦ Trả về phiên bản của tiêu chuẩn C đang được sử dụng (dưới dạng số nguyên).

  ◦ C89/C90: Không định nghĩa hoặc giá trị không xác định.

  ◦ C99: 199901L

  ◦ C11: 201112L 

  ◦ C17: 201710L

* **Ứng dụng:**

  ◦ Kiểm tra phiên bản tiêu chuẩn C để đảm bảo tính tương thích của mã.

* **VD:**

        #if __STDC_VERSION__ >= 201112L
        printf("This code uses C11 or later\n");
        #else
        #error "This code requires C11 or later"
        #endif

#### **3.6. Ví dụ tổng hợp**

* **Mục đích:**

        #include <stdio.h>
        #define LOG_ERROR(msg) fprintf(stderr, "ERROR: %s at %s:%d\n", msg, __FILE__, __LINE__)

        int main() {
            printf("Compiled on %s at %s\n", __DATE__, __TIME__);
            LOG_ERROR("Something went wrong");
            return 0;
        }

### **IV. Header Guards & Macro Safety**

#### **4.1. Header Guards**

* **Định nghĩa**

  ◦ Header Guards là kỹ thuật sử dụng các chỉ thị `#ifndef`, `#define`, và `#endif` 

  ◦ Dùng để ngăn tệp header được nhúng nhiều lần, tránh lỗi `redefinition` (định nghĩa lại hàm, biến, hoặc kiểu dữ liệu).   

* **Cú pháp**

        /* file: myheader.h */
        #ifndef MYHEADER_H
        #define MYHEADER_H

        // Nội dung của header
        void my_function(void);

        #endif 

* **Cách hoạt động**

  ◦ `#ifndef MYHEADER_H`: Kiểm tra xem macro `MYHEADER_H` có được định nghĩa chưa.  

  ◦ Nếu chưa, định nghĩa `MYHEADER_H` và nhúng nội dung header.

  ◦ Nếu đã được định nghĩa (do tệp header đã được nhúng trước đó), bỏ qua nội dung giữa `#ifndef` và `#endif.`

* **Thay thế bằng cách khác:**

  ◦ `#pragma once:` Đơn giản hơn header guards, chỉ cần một dòng để đảm bảo tệp header chỉ được nhúng một lần.

  ◦ VD:

        #pragma once
        void my_function(void);

#### **4.2. Macro Safety**

##### **4.2.1. Sử dụng ngoặc để tránh lỗi ưu tiên toán tử**

* **Vấn đề:**

  ◦ Macro là thay thế văn bản thuần túy, không kiểm tra kiểu dữ liệu hoặc ngữ nghĩa.  

  ◦ VD không an toàn

        #define MAX(a, b) a > b ? a : b
        int result = MAX(2 + 3, 4); // Thay thế thành: 2 + 3 > 4 ? 2 + 3 : 4 → 5 > 4 ? 5 : 4 = 5 (đúng)

        int result2 = MAX(2, 3 + 4); // Thay thế thành: 2 > 3 + 4 ? 2 : 3 + 4 → 2 > 7 ? 2 : 7 = 7 (đúng)  

* **Giải pháp: Bao quanh các đối số và toàn bộ biểu thức macro bằng dấu ngoặc.**

        #define MAX(a, b) ((a) > (b) ? (a) : (b))
        int result = 10 * MAX(2, 3); // Thay thế thành: 10 * ((2) > (3) ? (2) : (3)) = 10 * 3 = 30 (đúng)

##### **4.2.2. Tránh macro phức tạp**

* **Vấn đề:**

  ◦ Macro phức tạp (nhiều dòng hoặc logic phức tạp) khó debug và dễ gây lỗi.

* **Giải pháp:**

  ◦ Sử dụng hàm inline (C99 trở lên) hoặc chia nhỏ macro thành các phần đơn giản.


        inline int max(int a, int b) {
            return a > b ? a : b;
        }

##### **4.2.3. Sử dụng #error và #warning để kiểm soát lỗi**


        #if defined(__linux__)
        #warning "Chương trình được biên dịch trên Linux"
        #else
        #error "Chương trình chỉ hỗ trợ Linux"
        #endif

##### **4.2.4. Tránh side effects trong macro**

* **Vấn đề:**

  ◦ Macro có thể được thay thế nhiều lần, gây ra side effects nếu đối số là biểu thức có tác dụng phụ (e.g., `x++`).

* **VD không an toàn:**

        #define SQUARE(x) ((x) * (x))
        int x = 5;
        int result = SQUARE(x++); // Thay thế thành: ((x++) * (x++)) → x tăng 2 lần


### **V. Ví dụ minh họa**

* **Tệp header (log_utils.h)**

        #pragma once
        // Hoặc sử dụng header guards:
        // #ifndef LOG_UTILS_H
        // #define LOG_UTILS_H

        // Macro hằng số
        #define MAX_LOG_LENGTH 256
        #define VERSION 3

        // Macro an toàn để tìm giá trị lớn nhất
        #define MAX(a, b) ((a) > (b) ? (a) : (b))

        // Stringizing operator để chuyển đối số thành chuỗi
        #define TO_STRING(x) #x

        // Token pasting operator để tạo tên biến động
        #define CREATE_LOG_VAR(n) int CONCAT(log_count_, n) = n

        // Macro để ghi log với thông tin tệp, dòng, và thời gian
        #define LOG_MESSAGE(level, msg) \
            printf("LOG [%s:%d] %s at %s %s: %s\n", __FILE__, __LINE__, TO_STRING(level), __DATE__, __TIME__, msg)

        // Macro kiểm tra cấp độ debug
        #define DEBUG_LEVEL 2
        #if DEBUG_LEVEL >= 2
            #define DEBUG_VERBOSE(msg) LOG_MESSAGE(VERBOSE, msg)
        #else
            #define DEBUG_VERBOSE(msg) // Không làm gì nếu debug level < 2
        #endif

        // Hàm được định nghĩa trong header
        void print_system_info(void);
        void log_error(const char* msg);

        // #endif // LOG_UTILS_H

* **Tệp nguồn main.c**

        #include <stdio.h>
        #include <stdlib.h>
        #include "log_utils.h"

        // Kiểm tra phiên bản tiêu chuẩn C
        #if __STDC_VERSION__ < 201112L
            #error "This program requires C11 or later"
        #else
            #warning "Using C11 or later"
        #endif

        // Kiểm tra nền tảng
        #if defined(_WIN32)
            #define PLATFORM "Windows"
        #elif defined(__linux__)
            #define PLATFORM "Linux"
        #else
            #error "Unsupported platform"
        #endif

        // Định nghĩa lại macro nếu cần
        #ifdef OLD_LOG_STYLE
            #undef LOG_MESSAGE
            #define LOG_MESSAGE(level, msg) \
                printf("OLD STYLE LOG: %s\n", msg)
        #endif

        void print_system_info(void) {
            printf("System Info:\n");
            printf("  Platform: %s\n", PLATFORM);
            printf("  Compiled: %s %s\n", __DATE__, __TIME__);
            printf("  File: %s\n", __FILE__);
            printf("  Line: %d\n", __LINE__);
            printf("  C Standard: %ld\n", __STDC_VERSION__);
        }

        void log_error(const char* msg) {
            fprintf(stderr, "ERROR: %s at %s:%d\n", msg, __FILE__, __LINE__);
        }

        int main() {
            // Sử dụng token pasting để tạo biến động
            CREATE_LOG_VAR(1); // Trở thành: int log_count_1 = 1;
            CREATE_LOG_VAR(2); // Trở thành: int log_count_2 = 2;

            // In thông tin hệ thống
            print_system_info();

            // Sử dụng macro LOG_MESSAGE
            LOG_MESSAGE(INFO, "Program started"); // In thông tin log với cấp độ INFO

            // Sử dụng macro DEBUG_VERBOSE (chỉ hoạt động nếu DEBUG_LEVEL >= 2)
            DEBUG_VERBOSE("This is a verbose debug message");

            // Kiểm tra phiên bản và kích hoạt tính năng
            #if VERSION > 2
                printf("Advanced feature enabled: Processing data...\n");
            #elif VERSION == 2
                printf("Basic feature enabled: Limited processing...\n");
            #else
                printf("No feature available.\n");
            #endif

            // Sử dụng macro MAX
            printf("Max log count: %d\n", MAX(log_count_1, log_count_2));

            // Ghi log lỗi
            log_error("Sample error occurred");

            // Kiểm tra nền tảng với toán tử defined()
            #if defined(WINDOWS) && defined(X64_ARCHITECTURE)
                printf("Running on Windows 64-bit\n");
            #elif defined(__linux__)
                printf("Running on Linux\n");
            #endif

            // Sử dụng stringizing operator
            printf("Stringified message: %s\n", TO_STRING(Program terminated));

            return 0;
        }

* **Kết quả**

        Using C11 or later
        System Info:
        Platform: Linux
        Compiled: Oct 08 2025 21:37:00
        File: main.c
        Line: 31
        C Standard: 201112
        LOG [main.c:37] INFO at Oct 08 2025 21:37:00: Program started
        LOG [main.c:40] VERBOSE at Oct 08 2025 21:37:00: This is a verbose debug message
        Advanced feature enabled: Processing data...
        Max log count: 2
        ERROR: Sample error occurred at main.c:49
        Running on Linux
        Stringified message: Program terminated

</details>

<details>
	<summary><strong>CHƯƠNG 2: CÚ PHÁP CƠ BẢN</strong></summary>

## **CHƯƠNG 2: CÚ PHÁP CƠ BẢN**

### **I. Biến và kiểu dữ liệu**

#### **1.1. Biến**

##### **1.1.1. Định nghĩa**

* **Biến** là một tên gọi (identifier) đại diện cho một vùng nhớ trong bộ nhớ máy tính, được sử dụng để lưu trữ giá trị.

* Mỗi biến có một kiểu dữ liệu cụ thể, xác định:

  ◦ **Kích thước vùng nhớ:** Số byte mà biến chiếm trong bộ nhớ (ví dụ: 4 byte cho int trên hệ thống 32/64-bit).

  ◦ **Cách lưu trữ và giải thích dữ liệu:** Quy định cách giá trị được lưu trữ và sử dụng (ví dụ: số nguyên, số thực, ký tự).

* Giá trị của biến có thể thay đổi trong quá trình thực thi chương trình, trừ khi biến được khai báo là hằng (`const`).

##### **1.1.2. Quy tắc đặt tên biến**

* **Ký tự bắt đầu:** 

  ◦ Chữ cái (a-z hoặc A-Z).

  ◦ Dấu gạch dưới (`_`).

  ◦ Không được bắt đầu bằng số hoặc ký tự đặc biệt (ngoại trừ `_`).

* **Ký tự tiếp theo:** 

  ◦ Chữ cái (a-z, A-Z).

  ◦ Số (0-9).

  ◦ Dấu gạch dưới (`_`).

* **Phân biệt hoa/thường:** 

  ◦ Ngôn ngữ C phân biệt chữ hoa và chữ thường (case-sensitive). Ví dụ: `age` và `Age` là hai biến khác nhau.

* **Không sử dụng từ khóa:** 

  ◦ Tên biến không được trùng với các từ khóa của C, ví dụ: `int`, `return`, `if`, `while`, `for`, `switch`, v.v.

* **Độ dài tên biến:** 

  ◦ C không giới hạn độ dài tên biến, nhưng chỉ các ký tự đầu tiên (thường là 31 hoặc 63, tùy trình biên dịch) được sử dụng để phân biệt.


##### **1.1.3. VD**

* **Ví dụ tên biến hợp lệ:**

        int age;
        float _temperature;
        char studentName;
        unsigned long long total_count;

  ◦ **Ví dụ tên biến không hợp lệ**

        int 2age;        // Lỗi: Bắt đầu bằng số
        int my-var;      // Lỗi: Chứa ký tự đặc biệt "-"
        int return;      // Lỗi: Trùng từ khóa


#### **1.2. Kiểu dữ liệu**

##### **1.2.1. Kiểu dữ liệu cơ bản**

* **int** 

  ◦ **Mô tả:** Lưu trữ số nguyên (integer), không chứa phần thập phân.

  ◦ **Kích thước:** Thường 4 byte trên hệ thống 32/64-bit (có thể thay đổi tùy trình biên dịch).

  ◦ **Phạm vi:** 

        Với signed int (mặc định): -2,147,483,648 đến 2,147,483,647 (cho 4 byte).

        Với unsigned int: 0 đến 4,294,967,295.

  ◦ **VD:** 

        int count = 42;
        unsigned int max = 1000U; // U chỉ rõ unsigned

* **char** 

  ◦ **Mô tả:** Lưu trữ ký tự, sử dụng mã ASCII (1 ký tự = 1 byte).

  ◦ **Kích thước:** 1 byte.

  ◦ **Phạm vi:** 

        Với signed char: -128 đến 127.

        Với unsigned char: 0 đến 255.

  ◦ **VD:** 

        char letter = 'A'; // Lưu ký tự 'A' (mã ASCII 65)
        unsigned char code = 65; // Cũng lưu ký tự 'A'

* **float** 

  ◦ **Mô tả:** Lưu trữ số thực dấu chấm động (floating-point) với độ chính xác đơn.

  ◦ **Kích thước:** 4 byte.

  ◦ **Độ chính xác:** Khoảng 6-7 chữ số thập phân.

  ◦ **VD:** 

        float temperature = 36.6f; // f chỉ rõ kiểu float

* **double** 

  ◦ **Mô tả:** Lưu trữ số thực dấu chấm động với độ chính xác cao (double precision).

  ◦ **Kích thước:** 8 byte.

  ◦ **Độ chính xác:** Khoảng 15-16 chữ số thập phân.

  ◦ **VD:** 

        double pi = 3.14159265359;
        double scientific = 1.23e-4; // Ký hiệu khoa học: 0.000123

* **void** 

  ◦ **Mô tả:** Không chứa giá trị. Được sử dụng trong:

        Hàm không trả về giá trị (void function()).

        Con trỏ tổng quát (void*), có thể trỏ đến bất kỳ kiểu dữ liệu nào.

  ◦ **VD:** 

        void printMessage() {
            printf("Hello, World!\n");
        }
        void* ptr; // Con trỏ tổng quát

* **_Bool** 

  ◦ **Mô tả:** Kiểu dữ liệu boolean, lưu trữ giá trị 0 (false) hoặc 1 (true).

  ◦ **Kích thước:** Thường 1 byte.

  ◦ **Ứng dụng:** Sử dụng để biểu diễn giá trị logic.

  ◦ **VD:** 

        #include <stdbool.h>

        _Bool flag1 = 1;        // C99
        bool flag2 = true;      // Với stdbool.h

##### **1.2.2. Xác định kích thước và phạm vi dữ liệu**

* **Sử dụng toán tử sizeof:** 

  ◦ sizeof là một toán tử trong C dùng để xác định kích thước (tính bằng byte) của một kiểu dữ liệu hoặc biến

  ◦ Trả về kiểu `size_t` (kiểu không dấu)

  ◦ Cú pháp: 

        sizeof(type)      // Với kiểu dữ liệu
        sizeof(variable)  // Với biến
        sizeof expression // Với biểu thức

  ◦ Ví dụ:

        #include <stdio.h>

        int main() {
            int a = 10;
            double b = 3.14;
            char c = 'X';
            
            // Sử dụng với kiểu dữ liệu
            printf("Kích thước int: %zu bytes\n", sizeof(int));
            printf("Kích thước double: %zu bytes\n", sizeof(double));
            printf("Kích thước char: %zu bytes\n", sizeof(char));
            
            // Sử dụng với biến
            printf("Kích thước biến a: %zu bytes\n", sizeof(a));
            printf("Kích thước biến b: %zu bytes\n", sizeof(b));
            printf("Kích thước biến c: %zu bytes\n", sizeof(c));
            
            // Sử dụng với biểu thức
            printf("Kích thước a + b: %zu bytes\n", sizeof(a + b));
            
            return 0;
        }

* **Sử dụng thư viện <limits.h>:** 

  ◦ Thư viện <limits.h> chứa các hằng số định nghĩa giới hạn của các kiểu số nguyên

  ◦ Cung cấp cả giá trị lớn nhất và nhỏ nhất cho mỗi kiểu

  ◦ Các hằng số quan trọng trong `<limits.h>` cho kiểu char 

        CHAR_BIT    // Số bit trong 1 byte (thường là 8)
        CHAR_MIN    // Giá trị nhỏ nhất của char
        CHAR_MAX    // Giá trị lớn nhất của char
        SCHAR_MIN   // Giá trị nhỏ nhất của signed char
        SCHAR_MAX   // Giá trị lớn nhất của signed char
        UCHAR_MAX   // Giá trị lớn nhất của unsigned char

  ◦ Các hằng số quan trọng trong `<limits.h>` cho kiểu int

        INT_MIN     // Giá trị nhỏ nhất của int
        INT_MAX     // Giá trị lớn nhất của int
        UINT_MAX    // Giá trị lớn nhất của unsigned int
        SHRT_MIN    // Giá trị nhỏ nhất của short int
        SHRT_MAX    // Giá trị lớn nhất của short int
        USHRT_MAX   // Giá trị lớn nhất của unsigned short int
        LONG_MIN    // Giá trị nhỏ nhất của long int
        LONG_MAX    // Giá trị lớn nhất của long int
        ULONG_MAX   // Giá trị lớn nhất của unsigned long int
        LLONG_MIN   // Giá trị nhỏ nhất của long long int (C99)
        LLONG_MAX   // Giá trị lớn nhất của long long int (C99)
        ULLONG_MAX  // Giá trị lớn nhất của unsigned long long int (C99)

* **Sử dụng thư viện <float.h>:** 

  ◦ Thư viện `<float.h>` chứa các hằng số định nghĩa giới hạn và đặc tính của các kiểu số thực

  ◦ Cung cấp thông tin về độ chính xác, phạm vi, và các đặc tính khác

  ◦ Các hằng số quan trọng trong `<float.h>` cho kiểu float 

        FLT_MIN         // Số dương nhỏ nhất có thể biểu diễn
        FLT_MAX         // Số dương lớn nhất có thể biểu diễn
        FLT_EPSILON     // Chênh lệch nhỏ nhất giữa 1.0 và số tiếp theo
        FLT_DIG         // Số chữ số thập phân có độ chính xác
        FLT_MANT_DIG    // Số bit trong phần định trị (mantissa)

  ◦ Các hằng số quan trọng trong `<float.h>` cho kiểu double

        DBL_MIN         // Số dương nhỏ nhất có thể biểu diễn
        DBL_MAX         // Số dương lớn nhất có thể biểu diễn
        DBL_EPSILON     // Chênh lệch nhỏ nhất giữa 1.0 và số tiếp theo
        DBL_DIG         // Số chữ số thập phân có độ chính xác
        DBL_MANT_DIG    // Số bit trong phần định trị

  ◦ Các hằng số quan trọng trong `<float.h>` cho kiểu long double

        LDBL_MIN        // Số dương nhỏ nhất có thể biểu diễn
        LDBL_MAX        // Số dương lớn nhất có thể biểu diễn
        LDBL_EPSILON    // Chênh lệch nhỏ nhất giữa 1.0 và số tiếp theo
        LDBL_DIG        // Số chữ số thập phân có độ chính xác
        LDBL_MANT_DIG   // Số bit trong phần định trị

##### **1.2.3. Bộ sửa đổi (Modifiers)**

* **short và long:**

  ◦ **Mô tả:** Điều chỉnh kích thước của kiểu int hoặc các kiểu khác.

  ◦ **VD:**

        short int: Thường 2 byte, phạm vi -32,768 đến 32,767.
        long int: Thường 4 hoặc 8 byte (tùy hệ thống).
        long long int: Thường 8 byte, phạm vi rất lớn.

* **unsigned:**

  ◦ **Mô tả:** Chỉ lưu trữ giá trị không âm, tăng phạm vi dương của kiểu dữ liệu.

  ◦ **VD:**

        unsigned int: 0 đến 4,294,967,295 (4 byte).
        unsigned char: 0 đến 255.

* **signed:**

  ◦ **Mô tả:** Cho phép lưu trữ cả giá trị âm và dương. Đây là mặc định cho `int` và `char`.

  ◦ **VD:**

        signed int num = -42;

##### **1.2.4. Constants và Qualifiers**

* **const:**

  ◦ **Mô tả:** Biến được khai báo với `const` không thể thay đổi giá trị sau khi khởi tạo.

  ◦ **Ứng dụng:** Đảm bảo tính toàn vẹn dữ liệu, đặc biệt khi giá trị không cần thay đổi.

  ◦ **Ví dụ:**

        const int MAX = 100;
        MAX = 200; // Lỗi: Không thể thay đổi giá trị của const


* **volatile:**

  ◦ **Mô tả:** Chỉ định rằng giá trị của biến có thể thay đổi ngoài sự kiểm soát của chương trình (ví dụ: bởi phần cứng, ngắt, hoặc hệ thống).

  ◦ **Ứng dụng:** Thường dùng trong lập trình nhúng hoặc khi làm việc với phần cứng.

  ◦ **Ví dụ:**

        volatile int sensor_value; // Giá trị có thể thay đổi bất ngờ

* **restrict:**

  ◦ **Mô tả:** Gợi ý trình biên dịch rằng con trỏ là cách duy nhất để truy cập dữ liệu, giúp tối ưu hóa hiệu suất.

  ◦ **Ứng dụng:** Tăng hiệu quả truy cập bộ nhớ trong các chương trình phức tạp.

  ◦ **Ví dụ:**

        int *restrict ptr; // Chỉ ptr có thể truy cập dữ liệu

#### **1.3. Khai báo và khởi tạo**

##### **1.3.1. Khai báo**

* Khai báo là quá trình định nghĩa một biến với kiểu dữ liệu và tên, nhưng chưa gán giá trị.

* Cú pháp:

        <kiểu_dữ_liệu> <tên_biến>;

* VD:

        int age;
        float height;
        char grade;

##### **1.3.2. Khởi tạo**

* Khởi tạo là gán giá trị ban đầu cho biến khi khai báo.

* Cú pháp:

        <kiểu_dữ_liệu> <tên_biến> = <giá_trị>;

* VD:

        const float PI = 3.14159; // Hằng số
        volatile int sensor_value = 0; // Biến có thể thay đổi bất ngờ
        int age = 25;
        float height = 1.75f; // f để chỉ rõ float
        double large_num = 1.23e-4; // Ký hiệu khoa học
        char grade = 'A';


* Lưu ý:

  ◦ Nếu biến không được khởi tạo:

        Biến cục bộ: Giá trị là không xác định (undefined behavior, có thể là giá trị rác).

        Biến toàn cục hoặc tĩnh: Tự động khởi tạo bằng 0.

  ◦ Ví dụ:

        void example() {
            int uninitialized;    // Giá trị rác - undefined behavior
            static int s_var;     // Tự động = 0
            int initialized = 0;  // Luôn khởi tạo biến cục bộ!
        }

#### **1.4. Phạm vi và thời gian sống**

##### **1.4.1. Phạm vi (Scope)**

* **Cục bộ (Local):**

  ◦ Biến được khai báo bên trong một hàm hoặc khối lệnh ({}).

  ◦ Chỉ có thể truy cập trong phạm vi khai báo.

  ◦ VD:

        void example() {
            int local_var = 10; // Biến cục bộ
            printf("%d\n", local_var); // Hợp lệ
        }
        printf("%d\n", local_var); // Lỗi: local_var không tồn tại ngoài hàm

* **Toàn cục (Global):**

  ◦ Biến được khai báo bên ngoài tất cả các hàm.

  ◦ Có thể truy cập từ bất kỳ đâu trong chương trình.

  ◦ VD:

        int global_var = 100; // Biến toàn cục
        void example() {
            printf("%d\n", global_var); // Hợp lệ
        }

* **Tĩnh (Static):**

  ◦ Biến được khai báo với từ khóa static.

  ◦ Chỉ có thể truy cập trong phạm vi khai báo, nhưng giữ giá trị giữa các lần gọi hàm.

  ◦ Phân biệt static toàn cục và cục bộ:

        static int file_scope_var = 0; // Chỉ visible trong file hiện tại (toàn cục tĩnh)

        void func() {
            static int local_static = 0; // Chỉ visible trong hàm này (cục bộ tĩnh)
            local_static++;
        }


##### **1.4.2. Thời gian sống (Lifetime)**

* **Cục bộ (Local):**

  ◦ Biến cục bộ được tạo khi vào phạm vi (scope) và bị hủy khi thoát khỏi phạm vi.

  ◦ VD:

        void example() {
            int temp = 5; // temp tồn tại trong hàm
            printf("%d\n", temp);
        } // temp bị hủy khi hàm kết thúc

* **Toàn cục/Tĩnh:**

  ◦ Biến toàn cục và biến tĩnh tồn tại suốt thời gian chạy của chương trình.

  ◦ VD:

        static int global_count = 0; // Tồn tại suốt chương trình
        void counter() {
            static int count = 0; // Tồn tại suốt chương trình
            count++;
            printf("Count: %d\n", count);
        }

* **VD MINH HỌA:**

        #include <stdio.h>
        static int global_count = 0; // Biến toàn cục tĩnh

        void counter() {
            static int count = 0; // Biến tĩnh, giữ giá trị
            count++;
            printf("Count: %d\n", count);
        }

        int main() {
            counter(); // In: 1
            counter(); // In: 2
            printf("Global count: %d\n", global_count);
            return 0;
        }


#### **1.5. Typedef và Enum**

##### **1.5.1. Typedef**

* **Mô tả:**

  ◦ `typedef` cho phép tạo bí danh (alias) cho các kiểu dữ liệu, giúp mã nguồn dễ đọc và bảo trì hơn.

  ◦ Cú pháp:

        typedef <kiểu_dữ_liệu> <tên_bí_danh>;

* **Ví dụ:**

        typedef unsigned long ulong_t;
        ulong_t large_num = 123456789UL; // UL chỉ rõ unsigned long
        printf("%lu\n", large_num);

##### **1.5.2. Enum**

* **Mô tả:**

  ◦ Enum (viết tắt của enumeration) là một kiểu dữ liệu do người dùng định nghĩa trong C, được sử dụng để tạo một tập hợp các hằng số nguyên có tên (còn gọi là enumerators).

  ◦ Mỗi hằng số trong enum được gán một giá trị nguyên (int), giúp tăng tính rõ ràng và dễ đọc của mã nguồn, đặc biệt khi làm việc với các giá trị cố định hoặc trạng thái có ý nghĩa cụ thể.

  ◦ Enum thường được dùng để biểu diễn các tập hợp giá trị liên quan đến nhau, ví dụ: ngày trong tuần, trạng thái, màu sắc, hoặc các mã trạng thái.

  ◦ Cú pháp:

        enum <tên_enum> { 
            <danh_sách_hằng_số> 
            };
        
        <tên_enum>: Tên của kiểu enum, được sử dụng để khai báo biến.
        <danh_sách_hằng_số>: Các hằng số nguyên, cách nhau bởi dấu phẩy.

* **Cách hoạt động của Enum:**

  ◦ Gán giá trị cho hằng số

        Mỗi hằng số trong enum được gán một giá trị nguyên (int). Theo mặc định:

        Hằng số đầu tiên được gán giá trị 0.

        Các hằng số tiếp theo được gán giá trị tăng dần (tăng thêm 1 so với hằng số trước đó).

        Người dùng có thể tự gán giá trị cụ thể cho bất kỳ hằng số nào, và các hằng số tiếp theo sẽ tiếp tục tăng từ giá trị đó.

  ◦ VD:

        VD mặc định

        enum Day { 
            SUN, MON, TUE, WED, THU, FRI, SAT 
            };
        // Giá trị: SUN = 0, MON = 1, TUE = 2, WED = 3, THU = 4, FRI = 5, SAT = 6

        VD gán giá trị cụ thể:

        enum Week { 
            SUN = 1, MON, TUE, WED, THU, FRI, SAT 
            };
        // Giá trị: SUN = 1, MON = 2, TUE = 3, WED = 4, THU = 5, FRI = 6, SAT = 7

        VD gán giá trị không liên tiếp:

        enum Status { OFF = 0, ON = 1, ERROR = -1, UNKNOWN = 99 };
        // Giá trị: OFF = 0, ON = 1, ERROR = -1, UNKNOWN = 99

* **Kiểu dữ liệu của Enum:**

  ◦ Các hằng số trong enum có kiểu dữ liệu là int. Do đó, biến kiểu enum có thể được sử dụng trong các phép toán số học hoặc so sánh như các biến int thông thường.

        #include <stdio.h>

        enum Day { SUN, MON, TUE, WED, THU, FRI, SAT };

        int main() {
            enum Day today = MON;
            printf("Today is: %d\n", today); // In: 1 (giá trị của MON)
            if (today == 1) {
                printf("It's Monday!\n");
            }
            return 0;
        }

* **Kết hợp với typedef:**

  ◦ Để tăng tính gọn gàng và dễ sử dụng, enum thường được kết hợp với typedef để tạo bí danh cho kiểu enum.

  ◦ Điều này giúp lược bỏ từ khóa enum khi khai báo biến.

        typedef enum { 
            FALSE, 
            TRUE
             } bool_t;
        bool_t flag = TRUE;
        printf("Flag: %d\n", flag); // In: 1

* **Kích thước của Enum:**

  ◦ Kích thước của một biến enum thường bằng kích thước của int (thường là 4 byte trên hệ thống 32/64-bit).

  ◦ Để kiểm tra kích thước, sử dụng toán tử sizeof.

        #include <stdio.h>

        enum Day { SUN, MON, TUE };

        int main() {
            enum Day today = MON;
            printf("Size of enum Day: %zu bytes\n", sizeof(today)); // Thường in: 4
            return 0;
        }

### **II. Nhập/xuất cơ bản**

#### **2.1. Hàm printf**

##### **2.1.1. Định nghĩa**

* **Hàm printf (print formatted)** được sử dụng để in dữ liệu ra màn hình hoặc thiết bị đầu ra chuẩn (stdout) theo định dạng được chỉ định.

* Hàm này thuộc thư viện chuẩn `<stdio.h>` và là một trong những hàm phổ biến nhất trong C để hiển thị dữ liệu.

* **Cú pháp:**

        int printf(const char *format, ...);

  ◦ **format:** Chuỗi định dạng, chứa văn bản và các ký tự định dạng (`%`).

  ◦ `...`: Danh sách các đối số tương ứng với các ký tự định dạng.

  ◦ **Giá trị trả về:** Số ký tự được in ra (không tính ký tự null \0). Trả về giá trị âm nếu có lỗi.

##### **2.1.2. Ký tự định dạng (Format Specifiers)**




| Ký tự định dạng | Kiểu dữ liệu | Mô tả |
|:---------------:|:------------:|:------|
| %d hoặc %i | int | Số nguyên có dấu |
| %u | unsigned int | Số nguyên không dấu |
| %f | float | Số thực dấu chấm động |
| %lf | double | Số thực dấu chấm động độ chính xác cao |
| %c | char | Ký tự đơn |
| %s | char* | Chuỗi ký tự (kết thúc bằng \0) |
| %x hoặc %X | int | Số nguyên hiển thị dưới dạng hexa |
| %o | int | Số nguyên hiển thị dưới dạng bát phân |
| %p | void* | Địa chỉ con trỏ |


##### **2.1.3. Ký tự đặc biệt**

* **Một số ký tự đặc biệt thường được sử dụng trong chuỗi định dạng:** 

  ◦ `\n`: Xuống dòng (newline).

  ◦ `\t`: Ký tự tab ngang.

  ◦ `\\`: Hiển thị dấu gạch chéo ngược (`\`).

  ◦ `\"`: Hiển thị dấu nháy kép (").

  ◦ `\0`: Ký tự null (kết thúc chuỗi).

* **VD:** 

        printf("Hello\nWorld\t!"); // In: Hello
                                //     World    !


##### **2.1.4. Formatted I/O Flags**

* `printf` hỗ trợ các cờ (flags), độ rộng (width), và độ chính xác (precision) để tùy chỉnh cách hiển thị dữ liệu.

* **Width:** Chỉ định số ký tự tối thiểu để hiển thị.

  ◦ `%10d`: Chiếm ít nhất 10 ký tự, căn phải (mặc định).

  ◦ `%-10d`: Chiếm 10 ký tự, căn trái.

* **Precision:** Chỉ định số chữ số thập phân (cho kiểu `float`/`double`) hoặc độ dài chuỗi tối đa (cho `%s`).

  ◦ `%.2f`: Hiển thị 2 chữ số thập phân.

  ◦ `%.5s`: Hiển thị tối đa 5 ký tự của chuỗi.

* **Flags:** 

  ◦ `-`: Căn trái.

  ◦ `+`: Luôn hiển thị dấu (+ hoặc -) cho số có dấu.

  ◦ `0`: Điền số 0 vào các vị trí trống (thay vì khoảng trắng).

  ◦ `#`: Thêm tiền tố (ví dụ: `0x` cho hexa, `0` cho bát phân).

* **Precision:** Chỉ định số chữ số thập phân (cho kiểu `float`/`double`) hoặc độ dài chuỗi tối đa (cho `%s`).

  ◦ `%.2f`: Hiển thị 2 chữ số thập phân.

  ◦ `%.5s`: Hiển thị tối đa 5 ký tự của chuỗi.

* **Dynamic width/precision:** Sử dụng * để truyền độ rộng hoặc độ chính xác qua đối số.

  ◦ `%*d`: Độ rộng được cung cấp bởi một đối số kiểu int.

  ◦ `%.*f`: Độ chính xác được cung cấp bởi một đối số kiểu int.

* **VD:**

        #include <stdio.h>

        int main() {
            printf("%-10s %10d\n", "Tên", 123);     // In: Tên          123
            printf("%+d %.2f\n", 42, 3.14159);      // In: +42 3.14
            printf("%0*d\n", 5, 42);                // In: 00042
            printf("%*d\n", 5, 42);                 // In:    42
            printf("%.*f\n", 3, 3.14159);           // In: 3.142
            return 0;
        }


#### **2.2. Hàm scanf**

##### **2.2.1. Định nghĩa**

* **Hàm scanf (scan formatted)** được sử dụng để đọc dữ liệu từ bàn phím hoặc thiết bị đầu vào chuẩn (stdin) theo định dạng được chỉ định.

* Hàm này thuộc thư viện `<stdio.h>`.

* **Cú pháp:**

        int scanf(const char *format, ...);

  ◦ **format:** Chuỗi định dạng, tương tự như printf, xác định kiểu dữ liệu cần đọc.

  ◦ `...`: Các con trỏ đến biến nơi dữ liệu sẽ được lưu trữ (thường cần dấu `&`, trừ `%s`).

  ◦ **Giá trị trả về:** Số lượng đối số được đọc thành công. Nếu lỗi hoặc hết đầu vào (EOF), trả về giá trị nhỏ hơn số đối số mong đợi hoặc `-1`.

##### **2.2.2. Ký tự định dạng (Format Specifiers)**

* **Một số ký tự đặc biệt thường được sử dụng trong chuỗi định dạng:**

    ◦ `%d`: Đọc số nguyên (`int`).

    ◦  `%u`: Đọc số nguyên không dấu (`unsigned int`).

    ◦  `%f`: Đọc số thực (`float`).

    ◦  `%lf`: Đọc số thực độ chính xác cao (double).

    ◦  `%c`: Đọc ký tự đơn.

    ◦  `%s`: Đọc chuỗi ký tự (kết thúc bằng khoảng trắng hoặc \n).

* **Lưu ý:**

    ◦  Sử dụng dấu &

        Khi đọc dữ liệu vào biến (trừ %s), cần truyền địa chỉ của biến bằng toán tử &.

        Với %s, chỉ cần truyền con trỏ đến mảng ký tự (không cần &).

    ◦  Kiểm tra giá trị trả về

        Hàm scanf trả về số lượng đối số được đọc thành công. Kiểm tra giá trị này để phát hiện lỗi nhập liệu.

    ◦  Ký tự khoảng trắng

        scanf bỏ qua khoảng trắng (space, tab, newline) khi đọc số hoặc chuỗi, nhưng giữ lại khi đọc %c.

        Điều này có thể gây lỗi nếu ký tự \n sót lại trong bộ đệm.

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

##### **2.2.3. Xử lý lỗi nhập liệu**

* **Nhập sai định dạng:** Nếu người dùng nhập chuỗi vào %d, scanf sẽ thất bại và không gán giá trị cho biến.

* **Ký tự thừa trong bộ đệm:** Ký tự \n hoặc các ký tự khác có thể sót lại trong bộ đệm đầu vào, gây lỗi khi đọc dữ liệu tiếp theo.

* **Khắc phục:** 

  ◦ Xóa bộ đệm trước khi đọc dữ liệu mới

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

  ◦ Hoặc sử dụng %*c trong scanf để bỏ qua ký tự cụ thể

        scanf("%d%*c", &age); // Bỏ qua ký tự sau số


* **Ví dụ xử lý bộ đệm:** 

        #include <stdio.h>

        int main() {
            int age;
            char grade;
            printf("Nhập tuổi: ");
            scanf("%d", &age);
            // Xóa bộ đệm
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Nhập cấp độ (A/B/C): ");
            scanf("%c", &grade);
            printf("Tuổi: %d, Cấp độ: %c\n", age, grade);
            return 0;
        }


#### **2.3. Hàm getline (POSIX)**

##### **2.3.1. Định nghĩa**

* **Hàm getline** là một hàm POSIX (không thuộc chuẩn C ANSI) dùng để đọc cả một dòng từ đầu vào (thường là stdin), tránh lỗi tràn bộ đệm (buffer overflow) thường gặp với `scanf` khi đọc chuỗi.

* Hàm này thuộc thư viện <stdio.h> và yêu cầu hỗ trợ POSIX (ví dụ: Linux, macOS).

* **Cú pháp:**

        ssize_t getline(char **lineptr, size_t *n, FILE *stream);

  ◦ **lineptr:** Con trỏ đến con trỏ kiểu `char`, nơi lưu trữ chuỗi đọc được. Bộ nhớ sẽ được cấp phát động nếu cần.

  ◦ `n`: Con trỏ đến kích thước bộ đệm. Hàm sẽ cập nhật kích thước nếu cấp phát lại bộ nhớ.

  ◦ **stream:** Luồng đầu vào (thường là `stdin`).

  ◦ Giá trị trả về: Số ký tự đọc được (bao gồm `\n`) hoặc `-1` nếu có lỗi hoặc hết đầu vào (EOF).

* **Đặc điểm**

  ◦ Tự động cấp phát bộ nhớ: Nếu `lineptr` là `NULL` và `*n` là 0, `getline` sẽ cấp phát bộ nhớ động.

  ◦ An toàn hơn `scanf`: Không giới hạn độ dài chuỗi, tránh tràn bộ đệm.

  ◦ Yêu cầu giải phóng bộ nhớ: Người dùng phải gọi `free` để giải phóng bộ nhớ được cấp phát.


        #include <stdio.h>
        #include <stdlib.h>

        int main() {
            char *line = NULL;
            size_t len = 0;
            printf("Nhập chuỗi: ");
            if (getline(&line, &len, stdin) != -1) {
                printf("Bạn nhập: %s", line);
            } else {
                printf("Lỗi đọc dòng!\n");
            }
            free(line); // Giải phóng bộ nhớ
            return 0;
        }

##### **2.3.2. Ký tự định dạng (Format Specifiers)**

* **Một số ký tự đặc biệt thường được sử dụng trong chuỗi định dạng:**

    ◦ `%d`: Đọc số nguyên (`int`).

    ◦  `%u`: Đọc số nguyên không dấu (`unsigned int`).

    ◦  `%f`: Đọc số thực (`float`).

    ◦  `%lf`: Đọc số thực độ chính xác cao (double).

    ◦  `%c`: Đọc ký tự đơn.

    ◦  `%s`: Đọc chuỗi ký tự (kết thúc bằng khoảng trắng hoặc \n).

* **Lưu ý:**

    ◦  Sử dụng dấu &

        Khi đọc dữ liệu vào biến (trừ %s), cần truyền địa chỉ của biến bằng toán tử &.

        Với %s, chỉ cần truyền con trỏ đến mảng ký tự (không cần &).

    ◦  Kiểm tra giá trị trả về

        Hàm scanf trả về số lượng đối số được đọc thành công. Kiểm tra giá trị này để phát hiện lỗi nhập liệu.

    ◦  Ký tự khoảng trắng

        scanf bỏ qua khoảng trắng (space, tab, newline) khi đọc số hoặc chuỗi, nhưng giữ lại khi đọc %c.

        Điều này có thể gây lỗi nếu ký tự \n sót lại trong bộ đệm.

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

#### **2.4. Lỗi phổ biến và cách khắc phục**

##### **2.4.1. Nhập sai định dạng**

* **Vấn đề:** Người dùng nhập dữ liệu không khớp với định dạng được chỉ định (ví dụ: nhập chuỗi "abc" vào %d).

* **Hậu quả:** scanf thất bại, không gán giá trị cho biến, và có thể để lại dữ liệu trong bộ đệm.

* **Khắc phục:**

  ◦ Kiểm tra giá trị trả về của scanf:

        if (scanf("%d", &num) != 1) {
            printf("Nhập sai định dạng!\n");
        }

  ◦ Xóa bộ đệm sau khi đọc thất bại

        while ((c = getchar()) != '\n' && c != EOF);

##### **2.4.2. Bộ đệm đầu vào (Input Buffer)**

* **Vấn đề:** Ký tự `\n` hoặc các ký tự khác sót lại trong bộ đệm sau khi sử dụng `scanf`, gây lỗi khi đọc dữ liệu tiếp theo (đặc biệt với %c).

* **Hậu quả:** Các lệnh `scanf` sau có thể đọc nhầm ký tự còn sót lại thay vì dữ liệu mới.

* **Khắc phục:**

  ◦ Xóa bộ đệm trước khi đọc dữ liệu mới:

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

  ◦ Sử dụng %*c để bỏ qua ký tự không mong muốn

        scanf("%d%*c", &num);

  ◦ Sử dụng `getline` hoặc `fgets` để đọc cả dòng và xử lý sau.


        #include <stdio.h>

        int main() {
            int age;
            char grade;
            printf("Nhập tuổi: ");
            scanf("%d", &age);
            // Không xóa bộ đệm, scanf tiếp theo có thể đọc '\n'
            printf("Nhập cấp độ (A/B/C): ");
            scanf("%c", &grade); // Có thể đọc nhầm '\n'
            printf("Tuổi: %d, Cấp độ: %c\n", age, grade);

            // Cách khắc phục
            printf("\nNhập lại tuổi: ");
            scanf("%d", &age);
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Xóa bộ đệm
            printf("Nhập lại cấp độ (A/B/C): ");
            scanf("%c", &grade);
            printf("Tuổi: %d, Cấp độ: %c\n", age, grade);
            return 0;
        }

##### **2.4.3. Tràn bộ đệm khi đọc chuỗi**

* **Vấn đề:** Sử dụng `scanf` với `%s` mà không giới hạn độ dài chuỗi có thể gây tràn bộ đệm.

* **Khắc phục:**

  ◦ Sử dụng `%ns` để giới hạn số ký tự đọc:

        char buffer[20];
        scanf("%19s", buffer); // Đọc tối đa 19 ký tự, để chừa chỗ cho '\0'

  ◦ Sử dụng `fgets` hoặc `getline` để đọc chuỗi an toàn hơn.

##### **2.4.4. EOF và lỗi đầu vào**

* **Vấn đề:** Người dùng nhập EOF (Ctrl+D trên Linux, Ctrl+Z trên Windows) hoặc đầu vào bị lỗi.

* **Khắc phục:**

  ◦ Kiểm tra giá trị trả về của `scanf` hoặc `getline` để xử lý trường hợp EOF hoặc lỗi.

#### **2.5. Hàm xuất**

##### **2.5.1. Hàm puts**

* In chuỗi ra stdout và tự động thêm `\n`.

* **Cú pháp:**

        int puts(const char *s);

* **VD:**

        puts("Hello, World!"); // In: Hello, World! (với \n)

##### **2.5.2. Hàm putchar**

* In một ký tự ra stdout.

* **Cú pháp:**

        int putchar(int c);

* **VD:**

        putchar('A'); // In: A

#### **2.6. Hàm nhập**

##### **2.6.1. Hàm fgets**

* Đọc một dòng hoặc số ký tự cụ thể từ một luồng (thường là stdin).

* **Cú pháp:**

        char *fgets(char *s, int size, FILE *stream);

* **VD:**

        char buffer[100];
        if (fgets(buffer, 100, stdin)) {
            printf("Bạn nhập: %s", buffer);
        }

##### **2.6.2. Hàm getchar**

* Đọc một ký tự từ stdin.

* **Cú pháp:**

        int getchar(void);

* **VD:**

        int c = getchar();
        printf("Ký tự nhập: %c\n", c);
### **III. Toán tử**

#### **3.1. Toán tử số học**

##### **3.1.1. Định nghĩa**

* **Cộng (+):** Cộng hai giá trị.

* **Trừ (-):** Trừ hai giá trị.

* **Nhân (*):** Nhân hai giá trị.

* **Chia (/):** Chia hai giá trị.

  ◦ Khi cả hai toán hạng là kiểu int, kết quả sẽ bỏ phần thập phân (ví dụ: 7 / 2 = 3).

  ◦ Với kiểu float hoặc double, kết quả sẽ bao gồm phần thập phân (ví dụ: 7.0 / 2 = 3.5).

* **Chia lấy dư (%):** Trả về phần dư của phép chia (chỉ áp dụng cho kiểu int).

  ◦ Ví dụ: 7 % 3 = 1.

* **Tăng 1 (++):** Tăng giá trị biến lên 1

  ◦ **Tiền tố (++i):** Tăng giá trị trước khi sử dụng.

  ◦ **Hậu tố (i++):** Sử dụng giá trị hiện tại, sau đó tăng.

* **Giảm 1 (--):** Giảm giá trị biến xuống 1

  ◦ **Tiền tố (--i):** Giảm giá trị trước khi sử dụng.

  ◦ **Hậu tố (i++):** Sử dụng giá trị hiện tại, sau đó giảm.

##### **3.1.2. VD**

        #include <stdio.h>
        int main() {
            int a = 10, b = 3;
            printf("Cộng: %d\n", a + b);     // 13
            printf("Trừ: %d\n", a - b);      // 7
            printf("Nhân: %d\n", a * b);     // 30
            printf("Chia: %d\n", a / b);     // 3 (bỏ phần thập phân)
            printf("Chia lấy dư: %d\n", a % b); // 1
            printf("Tiền tố ++a: %d\n", ++a);   // 11 (tăng trước, in 11)
            printf("Hậu tố b++: %d\n", b++);    // 3 (in trước, tăng thành 4)
            printf("Giá trị b sau: %d\n", b);   // 4
            return 0;
        }

* **Lưu ý:**

  ◦ Phép chia với số 0 sẽ gây lỗi (undefined behavior).

  ◦ Toán tử tăng/giảm hậu tố có thể gây nhầm lẫn nếu dùng trong biểu thức phức tạp (ví dụ: a = i++ + i; là không rõ ràng).

#### **3.2. Toán tử Logic**

##### **3.2.1. Định nghĩa**

* **Toán tử logic thực hiện các phép toán logic trên các giá trị boolean (0 là sai, khác 0 là đúng).**

* Các toán tử này thường được sử dụng trong các biểu thức điều kiện để kiểm tra nhiều điều kiện cùng lúc, giúp quyết định luồng thực thi của chương trình.

##### **3.2.2. Các toán tử chính**

* **AND (&&):** Trả về `1` nếu cả hai vế đều đúng.

* **OR (||):** Phép toán logic "hoặc". Trả về `1` (true) nếu ít nhất một vế đúng. Chỉ sai khi cả hai vế đều sai.

* **NOT (!):** Phép toán logic "phủ định". Đảo ngược giá trị: `!0` = `1`, và `!non-zero` = `0`.

* **Short-circuit evaluation**

  ◦ **Với &&:** Nếu vế trái là sai (`0`), vế phải không được thực thi, vì toàn bộ biểu thức đã sai..

  ◦ **Với ||:** Nếu vế trái là đúng (khác `0`), vế phải không được thực thi, vì toàn bộ biểu thức đã đúng.

##### **3.2.3. Ứng dụng**

* Kiểm tra điều kiện an toàn: `if (ptr != NULL && *ptr > 0)` – tránh dereference con trỏ NULL.

* Xử lý lỗi: `if (file_open() || fallback_method())` – thử phương pháp thay thế nếu thất bại.

##### **3.2.4. Lưu ý**

* Các toán tử logic luôn trả về `0` hoặc `1`, không phải giá trị gốc của vế.

* Không sử dụng với các biểu thức không phải boolean; C sẽ tự chuyển đổi ngầm định.

##### **3.2.5. VD**
        
        #include <stdio.h>
        int main() {
            int a = 5, b = 0;
            printf("a && b: %d\n", a && b); // 0 (b = 0, sai)
            printf("a || b: %d\n", a || b); // 1 (a = 5, đúng)
            printf("!a: %d\n", !a);         // 0 (a = 5, đảo thành sai)
            
            // Short-circuit
            int x = 0, y = 10;
            if (x && ++y) { } // y không tăng vì x = 0
            printf("y: %d\n", y); // In: 10
            return 0;
        }
        
        
        #include <stdio.h>
        int expensive_function() {
            printf("Hàm tốn kém được gọi!\n");
            return 1;
        }
        int main() {
            int x = 0;
            if (x && expensive_function()) { } // Hàm không gọi vì x = 0
            int z = 1;
            if (z || expensive_function()) { } // Hàm không gọi vì z = 1
            return 0;
        }
        
#### **3.3. Toán tử so sánh**

##### **3.3.1. Định nghĩa**

* **Toán tử logic thực hiện các phép toán logic trên các giá trị boolean (0 là sai, khác 0 là đúng).**

* Chúng được sử dụng rộng rãi trong các cấu trúc điều khiển như if, while, để quyết định luồng chương trình dựa trên mối quan hệ giữa các biến.

##### **3.3.2. Các toán tử chính**

* **Toán tử so sánh dùng để so sánh hai giá trị, trả về 1 (đúng) hoặc 0 (sai).**

* **Bằng (==):** Kiểm tra hai giá trị có bằng nhau.

* **Không bằng (!=):** Kiểm tra hai giá trị có khác nhau.

* **Nhỏ hơn (<), Lớn hơn (>), Nhỏ hơn hoặc bằng (<=), Lớn hơn hoặc bằng (>=).**

##### **3.3.3. Nguyên lý hoạt động**

* Toán tử so sánh hoạt động trên các kiểu dữ liệu số (int, float, double), ký tự (char), và con trỏ (pointer). Với float/double, cần cẩn thận do lỗi làm tròn.

* Kết quả luôn là 0 hoặc 1, có thể dùng trực tiếp trong biểu thức logic.

##### **3.3.4. Lưu ý**

* Không sử dụng `==` để so sánh chuỗi (string), phải dùng `strcmp` từ `<string.h>`.

* Với con trỏ, `==` kiểm tra địa chỉ, không phải nội dung.

* Tránh so sánh số thực trực tiếp do độ chính xác.

* Dễ nhầm lẫn `==` với `=` (gán giá trị), dẫn đến lỗi logic (ví dụ: if (x = 5) luôn đúng và gán x=5).

* Với số thực, nên sử dụng epsilon để so sánh (ví dụ: `fabs(a - b) < 1e-9` thay vì `a == b`).

        #include <stdio.h>
        int main() {
            int a = 5, b = 3;
            printf("a == b: %d\n", a == b); // 0
            printf("a != b: %d\n", a != b); // 1
            printf("a < b: %d\n", a < b);   // 0
            printf("a >= b: %d\n", a >= b); // 1
            return 0;
        }



#### **3.4. Toán tử gán**

##### **3.4.1. Định nghĩa**

* Toán tử gán dùng để gán giá trị từ vế phải cho vế trái

* Chúng không chỉ đơn giản là gán mà còn có thể kết hợp với các phép toán khác để tạo ra các biểu thức ngắn gọn.

##### **3.4.2. Các toán tử chính**

* **Gán đơn giản (=):** Gán giá trị vế phải cho biến vế trái.

* **Gán kết hợp:** Kết hợp phép toán với gán

  ◦ `+=`: Cộng và gán (a += b tương đương a = a + b).cần.

  ◦ `-=, *=, /=, %=`: Tương tự.

* **VD1:**

        #include <stdio.h>
        int main() {
            int a = 10;
            a += 5;  // a = a + 5 = 15
            printf("a += 5: %d\n", a);
            a *= 2;  // a = a * 2 = 30
            printf("a *= 2: %d\n", a);
            return 0;
        }

* **VD2:**

        #include <stdio.h>
        int main() {
            int a, b, c;
            a = b = c = 10; // Chain gán
            printf("a: %d, b: %d, c: %d\n", a, b, c); // 10 10 10
            return 0;
        }

#### **3.5. Toán tử Bitwise**

##### **3.5.1. Định nghĩa**

* Toán tử bitwise hoạt động trực tiếp trên các bit của số nguyên, coi giá trị như dãy bit nhị phân

* Chúng hữu ích cho lập trình cấp thấp, tối ưu hóa bộ nhớ và tốc độ.

##### **3.5.2. Các toán tử chính**

* **AND (&):** Bitwise AND – `1` nếu cả hai bit là `1`.

* **OR (|):** Bitwise OR – `1` nếu ít nhất một bit là `1`.

* **XOR (^):** Bitwise XOR – 1 nếu hai bit khác nhau.

* **NOT (~):** Bitwise NOT – Đảo bit, nhưng với số có dấu, kết quả phụ thuộc vào biểu diễn (two's complement).

* **Dịch trái (<<):** Dịch bit sang trái, nhân với 2^mũ (shift amount).

* **Dịch phải (>>):** Dịch bit sang phải, chia cho 2^mũ; với số có dấu, giữ bit dấu (arithmetic shift).

* **VD1:**

        #include <stdio.h>
        int main() {
            int a = 10;
            a += 5;  // a = a + 5 = 15
            printf("a += 5: %d\n", a);
            a *= 2;  // a = a * 2 = 30
            printf("a *= 2: %d\n", a);
            return 0;
        }

        #include <stdio.h>
        int main() {
            int a, b, c;
            a = b = c = 10; // Chain gán
            printf("a: %d, b: %d, c: %d\n", a, b, c); // 10 10 10
            return 0;
        }

* **VD2:**

        #include <stdio.h>
        #define FLAG_READ  (1 << 0) // 0001
        #define FLAG_WRITE (1 << 1) // 0010
        int main() {
            unsigned int flags = 0;
            flags |= FLAG_READ;  // Bật flag read
            if (flags & FLAG_READ) printf("Read enabled\n");
            flags &= ~FLAG_READ; // Tắt flag read
            return 0;
        }

##### **3.5.3. Lưu ý**

* Sử dụng `unsigned` để tránh vấn đề với bit dấu.

* Kích thước bit phụ thuộc nền tảng (thường 32/64 bit).


#### **3.6. Độ ưu tiên toán tử**

##### **3.6.1. Định nghĩa**

* Độ ưu tiên (precedence) quyết định thứ tự thực hiện toán tử trong biểu thức phức tạp.

* Nếu ưu tiên bằng nhau, tính kết hợp (associativity) quyết định (thường từ trái sang phải).

##### **3.6.2. Thứ tự ưu tiên chi tiết (từ cao đến thấp):**

* Ngoặc `()`

* Tăng/giảm tiền tố `++, --`; NOT `!`; Bitwise NOT `~`

* Nhân `*`, Chia `/`, Dư `%`

* Cộng `+`, Trừ `-`

* Dịch bit `<<`, `>>`

* So sánh quan hệ `<`, `>`, `<=`, `>=`

* So sánh bằng `==`, `!=`

* Bitwise AND `&`

* Bitwise XOR `^`

* Bitwise OR 

* Logic AND `&&`

* Logic OR `||`

* Ba ngôi `?:`

* Gán `=, +=, v.v.`

* **VD1:**

        #include <stdio.h>
        int main() {
            int x = 10, y = 3, z = 2;
            int result = x + y * z; // y * z trước
            printf("Kết quả: %d\n", result); // 16
            result = (x + y) * z;
            printf("Kết quả với ngoặc: %d\n", result); // 26
            return 0;
        }

* **VD2:**

        #include <stdio.h>
        int main() {
            int a = 5;
            int res = a++ + a; // Hậu tố ++ ưu tiên thấp, res = 5 + 6 = 11? Không, undefined behavior
            printf("res: %d\n", res); // Tránh code này
            return 0;
        }

### **IV. Câu lệnh điều kiện**

#### **4.1. if-else**

##### **4.1.1. Định nghĩa**

* Câu lệnh `if-else` thực thi mã dựa trên điều kiện boolean. 

* Nếu điều kiện đúng, thực thi khối `if`; ngược lại, thực thi `else` (nếu có).

##### **4.1.2. Cú pháp**

        if (điều_kiện) {
            // Mã thực thi nếu điều_kiện đúng
        } else if (điều_kiện_khác) {
            // Mã thực thi nếu điều_kiện_khác đúng
        } else {
            // Mã thực thi nếu không điều kiện nào đúng
        }

##### **4.1.3. Nguyên lý hoạt động**

* Điều kiện là biểu thức trả về `khác 0 (true)` hoặc `0 (false)`.

* Có thể lồng ghép hoặc dùng `else if` cho nhiều trường hợp.

##### **4.1.4. Ứng dụng**

* **Kiểm tra đầu vào:** Kiểm tra tính hợp lệ của dữ liệu người dùng (ví dụ: số dương, chuỗi không rỗng).

* **Xử lý lỗi:** Kiểm tra trạng thái trước khi thực thi (ví dụ: kiểm tra con trỏ NULL).

        #include <stdio.h>
        int main() {
            int age;
            float income;
            printf("Nhập tuổi và thu nhập hàng tháng (triệu): ");
            scanf("%d %f", &age, &income);
            if (age >= 18) {
                if (income >= 10.0) {
                    printf("Đủ điều kiện vay vốn\n");
                } else {
                    printf("Thu nhập không đủ để vay\n");
                }
            } else {
                printf("Chưa đủ tuổi để vay\n");
            }
            return 0;
        }

#### **4.2. switch-case**

##### **4.2.1. Định nghĩa**

* `switch-case` xử lý nhiều giá trị cụ thể của biểu thức (thường int/char).

##### **4.2.2. Cú pháp**

        switch (biểu_thức) {
            case giá_trị_1:
                // Mã thực thi nếu biểu_thức == giá_trị_1
                break;
            case giá_trị_2:
                // Mã thực thi nếu biểu_thức == giá_trị_2
                break;
            default:
                // Mã thực thi nếu không khớp với case nào
        }

##### **4.2.3. Nguyên lý hoạt động**

* **Biểu thức:** Được đánh giá một lần, so sánh với các giá trị hằng trong các case.

* **Case:** Chỉ chấp nhận hằng số nguyên (int) hoặc ký tự (char). Không hỗ trợ khoảng giá trị hoặc biểu thức.

* **break:** Ngăn hiện tượng "fall-through" (thực thi các case tiếp theo). Nếu không có break, chương trình sẽ tiếp tục chạy tất cả các case phía dưới.

* **default:** Xử lý trường hợp không khớp với bất kỳ case nào, tương tự else.

##### **4.2.4. Ứng dụng thực tế**

* **Menu lựa chọn:** Xử lý các tùy chọn trong giao diện người dùng.

* **Phân loại:** Phân loại dựa trên giá trị cụ thể (ví dụ: xếp loại điểm, trạng thái).

* **Trạng thái máy (state machine):** Chuyển đổi trạng thái trong hệ thống nhúng.

        #include <stdio.h>
        int main() {
            char grade = 'B';
            switch (grade) {
                case 'A':
                case 'B':
                    printf("Đạt yêu cầu\n"); // Fall-through: cả A và B đều đạt
                    break;
                case 'C':
                    printf("Cần cải thiện\n");
                    break;
                default:
                    printf("Không hợp lệ\n");
            }
            return 0;
        }

#### **4.3. Toán tử ba ngôi**

##### **4.3.1. Định nghĩa**

* Toán tử ba ngôi `(?:)` là phiên bản ngắn của `if-else`, trả về giá trị dựa trên điều kiện.

##### **4.3.2. Cú pháp**

        điều_kiện ? biểu_thức_1 : biểu_thức_2

* Nguyên lý hoạt động:

    ◦ điều_kiện: Biểu thức boolean (khác 0 là true, 0 là false).

    ◦ Nếu điều kiện đúng, trả về biểu_thức_1; nếu sai, trả về biểu_thức_2.

    ◦ Kết quả có thể được gán cho biến hoặc sử dụng trực tiếp.

        #include <stdio.h>
        int main() {
            int a = 5, b = 8;
            int max = a > b ? a : b;
            printf("Giá trị lớn nhất: %d\n", max); // In: 8
            return 0;
        }

##### **4.3.3. Ứng dụng**

* **Gán giá trị điều kiện:** Ví dụ, gán giá trị lớn nhất giữa hai số

* **In kết quả ngắn gọn:** Thay thế if-else trong các trường hợp đơn giản.

* **Biểu thức trong hàm:*** Trả về giá trị dựa trên điều kiện.

##### **4.3.4. Lưu ý**

* Tránh lồng ghép quá nhiều toán tử ba ngôi (nested ternary) để giữ mã dễ đọc.

* Đảm bảo kiểu dữ liệu của `biểu_thức_1` và `biểu_thức_2` tương thích.       

        #include <stdio.h>
        int main() {
            int x = 10, y = 0;
            // Không nên: y++ là side effect
            printf("%d\n", x > 5 ? y++ : y); // Không rõ y++ có chạy không
            // Nên dùng if-else để rõ ràng
            if (x > 5) {
                printf("%d\n", y++);
            } else {
                printf("%d\n", y);
            }
            return 0;
        }

### **V. Vòng lặp**

#### **5.1. for**

##### **5.1.1. Định nghĩa**

* Vòng lặp for được sử dụng khi số lần lặp đã biết trước, tích hợp ba thành phần: khởi tạo, điều kiện, và cập nhật trong một dòng. 

##### **5.1.2. Cú pháp**

        for (khởi_tạo; điều_kiện; bước_nhảy) {
            // Mã thực thi
        }

##### **5.1.3. Nguyên lý hoạt động**

* **khởi_tạo:** Thực thi một lần trước khi vòng lặp bắt đầu (thường khởi tạo biến đếm).

* **điều_kiện:** Kiểm tra trước mỗi lần lặp; nếu sai (0), vòng lặp dừng.

* **bước_nhảy:** Thực thi sau mỗi lần lặp, thường cập nhật biến đếm.

        #include <stdio.h>
        int main() {
            int arr[] = {10, 20, 30, 40, 50};
            int n = 5;
            for (int i = 0; i < n; i++) {
                printf("Phần tử %d: %d\n", i, arr[i]);
            }
            return 0;
        }

##### **5.1.4. Lưu ý**

* Biến khai báo trong `for` (C99 trở lên) có phạm vi cục bộ, không tồn tại ngoài vòng lặp.

* Có thể bỏ qua bất kỳ phần nào trong `for` (khởi tạo, điều kiện, bước nhảy), nhưng phải giữ dấu `;`.

* Tránh thay đổi biến đếm trong thân vòng lặp để tránh lỗi logic.

##### **5.1.5. Ứng dụng**

* **Duyệt mảng:** Truy cập từng phần tử của mảng.

* **Tính toán lặp:** Tính tổng, tích, hoặc bảng cửu chương.

* **Thuật toán:** Vòng lặp trong sắp xếp, tìm kiếm.
        

#### **5.2. while**

##### **5.2.1. Định nghĩa**

* Vòng lặp `while` thực thi mã khi điều kiện đúng, kiểm tra điều kiện trước mỗi lần lặp.

##### **5.2.2. Cú pháp**

        while (điều_kiện) {
            // Mã thực thi
        }

##### **5.2.3. Nguyên lý hoạt động**

* **điều_kiện:** Được kiểm tra trước mỗi lần lặp; nếu sai (0), vòng lặp dừng.

* Nếu điều kiện sai ngay từ đầu, thân vòng lặp không được thực thi.

        #include <stdio.h>
        int main() {
            int num;
            printf("Nhập số (âm để dừng): ");
            scanf("%d", &num);
            while (num >= 0) {
                printf("Bạn nhập: %d\n", num);
                printf("Nhập số (âm để dừng): ");
                scanf("%d", &num);
            }
            printf("Kết thúc\n");
            return 0;
        }

##### **5.2.4. Ứng dụng thực tế**

* **Đọc dữ liệu:** Đọc file hoặc nhập liệu đến khi gặp điều kiện dừng.

* **Thuật toán tìm kiếm:** Tìm phần tử trong danh sách không có kích thước cố định.

* **Xử lý sự kiện:** Lặp cho đến khi nhận tín hiệu dừng.


#### **5.3. do-while**

##### **5.3.1. Định nghĩa**

* Vòng lặp `do-while` tương tự `while`, nhưng đảm bảo thân vòng lặp được thực thi ít nhất một lần, với điều kiện kiểm tra sau.

##### **5.3.2. Cú pháp**

        do {
            // Mã thực thi
        } while (điều_kiện);

* Nguyên lý hoạt động:

    ◦ Thân vòng lặp chạy trước, sau đó kiểm tra điều kiện.

    ◦ Nếu điều kiện đúng, lặp tiếp; nếu sai, dừng.

        #include <stdio.h>
        int main() {
            int choice;
            do {
                printf("1. Xem\n2. Sửa\n3. Thoát\nChọn: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1: printf("Đang xem...\n"); break;
                    case 2: printf("Đang sửa...\n"); break;
                    case 3: printf("Thoát\n"); break;
                    default: printf("Lựa chọn không hợp lệ\n");
                }
            } while (choice != 3);
            return 0;
        }

##### **5.3.3. Ứng dụng**

* **Nhập liệu:** Nhập cho đến khi hợp lệ (ví dụ: số dương).

* **Menu lặp:** Hiển thị menu và yêu cầu người dùng chọn đến khi thoát.

##### **5.3.4. Lưu ý**

* Cú pháp yêu cầu dấu `;` sau while.

* Đảm bảo điều kiện được cập nhật để tránh lặp vô hạn.

#### **5.4. Điều khiển vòng lặp**

##### **5.4.1. Định nghĩa**

* Câu lệnh `break` và `continue` điều khiển luồng thực thi trong vòng lặp.

  ◦ **break:** Thoát hoàn toàn khỏi vòng lặp gần nhất (hoặc switch).

  ◦ **continue:** Bỏ qua phần còn lại của lần lặp hiện tại, chuyển sang lần lặp tiếp theo.

##### **5.4.2. Nguyên lý hoạt động**

* **break:** Chuyển điều khiển ra ngoài vòng lặp, kết thúc nó ngay lập tức.

* **continue:** Bỏ qua mã phía sau trong thân vòng, nhưng vẫn kiểm tra điều kiện cho lần lặp tiếp theo.

* **VD1:**

        #include <stdio.h>
        int main() {
            int n = 17, isPrime = 1;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    isPrime = 0;
                    break; // Thoát khi tìm thấy ước
                }
            }
            printf("%d %s số nguyên tố\n", n, isPrime ? "là" : "không phải");
            return 0;
        }

* **VD2:**

        #include <stdio.h>
        int main() {
            for (int i = 1; i <= 10; i++) {
                if (i % 2 != 0) continue; // Bỏ qua số lẻ
                printf("%d ", i); // In: 2 4 6 8 10
            }
            return 0;
        }

### **VI. Hàm**

#### **6.1. Định nghĩa**

##### **6.1.1. Lý thuyết**

* Hàm là một khối mã có tên, nhận đầu vào (tham số), thực hiện xử lý, và có thể trả về một giá trị. Hàm giúp tách biệt logic, tăng tính tái sử dụng và giảm độ phức tạp.

##### **6.1.2. Cú pháp**

        kiểu_trả_về tên_hàm(kiểu_tham_số tham_số_1, kiểu_tham_số tham_số_2, ...) {
            // Mã thực thi
            return giá_trị; // Nếu kiểu_trả_về không phải void
        }

##### **6.1.3. Nguyên lý hoạt động**

* **kiểu_trả_về:** Kiểu dữ liệu của giá trị trả về (int, float, void, v.v.). Nếu là void, hàm không trả về gì.

* **tên_hàm:** Tuân theo quy tắc đặt tên biến (bắt đầu bằng chữ hoặc _, không chứa ký tự đặc biệt).

* **tham_số:** Danh sách tham số đầu vào, có thể rỗng.

* **Prototype:** Khai báo hàm trước khi sử dụng (trong header hoặc đầu file) để trình biên dịch biết cấu trúc hàm.

        #include <stdio.h>
        float rectangle_area(float length, float width) {
            if (length <= 0 || width <= 0) return -1; // Lỗi
            return length * width;
        }
        int main() {
            float area = rectangle_area(5.0, 3.0);
            if (area < 0) {
                printf("Kích thước không hợp lệ\n");
            } else {
                printf("Diện tích: %.2f\n", area); // In: 15.00
            }
            return 0;
        }

##### **6.1.4. Lưu ý**

* Khai báo prototype trong tệp header hoặc trước main nếu hàm định nghĩa sau.

* Tránh hàm quá dài; chia thành các hàm nhỏ hơn.

* Kiểm tra giá trị trả về để xử lý lỗi.

##### **6.1.5. Ứng dụng**

* **Hàm toán học:** Tính giai thừa, tổng, bình phương

* **Xử lý chuỗi:** Sao chép, nối chuỗi.

* **Tổ chức chương trình:** Tách logic giao diện, xử lý dữ liệu.

#### **6.2. Tham số**

##### **6.2.1. Lý thuyết**

* Tham số là cách truyền dữ liệu vào hàm, có hai cơ chế chính: pass-by-value và pass-by-reference.

* **Pass-by-value:**

  ◦ Truyền bản sao giá trị của biến vào hàm.

  ◦ Thay đổi tham số trong hàm không ảnh hưởng biến gốc.

* **Pass-by-reference:**

  ◦ Truyền địa chỉ (con trỏ) của biến.

  ◦ Thay đổi giá trị qua con trỏ ảnh hưởng biến gốc.

##### **6.2.2. Cú pháp**

* **Pass-by-value:** `void func(int x);`

* **Pass-by-reference:** `void func(int *x);`

##### **6.2.3. Nguyên lý hoạt động**

* **Value:** Hàm nhận bản sao, hoạt động độc lập với biến gốc. An toàn nhưng tốn bộ nhớ nếu tham số lớn (như cấu trúc).

* **Reference:** Hàm truy cập trực tiếp địa chỉ bộ nhớ, tiết kiệm bộ nhớ nhưng cần cẩn thận tránh lỗi con trỏ.

        #include <stdio.h>
        void swapByValue(int a, int b) {
            int temp = a; a = b; b = temp;
        }
        void swapByReference(int *a, int *b) {
            int temp = *a; *a = *b; *b = temp;
        }
        int main() {
            int x = 5, y = 10;
            swapByValue(x, y);
            printf("Pass-by-value: x = %d, y = %d\n", x, y); // Không đổi: 5, 10
            swapByReference(&x, &y);
            printf("Pass-by-reference: x = %d, y = %d\n", x, y); // Đổi: 10, 5
            return 0;
        }

##### **6.2.4. Lưu ý**

* Khai báo prototype trong tệp header hoặc trước main nếu hàm định nghĩa sau.

* Tránh hàm quá dài; chia thành các hàm nhỏ hơn.

* Kiểm tra giá trị trả về để xử lý lỗi.

##### **6.2.5. Ứng dụng**

* **Sử dụng const với con trỏ để ngăn sửa đổi:** `void func(const int *x);`.

* Kiểm tra con trỏ NULL trước khi sử dụng.

* Tránh truyền cấu trúc lớn bằng value, thay bằng con trỏ.


#### **6.3. Hàm Đệ quy**

##### **6.3.1. Lý thuyết**

* Hàm đệ quy là hàm tự gọi chính nó để giải quyết một bài toán bằng cách chia nhỏ bài toán thành các bài toán con có dạng tương tự.

* Đệ quy là một kỹ thuật lập trình mạnh mẽ, đặc biệt hữu ích trong các bài toán có cấu trúc lặp lại, như tính giai thừa, dãy Fibonacci, duyệt cây, hoặc các thuật toán chia để trị (divide-and-conquer).

##### **6.3.2. Cấu trúc**

* **Điều kiện dừng (base case):** 

  ◦ Điều kiện để hàm ngừng gọi đệ quy, tránh lặp vô hạn.

  ◦ Nếu không có điều kiện dừng, chương trình sẽ gây lỗi tràn ngăn xếp (stack overflow).

* **Bước đệ quy (recursive case):**

  ◦ Phần mã nơi hàm gọi chính nó với tham số được điều chỉnh để tiến gần hơn đến điều kiện dừng.


##### **6.3.3. Nguyên lý hoạt động**

* Mỗi lần hàm đệ quy được gọi, một bản sao của hàm (cùng với các biến cục bộ) được tạo trên ngăn xếp (call stack).

* Khi điều kiện dừng đạt được, các lần gọi hàm được giải phóng theo thứ tự ngược lại (LIFO - Last In, First Out), trả về kết quả từng bước.

        #include <stdio.h>
        unsigned long long factorial(int n) {
            if (n == 0 || n == 1) return 1; // Điều kiện dừng
            return n * factorial(n - 1);    // Bước đệ quy
        }
        int main() {
            int n = 5;
            printf("Giai thừa của %d là: %llu\n", n, factorial(n)); // In: 120
            return 0;
        }

##### **6.3.4. Lưu ý**

* Luôn đảm bảo có điều kiện dừng rõ ràng.

* Kiểm tra giới hạn của ngăn xếp khi xử lý dữ liệu lớn.

* Có thể tối ưu bằng tail recursion (đệ quy đuôi) nếu trình biên dịch hỗ trợ tối ưu hóa.

* Hiệu suất có thể thấp hơn so với vòng lặp (iterative) trong một số trường hợp.

* Tiêu tốn bộ nhớ ngăn xếp, đặc biệt với các bài toán có độ sâu đệ quy lớn.

* **Tối ưu đệ quy bằng Memoization:**

        #include <stdio.h>
        #define MAX_N 100
        unsigned long long memo[MAX_N] = {0};
        unsigned long long fibonacci_memo(int n) {
            if (n <= 1) return n;
            if (memo[n] != 0) return memo[n]; // Trả về giá trị đã tính
            memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
            return memo[n];
        }
        int main() {
            int n = 6;
            printf("Fibonacci thứ %d là: %llu\n", n, fibonacci_memo(n)); // In: 8
            return 0;
        }

##### **6.3.5. Ứng dụng**

* **Tính toán toán học:** Giai thừa, Fibonacci, tổ hợp.

* **Thuật toán:** Quicksort, mergesort, duyệt cây (DFS).

* **Xử lý cấu trúc đệ quy:** Cây nhị phân, biểu thức toán học.

#### **6.4. Hàm inline**

##### **6.4.1. Lý thuyết**

* `Hàm inline` là một gợi ý cho trình biên dịch chèn trực tiếp mã của hàm vào nơi hàm được gọi, thay vì thực hiện một lời gọi hàm thông thường.

* Điều này giúp giảm chi phí gọi hàm (function call overhead), đặc biệt với các hàm nhỏ và được gọi thường xuyên.


##### **6.4.2. Nguyên lý hoạt động**

* Thông thường, khi gọi hàm, chương trình phải:

  ◦ Lưu trạng thái hiện tại (đẩy các thanh ghi vào ngăn xếp).

  ◦ Chuyển điều khiển đến hàm

  ◦ Thực thi hàm và trả về kết quả

  ◦ Khôi phục trạng thái.

* Với `inline`, mã hàm được chèn trực tiếp vào vị trí gọi, loại bỏ các bước trên, giúp tăng tốc độ thực thi.

* **VD1:**

        #include <stdio.h>
        inline int square(int x) {
            return x * x;
        }
        int main() {
            printf("Bình phương: %d\n", square(5)); // In: 25
            return 0;
        }

* **VD2:**

        #include <stdio.h>
        #include <time.h>
        inline int inline_square(int x) {
            return x * x;
        }
        int normal_square(int x) {
            return x * x;
        }
        int main() {
            clock_t start, end;
            int result = 0;
            start = clock();
            for (int i = 0; i < 1000000; i++) {
                result += inline_square(i);
            }
            end = clock();
            printf("Thời gian inline: %f giây\n", (double)(end - start) / CLOCKS_PER_SEC);

            start = clock();
            for (int i = 0; i < 1000000; i++) {
                result += normal_square(i);
            }
            end = clock();
            printf("Thời gian không inline: %f giây\n", (double)(end - start) / CLOCKS_PER_SEC);
            return 0;
        }

##### **6.4.4. Lưu ý**

* Từ khóa `inline` chỉ là gợi ý, trình biên dịch có thể quyết định không inline nếu không tối ưu.

* Không nên sử dụng inline cho các hàm phức tạp hoặc có vòng lặp lớn.

* Kích thước mã tăng có thể ảnh hưởng đến bộ nhớ cache


##### **6.4.5. Ứng dụng**

* **Các hàm tiện ích nhỏ:** Tính bình phương, lập phương, kiểm tra điều kiện đơn giản.

* Tối ưu hóa hiệu suất trong các ứng dụng thời gian thực hoặc nhúng.

#### **6.5. Static Inline**

##### **6.5.1. Lý thuyết**

* `Hàm static inline` kết hợp hai đặc tính:

  ◦ `static:` Giới hạn phạm vi của hàm trong tệp hiện tại, ngăn hàm được truy cập từ các tệp khác.

  ◦ `inline:` Gợi ý trình biên dịch chèn mã hàm trực tiếp, tối ưu hóa hiệu suất.

##### **6.5.2. Nguyên lý hoạt động**

* Tương tự hàm `inline`, nhưng thêm thuộc tính `static` để đảm bảo hàm chỉ được sử dụng trong phạm vi tệp biên dịch, tránh xung đột tên với các tệp khác.

* Trình biên dịch có thể tạo một bản sao mã hàm trong tệp hiện tại mà không cần liên kết (linking) với các tệp khác.

* **VD1:**

        #include <stdio.h>
        static inline int cube(int x) {
            return x * x * x;
        }
        int main() {
            printf("Lập phương: %d\n", cube(3)); // In: 27
            return 0;
        }

* **VD2:**

   ◦ Tệp `utils.h`

        #ifndef UTILS_H
        #define UTILS_H
        static inline int cube(int x) {
            return x * x * x;
        }
        #endif

   ◦ Tệp `main.c`

        #include <stdio.h>
        #include "utils.h"
        int main() {
            printf("Lập phương: %d\n", cube(4)); // In: 64
            return 0;
        }

##### **6.5.3. Lưu ý**

* Trình biên dịch có thể bỏ qua `inline` nếu hàm quá phức tạp.

* `static inline` thường được dùng trong các tệp header để đảm bảo tính đóng gói.


##### **6.5.4. Ứng dụng**

* Tối ưu hóa các hàm tiện ích nội bộ trong các hệ thống nhúng.

* Sử dụng trong các thư viện hoặc mã nguồn lớn để tránh xung đột.

#### **6.6. Variadic Functions**

##### **6.6.1. Lý thuyết**

* Hàm variadic (hàm với số lượng tham số biến đổi) cho phép truyền vào một số lượng tham số không cố định.

* Trong C, điều này được thực hiện bằng cách sử dụng thư viện `<stdarg.h>`, cung cấp các macro để xử lý danh sách tham số.

##### **6.6.2. Cấu trúc và macro chính**

  ◦ `va_list`: Kiểu dữ liệu lưu danh sách tham số biến đổi.

  ◦ `va_start(ap, last)`: Khởi tạo danh sách tham số, với last là tham số cố định cuối cùng.

  ◦ `va_arg(ap, type)`: Lấy tham số tiếp theo, chỉ định kiểu dữ liệu (int, double, v.v.).

  ◦ `va_end(ap)`: Kết thúc xử lý danh sách tham số, giải phóng tài nguyên.

##### **6.6.3. Nguyên lý hoạt động**

* Hàm variadic cần ít nhất một tham số cố định để xác định số lượng hoặc kiểu của các tham số biến đổi.

* Các tham số được lưu trữ liên tiếp trong bộ nhớ, và `va_arg` truy cập chúng theo thứ tự.

* Trình biên dịch không kiểm tra kiểu hoặc số lượng tham số, nên lập trình viên phải tự đảm bảo tính chính xác.

* **VD1:**

        #include <stdio.h>
        #include <stdarg.h>
        int sum(int count, ...) {
            va_list ap;
            va_start(ap, count);
            int total = 0;
            for (int i = 0; i < count; i++) {
                total += va_arg(ap, int);
            }
            va_end(ap);
            return total;
        }
        int main() {
            printf("Tổng: %d\n", sum(4, 1, 2, 3, 4)); // In: 10
            return 0;
        }

* **VD2:**

        #include <stdio.h>
        #include <stdarg.h>
        double average(int count, ...) {
            va_list ap;
            va_start(ap, count);
            double total = 0;
            for (int i = 0; i < count; i++) {
                total += va_arg(ap, double);
            }
            va_end(ap);
            return count > 0 ? total / count : 0;
        }
        int main() {
            printf("Trung bình: %.2f\n", average(3, 1.5, 2.5, 3.5)); // In: 2.50
            return 0;
        }

##### **6.6.4. Lưu ý**

* Luôn sử dụng tham số cố định để xác định số lượng tham số biến đổi (ví dụ: `count` trong hàm sum).

* Kiểm tra kỹ kiểu dữ liệu khi dùng `va_arg`.

* Không gọi `va_arg` quá số lượng tham số thực tế, sẽ gây lỗi.


##### **6.6.4. Ứng dụng**

* **Hàm xuất/nhập chuẩn:** printf, scanf.

* **Hàm xử lý tổng hợp:** Tính tổng, trung bình, hoặc xử lý danh sách tham số.

#### **6.7. Assert**

##### **6.7.1. Lý thuyết**

* `assert` là một macro trong thư viện `<assert.h>`, dùng để kiểm tra điều kiện tại thời điểm chạy chương trình. 

* Nếu điều kiện sai, chương trình sẽ dừng và in thông báo lỗi, bao gồm tên tệp, dòng mã, và thông điệp tùy chỉnh.


##### **6.7.2. Nguyên lý hoạt động**

* Macro `assert(expr)` kiểm tra biểu thức expr.

* Nếu `expr` trả về `0` (sai), chương trình dừng và in thông báo lỗi.

* Nếu `expr` trả về `khác 0` (đúng), chương trình tiếp tục chạy.

* Để tắt `assert`, định nghĩa macro `NDEBUG` trước khi bao gồm `<assert.h>`.

##### **6.7.3. Cú pháp**

        #include <assert.h>
        assert(biểu_thức && "Thông điệp lỗi");

* **VD1:**

        #include <stdio.h>
        #include <assert.h>
        void check_positive(int x) {
            assert(x > 0 && "Số phải dương");
            printf("Số hợp lệ: %d\n", x);
        }
        int main() {
            check_positive(5);  // Chạy bình thường
            check_positive(-1); // Gây lỗi, chương trình dừng
            return 0;
        }

* **VD2:**

        #include <stdio.h>
        #include <assert.h>
        void print_array(int *arr, int size) {
            assert(arr != NULL && "Mảng không được NULL");
            assert(size > 0 && "Kích thước phải dương");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        int main() {
            int arr[] = {1, 2, 3};
            print_array(arr, 3); // In: 1 2 3
            print_array(NULL, 3); // Gây lỗi
            return 0;
        }

* **VD3:**

        #define NDEBUG
        #include <assert.h>
        #include <stdio.h>
        void check_positive(int x) {
            assert(x > 0 && "Số phải dương"); // Bị bỏ qua
            printf("Số hợp lệ: %d\n", x);
        }
        int main() {
            check_positive(-1); // Không gây lỗi, tiếp tục chạy
            return 0;
        }

##### **6.7.4. Lưu ý**

* Chỉ sử dụng `assert` cho các điều kiện được giả định luôn đúng trong mã.

* Không sử dụng `assert` cho xử lý lỗi người dùng (dùng if-else thay thế).

* Tránh đặt các lệnh có tác dụng phụ (side effects) trong `assert`, vì chúng sẽ bị bỏ qua khi `NDEBUG` được định nghĩa.


##### **6.7.5. Ứng dụng**

* **Kiểm tra đầu vào:** Đảm bảo tham số hợp lệ (ví dụ: số dương, con trỏ không NULL).

* **Kiểm tra trạng thái:** Xác minh trạng thái chương trình trước khi thực thi.

* **Gỡ lỗi:** Phát hiện lỗi logic trong mã.




</details>
