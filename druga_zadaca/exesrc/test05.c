#include <stdio.h>
#include "../inc/cmplx.h"

int main (){

    double real_part,mag,phase;
    cmplx_t a;
    a[0]=1;
    a[1]=1;
    mag=cmplx_mag(a);
    phase=cmplx_phs(a);
    real_part=cmplx_real(mag,phase);
    printf("%f", real_part);

    return 0;
}

