#include <stdio.h>
#include <string.h>

#include "cJSON.h"

int main(){
    int stat = 0;
    const char *pstr = {"{\"name\":\"xixi\",\"age\":16}"};

    puts(pstr);

    // parse json string
    cJSON *root = cJSON_Parse(pstr);
    if (!root)
    {
        printf("error:%s", cJSON_GetErrorPtr());
        stat = -1;
        goto done;
    }


// 老版本的元素类型判别方式
#if 0

    // get json element
    cJSON *element = cJSON_GetObjectItem(root, "name");
    if (element->type == cJSON_String)
    {
        printf("name==>%s\n", element->valuestring);
    }
    element = cJSON_GetObjectItem(root, "age");
    if (element->type == cJSON_Number)
    {
        printf("age==>%d\n", element->valueint);
    }

#endif

    // 新版本的元素类型判别方式
    cJSON *element = cJSON_GetObjectItem(root, "name");
    if (cJSON_IsString(element))
    {
        printf("name is %s\n", element->valuestring);
    }

    element = cJSON_GetObjectItem(root, "age");
    if (cJSON_IsNumber(element))
    {
        printf("age is %d\n", element->valueint);
    }

    // 数组数据的解析方式
    const char *array_str = "[0, 1, 1, \"0\"]";
    cJSON *array_data = cJSON_Parse(array_str);
    if (array_data == NULL)
    {
        printf("%s",cJSON_GetErrorPtr());
        stat = -1;
        goto done;
    }
    if (cJSON_IsArray(array_data))
    {
        int array_size = cJSON_GetArraySize(array_data);
        printf("array size %d\n", array_size);
        for (int i = 0; i < array_size; i++)
        {
            cJSON *value = cJSON_GetArrayItem(array_data, i);
            if (cJSON_IsNumber(value))
            {
                printf("prot%d: %d\n", i+1, value->valueint);
            }
            if (cJSON_IsString(value))
            {
                printf("prot%d: %s\n", i+1, value->valuestring);
            }
        }
    }

    // 读取带键的二维数组
    char *array_2d_str = "{\"array\":[[1, 0, 0 , 1],[1, 0, 8]]}";
    puts(array_2d_str);
    cJSON *array_2d_data = cJSON_Parse(array_2d_str);
    cJSON *data_2d = cJSON_GetObjectItem(array_2d_data, "array");
    int rows = cJSON_GetArraySize(data_2d);
    puts("===============================");
    puts("\tcol1\tcol2\tcol3\tcol4");
    for (int i = 0; i < rows; i++)
    {
        printf("raw%d\t", i);
        cJSON *values = cJSON_GetArrayItem(data_2d, i);
        int cols = cJSON_GetArraySize(values);
        for (int j = 0; j < cols; j++)
        {
            printf("data%d\t", cJSON_GetArrayItem(values, j)->valueint);
        }
        putchar('\n');
    }
    puts("===============================");


done:
    puts("start free ~");
    cJSON_Delete(root);
    cJSON_Delete(array_data);
    cJSON_Delete(array_2d_data);
    puts("over~\nGoodbye");
    return stat;
}