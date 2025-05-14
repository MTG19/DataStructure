
#include <iostream>

using namespace std;

int minFlips(int* arr, int n, int k) {
    // Array to track where flips start
    int* flipEffect = new int[n];
    for (int i = 0; i < n; i++) {
        flipEffect[i] = 0;
    }

    int flipCount = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (i >= k) {
            flipCount -= flipEffect[i - k];
        }

        // Determine actual value at arr[i] after flips
        int actualBit = arr[i];
        if (flipCount % 2 != 0) {
            actualBit = 1 - actualBit; // flip the bit
        }

        if (actualBit == 0) {
            if (i + k > n) {
                delete[] flipEffect;
                return -1; // when it is not possible, return -1.
            }

            flipEffect[i] = 1; // Mark start of a new flip
            flipCount++;
            res++;
        }
    }

    delete[] flipEffect;
    return res;
}

int main() {
    int n, k;
    cout << "Enter size of the array: ";
    cin >> n;

    cout << "Enter value of k: ";
    cin >> k;

    int* arr = new int[n];

    cout << "Enter " << n << " binary values (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Invalid input. Only 0 or 1 allowed." << endl;
            delete[] arr;
            return 1;
        }
    }

    int result = minFlips(arr, n, k);
    cout << "Minimum number of flips: " << result << endl;

    delete[] arr;
    return 0;
}

