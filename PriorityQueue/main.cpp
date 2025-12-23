#include <iostream>
#include "pqtype.h"
#include "pqtype.cpp"

using namespace std;

void isQueueEmpty(PQType<int>& queue){
    if (queue.IsEmpty())
        cout << "Queue is Empty" <<endl;
    else
        cout << "Queue is Not Empty" <<endl;
}

int maxNumberOfCandies(int mins,PQType<int>& candies){
    int total,candynum;
    while (mins!=0){
        candies.Dequeue(candynum);
        total+=candynum;
        candies.Enqueue(candynum/2);
        mins--;
    }
    return total;
}

int main()
{
    // normal priority queue implementation

    PQType<int> queue(15); //creating queue
    isQueueEmpty(queue); //checking the made queue

    // enqueue this set of numbers 4 9 2 7 3 11 17 0 5 1
    int nums[] = {4,9,2,7,3,11,17,0,5,1};

    for (int n : nums)
        queue.Enqueue(n); // iterating the data

    isQueueEmpty(queue); //checking the queue empty or not after enqueuing

    int x;

    queue.Dequeue(x); //extracting max from max heap
    cout << x <<endl;

    queue.Dequeue(x); //extracting again
    cout << x <<endl;

    // magic candy bag problem
    int bags, mins;
    PQType<int> candies(bags);
    cout << "Number of bags of magical candies: " << endl;
    cin >> bags;
    cout << "Number of minutes to eat candy, assuming 1 bag takes 1 minute to eat: " << endl;
    cin >> mins;
    cout << "Number of candies in each magical bag: " << endl;
    for (int i=0;i<bags;i++){
        int candynum;
        cin >> candynum;
        candies.Enqueue(candynum);
    }
    cout << "Maximum candies possible to eat: " << maxNumberOfCandies(mins,candies) << endl;
}
