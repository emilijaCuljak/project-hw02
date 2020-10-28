#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../inc/io.h"
#include "../inc/cmplx.h"

#define sine_length 20000
#define sine_freq 50

int floatToInt(float ulaz){

    void *a = (void *) &ulaz;
    int vrijednost_ieee = *((int *) a);
    //int vrijednost_cijeli_broj = (int) ulaz;
    return vrijednost_ieee;
}

float readAsFloat (int fd){

    int vrijednost_ieee = read_word(fd);
    void *a = (void *) &vrijednost_ieee;
    float vrijednost = *((float *) a);
    return vrijednost;
}


int main (){

    int i,N,fd,word;
    N=30;
    cmplx_t output [sine_length];
    cmplx_t sineWV[sine_length];
    double samp_rate=200;
    double samp_time=(double)1/samp_rate;
    double pi=3.14159;
    double theta=0.0;

    for(i = 0; i < sine_length; i++)

    {
        theta = 2.0*pi*sine_freq*(double)i*samp_time;
        sineWV[i][0]  = 10.0*sin(theta);
        sineWV[i][1]  = 0.0;
    }

    
     cmplx_dft (sineWV,output,N);

     fd=open("proba1.txt",O_WRONLY);

     



     for (i = 0; i < N; i++)
     {  
         word=floatToInt(output[i][0]);
         write_word (fd, word);
         word=floatToInt(output[i][1]);
         write_word (fd,word);
     }
     
     
    close(fd);
    return 0;
}



