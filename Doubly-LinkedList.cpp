#include<iostream>

using namespace std;
class Node{
  public:
  int data;
  Node *next;
  Node *previous;
 
  Node()
  {
      data=0;
      next=NULL;
      previous=NULL;
  }
  Node(int data)
  {
      this->data=data;
      next=NULL;
      previous=NULL;
  }
  void setData(int data)
  {
      this->data=data;
  }
  void setNext(Node* next)
  {
      this->next=next;
  }
  int getData()
  {
      return this->data;
  }
  Node* getNext()
  {
      return this->next;
  }
  Node* getPrevious()
  {
      return this->previous;
  }
  void setPrevious(Node* node)
  {
      this->previous=node;
  }
  
};
class LinkedList{
    
  Node *head;
  public:
  
  
  LinkedList()
  {
      head=NULL;
      
  }
  bool isEmpty()
  {
      return (head==NULL);
  }
  void insertAtBeginning(int val)
  {
      Node *n=new Node(val);
      n->next=head;
      if(head!=NULL)
      {
        head->previous=n;
      }
      head=n;
  }
  void removeFromBegin()
  {
      if(!isEmpty())//if list is not empty
      {
         Node *t=head->getNext();//pointing head to next Node
         delete head; //deleting Node 
         head=t; 
         
         //Alternate code:
        /* Node *t;  
         t=head->getNext();
         delete t;
         head=t;*/
        }
  }
   
 void get1stElement()
 {
     cout<<"\nPrinting 1st element:"<<endl;
     cout<<(head->getData()); 
 }
 Node * getLastElement(){
     Node * temp = head;
     if(temp!=NULL){
        while(temp->getNext()!=NULL){
            temp=temp->getNext();
        }
    }
    return temp;
    // cout<<head->getData();
}
 
 void printAllElements()
{   
    if(!isEmpty()){
    Node* temp=head;
    while (temp != NULL) {
        cout << temp->getData() <<"->";
        temp = temp->getNext();
    }
    cout << "NULL\n";
}
}

void getLength()
{
    if(!isEmpty())
    {
        int i=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            temp=temp->getNext();
            i++;
        }
        cout<<i;
    }
}   

  void insertNodeAtEnd(int val)
{
    Node *t1 = new Node(val);
   if(isEmpty()){
       head=t1;
   }
   else
   {
     Node *temp=head;
     while(temp->getNext()!=NULL)
     {
         temp=temp->getNext();
     }
     temp->setNext(t1);
     t1->setPrevious(temp);
   }
}
/*To delete the last node of a linked list, find the second last node and make the next pointer of that node null. */

    void removeFromLast(){
        Node * temp = head;
        Node * temp2 = head->getNext();
        
        while (temp2->getNext() != NULL){
            temp = temp->getNext();     // second last
            temp2 = temp2->getNext(); // last
        }
        delete temp2;
        temp->setNext(NULL);
    }

};

int main()
{
   LinkedList l1;
   cout<<l1.isEmpty();
   cout<<endl;
   //l1.insertAtBeginning(20);
   l1.insertNodeAtEnd(20);
   l1.insertNodeAtEnd(30);
   l1.insertNodeAtEnd(40);
   
    l1.printAllElements();
    
    l1.removeFromLast();
    l1.printAllElements();
   
   	
}
