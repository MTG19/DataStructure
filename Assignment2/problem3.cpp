
#include <iostream>
#include <string>
#include <fstream>

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
    while (true) {
        cout << "\nChoose input method:\n";
        cout << "1. Manual entry\n";
        cout << "2. Load from file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1/2/3): ";

        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }

        int n, k;
        int* arr = nullptr;

        if (choice == 1) {
            cout << "Enter size of the array: ";
            cin >> n;

            cout << "Enter value of k: ";
            cin >> k;

            arr = new int[n];
            cout << "Enter " << n << " binary values (0 or 1): ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
                if (arr[i] != 0 && arr[i] != 1) {
                    cout << "Invalid input. Only 0 or 1 allowed.\n";
                    delete[] arr;
                    continue;
                }
            }
        } else if (choice == 2) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;

            ifstream file(filename);
            if (!file.is_open()) {
                cout << "Failed to open file.\n";
                continue;
            }

            file >> n >> k;
            arr = new int[n];
            for (int i = 0; i < n; i++) {
                file >> arr[i];
                if (arr[i] != 0 && arr[i] != 1) {
                    cout << "Invalid input in file. Only 0 or 1 allowed.\n";
                    delete[] arr;
                    file.close();
                    continue;
                }
            }
            file.close();
        } else {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        int result = minFlips(arr, n, k);
        cout << "Minimum number of flips: " << result << endl;
        delete[] arr;

        string again;
        cout << "Do you want to perform another action? (yes/no): ";
        cin >> again;
        if (again != "yes" && again != "y") {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}

