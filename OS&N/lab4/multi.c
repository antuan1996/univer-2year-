#include <stdio.h>
#include <pthread.h>
#include <math.h>
double f(double x)
{
    return (x-2.)*(x-2.);
}
void* func(void* fname)
{
    FILE* f1 = fopen((char*)fname,"r");
    float  lb,rb, eps;
    fscanf(f1,"%f %f %f",&lb, &rb, &eps);
    fclose(f1);
    printf("Input = %f:%f  eps = %f ", lb, rb,eps);
    while(fabs(rb - lb) > eps)
    {
        double sep1 = lb + (rb - lb )/ 3.;
        double sep2 = lb + 2 * (rb - lb )/ 3.;
        if( f(sep1) > f(sep2))
            lb = sep1;
        else
            rb = sep2;
    } 
    printf("answer = %f\n",lb);
    return 0;
}
int main(int argc, char **argv)
{
    //printf("%d\n", argc);
    pthread_t tid[argc - 1];
    for(int i = 0; i < argc - 1; ++i)
    {
        pthread_create(tid + i, NULL, func, (void* )argv[i + 1]);
    }
    for(int i = 0; i < argc - 1; ++i)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}

