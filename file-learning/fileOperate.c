#include <stdio.h>
#include <stdlib.h>

#include "fileOperate.h"

int readFile(char *filename, char *mode){
    // 打开文件
    FILE *fp = fopen(filename, mode);
    char str[N + 1];

    // 判断文件是否打开失败
    if(fp == NULL){
        printf("文件打开失败，请检查文件是否存在！");
        return 1;
        exit(0);
    }

    // 输出文件内容
    while(fgets(str, N, fp) != NULL){
        printf("%s", str);
    }

    fclose(fp);
    return 0;
}

int readChar(char *filename, char *mode){
    FILE *fp = fopen(filename, mode);
    char ch;
    if(fp == NULL){
        puts("这文件找不到啊，闹呢？");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }
    putchar('\n');

    fclose(fp);
    puts("over~");

    return 0;

}

int add_message(char *filename, char *mode, char *message)
{
    FILE *fp = fopen(filename, mode);
    fprintf(fp, "你好%s\n", message);
    return 0;
}
