#include <iostream>
#include "ListNode.h"
using namespace std;

int main() {

    ListNode* node1 = new ListNode();

    node1->data = 42;   
    node1->next = new ListNode();
    node1->next->data = -3;
    node1->next->next = new ListNode();
    node1->next->next->data = 17; 
    node1->next->next->next = new ListNode();
    node1->next->next->next->data = 99; 
    node1->next->next->next->next = NULL;
    // cout << node1->next->next->next->data;
    ListNode* current = node1;
    while(current != NULL) {
        cout<<current->data << endl;
        current = current->next;
    }
    
    return 0;
}