#ifndef METADATA_H
#define METADATA_H
#include <string.h>
#include <stdlib.h>

class MetaData
{
public:
    MetaData();
    int archivoDirectory;
    char path[1012];
    int startData;
    int sizeData;
    void setPath(char*n);
};

#endif // METADATA_H
