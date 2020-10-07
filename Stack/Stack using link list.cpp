#include<bits/stdc++.h>
using namespace std;

struct Mystack{

int data;
struct Mystack* next;

};
struct Mystack* top;

 int peek()
 {
 	if(top==NULL)
 		cout << "Stack empty";
 	else
 		return top->data;
 }
  void display()
  {
  	if(top==NULL)
  		cout << "Stack empty";
  	else
  	{
  		struct Mystack* node;
  		node = top;
  		while(node!=NULL)
  		{
  			cout << node->data << " ";
  			node=node->next;
  		}
  	}
  }
  void push(int x)
  {
  	struct Mystack* newnode;
  	newnode=new Mystack();
  	newnode->data=x;
  	newnode->next=top;
  	top=newnode;
  	
  }


  void pop()
  {
  	if(top==NULL)
  		cout << "Stack underflow";

struct  Mystack* newstack;
newstack = top;
top=top->next;
newstack->next=NULL;
free(newstack);


  }



  int main()
  {

 push(11);  
    push(22);  
    push(33);  
    push(44);  
  
    // Display stack elements  
    display();  
  
    // Print top element of stack  
    cout << "\nTop element is " << peek() << endl;  
  
    // Delete top elements of stack  
    pop();  
    pop();  
  
    // Display stack elements  
    display();  
  
    // Print top element of stack  
    cout << "\nTop element is "   << peek() << endl;  
           




  	return 0;
  }