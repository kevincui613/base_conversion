#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdint.h>

/* 数据结构：存储各进制转换结果 */
typedef struct {
    char binary_original[33];    /* 二进制原码 */
    char binary_ones[33];        /* 二进制反码 */
    char binary_twos[33];        /* 二进制补码 */
    char hexadecimal[11];        /* 十六进制数 */
    char octal[12];              /* 八进制数 */
} ConversionResult;

/* 
 * 函数：十进制数转换为各进制
 * 参数：
 *   decimal - 输入的十进制整数
 *   result - 输出结果结构体指针
 * 返回值：成功返回0，失败返回-1
 */
int convert_decimal(int32_t decimal, ConversionResult *result);

/*
 * 函数：将十进制转换为二进制原码
 * 参数：
 *   num - 输入的十进制数
 *   buffer - 存放二进制原码的缓冲区
 *   size - 缓冲区大小
 * 返回值：二进制字符串长度
 */
int decimal_to_binary_original(int32_t num, char *buffer, int size);

/*
 * 函数：根据原码得到反码
 * 参数：
 *   original - 原码字符串
 *   ones - 存放反码的缓冲区
 * 返回值：反码字符串长度
 */
int binary_ones_complement(const char *original, char *ones);

/*
 * 函数：根据反码得到补码（反码+1）
 * 参数：
 *   ones - 反码字符串
 *   twos - 存放补码的缓冲区
 * 返回值：补码字符串长度
 */
int binary_twos_complement(const char *ones, char *twos);

/*
 * 函数：十进制转十六进制
 * 参数：
 *   num - 输入的十进制数
 *   buffer - 存放十六进制的缓冲区
 *   size - 缓冲区大小
 * 返回值：十六进制字符串长度
 */
int decimal_to_hexadecimal(int32_t num, char *buffer, int size);

/*
 * 函数：十进制转八进制
 * 参数：
 *   num - 输入的十进制数
 *   buffer - 存放八进制的缓冲区
 *   size - 缓冲区大小
 * 返回值：八进制字符串长度
 */
int decimal_to_octal(int32_t num, char *buffer, int size);

/*
 * 函数：打印转换结果
 * 参数：
 *   decimal - 原始十进制数
 *   result - 转换结果结构体
 */
void print_conversion_result(int32_t decimal, const ConversionResult *result);

#endif /* CONVERTER_H */
