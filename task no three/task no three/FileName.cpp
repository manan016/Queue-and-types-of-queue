#include <iostream>
using namespace std;

#define MAX_SIZE 10

struct Patient {
    string name;
    int severity;
};

class HospitalPriorityQueue {
private:
    Patient q[MAX_SIZE];
    int size;

public:
    HospitalPriorityQueue() : size(0) {}

    void addPatient() {
        if (size == MAX_SIZE) {
            cout << " Emergency room is full! Cannot admit more patients.\n";
            return;
        }

        Patient p;
        cout << "Enter patient name: ";
        cin >> p.name;
        cout << "Enter severity level (1 = mild, 10 = critical): ";
        cin >> p.severity;

        q[size++] = p;
        cout << " Patient " << p.name << " added with severity level " << p.severity << ".\n";
    }

    void treatPatient() {
        if (size == 0) {
            cout << "⚠️ No patients to treat!\n";
            return;
        }

        int mostSevere = 0;
        for (int i = 1; i < size; i++) {
            if (q[i].severity > q[mostSevere].severity)
                mostSevere = i;
        }

        cout << " Treating patient " << q[mostSevere].name
            << " (severity " << q[mostSevere].severity << ").\n";

        for (int i = mostSevere; i < size - 1; i++)
            q[i] = q[i + 1];

        size--;
    }

    void displayPatients() const {
        if (size == 0) {
            cout << " No patients waiting.\n";
            return;
        }

        cout << "\n Waiting Patients (Name : Severity)\n";
        cout << "-----------------------------------\n";
        for (int i = 0; i < size; i++) {
            cout << q[i].name << " : " << q[i].severity << "\n";
        }
    }
};

int main() {
    HospitalPriorityQueue hospital;
    int choice;

    do {
        cout << "\n=====  Hospital Emergency Room System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Most Severe Patient\n";
        cout << "3. View Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "---------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: hospital.addPatient(); break;
        case 2: hospital.treatPatient(); break;
        case 3: hospital.displayPatients(); break;
        case 4: cout << " System closing. Stay healthy!\n"; break;
        default: cout << "❌ Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
