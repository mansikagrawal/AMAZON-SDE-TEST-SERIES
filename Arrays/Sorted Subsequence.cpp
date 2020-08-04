/*   Sorted subsequence of size 3 
Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Input:
The first line of input contains an integer T denoting the no of test cases.
 Then T test cases follow.
 The first line of each test case contains an integer N denoting the size of the array A in the next line are N space-separated values of the array A.

Output:
For each test case in a new line,
 the output will be 1 if the sub-sequence returned by the function is present in array A else 0. 
If the sub-sequence returned by the function is not in the format as mentioned then the output will be -1.

User Task:
Your task is to complete the function find3Numbers which finds any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. 
You need to return them as a vector, if no such element is present then return the empty vector of size 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 106, for each valid i

Example:
Input:
2
5
1 2 1 1 3
3
1 1 3
Output:
1
0

Explanation:
Test case 1: a sub-sequence 1 2 3 exist.
Test case 2: no such sub-sequence exist. */

/* Hint - 1) Create an auxiliary array smaller[0..n-1]. smaller[i] should store the index of a number which is smaller than arr[i] 
and is on left side of arr[i]. smaller[i] should contain -1 if there is no such element.
2) Create another auxiliary array greater[0..n-1]. greater[i] should store the index of a number which is greater than arr[i] 
and is on right side of arr[i]. greater[i] should contain -1 if there is no such element.
3) Finally traverse both smaller[] and greater[] and find the index i for which both smaller[i] and greater[i] are not -1.  */

#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int>& v1, vector<int>& v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

vector<int> find3Numbers(vector<int>, int);

// Driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        auto res = find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}

/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> arr, int n)
{
    // Your code here
    int max = n - 1;
    int* smaller = new int[n];
    int* greater = new int[n];
    int min = 0;
    // find smalller array
    smaller[0] = -1;
    greater[n - 1] = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[min]) {
            min = i;
            smaller[i] = -1;
        }
        else {
            smaller[i] = min;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[max]) {
            max = i;
            greater[i] = -1;
        }
        else {
            greater[i] = max;
        }
    }
    vector<int> v;

    for (int i = 0; i < n; i++) {
        if (smaller[i] != -1 and greater[i] != -1) {
            v.push_back(arr[smaller[i]]);
            v.push_back(arr[i]);
            v.push_back(arr[greater[i]]);
            return v;
        }
    }
    delete[] smaller;
    delete[] greater;
    return v;
}
