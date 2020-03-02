#include "LinkedList.h"

void printer(LinkedList& a);

int main() {

    LinkedList a;

    a.add(5); 
    a.add(77); 
    a.add(-2); 
    a.add(32); 
    printer(a); //print
    a.remove(2); 
    printer(a); //print
    cout<<"size is "<<a.size()<<endl;
    cout<<"is empty "<<a.isEmpty()<<endl;
    a.insert(2, 55);
    printer(a); //print
    a.set(2, 35);
    printer(a); //print
    a.clear();
    cout<<"New Size "<<a.size()<<endl;
    cout<<"isEmpty? "<<a.isEmpty();

    return 0;
}

void printer(LinkedList& a) {
        for (int i = 0; i < a.size(); i++) {
        cout<<a.get(i)<<endl;
    }
}
