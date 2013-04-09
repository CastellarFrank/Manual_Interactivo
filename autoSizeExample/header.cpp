#include "header.h"

Header::Header()
{
    memset(this->fileName,0,212);
    memset(this->mainDirectory,0,610);
    this->fileCant=0;
    this->directoryCant=0;
    this->cantMetada=0;
    this->sizeMetada=0;
    this->allHeaderSize=0;
    this->totalDataSize=0;
}

void Header::setmainDirectory(char *n){
    strcpy(this->mainDirectory,n);
}

void Header::setName(char *n){
    strcpy(this->fileName,n);
}
