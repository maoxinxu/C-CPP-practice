#include <stdio.h>

#include "fileOperate.h"

int __init__(){
    puts("init start~");
    puts("init sucdessfull!");
    return 0;
}

int main(){
    __init__();
    // readFile("老师学生和家长.txt", "r");
    readChar("老师学生和家长.txt", "r");
    puts("已经完事啦~");

    add_message("test.txt", "a+", "4455");
    return 0;
}