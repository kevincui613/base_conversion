# Makefile for Base Conversion Project
# Supports Windows (MinGW) and Linux

CC = gcc
CFLAGS = -Wall -Wextra -g -O2
INCLUDE_DIR = -Iinclude
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/converter

# 源文件和目标文件
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# 默认目标
all: $(TARGET)

# 创建输出目录
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJDIR) $(BINDIR) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	@echo "? 编译完成: $@"

# 编译源文件为目标文件
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
	@echo "? 编译: $<"

# 清理构建文件
clean:
	@rm -rf $(OBJDIR) $(BINDIR)
	@echo "? 清理完成"

# 运行程序
run: all
	$(TARGET)

# 重新构建
rebuild: clean all

# 帮助信息
help:
	@echo "====== Base Conversion Project ======"
	@echo "可用的 make 命令:"
	@echo "  make all     - 编译项目"
	@echo "  make clean   - 清理构建文件"
	@echo "  make run     - 编译并运行"
	@echo "  make rebuild - 重新构建"
	@echo "  make help    - 显示此帮助信息"
	@echo "======================================"

.PHONY: all clean run rebuild help
