#include <iostream>
using namespace std;

#define MAX_SIZE 10  // maximum queue capacity

struct Customer {
    int token;     // customer token number
    int priority;  // smaller number = higher priority
};

class BankPriorityQueue {
private:
    Customer q[MAX_SIZE];
    int size;

public:
    // Constructor
    BankPriorityQueue() : size(0) {}

    // Add a customer to the queue
    void enqueue() {
        if (size == MAX_SIZE) {
            cout << "⚠️ Queue is full! Cannot add more customers.\n";
            return;
        }

        Customer c;
        cout << "Enter token number: ";
        cin >> c.token;
        cout << "Enter priority (1 = highest, 5 = lowest): ";
        cin >> c.priority;

        q[size++] = c;
        cout << "✅ Customer " << c.token << " added with priority " << c.priority << ".\n";
    }

    // Serve the customer with the highest priority
    void dequeue() {
        if (size == 0) {
            cout << "⚠️ No customers to serve!\n";
            return;
        }

        int highest = 0;
        for (int i = 1; i < size; i++) {
            if (q[i].priority < q[highest].priority)
                highest = i;
        }

        cout << "🎯 Serving customer " << q[highest].token
            << " (priority " << q[highest].priority << ").\n";

        // Shift all remaining elements left
        for (int i = highest; i < size - 1; i++)
            q[i] = q[i + 1];

        size--;
    }

    // Display all waiting customers
    void display() const {
        if (size == 0) {
            cout << "📭 No customers waiting.\n";
            return;
        }

        cout << "\n🧾 Waiting Customers (Token : Priority)\n";
        cout << "-----------------------------------\n";
        for (int i = 0; i < size; i++) {
            cout << q[i].token << " : " << q[i].priority << "\n";
        }
    }
};

// ===================== MAIN =====================
int main() {
    BankPriorityQueue bank;
    int choice;

    do {
        cout << "\n===== 🏦 Bank Priority Queue System =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Highest Priority Customer\n";
        cout << "3. View Queue\n";
        cout << "4. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: bank.enqueue(); break;
        case 2: bank.dequeue(); break;
        case 3: bank.display(); break;
        case 4: cout << "👋 Goodbye!\n"; break;
        default: cout << "❌ Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
