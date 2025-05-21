#include <iostream>
#include <fstream>

using namespace std;

struct Patient {     //Patient's information structure
    char name[100];
    int severity;
    int arrivalTime;
};

bool isUpPrior(Patient a, Patient b) {     //Priority comparison
    if (a.severity > b.severity){
        return true;
    }
    if (a.severity == b.severity && a.arrivalTime < b.arrivalTime){
        return true;
    }
    return false;
}

class MaxHeap {     //MaxHeap class using a binary heap structure
private:
    Patient* heap;
    int capacity;
    int size;

    void swap(Patient &a, Patient &b) {     //Swap two patients in the heap
        Patient temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {     //Move the patient up the heap until the max-heap property is restored
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (isUpPrior(heap[index], heap[parent])) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {     //Move the patient down the heap until the max-heap property is restored
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        //Find the highest priority among node and its children
        if (left < size && isUpPrior(heap[left], heap[largest])) {
            largest = left;
        }
        if (right < size && isUpPrior(heap[right], heap[largest])) {
            largest = right;
        }

        //If a child has higher priority, swap and recur
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new Patient[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(Patient p) {
        if (size == capacity) {
            cout << "Heap is full!\n";
            return;
        }
        heap[size] = p;
        heapifyUp(size);
        size++;
    }

    Patient* extract_max() {     //Return and remove the highest-priority patient
        if (size == 0) return nullptr;

        Patient* maxPatient = new Patient;
        *maxPatient = heap[0];

        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return maxPatient;
    }

    Patient* peek() {     //Return highest-priority patient without removing
        if (size == 0) return nullptr;
        return &heap[0];
    }

    void print_heap() {     //Print the heap as an array of names
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << heap[i].name;
            if (i < size - 1) cout << ", ";
        }
        cout << " ]\n";
    }
};

int main() {
    cout << "___Emergency Room Priority Queue___\n\n";

    string repeat = "yes";

    while (repeat == "yes" || repeat == "y") {
        int n;
        int inputMethod;
        cout << "Choose input method:\n1. Manual Entry\n2. Load from File\nEnter choice: ";
        cin >> inputMethod;

        MaxHeap* emergencyQueue = nullptr;

        if (inputMethod == 1) {
            cout << "Enter the number of patients please: ";
            cin >> n;
            emergencyQueue = new MaxHeap(n);

            for (int i = 0; i < n; i++) {
                Patient p;
                cout << "\nEnter the details for patient " << i + 1 << ":\n";
                cout << "Name: ";
                cin >> ws;
                cin.getline(p.name, 100);
                cout << "Severity (1-100): ";
                cin >> p.severity;
                p.arrivalTime = i;
                emergencyQueue->insert(p);
                cout << "Heap after insertion: ";
                emergencyQueue->print_heap();
                cout << "--------------------------------\n";
            }
        } else if (inputMethod == 2) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;

            ifstream file(filename);
            if (!file.is_open()) {
                cout << "Error opening file.\n";
                return 1;
            }

            file >> n;
            emergencyQueue = new MaxHeap(n);
            for (int i = 0; i < n; i++) {
                Patient p;
                file >> ws;
                file.getline(p.name, 100);
                file >> p.severity;
                p.arrivalTime = i;
                emergencyQueue->insert(p);
                cout << "Heap after insertion: ";
                emergencyQueue->print_heap();
                cout << "--------------------------------\n";
            }
            file.close();
        } else {
            cout << "Invalid input method.\n";
            return 1;
        }

        cout << "\nTreatment Order:\n";
        int order = 1;
        Patient* treated;
        while ((treated = emergencyQueue->extract_max()) != nullptr) {
            cout << order++ << ". " << treated->name
                 << " (Severity: " << treated->severity
                 << ", Arrival: " << treated->arrivalTime << ")\n";
            delete treated;
        }

        delete emergencyQueue;

        cout << "\nDo you want to perform another operation? (yes/no): ";
        cin >> repeat;
        cout << endl;
    }

    cout << "Exiting program. Goodbye!\n";
    return 0;
}
