#include "../Include/fileOperate.h"

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
    return 0;
}