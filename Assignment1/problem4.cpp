#include "SortingSystem.h"
#include <cstdio>
#include <fstream>   // Include the file stream library for file handling
#include <limits>    // Include the limits library for handling input validation
#include <iomanip>  // for setprecision
#include <chrono>
using namespace chrono;

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

    cout << "\nSorted Data: ";
    displayData();
}

//_____________________________________________________________________________________
// Selection Sort
template <typename T>
void SortingSystem<T>::selectionSort() {
    cout<<"\nSorting using Selection Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

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

    cout << "\nSorted Data: ";
    displayData();
}

//_____________________________________________________________________________________
// Bubble Sort
template <typename T>
void SortingSystem<T>::bubbleSort() {
    cout<<"\nSorting using Bubble Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

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

    cout << "\nSorted Data: ";
    displayData();
}

//_____________________________________________________________________________________
// Shell Sort
template <typename T>
void SortingSystem<T>::shellSort() {
    cout<<"\nSorting using Shell Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    //Shell Sort implementation
    for (int gap = size / 2; gap > 0; gap /= 2) {     //To reduce the gap in each iteration
        for (int i = gap; i < size; i++) {      //Traverse elements starting from the gap
            T temp = data[i];     //Store the current element
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {     //Shift earlier gap-sorted elements to their right position
                data[j] = data[j - gap];
            }
            data[j] = temp;     //Put the stored element in its right position
        }
        
        cout << "After gap " << gap << ": ";
        displayData();
    }

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
    if (left == 0 && right == size - 1) {
        cout<<"\nSorting using Merge Sort...\n";
        cout<<"Initial Data: ";
        displayData();
        cout<<"\n";
    }
    
    clock_t start = clock();

     if (left < right) {
        int mid = left + (right - left) / 2;     //To find the middle point
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);

        cout << "\nAfter merging (" << left << " to " << right << "): ";
        displayData();
    }

    if (left == 0 && right == size - 1) {
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Sorting Time: " << fixed << setprecision(5) << duration << " seconds\n";
    }
}

// Merge helper function (for Merge Sort)
template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    //Temporary arrays
    T* leftArr = new T[leftSize];
    T* rightArr = new T[rightSize];

    //To copy data to the temp arrays
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = data[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = data[mid + 1 + j];

    //Merge the temp arrays back
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            data[k] = leftArr[i];
            i++;
        } else {
            data[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {     //Copy the rest of the elements of leftArr, if there is
        data[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {     //Copy the rest of the elements of rightArr, if there is
        data[k] = rightArr[j];
        j++;
        k++;
    }

    //Free allocated memory
    delete[] leftArr;
    delete[] rightArr;
}
//_____________________________________________________________________________________
// Quick Sort
template <typename T>
void SortingSystem<T>::quickSort(int low, int high) {
    cout<<"\nSorting using Quick Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";
    auto start = chrono::high_resolution_clock::now();

    // implement the quick sort function here (for Quick Sort)

    cout << "\nSorted Data: ";
    displayData();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Sorting Time: " << fixed << setprecision(5) << duration.count() << " seconds\n";
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

    // implement the count sort function here (for Count Sort)

    cout << "\nSorted Data: ";
    displayData();
}

//_____________________________________________________________________________________
// Radix Sort
template <typename T>
void SortingSystem<T>::radixSort() {
    cout<<"\nSorting using Radix Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    // implement the radix sort function here (for Radix Sort)

    cout << "\nSorted Data: ";
    displayData();
}

//_____________________________________________________________________________________
// Bucket Sort
template <typename T>
void SortingSystem<T>::bucketSort() {
    cout<<"\nSorting using Bucket Sort...\n";
    cout<<"Initial Data: ";
    displayData();
    cout<<"\n";

    // implement the bucket sort function here (for Bucket Sort)

    cout << "\nSorted Data: ";
    displayData();
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
// Implement measureSortTime using chrono
template<typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    auto start = high_resolution_clock::now();
    (this->*sortFunc)();
    auto end = high_resolution_clock::now();

    duration<double> duration = end - start;
    cout << fixed << setprecision(5);
    cout << "Sorting Time: " << duration.count() << " seconds\n";
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
// Helper functions for integer validation

static bool isInteger(const string& s) {
    if (s.empty()) return false;

    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i++;

    for (; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

template <typename T>
bool allIntegers(SortingSystem<T>* sorter, int known_size) {
    // Create a stringstream from the displayed data
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    sorter->displayData();
    cout.rdbuf(old);

    string displayed_data = buffer.str();
    size_t pos = displayed_data.find('[') + 1;
    size_t end_pos = displayed_data.find(']');
    string content = displayed_data.substr(pos, end_pos - pos);

    // Split content by commas and check each element
    size_t comma_pos = 0;
    while ((comma_pos = content.find(',')) != string::npos) {
        string element = content.substr(0, comma_pos);
        content.erase(0, comma_pos + 2); // Skip comma and space
        if (!isInteger(element)) return false;
    }
    // Check last element
    if (!content.empty() && !isInteger(content)) return false;

    return true;
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

        SortingSystem<string>* sorter = nullptr;

        if (input == 1) {
            // Manual input
            cout << "\nEnter number of elements: ";
            while (!(cin >> size) || size <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid size! Enter a positive integer: ";
            }
            sorter = new SortingSystem<string>(size);
            cout << "Enter elements: ";
            for (int i = 0; i < size; i++) {
                cin >> sorter->getDataAt(i);
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

            sorter = new SortingSystem<string>(size);
            string element;
            for (int i = 0; i < size; i++) {
                if (!(inputFile >> element)) {
                    cout << "Error reading data from file!\n";
                    delete sorter;
                    return 1;
                }
                sorter->setDataAt(i, element);
            }
            inputFile.close();
        }

        // Show initial data
        cout<<"\nInitial Data: ";
        sorter->displayData();

        //display menu
        sorter->showMenu();
        while (!(cin >> choice) || choice < 1 || choice > 9 || (choice==7) || (choice==8)) {

            if (choice==7 || choice==8) {
                if (!allIntegers(sorter, size)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nCount Sort and Radix Sort are only for integers!\n"
                           "Please choose another sorting algorithm : ";
                }
            }else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid choice! Please enter 1-9: ";
            }
        }

        switch (choice) {
            case 1: sorter->measureSortTime(&SortingSystem<string>::insertionSort); break;
            case 2: sorter->measureSortTime(&SortingSystem<string>::selectionSort); break;
            case 3: sorter->measureSortTime(&SortingSystem<string>::bubbleSort); break;
            case 4: sorter->measureSortTime(&SortingSystem<string>::shellSort); break;
            case 5: sorter->mergeSort(0, size - 1); break;
            case 6: sorter->quickSort(0, size - 1); break;
            case 7: sorter->measureSortTime(&SortingSystem<string>::countSort); break;
            case 8: sorter->measureSortTime(&SortingSystem<string>::radixSort); break;
            case 9: sorter->measureSortTime(&SortingSystem<string>::bucketSort); break;
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
