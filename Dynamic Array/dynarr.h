#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED

class dynArr
{
private:
    int **data;
    int rows,cols;
public:
    dynArr();
    dynArr(int r,int c);
    ~dynArr();
    void setValue(int index1, int index2, int value);
    int getValue(int index1 ,int index2);
    void allocate(int r,int c);
};
#endif // DYNARR_H_INCLUDED
