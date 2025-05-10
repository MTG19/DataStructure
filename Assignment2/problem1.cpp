//
// Created by israa on 5/10/2025.
//
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Node structure for stack
struct Node {
    char* url;
    Node* next;

    Node(const char* str) {
        url = new char[strlen(str) + 1];
        strcpy(url, str);
        next = nullptr;
    }

    ~Node() {
        delete[] url;
    }
};

// Custom stack (linked list implementation)
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        clear();
    }

    void push(const char* url) {
        Node* node = new Node(url);
        node->next = top;
        top = node;
    }

    char* pop() {
        if (isEmpty()) return nullptr;
        Node* temp = top;
        top = top->next;
        char* urlCopy = new char[strlen(temp->url) + 1];
        strcpy(urlCopy, temp->url);
        delete temp;
        return urlCopy;
    }

    char* peek() const {
        return isEmpty() ? nullptr : top->url;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Browser History Manager
class BrowserHistory {
private:
    Stack backStack;
    Stack forwardStack;
    char* currentUrl;

public:
    BrowserHistory() {
        currentUrl = nullptr;
    }

    ~BrowserHistory() {
        delete[] currentUrl;
    }

    void visit(const char* url) {
        if (currentUrl != nullptr)
            backStack.push(currentUrl);
        delete[] currentUrl;
        currentUrl = new char[strlen(url) + 1];
        strcpy(currentUrl, url);
        forwardStack.clear();
        cout << "Visited: " << currentUrl << endl;
    }

    void goBack() {
        if (backStack.isEmpty()) {
            cout << "Cannot go back!" << endl;
            return;
        }
        forwardStack.push(currentUrl);
        delete[] currentUrl;
        currentUrl = backStack.pop();
        cout << "Went back to: " << currentUrl << endl;
    }

    void goForward() {
        if (forwardStack.isEmpty()) {
            cout << "Cannot go forward!" << endl;
            return;
        }
        backStack.push(currentUrl);
        delete[] currentUrl;
        currentUrl = forwardStack.pop();
        cout << "Went forward to: " << currentUrl << endl;
    }

    void printCurrent() const {
        cout << "Current URL: " << (currentUrl ? currentUrl : "None") << endl;
    }
};

int main() {
    BrowserHistory browser;

    ifstream input("test3.txt");
    string command;
    while (input >> command) {
        if (command == "visit") {
            string url;
            input >> ws;
            getline(input, url);
            browser.visit(url.c_str());
        } else if (command == "back") {
            browser.goBack();
        } else if (command == "forward") {
            browser.goForward();
        } else if (command == "print") {
            browser.printCurrent();
        }
    }

    return 0;
}

