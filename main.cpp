#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Node.h"

using namespace std;

int main() {
    int x;
    Node* head= new Node();
    Node* current= head;
    cout<<"enter a list of integers and -1 to stop"<<endl;
    cin>>x;
    //populate the linked list with at least 7 nodes
    while(x!=-1){
       Node* n= new Node(x);
       current->InsertAfter(n);
       current=n; //current=current->getNext;
       cin>>x;

    }

    //print the nodes of the linked list
    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    //1) find the node that has the minimum value
    current = head->getNext();
    int minValue = current->getValue();
    while(current!=nullptr){
        if(minValue > current->getValue()){
            minValue = current->getValue();
        }
        current=current->getNext();
    }
    cout << "minValue: " << minValue;

    //2) remove the 4th node from the list

    //3) remove the last node

    //4) remove the first node

    //6) delete all nodes
    return 0;
}