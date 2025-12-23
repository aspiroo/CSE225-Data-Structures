#include <iostream>
#include "binarysearchtree.h"
#include "binarysearchtree.cpp"

using namespace std;

void printTree(TreeType<int> tree,enum OrderType order){
    bool finished=false;
    tree.ResetTree(order);
    while (!finished){
        int num;
        tree.GetNextItem(num,order,finished);
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    TreeType<int> tree = TreeType<int>();

    //checking tree is empty or not
    if (tree.IsEmpty()){
        cout << "Tree is empty" <<endl;
    }
    else{
        cout << "Tree is not empty" <<endl;
    }

    // inserting 4 9 2 7 3 11 17 0 5 1
    tree.InsertItem(4);
    tree.InsertItem(9);
    tree.InsertItem(2);
    tree.InsertItem(7);
    tree.InsertItem(3);
    tree.InsertItem(11);
    tree.InsertItem(17);
    tree.InsertItem(0);
    tree.InsertItem(5);
    tree.InsertItem(1);

    //checking tree is empty or not
    if (tree.IsEmpty()){
        cout << "Tree is empty" <<endl;
    }
    else{
        cout << "Tree is not empty" <<endl;
    }

    //printing tree length
    cout << tree.LengthIs() <<endl;

    // looking for item 9
    bool found;
    int item=9;
    tree.RetrieveItem(item,found);
    if (found){
        cout << "Item is found" << endl;
    }
    else{
        cout << "Item is not found" << endl;
    }
    // looking for item 13
    item=13;
    tree.RetrieveItem(item,found);
    if (found){
        cout << "Item is found" << endl;
    }
    else{
        cout << "Item is not found" << endl;
    }

    enum OrderType in_order = IN_ORDER;
    enum OrderType pre_order = PRE_ORDER;
    enum OrderType post_order = POST_ORDER;
    printTree(tree,in_order);
    printTree(tree,pre_order);
    printTree(tree,post_order);

}
