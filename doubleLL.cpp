#include<iostream>
#include<list>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  Node(int val){
    data=val;
    next=NULL;
    prev=NULL;

  }
};
 
class doubleList{
  Node* head;
  Node* tail;

  public:
  doubleList(){
    head=tail=NULL;
  }
  void push_front(int val){
    Node* newNode=new Node(val);
    if(head==NULL){
      head=tail=newNode;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
  }

  void push_back(int val){
  Node* newNode=new Node(val);
   if(head==NULL){
     head=tail=newNode;
   }
    newNode->prev=tail;
   tail->next=newNode;
   tail=newNode;
  }
  void printNode(){
    Node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"<=>";
      temp=temp->next;
    }
    cout<<"NULL";
   }
   void pop_front(){
      if(head==NULL){
        cout<<"DLL is empty";
        return;
      }
      Node* temp=head;
      head=head->next;
      if(head !=NULL){
        head->prev=NULL;
      }
      temp->next=NULL;
      delete temp;
   }
   void pop_back(){
    if(head==NULL){
      cout<<"DLL is empty";
      return;
    }
    Node* temp=tail;
    tail=tail->prev;
     if(tail !=NULL){
      tail->next=NULL;
     }
     temp->prev=NULL;
     delete temp;
   }
  };
int main(){
  doubleList ll;
  ll.push_front(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
 // ll.printNode();
  ll.pop_front();
 // ll.printNode();
  ll.pop_back();
  //ll.pop_back();
  ll.printNode();
  return 0;
}