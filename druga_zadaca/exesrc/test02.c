#include <stdio.h>
#include "../inc/cmplx.h"

int main (){

cmplx_t a,b,c;
a[0]=7;
a[1]=7;
b[0]=0;
b[1]=8;
cmplx_mul(a,b,c);
printf("%f+%fi",c[0], c[1]);

return 0;

}
