# =================================================
# Makefile chung cho nhiều bài Ex1, Ex2, ...
# Có thể dùng trực tiếp khi cd vào folder bất kỳ
# make -f ../makefile
# =================================================

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

# --------------------------
# Xác định thư mục bài tập
# --------------------------
# Phát hiện xem đang chạy từ thư mục con hay thư mục gốc
ifneq ($(wildcard *.c),)
    # Đang ở thư mục con Ex* (có file .c trong thư mục hiện tại)
    FOLDER := .
    TARGET := $(notdir $(CURDIR)).exe
else
    # Đang ở thư mục gốc Chapter1
    FOLDER ?= Ex1
    TARGET := $(FOLDER).exe
endif

# --------------------------
# Tập tin nguồn & object
# --------------------------
SOURCES := $(wildcard $(FOLDER)/*.c)
OBJECTS := $(SOURCES:.c=.o)

$(info Building in folder: $(FOLDER))
$(info Sources: $(SOURCES))
$(info Target: $(TARGET))

# --------------------------
# Rule chính
# --------------------------
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "✔ Build xong $(TARGET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Chạy chương trình
run: $(TARGET)
	./$(TARGET)

# Dọn file tạm
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "✔ Đã xóa các file tạm"

.PHONY: all run clean