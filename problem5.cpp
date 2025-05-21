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
    bool isValidIntegerInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
int main()
{
    int n;

    // Input validation for number of elements
    while (true) {
        cout << "Enter the number of elements: ";
        cin >> n;
        if (!isValidIntegerInput() || n <= 0) {
            cout << "Invalid input! Please enter a positive integer.\n";
        } else {
            break;
        }
    }

    int* arr = new int[n];

    // Input validation for elements
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
            if (!isValidIntegerInput()) {
                cout << "Invalid input! Please enter an integer.\n";
            } else {
                break;
            }
        }
    }

    StatisticalCalculation stats(arr, n);
    delete[] arr;

    while (true) {
        cout << "\nSelect a statistical calculation:\n";
        cout << "1. Find Median\n2. Find Minimum\n3. Find Maximum\n4. Find Mean\n5. Find Summation\n";
        cout << "Enter your choice (1-5): ";

        int choice;
        while (true) {
            cin >> choice;
            if (!isValidIntegerInput() || choice < 1 || choice > 5) {
                cout << "Invalid choice! Please enter a number between 1 and 5: ";
            } else {
                break;
            }
        }

        switch (choice) {
            case 1: cout << "Median: " << stats.findMedian() << endl; break;
            case 2: cout << "Minimum: " << stats.findMinimum() << endl; break;
            case 3: cout << "Maximum: " << stats.findMaximum() << endl; break;
            case 4: cout << "Mean: " << stats.findMean() << endl; break;
            case 5: cout << "Summation: " << stats.findSummation() << endl; break;
        }
    }

    return 0;
}

/*


#Odd number of elements:
Test Case 1: 

Enter the number of elements: 5
Enter element 1: 3
Enter element 2: 1
Enter element 3: 4
Enter element 4: 5
Enter element 5: 2

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 3

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 1

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 5

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 3

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 15


//Test Case 2: 
Input:
Enter the number of elements: 5
Enter element 1: 1
Enter element 2: 3
Enter element 3: 1
Enter element 4: 3
Enter element 5: 1

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 1

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 1

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 3

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 1.8

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 9






# Even number of elements:
//Test Case 3: 
Enter the number of elements: 4
Enter element 1: 10
Enter element 2: 2
Enter element 3: 8
Enter element 4: 4

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 6

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 2

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 10

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 6

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 24



//Test Case 4: 
Input:
Enter the number of elements: 4
Enter element 1: 6
Enter element 2: 2
Enter element 3: 4
Enter element 4: 8

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 5

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 2

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 8

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 5

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 20



//Test Case 5: Contains zero
Input:
Enter the number of elements: 4
Enter element 1: 0
Enter element 2: 2
Enter element 3: 4
Enter element 4: 6

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 3

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 0

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 6

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 3

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 12



# All elements the same:
// Test Case 6: 
Input:
 Enter the number of elements: 4
Enter element 1: 7
Enter element 2: 7
Enter element 3: 7
Enter element 4: 7

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 7

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 7

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 7

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 7

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 28



//Test Case 7: 
Input:
Enter the number of elements: 1
Enter element 1: 42

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 42

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 42

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 42

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 42

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 42




# Single element:
// Test Case 8: 
Input:
Enter the number of elements: 1
Enter element 1: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 9


//Test Case 9:  
Input:
Enter the number of elements: 1
Enter element 1: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 9

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
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

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 1
Median: 3.5

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 2
Minimum: 1

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 3
Maximum: 6

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 4
Mean: 3.5

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 5
Summation: 21



#invalid input
//test case 11:
Enter the number of elements: 5
Enter element 1: 4
Enter element 2: 8
Enter element 3: 7
Enter element 4: 5
Enter element 5: 1

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): 6
Invalid choice! Please enter a number between 1 and 5:

//test case 12:
Enter the number of elements: 5
Enter element 1: 4
Enter element 2: 8
Enter element 3: 7
Enter element 4: 5
Enter element 5: 1

Select a statistical calculation:
1. Find Median
2. Find Minimum
3. Find Maximum
4. Find Mean
5. Find Summation
Enter your choice (1-5): a
Invalid choice! Please enter a number between 1 and 5:






 


*/
