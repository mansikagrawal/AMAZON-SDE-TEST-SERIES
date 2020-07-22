/* Find duplicates in an array 
Given an array a[] of size N which contains elements from 0 to N-1,
 you need to find all the elements occurring more than once in the given array.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an integer N which denotes the number of elements in the array.
 The second line of each test case contains n space separated integers denoting elements of the array a[].

Output:
Print the duplicate elements from the given array. The order of the output should be in sorted order.
 Print -1 if no duplicate exists.

Your Task:
Complete the function duplicates() which takes array a[] and n as input as parameters 
and returns a list of elements that occur more than once in the given array in sorted manner. If no such element is found return -1. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Note : The extra space is only for the array to be returned.
Try and perform all operation withing the provided array. 

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= A[i] <= N-1, for each valid i

Example:
Sample Input:
2
4
0 3 1 2
5
2 3 1 2 3 

Sample Output:
-1
2 3 

Explanation:
Testcase 1: N=4 and all elements from 0 to (N-1 = 3) are present in the given array. Therefore output is -1.
Testcase 2: 2 and 3 occur more than once in the given array. */

/* Hint - 1- Traverse the given array from i= 0 to n-1 elements
     Go to index arr[i]%n and increment its value by n.
2- Now traverse the array again and print all those 
   indexes i for which arr[i]/n is greater than 1.

This approach works because all elements are in range
from 0 to n-1 and arr[i]/n would be greater than 1
only if a value "i" has appeared more than once. */

#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

vector<int> duplicates(int a[], int n)
{
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }

    for (auto x : mp) {
        if (x.second > 1)
            v.push_back(x.first);
    }
    if (v.size() == 0)
        v.push_back(-1);
    return v;

}
