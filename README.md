### **📌 Introduction to Data Structures Assignment #1**

This assignment focuses on **object-oriented programming (OOP) and fundamental data structures** in **C++**, reinforcing concepts like **dynamic memory allocation, linked lists, sorting algorithms, and stack-based computation**. The goal is to develop efficient, well-structured solutions **without using STL** while ensuring proper memory management.

Each problem is designed to strengthen your understanding of **data structures and algorithms**, emphasizing:  
✔ **Linked Lists** (for managing polynomial expressions and sorted data)  
✔ **Dynamic Memory Management** (for handling growing data efficiently)  
✔ **Sorting Algorithms** (implementing and visualizing different techniques)  
✔ **Stacks** (for expression evaluation)  
✔ **Operator Overloading** (for intuitive operations on custom data structures)

Your **Data Structures Assignment #1** consists of **five** problems in **C++**, without using **STL**. Below is a structured plan to tackle each problem efficiently.

---

### ✅ **Problem 1: Iftar Invitation Manager**
Implement an **OOP-based** system to manage Iftar invitations.

- **Create a `Guest` class** with attributes:
    - `name` (string)
    - `contactInfo` (string)
    - `status` (enum: Pending, Accepted, Declined)

- **Create an `InvitationManager` class** to:
    - Store and manage guests dynamically.
    - Add, remove, and update guests' RSVP status.
    - Display the list of guests with their statuses.

- **Use dynamic memory allocation** to handle guests efficiently.

---

### ✅ **Problem 2: Polynomial Operations**
Perform operations on polynomials using **linked lists**.

- **Create a `Node` struct** representing a polynomial term:
    - `coefficient` (int)
    - `exponent` (int)
    - `next` (pointer to next term)

- **Create a `Polynomial` class** with methods:
    - `insertTerm(int coeff, int exp)`: Adds a new term while maintaining order.
    - `add(Polynomial&)`: Returns the sum of two polynomials.
    - `subtract(Polynomial&)`: Returns the difference of two polynomials.
    - `multiply(Polynomial&)`: Returns the product of two polynomials.
    - `display()`: Prints the polynomial in a readable format.

- **Avoid duplicate exponents** by merging terms when inserting.

---

### ✅ **Problem 3: Sorted Linked List**
Implement a **sorted singly linked list** with operators.

- **Create a `Node` struct** with:
    - `data` (int)
    - `next` (pointer to next node)

- **Create a `SortedLinkedList` class** with:
    - `insert(int value)`: Inserts while maintaining order.
    - `remove(int value)`: Deletes a specific element.
    - `operator+` (merging two lists).
    - `operator<<` (printing the list).

- **Ensure efficient insertion/deletion** without unnecessary traversals.

---

### ✅ **Problem 4: Nine Sorting Algorithms with Templates**
Implement and display **9 sorting algorithms**, supporting different data types.

- **Use function templates** to handle multiple data types.
- Implement the following **sorting algorithms**:
    1. **Bubble Sort**
    2. **Selection Sort**
    3. **Insertion Sort**
    4. **Merge Sort**
    5. **Quick Sort**
    6. **Heap Sort**
    7. **Shell Sort**
    8. **Radix Sort**
    9. **Bucket Sort**

- **Display each sorting step** for visualization.

---

### ✅ **Problem 5: Stack-based Expression Evaluator**
Implement a **stack-based system** for evaluating arithmetic expressions.

- **Use a manually implemented stack** (not STL) to:
    - Convert **infix expressions** to **postfix**.
    - Evaluate the **postfix** expression.

- **Create a `Stack` class** using an array or linked list with:
    - `push(int value)`, `pop()`, `peek()`, `isEmpty()`.

- **Create an `ExpressionEvaluator` class** with:
    - `convertToPostfix(string infix)`.
    - `evaluatePostfix(string postfix)`.

---

### ⚡ **Implementation Constraints**
✅ **No STL allowed** – Use raw pointers, manual memory management.  
✅ **Efficiency matters** – Optimize operations, avoid redundant traversals.  
✅ **Memory safety** – Handle memory leaks properly (use destructors).  
✅ **Edge cases** – Handle empty inputs, invalid operations, and duplicates.

---
