#include <bits/stdc++.h>
using namespace std;
 void transfer(stack<int> &s1, stack<int> &s2, int n )
 {
     for(int  i=1;i<=n;i++)
     {
         s2.push(s1.top());
         s1.pop();
     }
     
 }
void reversestack(stack<int> &s1)
{
   
    stack<int> s2;
    int n = s1.size();
     for(int i=1;i<=s1.size();i++)
     {int x = s1.top();
     s1.pop();
         transfer(s1, s2,n-i );
         s1.push(x);
         transfer(s2,s1,n-i);
     }
    
}

int main() {
	
	stack<int> s ;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	reversestack(s);
    // Output should be 1 2 3 4 if the stack is reversed 
	while(!s.empty())
	{
	    cout << s.top()<<endl;
	    s.pop();
	}
	return 0;
}