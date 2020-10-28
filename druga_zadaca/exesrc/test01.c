#include <stdio.h>
#include "../inc/cmplx.h"

int main () {

cmplx_t a,b,c;
a[0]=1;
a[1]=1;
b[0]=1;
b[1]=1;
cmplx_div(a,b,c);
printf("%f+%fi",c[0], c[1]);

return 0;

}
