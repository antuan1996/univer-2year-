#include <stdio.h>
#include <pthread.h>
#include <math.h>

int main(int argc, char **argv)
{

    int a,b;
    scanf("%d %d",&a, &b);
    int mod = a / b;
    int div = a % b;
    printf("%d %d", mod, div);
    return 0;
}

