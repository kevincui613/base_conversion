#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"

/* 函数声明 */
void display_menu(void);
int get_user_input(void);
void process_conversion(int32_t decimal);

/*
 * 主函数：程序入口
 */
int main(int argc, char **argv)
{
    /* 非交互自测开关：传入 --selftest 将直接输出 -314156 的转换结果并退出 */
    if (argc == 2 && strcmp(argv[1], "--selftest") == 0) {
        process_conversion(-314156);
        return 0;
    }
    int choice;
    int32_t decimal;

    printf("\n");
    printf("╔═══════════════════════════════════════╗\n");
    printf("║     十进制进制转换工具 v1.0          ║\n");
    printf("║  (Binary/Hex/Octal Converter)        ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    while (1) {
        display_menu();
        choice = get_user_input();

        switch (choice) {
            case 1:
                printf("\n请输入一个十进制整数: ");
                scanf("%d", &decimal);
                process_conversion(decimal);
                break;

            case 2:
                printf("\n【使用说明】\n");
                printf("1. 输入一个十进制整数\n");
                printf("2. 程序将输出该数的以下转换结果：\n");
                printf("   - 二进制原码：符号位(0/1) + 数值位\n");
                printf("   - 二进制反码：负数各位取反（符号位不变）\n");
                printf("   - 二进制补码：反码+1（用于计算机内部存储）\n");
                printf("   - 十六进制数：0-9, a-f表示\n");
                printf("   - 八进制数：0-7表示\n\n");
                break;

            case 3:
                printf("\n【示例】\n");
                printf("示例1：输入 5\n");
                process_conversion(5);

                printf("示例2：输入 -5\n");
                process_conversion(-5);

                printf("示例3：输入 255\n");
                process_conversion(255);
                break;

            case 4:
                printf("\n感谢使用！再见。\n\n");
                return 0;

            default:
                printf("\n❌ 无效选择，请重新输入！\n\n");
        }
    }

    return 0;
}

/*
 * 显示菜单
 */
void display_menu(void)
{
    printf("\n┌─────────────────────────────┐\n");
    printf("│       主菜单                  │\n");
    printf("├─────────────────────────────┤\n");
    printf("│ 1. 转换十进制数              │\n");
    printf("│ 2. 查看使用说明              │\n");
    printf("│ 3. 查看示例                  │\n");
    printf("│ 4. 退出程序                  │\n");
    printf("└─────────────────────────────┘\n");
    printf("请选择 (1-4): ");
}

/*
 * 获取用户输入
 */
int get_user_input(void)
{
    int input;
    if (scanf("%d", &input) != 1) {
        while (getchar() != '\n');  /* 清空输入缓冲区 */
        return -1;
    }
    return input;
}

/*
 * 处理转换操作
 */
void process_conversion(int32_t decimal)
{
    ConversionResult result;

    /* 执行转换 */
    if (convert_decimal(decimal, &result) != 0) {
        printf("❌ 转换失败！\n");
        return;
    }

    /* 显示结果 */
    print_conversion_result(decimal, &result);
}
