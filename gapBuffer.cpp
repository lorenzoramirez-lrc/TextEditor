#include "gapBuffer.h"

gapBuffer::gapBuffer(int gapSize){

    buf = new char[gapSize];

    bufstr = buf;
    bufend = buf+ gapSize;

    gapstr= bufstr;
    gapend = bufend;
}

gapBuffer::~gapBuffer(){

    delete buf;

}

void gapBuffer::moveLeft(){
    if(bufstr!= gapstr){

        *gapend = *gapstr--;
        gapstr = gapstr--;
        gapend = gapend--;
    }
}

void gapBuffer::moveRight(){
    if(bufend != gapend){
        *gapstr = *gapend++;
        gapend = gapend++;
        gapstr = gapstr++;
    }
}

void gapBuffer::moveCursor(char *position){

    while()


}







