#include <iostream>
#include <bits/stdc++.h>
#include "stacktype.h"
#include "stacktype.cpp"

using namespace std;

int priority(char c) // quantifies the importance of operator order
{
    if (c=='+' || c=='-')
    {
        return 1;
    }
    else if (c=='/' || c=='*')
    {
        return 2;
    }
    else if (c=='^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

int calculate(int x,int y, char c) // calculates two numbers with a operator
{
    switch (c)
    {
    case '+':
        return x+y;
        break;
    case '-':
        return x-y;
        break;
    case '*':
        return x*y;
        break;
    case '/':
        if (y==0)
        {
            return -1;
        }
        return x/y;
        break;
    case '^':
        return pow(x,y);
        break;
    default:
        return -1;
    }
}

bool isOperator(char c) // checks a char is a operator or not
{
    return c=='+' || c=='-' ||c=='/' || c=='*' || c=='^';
}

string convertToPostFix(string infix) // converts from infix to postfix
{
    StackType<char> stack;
    string result;
    string error ="Invalid Expression";
    int bracketopen;

    for(int i=0; i<infix.length(); i++)
    {
        char c = infix[i];
        if (c==' ') // skipping spaces
        {
            continue;
        }
        else if (c>='0' && c<='9') // checking char for digit
        {
            result+=c;
        }
        else if (c=='(') // if char is parentheses push in stack
        {
            stack.Push(c);
            bracketopen++; // iterating variable to track brackets
        }
        else if (c== ')')
        {
            if (bracketopen==0) // if no pre existing bracket display error message
            {
                return error;
            }
            while (!stack.IsEmpty() && stack.Top()!='(') // add all operators in stack between two brackets in result
            {
                result+=stack.Top();
                stack.Pop();
            }
            if (!stack.IsEmpty()) // always checking if stack is empty before popping
            {
                stack.Pop();
            }
            bracketopen--;
        }
        else if (isOperator(c))
        {
            if (i == 0 || i == infix.length() - 1 || isOperator(infix[i - 2])) // checking placement of operators
            {
                return error;
            }
            while (!stack.IsEmpty() && priority(c) <= priority(stack.Top())) // adding operators in order of priority
            {
                result += stack.Top();
                stack.Pop();
            }
            stack.Push(c); // pushing the operator
        }
    }

    if (bracketopen!=0) // checking for unbalanced parentheses
    {
        return error;
    }

    while (!stack.IsEmpty()) // adding to result until stack empties
    {
        if (stack.Top() == '(')
        {
            return error;
        }
        result += stack.Top();
        stack.Pop();
    }

    return result;
}

int evaluatePostFix(string postfix) // returns result from a postfix expressionh
{
    StackType<int> stack;
    char c;
    for (int i=0; i<postfix.length(); i++)
    {
        c=postfix[i];
        if (c>='0' && c<='9')
        {
            stack.Push(c-'0'); // if digit then push that int into stack
        }
        else
        {
            if(stack.IsEmpty()){ // if stack empty, expression invalid
                return -1;
            }
            int result=0;
            int num1 = stack.Top();
            stack.Pop();
            int num2 = stack.Top();
            stack.Pop();
            result = calculate(num2,num1,c); // if operator take two digits and calculate the result of two numbers and push into stack
            stack.Push(result);
        }
    }
    return stack.Top();
}

int main()
{
    string infix[] =
    {
        "9 + 3 * 5 / (9 - 4)",   //result is 12
        "(5 + 3) * 9 / 3",       //result is 24
        "3 + 4 / (2 - 3) * / 5", //invalid
        "7 / 5 + (4 - (2) * 3"   //invalid
    };

    cout << "All expressions are used for single digit numbers!" << endl;
    cout << "Infix => Postfix => Result" << endl << endl;

    for (string exp : infix)
    {
        cout << exp << " => " << convertToPostFix(exp) << " => " << evaluatePostFix(convertToPostFix(exp)) << endl;
    }

}
