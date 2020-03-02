#include "LinkedList.h"

LinkedList::LinkedList() {
    front = NULL;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(int value) { 
    if (front == NULL) {
        front = new ListNode(value);
    }
    else {
        ListNode* current = front; 
        while (current->next != NULL) {
            current = current->next;
        } 
        current->next = new ListNode(value);
    }
}

int LinkedList::get(int index) const {
    ListNode* current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void LinkedList::set(int index, int value) {
    ListNode* current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;        
}

void LinkedList::insert(int index, int value) {
    if (index == 0) {
        ListNode* oldFront = front;
        front = new ListNode(value);
        front->next = oldFront;
    }
    ListNode* current = front;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    ListNode* temp = new ListNode(value);
    temp->next = current->next;
    current->next = temp;

}

void LinkedList::remove(int index) {
    ListNode* trash;
    if (index == 0) {
        trash = front;
        front = front->next;
    }
    else {
        ListNode* current = front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        trash = current->next; 
        current->next = current->next->next;
    }
    delete trash;
}

void LinkedList::clear() {
    while (front != NULL) {
        remove(0);
    } 
}

bool LinkedList::isEmpty() const {
    if (front == NULL) {
        return true;
    }
    else return false;
}

int LinkedList::size() const {
    int sum = 0;
    if (front != NULL) {
        ListNode* current = front;
        sum = 1;
        while(current->next != NULL) {
            current = current->next;
            sum += 1;
        }        
    }
    return sum;
};
