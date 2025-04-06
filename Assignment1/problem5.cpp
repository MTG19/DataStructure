#include <iostream>
using namespace std;
class StatisticalCalculation {
private:
    int*numbers;
    int size;
void bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                    swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}
public:
    StatisticalCalculation(int arr[],int n){
    size=n;
    numbers=new int[size];
     for (int i = 0; i < size; i++)
            numbers[i] = arr[i];
        bubbleSort();
    }

    ~StatisticalCalculation() {
        delete[] numbers;
    }

    double findMedian() {
        if (size % 2 == 0)
            return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
        else
            return numbers[size / 2];
    }

    int findMinimum() {
        return numbers[0];
    }

    int findMaximum() {
        return numbers[size - 1];
    }

    double findMean() {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += numbers[i];
        return (double)sum / size;
    }

    int findSummation() {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += numbers[i];
        return sum;
    }
    };
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    StatisticalCalculation stats(arr, n);
    delete[] arr;

    while (true) {
        cout << "\nSelect a statistical calculation:\n";
        cout << "1. Find Median\n2. Find Minimum\n3. Find Maximum\n4. Find Mean\n5. Find Summation\n6. Exit\n";
        cout << "Enter your choice (1-6): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: cout << "Median: " << stats.findMedian() << endl; break;
            case 2: cout << "Minimum: " << stats.findMinimum() << endl; break;
            case 3: cout << "Maximum: " << stats.findMaximum() << endl; break;
            case 4: cout << "Mean: " << stats.findMean() << endl; break;
            case 5: cout << "Summation: " << stats.findSummation() << endl; break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
