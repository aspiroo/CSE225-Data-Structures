#include <iostream>
#include "quetype.h"
#include "quetype.cpp"
#include <cmath>

using namespace std;

template<class ItemType>
void isQueueEmpty(QueType<ItemType> list){
    if (list.IsEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }
}
template<class ItemType>
void isQueueFull(QueType<ItemType> list){
    if (list.IsFull()){
        cout << "Queue is full" << endl;
    }
    else{
        cout << "Queue is not full" << endl;
    }
}
template<class ItemType>
void printQueue(QueType<ItemType> list){
    QueType<ItemType> copy = list;
    ItemType item;
    while (!copy.IsEmpty()){
        copy.Dequeue(item);
        cout << item << " " ;
    }
    cout << endl;
}

void intToBinary(int num){
    QueType<string> binary = QueType<string>(num);
    string s1="1",s2;
    binary.Enqueue(s1);
    for (int i=0;i<num;i++){
        s2 = s1;
        s1.append("0");
        s2.append("1");

    }

}

int main()
{

    QueType<int> numbers = QueType<int>(5);

    isQueueEmpty(numbers);

    numbers.Enqueue(5);
    numbers.Enqueue(7);
    numbers.Enqueue(4);
    numbers.Enqueue(2);

    isQueueEmpty(numbers);
    isQueueFull(numbers);

    numbers.Enqueue(6);

    printQueue(numbers);

}
