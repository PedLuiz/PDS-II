#include "list.hpp"

#include <iostream>

void List::insertNode(int data) {
    Node* aux = new Node;
    aux->data = data;
    aux->next = nullptr;
    if (head == nullptr) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
}

void List::display() {
    Node* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Você deverá implementar apenas esse método
void List::inverte() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    tail = head;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    } 
    head = prev;

    return;
}
