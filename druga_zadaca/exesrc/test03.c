#include <stdio.h>
#include "../inc/cmplx.h"


int main (){

    double mag;
    cmplx_t a;
    a[0]=1;
    a[1]=1;
    mag=cmplx_mag(a);
    
    printf("%f", mag);

    return 0;
}
