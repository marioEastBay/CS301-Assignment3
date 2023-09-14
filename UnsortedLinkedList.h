#ifndef UNSORTEDLINKEDLIST_H
#define UNSORTEDLINKEDLIST_H

#include <iostream>
#include "ItemType.h"
using namespace std;

class Node {
public:
    ItemType data;
    Node* next;

    Node(ItemType value) : data(value), next(nullptr) {}
};

class UnsortedLinkedList {
private:
    Node* head;
    int length;
    Node* currentPos;
    Node* listData;

public:
    // Constructor
    UnsortedLinkedList();

    // Destructor
    ~UnsortedLinkedList();

    // Get the current length of the list
    int GetLength() const;

    // Add an item to the list
    void PutItem(ItemType item);

    // Print the contents of the list to the console
    void PrintList() const;

    // Get an item from the list and set 'found' to true if found, false otherwise
    ItemType GetItem(ItemType& item, bool& found);

    // Check if the list is full (for a linked list, it's never full)
    bool IsFull() const { return false;}

    // Delete an item from the list
    void DeleteItem(ItemType item);

    // Make the list empty
    void MakeEmpty();

    ItemType GetNextItem();

    void ResetList() { currentPos = nullptr;}
};

UnsortedLinkedList::UnsortedLinkedList() {
    head = nullptr;
    length = 0;
}

UnsortedLinkedList::~UnsortedLinkedList() {
    // Destructor code here, if needed
    MakeEmpty();
}

int UnsortedLinkedList::GetLength() const {
    return length;
}

void UnsortedLinkedList::PutItem(ItemType item) {
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;
    length++;
}

void UnsortedLinkedList::PrintList() const {
    Node* current = head;
    while (current != nullptr) {
        //cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

ItemType UnsortedLinkedList::GetItem(ItemType& item, bool &found) {
    bool moreToSearch;
    Node* location;

    location = listData;
    found = false;
    moreToSearch = (location != nullptr);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(location->data))
        {
            case LESS    :
            case GREATER : location = location->next;
                moreToSearch = (location != nullptr);
                break;
            case EQUAL   : found = true;
                item = location->data;
                break;
        }
    }
    return item;
}

void UnsortedLinkedList::DeleteItem(ItemType item) {
    Node* location = listData;
    Node* tempLocation;

    // Locate node to be deleted.
    if (item.ComparedTo(listData->data) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (item.ComparedTo((location->next)->data) != EQUAL)
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void UnsortedLinkedList::MakeEmpty() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

ItemType UnsortedLinkedList::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
    ItemType item;
    if (currentPos == nullptr)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->data;
    return item;
}
#endif