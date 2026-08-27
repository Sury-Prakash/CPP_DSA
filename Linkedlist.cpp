#include<iostream>
using namespace std;


class Node{
  public:
  int data;
  Node* next;

  Node(int val){
    data=val;
    next=NULL;
  }
};

class List{
  Node* head;
  Node* tail;

  public:
  List(){
    head=tail=NULL;
  }
   //add push_front
  void push_front(int val){
    Node* newNode= new Node(val);
    if(head==NULL){
       head=tail=newNode;
    }else{
      newNode->next=head;
      head=newNode;
    }
  }
  //add push_back
  void push_back(int val){
       Node* newNode = new Node(val);
       if(head==NULL){
        head=tail=newNode;
       }else{
        tail->next=newNode;
        tail=newNode;
       }
  }
  void pop_front(){
    if(head==NULL){
      cout<<" LL is Empty";
    }
     Node* temp=head;
     head=head->next;
     temp->next=NULL;
     delete temp;
  }

  void pop_back(){
   if(head==NULL){
    cout<<"LL is empty";
   }
   Node* temp=head;
   while(temp->next !=tail){
      temp=temp->next; 
   }
    temp->next=NULL;
     delete tail;
     tail=temp;
  }
  
  // idx -> search key 
  int search(int kay){
    Node* temp=head;
    int idx=0;
    while(temp !=NULL){
      if(temp->data==kay){
          return idx;
      }
      temp=temp->next;
      idx++;
    }
    return -1;
  }

  //insert 
  void insert(int val, int pos){
      if(pos<0){
        cout<<"Invalid pos";
      }
      if(pos==0){
        push_front(val);
        return;
      }
    Node* temp=head;
    for(int i=0; i<pos-1; i++){
      if(temp==NULL){
        cout<<"Invalid pos";
      }
      temp=temp->next;
    }
    Node* newNode =new Node(val);
    newNode->next=temp->next;
    temp->next=newNode;
  }

  void printList(){
    Node* temp=head;
    while(temp !=NULL){
      cout<<temp->data<<" ->";
      temp=temp->next;
    }
    cout<<"NULL";
  }
};
int main(){
 List ll;
 ll.push_front(1);
 ll.push_front(2);
 ll.push_front(3);
 ll.push_front(4);
 //cout<<ll.search(1);
 //ll.printList();
 ll.push_back(5);
 ll.push_back(7);
 ll.pop_front();
 ll.printList();
   ll.insert(2,1);
  ll.printList();

}