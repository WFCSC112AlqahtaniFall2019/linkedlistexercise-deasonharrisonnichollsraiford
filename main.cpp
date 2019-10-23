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
    cout << "minValue: " << minValue << endl;
    cout<<"Remove 4th node:"<<endl;

    //2) remove the 4th node from the list
    Node* prev=head;
    current = head->getNext();
    int counter = 1;
    while(current!= nullptr){
        counter++;
        prev = current;
        current = current->getNext();
        if(counter == 4){
            prev->setNext(current->getNext());
            current->setNext(nullptr);
            delete current;
            break;
        }
    }

    //Print part 2
    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    cout<<"Remove last node:"<<endl;
    //3) remove the last node
    Node* prev2=head;
    current = head->getNext();
    while(current!= nullptr){

        if (current->getNext() == nullptr) {
            prev2->setNext(nullptr);
            delete current;

        }
        prev2 = current;
        current = current->getNext();
    }

    //Print part 3
    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    cout<<"Remove first node:"<<endl;
    //4) remove the first node
    Node* prev3=head;
    current = head->getNext();
   if(current!= nullptr){
        prev3 = current;
        current = current->getNext();
        if(current!=nullptr){
            head->setNext(current);
            prev3->setNext(nullptr);
            delete prev3;
        }
    }

    //Print part 4
    current=head->getNext();
    while(current!=nullptr)
    {
        current->printNode();
        current=current->getNext();
    }

    cout << "Delete nodes:" << endl;
    //6) delete all nodes
    Node *prev4 = head;
    current = head->getNext();
    while (current != nullptr) {
        if (current->getNext() == nullptr) {
            prev2->setNext(nullptr);
            delete current;
            current = head->getNext();
        }
        prev2 = current;
        current = current->getNext();

    }
    return 0;
}