/*
Third largest element
Given an array of distinct elements.
 Find the third largest element in it.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case is N, size of the array.
The second line of each test case contains N space separated values of the array a[].

Output:
Print the third largest element of the array. If the array has less than 3 elements print -1.

Your Task:
Complete the function thirdLargest() which takes the array a[]
and the size of the array, n, as input parameters and
returns the third largest element in the array.
It return -1 if there are less than 3 elements in the given array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105

Example:
Sample Input:
2
5
2 4 1 3 5
2
10 2

Sample Output:
3
-1

Explanation:
Test Case 1: Largest number is 5, followed by 4 and then 3. Hence, the answer is 3.
Test Case 2: Since there are less than 3 numbers, output is -1.     */

/* Hint - Use heaps to do this problem
          Make a min or max heap. It will take log n time
          Sort the heap and return the a[n-3] */

#include <bits/stdc++.h>
using namespace std;
int thirdLargest(int a[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << thirdLargest(a, n) << endl;
    }
}

int thirdLargest(int a[], int n)
{

    if (n < 3)
        return -1;
    // Max heap 
    make_heap(a, a + n);
    // Sorting the max heap
    sort_heap(a, a + n);

    return a[n - 3];
}
