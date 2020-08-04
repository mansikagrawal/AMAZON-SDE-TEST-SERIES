/* Remove duplicates in small prime array 
Given an array consisting of only prime numbers, remove all duplicate numbers from it. 
Note: Retain the first occurrence of the duplicate element.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines,
first of which contains N, the size of array. The second line contains N space separated elements of the array. 

Output:
Print the resultant array with no duplicate elements. 

Your Task:
Complete the function removeDuplicate() that takes given array and N as input parameters and returns modified array which has no duplicates.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=T<=200
1<=N=1000
2<=A[i]<100

Example:
Sample Input:
1
6
2 2 3 3 7 5

Sample Output:
2 3 7 5

Explanation:
After removing the duplicate 2 and 3 we get 2 3 7 5. */

#include <bits/stdc++.h>
using namespace std;
vector<int> removeDuplicate(vector<int>& arr, int n);

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        vector<int> result = removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}

vector<int> removeDuplicate(vector<int>& arr, int n)
{
    int dp[100] = { 0 };
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (dp[arr[i]] == 0) {
            dp[arr[i]] = 1;
            v.push_back(arr[i]);
        }
    }
    return v;
}
