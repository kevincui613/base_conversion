#include "converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 业务逻辑：十进制转二进制原码
 * 原码：符号位+数值位，正数符号位为0，负数符号位为1
 */
int decimal_to_binary_original(int32_t num, char *buffer, int size)
{
    if (!buffer || size < 2) {
        return -1;
    }

    int pos = 0;
    
    /* 处理符号位 */
    if (num < 0) {
        buffer[pos++] = '1';
        num = -num;  /* 取绝对值 */
    } else {
        buffer[pos++] = '0';
    }

    /* 处理数值位：从高位到低位转换 */
    if (num == 0) {
        if (pos + 1 < size) {
            buffer[pos++] = '0';
            buffer[pos] = '\0';
            return pos;
        }
        return -1;
    }

    /* 提取二进制位 */
    int bits = 0;
    int temp = num;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }

    /* 确保缓冲区足够 */
    if (pos + bits >= size) {
        return -1;
    }

    /* 从最高位到最低位填充缓冲区 */
    for (int i = bits - 1; i >= 0; i--) {
        buffer[pos++] = ((num >> i) & 1) ? '1' : '0';
    }

    buffer[pos] = '\0';
    return pos;
}

/*
 * 业务逻辑：根据原码计算反码
 * 反码：正数的反码等于其原码；负数的反码是在其原码的基础上，符号位不变，其余各位按位取反
 */
int binary_ones_complement(const char *original, char *ones)
{
    if (!original || !ones) {
        return -1;
    }

    int len = strlen(original);
    strcpy(ones, original);

    /* 如果符号位为1（负数），则其他位取反 */
    if (original[0] == '1') {
        for (int i = 1; i < len; i++) {
            ones[i] = (original[i] == '0') ? '1' : '0';
        }
    }

    return len;
}

/*
 * 业务逻辑：根据反码计算补码
 * 补码：正数的补码等于其原码；负数的补码是在其反码的基础上加1
 */
int binary_twos_complement(const char *ones, char *twos)
{
    if (!ones || !twos) {
        return -1;
    }

    int len = strlen(ones);
    strcpy(twos, ones);

    /* 如果符号位为1（负数），则反码+1得到补码 */
    if (ones[0] == '1') {
        /* 从最低位开始执行+1操作 */
        int carry = 1;
        for (int i = len - 1; i >= 1 && carry; i--) {
            if (twos[i] == '0') {
                twos[i] = '1';
                carry = 0;
            } else {
                twos[i] = '0';
            }
        }
    }

    return len;
}

/*
 * 业务逻辑：十进制转十六进制
 */
int decimal_to_hexadecimal(int32_t num, char *buffer, int size)
{
    if (!buffer || size < 3) {
        return -1;
    }

    int pos = 0;
    int is_negative = num < 0;

    /* 处理负数：用补码形式表示 */
    if (is_negative) {
        buffer[pos++] = '-';
        num = -num;
    }

    if (num == 0) {
        buffer[pos++] = '0';
        buffer[pos] = '\0';
        return pos;
    }

    /* 临时存储十六进制数字 */
    char temp[20];
    int temp_len = 0;

    while (num > 0) {
        int digit = num % 16;
        temp[temp_len++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        num /= 16;
    }

    /* 反序填充缓冲区 */
    if (pos + temp_len >= size) {
        return -1;
    }

    for (int i = temp_len - 1; i >= 0; i--) {
        buffer[pos++] = temp[i];
    }

    buffer[pos] = '\0';
    return pos;
}

/*
 * 业务逻辑：十进制转八进制
 */
int decimal_to_octal(int32_t num, char *buffer, int size)
{
    if (!buffer || size < 3) {
        return -1;
    }

    int pos = 0;
    int is_negative = num < 0;

    /* 处理负数 */
    if (is_negative) {
        buffer[pos++] = '-';
        num = -num;
    }

    if (num == 0) {
        buffer[pos++] = '0';
        buffer[pos] = '\0';
        return pos;
    }

    /* 临时存储八进制数字 */
    char temp[30];
    int temp_len = 0;

    while (num > 0) {
        temp[temp_len++] = '0' + (num % 8);
        num /= 8;
    }

    /* 反序填充缓冲区 */
    if (pos + temp_len >= size) {
        return -1;
    }

    for (int i = temp_len - 1; i >= 0; i--) {
        buffer[pos++] = temp[i];
    }

    buffer[pos] = '\0';
    return pos;
}

/*
 * 主转换函数：整合所有转换逻辑
 */
int convert_decimal(int32_t decimal, ConversionResult *result)
{
    if (!result) {
        return -1;
    }

    /* 转换为二进制原码 */
    if (decimal_to_binary_original(decimal, result->binary_original, 33) < 0) {
        return -1;
    }

    /* 根据原码计算反码 */
    if (binary_ones_complement(result->binary_original, result->binary_ones) < 0) {
        return -1;
    }

    /* 根据反码计算补码 */
    if (binary_twos_complement(result->binary_ones, result->binary_twos) < 0) {
        return -1;
    }

    /* 转换为十六进制 */
    if (decimal_to_hexadecimal(decimal, result->hexadecimal, 11) < 0) {
        return -1;
    }

    /* 转换为八进制 */
    if (decimal_to_octal(decimal, result->octal, 12) < 0) {
        return -1;
    }

    return 0;
}

/*
 * 输出函数：格式化显示所有转换结果
 */
void print_conversion_result(int32_t decimal, const ConversionResult *result)
{
    printf("\n========== 进制转换结果 ==========\n");
    printf("输入十进制数: %d\n\n", decimal);

    printf("【二进制表示】\n");
    printf("  原码:  %s\n", result->binary_original);
    printf("  反码:  %s\n", result->binary_ones);
    printf("  补码:  %s\n\n", result->binary_twos);

    printf("【其他进制表示】\n");
    printf("  十六进制: %s\n", result->hexadecimal);
    printf("  八进制:   %s\n", result->octal);
    printf("==================================\n\n");
}
