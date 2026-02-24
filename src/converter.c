#include "converter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 业务逻辑：十进制转换为二进制原码
 * 原码：符号位+数值位，正数符号位为0，负数符号位为1
 */
int decimal_to_binary_original(int32_t num, char *buffer, int size)
{
    if (!buffer || size < 33) {
        return -1;
    }

    int pos = 0;
    
    /* 设置符号位 */
    if (num < 0) {
        buffer[pos++] = '1';
        num = -num;  /* 取绝对值 */
    } else {
        buffer[pos++] = '0';
    }

    /* 对于32位表示，数值位固定31位 */
    for (int i = 30; i >= 0; i--) {
        buffer[pos++] = ((num >> i) & 1) ? '1' : '0';
    }

    buffer[pos] = '\0';
    return pos;
}

/*
 * ҵ���߼�������ԭ����㷴��
 * ���룺�����ķ��������ԭ�룻�����ķ���������ԭ��Ļ����ϣ�����λ���䣬�����λ��λȡ��
 */
int binary_ones_complement(const char *original, char *ones)
{
    if (!original || !ones) {
        return -1;
    }

    int len = strlen(original);
    strcpy(ones, original);

    /* �������λΪ1����������������λȡ�� */
    if (original[0] == '1') {
        for (int i = 1; i < len; i++) {
            ones[i] = (original[i] == '0') ? '1' : '0';
        }
    }

    return len;
}

/*
 * ҵ���߼������ݷ�����㲹��
 * ���룺�����Ĳ��������ԭ�룻�����Ĳ��������䷴��Ļ����ϼ�1
 */
int binary_twos_complement(const char *ones, char *twos)
{
    if (!ones || !twos) {
        return -1;
    }

    int len = strlen(ones);
    strcpy(twos, ones);

    /* �������λΪ1��������������+1�õ����� */
    if (ones[0] == '1') {
        /* �����λ��ʼִ��+1���� */
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
 * ҵ���߼���ʮ����תʮ������
 */
int decimal_to_hexadecimal(int32_t num, char *buffer, int size)
{
    if (!buffer || size < 3) {
        return -1;
    }

    int pos = 0;
    int is_negative = num < 0;

    /* �����������ò�����ʽ��ʾ */
    if (is_negative) {
        buffer[pos++] = '-';
        num = -num;
    }

    if (num == 0) {
        buffer[pos++] = '0';
        buffer[pos] = '\0';
        return pos;
    }

    /* ��ʱ�洢ʮ���������� */
    char temp[20];
    int temp_len = 0;

    while (num > 0) {
        int digit = num % 16;
        temp[temp_len++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        num /= 16;
    }

    /* ������仺���� */
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
 * ҵ���߼���ʮ����ת�˽���
 */
int decimal_to_octal(int32_t num, char *buffer, int size)
{
    if (!buffer || size < 3) {
        return -1;
    }

    int pos = 0;
    int is_negative = num < 0;

    /* �������� */
    if (is_negative) {
        buffer[pos++] = '-';
        num = -num;
    }

    if (num == 0) {
        buffer[pos++] = '0';
        buffer[pos] = '\0';
        return pos;
    }

    /* ��ʱ�洢�˽������� */
    char temp[30];
    int temp_len = 0;

    while (num > 0) {
        temp[temp_len++] = '0' + (num % 8);
        num /= 8;
    }

    /* ������仺���� */
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
 * ��ת����������������ת���߼�
 */
int convert_decimal(int32_t decimal, ConversionResult *result)
{
    if (!result) {
        return -1;
    }

    /* ת��Ϊ������ԭ�� */
    if (decimal_to_binary_original(decimal, result->binary_original, 33) < 0) {
        return -1;
    }

    /* ����ԭ����㷴�� */
    if (binary_ones_complement(result->binary_original, result->binary_ones) < 0) {
        return -1;
    }

    /* ���ݷ�����㲹�� */
    if (binary_twos_complement(result->binary_ones, result->binary_twos) < 0) {
        return -1;
    }

    /* ת��Ϊʮ������ */
    if (decimal_to_hexadecimal(decimal, result->hexadecimal, 11) < 0) {
        return -1;
    }

    /* ת��Ϊ�˽��� */
    if (decimal_to_octal(decimal, result->octal, 12) < 0) {
        return -1;
    }

    return 0;
}

/*
 * �����������ʽ����ʾ����ת�����
 */
void print_conversion_result(int32_t decimal, const ConversionResult *result)
{
    printf("\n========== ����ת����� ==========\n");
    printf("����ʮ������: %d\n\n", decimal);

    printf("�������Ʊ�ʾ��\n");
    printf("  ԭ��:  %s\n", result->binary_original);
    printf("  ����:  %s\n", result->binary_ones);
    printf("  ����:  %s\n\n", result->binary_twos);

    printf("���������Ʊ�ʾ��\n");
    printf("  ʮ������: %s\n", result->hexadecimal);
    printf("  �˽���:   %s\n", result->octal);
    printf("==================================\n\n");
}
