/*   Max sum path in two arrays 
Given two sorted arrays A and B, such that the arrays may have some common elements.
Find the sum of the maximum sum path to reach from the beginning of any array to end of any of the two arrays.
We can switch from one array to another array only at the common elements.

Input:
First line of input contains number of testcases T. For each testcase, there will be three lines.
First line contains M and N denoting the length of the two sorted array A and B respectively.
Second line contains elements of array A. Third line contains elements of array B.

Output:
For each test case, the output is the max sum obtained from the two arrays.

Your Task:
Complete the function max_path_sum() that takes the two arrays A and B along with their sizes M and N as input parameters. 
It returns the sum of the maximum sum path.

Expected Time Complexity: O(M + N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= M,N <= 105
1 <= A[i], B[i] <= 106

Example:
Sample Input:
2
5 4
2 3 7 10 12
1 5 7 8 
3 3
1 2 4
1 2 7

Sample Output:
35 
10

Explanation:
Testcase 1: The path will be 1+5+7+10+12 = 35.
Testcase 2: The path will be 1+2+7=10.     */

#include <bits/stdc++.h>
using namespace std;

int max_path_sum(int[], int[], int, int);

int main()
{
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];
        int result = max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

/* Hint -    
 Use two pointers to iterate over two arrays
    while (i < m && j < n)
    {
if ar1 is smaller than ar2, incresing ar1 and adding its value to sum1
            sum1 += ar1[i++];
if ar2 is smaller than ar1, incresing ar2 and adding its value to sum2
            sum2 += ar2[j++];
if ar1=ar2, checking the maximum sum obtained from both the arrays updating result and sum1 and sum2 is again changed to zero
result += max(sum1, sum2);
            sum1 = 0, sum2 = 0;
            while (i < m &&  j < n && ar1[i] == ar2[j])
            {
                result = result + ar1[i++];
                j++;
            } */
int max_path_sum(int a[], int b[], int m, int n)
{

    int i = 0, j = 0, sum1 = 0, sum2 = 0, result = 0;

    while (i < m and j < n) {
        if (a[i] < b[j])
            sum1 += a[i++];
        else if (a[i] > b[j])
            sum2 += b[j++];
        else {
            result += max(sum1, sum2);
            sum1 = sum2 = 0;

            while (i < m and j < n and a[i] == b[j]) {
                result += a[i++];
                j++;
            }
        }
    }
    while (i < m)
        sum1 += a[i++];
    while (j < n)
        sum2 += b[j++];
    result += max(sum1, sum2);
    return result;
}
