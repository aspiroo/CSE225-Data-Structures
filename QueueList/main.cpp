#include <iostream>
#include "quetype.h"
#include "quetype.cpp"

using namespace std;

// function to calculate the minimum number of coins required to reach a given amount
int numberOfCoins(int typesOfCoin, int* coinValues, int finalAmount) {
    QueType<int> cost;  // queue to keep track of the cost to reach each amount
    QueType<int> queue; // queue to store different amounts as we build towards the final amount
    bool repeat[finalAmount + 1] = {false}; // array to keep track of amounts we have already repeated

    // initialize the queue with each coin value
    for (int i = 0; i < typesOfCoin; i++) {
        queue.Enqueue(coinValues[i]);
        cost.Enqueue(1);
        repeat[coinValues[i]] = true;
    }

    int current_amount, current_cost, new_amount; // variables for current amount, current cost, and new amount

    // loop until the queue is empty
    while (!queue.IsEmpty()) {
        queue.Dequeue(current_amount); // dequeue an amount
        cost.Dequeue(current_cost);    // dequeue the corresponding cost

        // if current amount matches the target, return the cost
        if (current_amount == finalAmount) {
            return current_cost;
        }

        // try adding each coin value to the current amount to explore new amounts
        for (int i = 0; i < typesOfCoin; i++) {
            new_amount = current_amount + coinValues[i]; // calculate new amount by adding a coin value

            // if new amount is within bounds and hasn't been repeated, enqueue it
            if (new_amount <= finalAmount && !repeat[new_amount]) {
                queue.Enqueue(new_amount);
                cost.Enqueue(current_cost + 1);
                repeat[new_amount] = true;
            }
        }
    }
    // return -1 if no solution is found
    return -1;
}

int main() {
    cout << "Minimum number of coins to pay a certain amount" << endl;
    cout << "Enter number of entries: ";
    int n;
    cin >> n;
    cout << endl;

    // process each entry
    for (int i = 0; i < n; i++) {
        cout << "For entry number " << i + 1 << endl;
        int types;
        cout << "Enter number of types of coin: ";
        cin >> types;
        cout << endl;

        int coins[types]; // array to store the value of each coin type
        for (int j = 0; j < types; j++) {
            cout << "Enter coin value: ";
            cin >> coins[j];
        }

        int target; // variable to store the target amount
        cout << endl;
        cout << "Enter final amount: ";
        cin >> target;
        cout << endl;

        // call function to calculate the minimum number of coins needed
        int result = numberOfCoins(types, coins, target);

        // output the result
        cout << "Number of coins needed: " << result << endl << endl;
    }
}
