#include "UnsortedLinkedList.h"

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

void UnsortedLinkedList::PutItem(int item) {
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;
    length++;
}

void UnsortedLinkedList::PrintList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void UnsortedLinkedList::GetItem(int item, bool &found) const {
    found = false;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            found = true;
            break;
        }
        current = current->next;
    }
}

bool UnsortedLinkedList::IsFull() const {
    return false; // Linked list can't be full
}

void UnsortedLinkedList::DeleteItem(int item) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == item) {
            if (prev == nullptr) {
                // Item to delete is at the head of the list
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            length--;
            break;
        }

        prev = current;
        current = current->next;
    }
}

void UnsortedLinkedList::MakeEmpty() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}
