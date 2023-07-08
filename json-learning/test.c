#include <stdio.h>
#include <string.h>

#include "cJSON.h"

const char *json_data = "{\"key1\":1, \"key2\":[1,2,3,\"4\"], \"key3\":{\"name\":\"xixi\", \"age\":18}}";

void read_json(cJSON *root)
{
    if (root == NULL) return;

    switch (root->type)
    {
        case cJSON_Object:
            cJSON *child = root->child;
            if (child != NULL)
            {
                read_json(child);
                child = child->next;
            }
            break;
        case cJSON_Array:
            {
                int array_size = cJSON_GetArraySize(root);
                for (int i = 0; i < array_size; i++)
                {
                    cJSON *item = cJSON_GetArrayItem(root, i);
                    read_json(item);
                }
            }
            break;
        case cJSON_String:
            printf("%s\n", root->valuestring);
            break;
        case cJSON_Number:
            if ((root->valueint - root->valuedouble) != 0)
            {
                printf("%lf\n", root->valuedouble);
            }
            else
            {
                printf("%d\n", root->valueint);
            }
            break;
        case cJSON_True:
            break;
        case cJSON_False:
            break;
        case cJSON_NULL:
            break;
        default:
            break;
    }
    return;
}

int main(){
    cJSON *root = cJSON_Parse(json_data);
    read_json(root);
    cJSON_Delete(root);

    return 0;
}