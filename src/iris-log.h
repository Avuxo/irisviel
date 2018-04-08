#include <stdio.h>
#include <stdlib.h>

void iris_log(char *note){ printf("[NOTE] %s\n", note);}
void iris_error(char *err){ fprintf(stderr, "[ERROR] %s\n", err); }
void iris_fatalError(char *err){
    fprintf(stderr, "[FATAL ERROR] %s\n", err);
    exit(1);
}
