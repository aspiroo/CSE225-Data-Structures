#include <iostream>
#include "dynarr.h"
using namespace std;

int main()
{
    int r,c;
    cout << "Enter number of rows and columns for matrix: ";
    cin >> r >> c;

    dynArr d1(r,c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int input;
            cout << "Enter " << i << "," << j << " number: ";
            cin >> input;
            d1.setValue(i,j,input);
            }
        cout << endl;
    }

    cout << "Matrix of numbers:" << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << d1.getValue(i,j) << " ";
            }
        cout << endl;
    }

    cout << endl << "Enter new number of rows and columns for matrix: ";
    cin >> r >> c;

    d1.allocate(r,c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int input;
            cout << "Enter " << i << "," << j << " number: ";
            cin >> input;
            d1.setValue(i,j,input);
            }
        cout << endl;
    }

    cout << "Matrix of numbers:" << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << d1.getValue(i,j) << " ";
        }
        cout << endl;
    }

}
