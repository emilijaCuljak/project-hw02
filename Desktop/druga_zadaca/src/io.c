#include <unistd.h>



int read_word(int fd){

    void *c;
    read(fd,c,4);
    return *((int *) c);
}

short read_half(int fd){

    void *c;
    read(fd,c,2);
    return *((int *)c);
}

void write_word(int fd, int word){

    void *c = (void *) &word;
    write(fd,word,4);

}

void write_half(int fd, short word){

     void *c = (void *) &word;
     write(fd,word,2);

}





