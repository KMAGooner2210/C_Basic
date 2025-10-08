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
