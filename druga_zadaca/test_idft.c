#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "io.h"
#include "cmplx.h"

#define sine_length 20000
#define sine_freq 50


float readAsFloat (int fd){

    int vrijednost_ieee = read_word(fd);
    void *a = (void *) &vrijednost_ieee;
    float vrijednost = *((float *) a);
    return vrijednost;
}

int main (){

    int i,N,fd,words;
    float vrijednost;
    N=30;
    cmplx_t output [sine_length];
    cmplx_t sineWV[sine_length];
    double samp_rate=200;
    double samp_time=(double)1/samp_rate;
    double pi=3.14159;
    double theta=0.0;

    fd=open("proba1.bin",O_RDONLY);

    
     for (i = 0; i < N; i++)
     {  
         output[i][0]=readAsFloat(fd);
         output[i][1]=readAsFloat(fd);        
     }

    cmplx_idft(output,sineWV,N);

    for ( i = 0; i < N; i++)
    {
        printf("%f+%fi\n",output[i][0],output[i][1]);
    }
    

     close(fd);
     return 0;

}
