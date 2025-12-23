#include "dynarr.h"
#include <iostream>
using namespace std;

dynArr::dynArr()
{
    data = NULL;
    rows = 0, cols = 0;
}
dynArr::dynArr(int r,int c)
{
    data = new int*[r];
    for (int i=0;i<c;i++){
        data[i] = new int[c];
    }
    rows = r, cols = c;
}
dynArr::~dynArr()
{
    for(int i=0;i<rows;i++){
        delete [] data[i];
    }
    delete [] data;
    data = NULL;
    cout << "Array destroyed" << endl;
}
int dynArr::getValue(int index1,int index2)
{
    return data[index1][index2];
}
void dynArr::setValue(int index1,int index2, int value)
{
    data[index1][index2] = value;
}
void dynArr::allocate(int r,int c){
    if (data != NULL){
        dynArr();
    }
    data = new int* [r];
    for (int i=0;i<c;i++){
        data[i] = new int[c];
    }
    rows = r, cols = c;
    cout << "Memory allocated" << endl;
}

