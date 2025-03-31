#include "SortingSystem.h"
#include <cstdio>
#include <fstream>   // Include the file stream library for file handling
#include <ctime>
#include <limits>    // Include the limits library for handling input validation

// Constructor
template <typename T>
SortingSystem<T>::SortingSystem(int n) : size(n) {
    data = new T[size];
}

// Destructor
template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}

//_____________________________________________________________________________________
// Insertion Sort
template <typename T>
void SortingSystem<T>::insertionSort() {
    printf("\nSorting using Insertion Sort:\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the insertion sort function here (for Insertion Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Selection Sort
template <typename T>
void SortingSystem<T>::selectionSort() {
    printf("\nSorting using Selection Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the selection sort function here (for Selection Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Bubble Sort
template <typename T>
void SortingSystem<T>::bubbleSort() {
    printf("\nSorting using Bubble Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the bubble sort function here (for Bubble Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Shell Sort
template <typename T>
void SortingSystem<T>::shellSort() {
    printf("\nSorting using Shell Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the shell sort function here (for Shell Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Merge Sort
template <typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    printf("\nSorting using Merge Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the merge sort function here (for Merge Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

// Merge helper function (for Merge Sort)
template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {

    // implement the merge function here (for Merge Sort)

}

//_____________________________________________________________________________________
// Quick Sort
template <typename T>
void SortingSystem<T>::quickSort(int low, int high) {
    printf("\nSorting using Quick Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the quick sort function here (for Quick Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

// Partition helper function (for Quick Sort)
template <typename T>
int SortingSystem<T>::partition(int low, int high) {

    //implementing the partition function

    return 0;
}

//_____________________________________________________________________________________
// Count Sort
template <typename T>
void SortingSystem<T>::countSort() {
    printf("\nSorting using Count Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the count sort function here (for Count Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Radix Sort
template <typename T>
void SortingSystem<T>::radixSort() {
    printf("\nSorting using Radix Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the radix sort function here (for Radix Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Bucket Sort
template <typename T>
void SortingSystem<T>::bucketSort() {
    printf("\nSorting using Bucket Sort...\n");
    printf("Initial Data: ");
    displayData();

    clock_t start = clock();

    // implement the bucket sort function here (for Bucket Sort)

    clock_t end = clock();
    printf("Sorted Data: ");
    displayData();
    printf("Sorting Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Helper function to display data
template <typename T>
void SortingSystem<T>::displayData() {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);  // Change format specifier for other types
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

//_____________________________________________________________________________________
// Helper function to measure sort time
template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    clock_t start = clock();
    (this->*sortFunc)();
    clock_t end = clock();
    printf("Execution Time: %.5f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
}

//_____________________________________________________________________________________
// Helper function to swap elements
template <typename T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

//_____________________________________________________________________________________
// Show menu
template <typename T>
void SortingSystem<T>::showMenu() {
    printf("\nSelect a sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Quick Sort\n");
    printf("7. Count Sort (integers only)\n");
    printf("8. Radix Sort (integers only)\n");
    printf("9. Bucket Sort\n");
    printf("Enter your choice (1-9): ");
}

// Explicit template instantiation for int
template class SortingSystem<int>;

//_____________________________________________________________________________________

// Main function
int main() {
    printf("_________________________________________\n");
    printf("Welcome to Sorting System Program!\n");
    printf("_________________________________________\n");

    int input;
    cout << "\nChoose input method:\n1. Manual input\n2. Read from file\nEnter choice: ";
    while (!(cin >> input) || (input != 1 && input != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid choice (1 or 2): ";
    }

    int size;
    SortingSystem<int>* sorter = nullptr;

    if (input == 1) {
        // Manual input
        cout << "\nEnter number of elements: ";
        while (!(cin >> size) || size <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid size! Enter a positive integer: ";
        }
        sorter = new SortingSystem<int>(size);
        cout << "Enter elements: ";
        for (int i = 0; i < size; i++) {
            while (!(cin >> sorter->getDataAt(i))) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter an integer: ";
            }
        }
    } else {
        // File input
        ifstream inputFile;
        string filename;
        while (true) {
            cout << "\nEnter filename: ";
            cin >> filename;
            inputFile.open(filename);
            if (inputFile) break;
            cout << "File not found! Please enter a valid filename.\n";
        }

        if (!(inputFile >> size) || size <= 0) {
            cout << "Error reading size from file!\n";
            return 1;
        }

        sorter = new SortingSystem<int>(size);
        for (int i = 0; i < size; i++) {
            if (!(inputFile >> sorter->getDataAt(i))) {
                cout << "Error reading data from file!\n";
                delete sorter;
                return 1;
            }
        }
        inputFile.close();
    }

    // Show initial data
    printf("\nInitial Data: ");
    sorter->displayData();

    // Main menu loop
    int choice;
    char repeat;
    do {
        sorter->showMenu();
        while (!(cin >> choice) || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter 1-9: ";
        }

        switch (choice) {
            case 1: sorter->insertionSort(); break;
            case 2: sorter->selectionSort(); break;
            case 3: sorter->bubbleSort(); break;
            case 4: sorter->shellSort(); break;
            case 5: sorter->mergeSort(0, size - 1); break;
            case 6: sorter->quickSort(0, size - 1); break;
            case 7: sorter->countSort(); break;
            case 8: sorter->radixSort(); break;
            case 9: sorter->bucketSort(); break;
        }

        cout << "\nDo you want to sort another dataset? (1 = Yes, 2 = No): ";
        while (!(cin >> repeat) || (repeat != '1' && repeat != '2')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid choice (1 or 2): ";
        }
    } while (repeat == '1');

    delete sorter;
    printf("\nThank you for using the sorting system! Goodbye!\n");
    return 0;
}

