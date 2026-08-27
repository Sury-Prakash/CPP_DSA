
 public  class LinkedList{
  Node head;

  class Node{
    int data;
    Node next;

    Node(int data){
      this.data=data;
      this.next=null;
    }
  }
    public void addFirst(int data){
     Node newNode=new Node(data);
     if(head==null){
      head=newNode;
      return;
     }else{
      newNode.next=head;
      head=newNode;
     }
  }
  public void printLL(){
    Node temp=head;
    while(temp  != null){
          System.err.print(temp.data+"->");
          temp=temp.next;
    }
    System.err.println("Null");
  }




  public static void main(String args[]){
    LinkedList ll = new LinkedList();
    ll.addFirst(1);
    ll.addFirst(2);
    ll.printLL();
  }
}
 