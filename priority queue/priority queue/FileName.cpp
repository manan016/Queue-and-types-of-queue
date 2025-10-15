#include <iostream>
using namespace std;

#define SIZE 10

struct Customer {
    int token;
    int priority;
};

class BankPriorityQueue {
    Customer arr[SIZE];
    int count;

public:
    BankPriorityQueue() {
        count = 0;
    }

    void enqueue() {
        if (count == SIZE) {
            cout << "Queue is full!" << endl;
            return;
        }
        int token, priority;
        cout << "Enter token number: ";
        cin >> token;
        cout << "Enter priority (1 = highest, 5 = lowest): ";
        cin >> priority;

        arr[count].token = token;
        arr[count].priority = priority;
        count++;
        cout << "Customer " << token << " added with priority " << priority << endl;
    }

    void dequeue() {
        if (count == 0) {
            cout << "No customers to serve!" << endl;
            return;
        }

        int highestIndex = 0;
        for (int i = 1; i < count; i++) {
            if (arr[i].priority < arr[highestIndex].priority) {
                highestIndex = i;
            }
        }

        cout << "Serving customer " << arr[highestIndex].token
            << " (priority " << arr[highestIndex].priority << ")" << endl;

        for (int i = highestIndex; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No customers waiting." << endl;
            return;
        }
        cout << "Waiting customers (token : priority):" << endl;
        for (int i = 0; i < count; i++) {
            cout << arr[i].token << " : " << arr[i].priority << endl;
        }
    }
};

int main() {
    BankPriorityQueue pq;
    int choice;
    do {
        cout << "\n--- Bank Priority Queue ---" << endl;
        cout << "1. Add customer" << endl;
        cout << "2. Serve highest-priority customer" << endl;
        cout << "3. View queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: pq.enqueue(); break;
        case 2: pq.dequeue(); break;
        case 3: pq.display(); break;
        case 4: cout << "Goodbye!" << endl; break;
        default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}