#include "SortingSystem.h"
#include <cstdio>
#include <fstream>   // Include the file stream library for file handling
#include <ctime>
#include <limits>    // Include the limits library for handling input validation
#include <iomanip>  // for setprecision

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
    cout<<"\nSorting using Insertion Sort:\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    for (int i = 1; i < size; i++) {
        T key = data[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;

        // Display iteration
        cout << "Iteration " << i << ": ";
        displayData();
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
}

//_____________________________________________________________________________________
// Selection Sort
template <typename T>
void SortingSystem<T>::selectionSort() {
    cout<<"\nSorting using Selection Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;

        // Find the minimum element in unsorted array
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        T temp = data[min_idx];
        data[min_idx] = data[i];
        data[i] = temp;

        // Display iteration
        cout << "Iteration " << i << ": ";
        displayData();
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
}

//_____________________________________________________________________________________
// Bubble Sort
template <typename T>
void SortingSystem<T>::bubbleSort() {
    cout<<"\nSorting using Bubble Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Swap if current element is greater than next
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swapped = true;
            }
        }

        // Display iteration
        cout << "Iteration " << i << ": ";
        displayData();

        // If no swaps occurred, array is sorted
        if (!swapped) break;
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
}

//_____________________________________________________________________________________
// Shell Sort
template <typename T>
void SortingSystem<T>::shellSort() {
    cout<<"\nSorting using Shell Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    // implement the shell sort function here (for Shell Sort)

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
}

//_____________________________________________________________________________________
// Merge Sort
template <typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    cout<<"\nSorting using Merge Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    // implement the merge sort function here (for Merge Sort)

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
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
    cout<<"\nSorting using Quick Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    // implement the quick sort function here (for Quick Sort)

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
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
    cout<<"\nSorting using Count Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    // implement the count sort function here (for Count Sort)

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
}

//_____________________________________________________________________________________
// Radix Sort
template <typename T>
void SortingSystem<T>::radixSort() {
    cout<<"\nSorting using Radix Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    // implement the radix sort function here (for Radix Sort)

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
}

//_____________________________________________________________________________________
// Bucket Sort
template <typename T>
void SortingSystem<T>::bucketSort() {
    cout<<"\nSorting using Bucket Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    clock_t start = clock();

    // implement the bucket sort function here (for Bucket Sort)

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSorted Data: ";
    displayData();
    cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
}

//_____________________________________________________________________________________
// Helper function to display data
template <typename T>
void SortingSystem<T>::displayData() {
    cout<<"[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout<<", ";
        }
    }
    cout<<"]\n";
}

//_____________________________________________________________________________________
// Helper function to measure sort time
template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    clock_t start = clock();
    (this->*sortFunc)();
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(5);
    cout << "Execution Time: " << duration << " seconds\n";
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
    cout<<"\nSelect a sorting algorithm:\n";
    cout<<"1. Insertion Sort\n";
    cout<<"2. Selection Sort\n";
    cout<<"3. Bubble Sort\n";
    cout<<"4. Shell Sort\n";
    cout<<"5. Merge Sort\n";
    cout<<"6. Quick Sort\n";
    cout<<"7. Count Sort (integers only)\n";
    cout<<"8. Radix Sort (integers only)\n";
    cout<<"9. Bucket Sort\n";
    cout<<"Enter your choice (1-9): ";
}

// Explicit template instantiation for int
template class SortingSystem<int>;

//_____________________________________________________________________________________

// Main function
int main() {
    cout<<"________________________________________\n"
          "   Welcome to Sorting System Program!\n"
          "________________________________________\n";

    // Main menu loop
    int choice;
    char repeat;
    int size;
    int input;

    do {

        cout << "\nChoose input method:\n1. Manual input\n2. Read from file\nEnter choice: ";
        while (!(cin >> input) || (input != 1 && input != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid choice (1 or 2): ";
        }

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
        cout<<"\nInitial Data: ";

        //display menu
        sorter->displayData();
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

        delete sorter;
        cout << "\nDo you want to sort another dataset? (1 = Yes, 2 = No): ";
        while (!(cin >> repeat) || (repeat != '1' && repeat != '2')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid choice (1 or 2): ";
        }
    } while (repeat == '1');

    cout<<"\nThank you for using the sorting system! Goodbye!\n";

    return 0;
}

