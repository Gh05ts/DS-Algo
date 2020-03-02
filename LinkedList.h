#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <string>

using namespace std;

struct ListNode { 
    int data;
    ListNode* next;

    ListNode(int d = 0, ListNode* n = NULL) {
        data = d;
        next = n;
    }
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        void add(int value);
        void clear();
        int get(int index) const;
        void insert(int index, int value);
        bool isEmpty() const;
        void remove(int index);
        void set(int index, int value);
        int size() const;

        friend ostream& operator <<(ostream& out, LinkedList&);

    private:
        ListNode* front;
};

#endif















