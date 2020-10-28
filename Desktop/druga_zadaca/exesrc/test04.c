#include <stdio.h>
#include "../inc/cmplx.h"

int main (){

    double phs;
    cmplx_t a;
    a[0]=1;
    a[1]=1;
    phs=cmplx_phs(a);
    printf("%f", phs);

    return 0;
}



