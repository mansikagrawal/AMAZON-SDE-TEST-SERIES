#include <bits/stdc++.h>
using namespace std;
class Stack{
  private:
  int top;
  int arr[1000];
  public:
  Stack()
  {
      top=-1;
  }
  void push(int x)
  {
      top++;
      arr[top] = x;
  }
  int pop()
  {
      if(top==-1)
      return -1;
      int x = arr[top];
      top--;
      return x;
  }
  void printstack()
  {
      int cnt=top;
      while(cnt!=-1)
      {
          cout << arr[cnt] << " ";
          cnt--;
      }
  }
  
  
};
int main() {
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.printstack(); 
cout << endl;
cout << s.pop()<<endl;
	return 0;
}