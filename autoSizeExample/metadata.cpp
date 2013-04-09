#include "metadata.h"

MetaData::MetaData()
{
    this->archivoDirectory=-1;
    memset(this->path,0,1012);
    this->sizeData=0;
    this->startData=0;
}

void MetaData::setPath(char *n){
    strcpy(this->path,n);
}
