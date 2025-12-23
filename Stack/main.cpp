#include <iostream>
#include"stacktype.h"
#include"stacktype.cpp"
using namespace std;

void printStack(StackType<int> stack){
    StackType<int> copy = stack;
    int arr[5];
    int i=0;
    while (!copy.IsEmpty()){
        arr[i] = copy.Top();
        copy.Pop();
        i++;
    }
    for(int j=i-1;j>=0;j--){
        cout << arr[j] << " ";
    }
    cout << endl;
}

void isBalanced(string brackets){
    StackType<char> parentheses = StackType<char>();
    for (int i=0;i<brackets.length();i++){
        if (brackets[i]=='('){

            parentheses.Push(brackets[i]);
        }
        else if (brackets[i]==')'){
            if (parentheses.IsEmpty()){
                cout << "Not Balanced" << endl;
                return;
            }
            parentheses.Pop();
        }
    }
    if (parentheses.IsEmpty()){
        cout << "Balanced" << endl;
    }
    else{
        cout << "Not Balanced" << endl;
    }
}
int main()
{
    StackType<int> stack = StackType<int>();
    if (stack.IsEmpty())
        cout << "Stack is Empty"  <<  endl;
    else
        cout << "Stack is not Empty" <<  endl;
    stack.Push(5);
    stack.Push(7);
    stack.Push(4);
    stack.Push(2);
    if (stack.IsEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
    if (stack.IsFull())
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is not Full" << endl;
    printStack(stack);
    stack.Push(3);
    printStack(stack);
    if (stack.IsFull())
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is not Full" << endl;
    stack.Pop();
    stack.Pop();
    cout << stack.Top() << endl;
    isBalanced("()");
    isBalanced("(())()(()())()");
    isBalanced("(())()((()");
    isBalanced("(())))((()");
}
