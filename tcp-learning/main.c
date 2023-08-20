#include <stdio.h>
#include <string.h>

#include "mongoose.h"


void ev_handler_functon()
{
    return;
}

struct mg_mgr mg;
mg_mgr_init(&mg, NULL);
struct mg_connection *c = mg_bind(&mgr, "80", ev_handler_functon);

for (;;){
    mg_mgr_poll(&mgr, 1000);
}


int main(int argc, char *argv[]){
    for (int i = 0; i < argc; i++)
    {
        printf("arg%d-->%s\n", i, argv[i]);
    }
    return 0;
}
