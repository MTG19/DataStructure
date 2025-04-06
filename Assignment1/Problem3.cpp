#include <iostream>
#include <stdexcept>     //To handle exceptions
using namespace std;

class Node {     //Node class for linked list
public:
    int data;     //To store the value of the node
    Node* next;     //A pointer to the next node
    Node(int val) : data(val), next(nullptr) {}     //constructor to initialize the node
};

class SortedLinkedList {     //Sorted linked list class
private:
    Node* head;     //Pointer to the head of the linked list

public:
    SortedLinkedList() : head(nullptr) {}     //Constructor to initialize empty lis

    void insert(int value) {     //Function to insert a value
        Node* newNode = new Node(value);     //To create a new node with the inserted value
        if (!head || value < head->data) {     //Insert at the beginning if the list is empty || the new value is smaller than head
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* curr = head;     //Else start from the head
            while (curr->next && curr->next->data < value) {      //Find the correct position to insert
                curr = curr->next;
            }
            newNode->next = curr->next;      //To insert the new node in its right index
            curr->next = newNode;
        }
    }

    void remove(int index) {     //Function to remove a node at a given index
        if (!head) return;     //If list is empty, don't dp anything

        if (index == 0) {     //In case of removing the head
            Node* temp = head;     //Store the head
            head = head->next;     //Move the head to the next node
            delete temp;     //Delete the old head which was stored
            return;
        }

        Node* curr = head;      //Start from the head
        for (int i = 0; curr->next && i < index - 1; i++) {     //Traverse to the node before the one should be deleted
            curr = curr->next;
        }

        if (curr->next) {     //Delete the next node if available
            Node* temp = curr->next;     //Store the node which should be deleted
            curr->next = curr->next->next;     //Update the link
            delete temp;     //Delete stored node
        }
    }

    //Overload output operator to print the linked list
    friend ostream& operator<<(ostream& os, const SortedLinkedList& list) {
        os << "[";     //Start printing the list
        Node* curr = list.head;     //Start from the head
        while (curr) {
            os << curr->data;     //Print the node value
            if (curr->next) os << ", ";     //Print comma if there is more nodes
            curr = curr->next;     //Move to the next
        }
        os << "]";     //End printing the list
        return os;
    }

    //Overload index operator to access elements
    int operator[](int index) {
        Node* curr = head;     //Start from the head

        for (int i = 0; curr && i < index; i++) {
            curr = curr->next;     //Move to the next
        }
        if (!curr) throw out_of_range("Index is out of bounds");     //Handle invalid index
        return curr->data;     //Return the found value
    }

    ~SortedLinkedList() {     //Destructor to free allocated memory
        while (head) {
            Node* temp = head;     //Store the current node
            head = head->next;     //Move the head to the next node
            delete temp;     //Delete the current node
        }
    }
};

int main() {
    SortedLinkedList L;     //Create empty sorted linked list
    int choice, value, index;

    while (true) {
        cout << "\nChoose operation:\n";
        cout << "1. Insert\n2. Remove\n3. Display\n4. Access by Index\n5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                L.insert(value);
                cout << "List: " << L << endl;
                break;

            case 2:
                cout << "Enter the index to remove: ";
                cin >> index;
                L.remove(index);
                cout << "List: " << L << endl;
                break;

            case 3:
                cout << "List: " << L << endl;
                break;

            case 4:
                cout << "Enter the index to access: ";
                cin >> index;
                try {
                    cout << "Element at the index " << index << " is: " << L[index] << endl;
                } catch (const out_of_range& e) {
                    cout << "\nError: " << e.what() << endl;
                }
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice, Please Try again!" << endl;
        }
    }
}




/*

Test Case 1: Insertion

L.insert(5); //L = [5]
L.insert(8); //L = [5, 8]
L.insert(7); //L = [5, 7, 8]
L.insert(6); //L = [5, 6, 7, 8]
L.insert(6); //L = [5, 6, 6, 7, 8]
cout << L;   //Output: [5, 6, 6, 7, 8]
--------------------------------------------------
Test Case 2: Deleting

//Starting List: [5, 6, 6, 7, 8]
L.remove(0);  //L = [6, 6, 7, 8]
cout << L;    //Output: [6, 6, 7, 8]
L.remove(100); //No change (out of bounds)
cout << L;    //Output: [6, 6, 7, 8]
L.remove(2);  //L = [6, 6, 8]
cout << L;    //Output: [6, 6, 8]
L.remove(2);  //L = [6, 6]
cout << L;    //Output: [6, 6]
--------------------------------------------------
Test Case 3: Accessing elements using index operator

cout << L[2];  //Output: 6
cout << L[10]; //Throws out_of_range exception

*/