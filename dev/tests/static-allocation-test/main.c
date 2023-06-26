#include<stdio.h>
#include<math.h>
#include<string.h>

#define size 1000000000u
static char memtest[size];

void main(){
    memset(memtest, 5, size);

    register char *start, *index = &memtest[900000000];
    start = index;

    *(index++) = 'h';
    *(index++) = 'e';
    *(index++) = 'l';
    *(index++) = 'l';
    *(index++) = 'o';
    *(index++) = '\n';
    *(index++) = 0;

    printf(start);
    getchar();
}