#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* i = malloc(sizeof(int));
    *i = 10;
    printf("%d\n", *i);
    return 0;
}
