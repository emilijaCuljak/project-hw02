#include <stdio.h>
#include "../inc/cmplx.h"

int main (){

    double imag_part,mag,phase;
    cmplx_t a;
    a[0]=1;
    a[1]=5;
    mag=cmplx_mag(a);
    phase=cmplx_phs(a);
    imag_part=cmplx_imag(mag,phase);
    printf("%f", imag_part);

    return 0;
}


