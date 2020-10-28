#include "../inc/cmplx.h"
#include <stdio.h>
#include <math.h>

//a/b
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c){
    c[0]=(a[0]*b[0]+a[1]+b[1])/(b[0]*b[0]+b[1]*b[1]);
    c[1]=(a[1]*b[0]-a[0]*b[1])/(b[0]*b[0]+b[1]*b[1]);
}

//a*b
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c){
    c[0]=a[0]*b[0]-a[1]*b[1];
    c[1]=a[0]*b[1]+a[1]*b[0];
}

// returns |a|
double cmplx_mag(cmplx_t a){
    double mag;
    mag = sqrt(a[0]*a[0]+a[1]*a[1]);
    return mag;
}

// returns phase in radians of a 
double cmplx_phs(cmplx_t a){
    double phs;
    phs=atan2(a[1],a[0]);
    return phs;
}

// returns real part of mag/_phs
double cmplx_real(double mag, double phs){
    return (cos(phs)*mag);

}

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs){
    if (phs<0.0){
        return (-1*(sin(phs)*mag));
    }
    else{ 
         return (sin(phs)*mag);
    }
   
}

// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
    int k,t;
    double phase,real_part,im_part;
    cmplx_t e,product,sum;
    for(k=0;k<N;k++){
        sum[0]=0;
        sum[1]=0;
        for(t=0;t<N;t++){
            phase=-2*3.141592654*t*k/N;
            real_part=cmplx_real(1.0,phase);
            im_part=cmplx_imag(1.0,phase);
            e[0]=real_part;
            e[1]=im_part;
            cmplx_mul(input[t],e,product);
            sum[0]+= product[0];
            sum[1]+= product[1];
        }
        output[k][0]=sum[0];
        output[k][1]=sum[1];
    }
}

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
    int k,t;
    double phase,real_part,im_part;
    cmplx_t e,product,sum;
    for(k=0;k<N;k++){
        sum[0]=0;
        sum[1]=0;
        for(t=0;t<N;t++){
            phase=-2*3.141592654*t*k/N;
            real_part=cmplx_real(1.0,phase);
            im_part=cmplx_imag(1.0,phase);
            e[0]=real_part;
            e[1]=im_part;
            cmplx_mul(input[t],e,product);
            sum[0]+= product[0];
            sum[1]+= product[1];
        }
        output[k][0]=sum[0]/N;
        output[k][1]=sum[1]/N;
    }
}

