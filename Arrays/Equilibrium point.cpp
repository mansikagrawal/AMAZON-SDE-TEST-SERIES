/* Equilibrium Point 
Given an array A of N positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases.
Then T test cases follow. First line of each test case contains an integer N denoting the size of the array.
Then in the next line are N space separated values of the array A.

Output:
For each test case in a new line print the index of the first Equilibrium Point. 
The output should be based on 1 based indexing. If no such point exists print -1.

User Task:
The task is to complete the function equilibriumPoint() which takes the array and N as input parameters and returns the point of equilibrium.
Return -1 if no such point exists.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 108

Example:
Sample Input:
2
1
1
5
1 3 5 2 2

Sample Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements before it (1+3) = elements after it (2+2). */

/* Hint - The idea is to get total sum of array first. Then Iterate through the array and
keep updating the left sum which is initialized as zero. In the loop, we can get right sum by subtracting the elements one by one. */

#include <iostream>
using namespace std;

int equilibriumPoint(long long a[], int n);

int main()
{

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}


// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum -= a[i];
        if (sum == sum2)
            return i + 1;
        sum2 += a[i];
    }
    return -1;
}
