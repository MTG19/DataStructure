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
        cout << "1. Find Median\n2. Find Minimum\n3. Find Maximum\n4. Find Mean\n5. Find Summation\n";
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: cout << "Median: " << stats.findMedian() << endl; break;
            case 2: cout << "Minimum: " << stats.findMinimum() << endl; break;
            case 3: cout << "Maximum: " << stats.findMaximum() << endl; break;
            case 4: cout << "Mean: " << stats.findMean() << endl; break;
            case 5: cout << "Summation: " << stats.findSummation() << endl; break;
            default: cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
/*


#Odd number of elements:
Test Case 1: 
Input:
Enter the number of elements: 5
Enter element 1: 3
Enter element 2: 1
Enter element 3: 4
Enter element 4: 5
Enter element 5: 2
Expected Output:
if user choose option 1 :
Median: 3
if user choose option 2 :
Minimum: 1
if user choose option 3 :
Maximum: 5
if user choose option 4 :
Mean: 3
if user choose option 5 :
Summation: 15

//Test Case 2: 
Input:
Enter the number of elements: 5
Enter element 1: 1
Enter element 2: 3
Enter element 3: 1
Enter element 4: 3
Enter element 5: 1
Expected Output:
if user choose option 1 :
Median: 1
if user choose option 2 :
Minimum: 1
if user choose option 3 :
Maximum: 3
if user choose option 4 :
Mean: 1.8
if user choose option 5 :
Summation: 9





# Even number of elements:
//Test Case 3: 
Input:
Enter the number of elements: 4
Enter element 1: 10
Enter element 2: 2
Enter element 3: 8
Enter element 4: 4
Expected Output:
if user choose option 1 :
Median: (4 + 8) / 2 = 6
if user choose option 2 :
Minimum: 2
if user choose option 3 :
Maximum: 10
if user choose option 4 :
Mean: (10 + 2 + 8 + 4) / 4 = 6
if user choose option 5 :
Summation: 24


//Test Case 4: 
Input:
Enter the number of elements: 4
Enter element 1: 6
Enter element 2: 2
Enter element 3: 4
Enter element 4: 8
Expected Output:
if user choose option 1 :
Median: 5
if user choose option 2 :
Minimum: 2
if user choose option 3 :
Maximum: 8
if user choose option 4 :
Mean: 5
if user choose option 5 :
Summation: 20


//Test Case 5: Contains zero
Input:
Enter the number of elements: 4
Enter element 1: 0
Enter element 2: 2
Enter element 3: 4
Enter element 4: 6
Expected Output:
if user choose option 1 :
Median: 3
if user choose option 2 :
Minimum: 0
if user choose option 3 :
Maximum: 6
if user choose option 4 :
Mean: 3
if user choose option 


# All elements the same:
// Test Case 6: 
Input:
Input:
Enter the number of elements: 4
Enter element 1: 7
Enter element 2: 7
Enter element 3: 7
Enter element 4: 7
Expected Output:
if user choose option 1 :
Median: 7
if user choose option 2 :
Minimum: 7
if user choose option 3 :
Maximum: 7
if user choose option 4 :
Mean: 7
if user choose option 5 :
Summation: 28


//Test Case 7: 
Input:
Enter the number of elements: 3
Enter element 1: 5
Enter element 2: 5
Enter element 3: 5
Expected Output:
if user choose option 1 :
Median: 5
if user choose option 2 :
Minimum: 5
if user choose option 3 :
Maximum: 5
if user choose option 4 :
Mean: 5
if user choose option 5 :
Summation: 15
  



# Single element:
// Test Case 8: 
Input:
Input:
Enter the number of elements: 1
Enter element 1: 42
Expected Output:
if user choose option 1 :
Median: 42
if user choose option 2 :
Minimum: 42
if user choose option 3 :
Maximum: 42
if user choose option 4 :
Mean: 42
if user choose option 5 :
Summation: 42

//Test Case 9:  
Input:
Enter the number of elements: 1
Enter element 1: 9
Expected Output:
if user choose option 1 :
Median: 9
if user choose option 2 :
Minimum: 9
if user choose option 3 :
Maximum: 9
if user choose option 4 :
Mean: 9
if user choose option 5 :
Summation: 9



#mixed numbers:
//Test Case 10: 
Input:
Enter the number of elements: 6
Enter element 1: 1
Enter element 2: 3
Enter element 3: 2
Enter element 4: 4
Enter element 5: 6
Enter element 6: 5
Expected Output:
if user choose option 1 :
Median: 3.5
if user choose option 2 :
Minimum: 1
if user choose option 3 :
Maximum: 6
if user choose option 4 :
Mean: 3.5
if user choose option 5 :
Summation: 21


 


*/
