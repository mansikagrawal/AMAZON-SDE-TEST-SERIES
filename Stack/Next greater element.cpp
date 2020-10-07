/* Given an array A[] of size N having distinct elements, the task is to find the 
next greater element for each element of the array in order of their appearance in the array.

Next greater element of an element in the array is the nearest element on the right which is greater than the current element.

If there does not exist next greater of current element, then next greater element
 for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
Example 2:

Input: 
N = 5, arr[] [6 8 0 1 3]
Output:
8 -1 1 3 -1
Explanation:
In the array, the next larger element to 
6 is 8, for 8 there is no larger elements 
hence it is -1, for 0 it is 1 , for 1 it 
is 3 and then for 3 there is no larger 
element on right and hence -1.
Your Task:
This is a function problem. You only need to complete the function nextLargerElement 
that takes array and n as parameters and returns an array of length n denoting the
 next greater elements for all the corresponding elements in the input array.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= N <= 106
1 <= Ai <= 1018
*/


/* *************HINT************** */
/*   With the use of the stack one can achieve the solution to the problem.
Follow the below algorithm for to achieve the solution.

1) Push the first element to stack.
2) Pick rest of the elements one by one and follow the following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is greater than the popped element, then next is the next greater element for the popped element.
….d) Keep popping from the stack while the popped element is smaller than next.next becomes the next greater element for all such popped elements
….e) Finally, push the next in the stack.
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.  */



#include<bits/stdc++.h>
using namespace std;


// Function to store Next larger elements
vector <long long> nextLargerElement(long long arr[], int n){
stack<long long> s;
vector<long long> v(n);
for(int i=n-1;i>=0;i--)
{
    while(!s.empty() and s.top() <= arr[i])
    s.pop();
    if(s.empty())
    v[i] = -1;
    else
    v[i] = s.top();
    s.push(arr[i]);
    
}
return v;

}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  