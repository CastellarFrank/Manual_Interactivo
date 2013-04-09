#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>

class Header
{
public:
    Header();
    char fileName[212];
    char mainDirectory[610];
    int fileCant;
    int directoryCant;
    int sizeMetada;
    int cantMetada;
    int allHeaderSize;
    int totalDataSize;


    void setName(char *n);
    void setmainDirectory(char*n);

private:
    char padding[174];

};

#endif // HEADER_H
