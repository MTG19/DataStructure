
#ifndef SORTINGSYSTEM_H
#define SORTINGSYSTEM_H

#include <iostream>
using namespace std;

template <typename T>
class SortingSystem {
private:
    T* data; // Dynamic array for storing input data
    int size; // Size of the array

public:
    SortingSystem(int n); // Construction
    ~SortingSystem(); // Destructor

    void insertionSort(); // (1) Insertion Sort
    void selectionSort(); // (2) Selection Sort
    void bubbleSort(); // (3) Bubble Sort
    void shellSort();

    void shellsSort(); // (4) Shell Sort
    void mergeSort(int left, int right); // (5) Merge Sort
    void quickSort(int left, int right); // (6) Quick Sort
    void countSort(); // (7) Count Sort (Only for int)
    void radixSort(); // (8) Radix Sort (Only for int)
    void bucketSort(); // (9) Bucket Sort

    void merge(int left, int mid, int right); // Merge Sort Helper
    int partition(int low, int high); // Quick Sort Helper

    void displayData(); // Print the current state of the array
    void measureSortTime(void (SortingSystem::*sortFunc)()); // Measure sorting time

    void showMenu(); // Display menu for user interaction

    T& getDataAt(int index) {
        return data[index];
    }
    T& setDataAt(int index , const T& value) {
        data[index] = value;
        return data[index];
    }
};

#endif //SORTINGSYSTEM_H
