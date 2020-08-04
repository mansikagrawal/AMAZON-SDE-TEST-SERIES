/* Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 

Input: 
The first line of the input contains T denoting the number of test cases.
The first line of each test case contains two space-separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation.
The subsequent line will contain N space-separated array elements.

Output:
For each test case, in a new line, print the rotated array.

Your Task:
Complete the function rotateArr() which takes the array, D and N as input parameters and rotates the array by D elements. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 200
1 <= N <= 107
1 <= D <= N
0 <= arr[i] <= 105

Example:
Sample Input:
2
5 2
1 2 3 4 5 
10 3
2 4 6 8 10 12 14 16 18 20

Sample Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6

Explanation :
Testcase 1: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.
Testcase 2: 2 4 6 8 10 12 14 16 18 20  when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.      */

#include <bits/stdc++.h>
using namespace std;

void rotateArr(int a[], int d, int n)
{

    // first reverse the d elements
    reverse(a, a + d);

    // now reverse the last n-d elements
    reverse(a + d, a + n);

    // finally, reverse the whole array
    reverse(a, a + n);
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        rotateArr(arr, d, n);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
