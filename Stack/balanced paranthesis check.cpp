#include <bits/stdc++.h>
using namespace std;

void paracheck(string &str)
{
    
    stack<char> s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(' or  str[i] == '{' or str[i] == '[')
        s.push(str[i]);
        if(str[i]==')' or str[i] == '}' or str[i] == ']')
        {
            s.pop();
        }
    }
  
    if(s.empty()==true)
    cout << " Balanced ";
    else
    cout << " Not Balanced ";
}
int main() {

string str;
cin>>str;

paracheck(str);
	return 0;
}