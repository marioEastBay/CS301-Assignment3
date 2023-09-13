#ifndef UNSORTEDLINKEDLIST_H
#define UNSORTEDLINKEDLIST_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class UnsortedLinkedList {
private:
    Node* head;
    int length;

public:
    // Constructor
    UnsortedLinkedList();

    // Destructor
    ~UnsortedLinkedList();

    // Get the current length of the list
    int GetLength() const;

    // Add an item to the list
    void PutItem(int item);

    // Print the contents of the list to the console
    void PrintList() const;

    // Get an item from the list and set 'found' to true if found, false otherwise
    void GetItem(int item, bool &found) const;

    // Check if the list is full (for a linked list, it's never full)
    bool IsFull() const;

    // Delete an item from the list
    void DeleteItem(int item);

    // Make the list empty
    void MakeEmpty();
};

#endif
