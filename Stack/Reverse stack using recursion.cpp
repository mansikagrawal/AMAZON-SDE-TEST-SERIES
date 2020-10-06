#include <bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int> &s, int x)
{
    if(s.empty()==true){
    s.push(x);return;}
    int t= s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(t);
}
// The idea is to pop the first element and put it at the last and continue it till the whole 
// stack is reversed 
void reversestack(stack<int>&s)
{
    if(s.empty())
    return;
    int x = s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s,x);

}

int main() {
	
	stack<int> s ;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	reversestack(s);
	while(!s.empty())
	{
	    cout << s.top()<<endl;
	    s.pop();
	}
	return 0;
}