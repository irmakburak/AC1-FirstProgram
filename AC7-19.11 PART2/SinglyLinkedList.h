#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addAtFront(T value) {
        Node<T>* newNode = new Node<T>(value, head);
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void addAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value, nullptr);

        if (tail == nullptr) { 
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void removeFromFront() {
        if (head == nullptr)
            return;

        Node<T>* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
    }

    void removeFromEnd() {
        if (head == nullptr)
            return;

        if (head->next == nullptr) { 
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        tail = temp;
    }

    int size() const {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif
