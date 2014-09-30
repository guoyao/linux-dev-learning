#include <stdio.h>
#include <stdlib.h>

#define __STDC_WANT_LIB_EXT1__ 1

#include <string.h>

int main(void) {
    #if defined __STDC_LIB_EXT1__
        printf("Optional functions are defined.\n");
    #else
        printf("Optional functions are not defined.\n");
    #endif

    char str[5] = "hello";
 //   printf("%d\n", strnlen_s(str, sizeof(str)));
    return 0;
}
