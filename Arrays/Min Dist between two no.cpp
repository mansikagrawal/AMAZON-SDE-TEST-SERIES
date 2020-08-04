/*      Minimum distance between two numbers 
You are given an array A, of N elements. Find minimum index based distance between two elements of the array, x and y.

Input :
The first line of input contains an integer T, denoting the number of test cases.
Then T test cases follow. Each test case consists of three lines. The first line of each test case contains an integer N denoting size array.
Then in the next line are N space separated values of the array A. The last line of each test case contains two integers  x and y.

Output :
Print the minimum index based distance between x and y.

Your Task:
Complete the function minDist() which takes the array, n, x and y as input parameters and returns the minimum distance between x and y in the array.
If no such distance is possible then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= A[i], x, y <= 105

Example:
Sample Input:
2
4
1 2 3 2
1 2
7
86 39 90 67 84 66 62 
42 12

Sample Output:
1
-1

Explanation:
Testcase1: x = 1 and y = 2. There are two distances between x and y, which are 1 and 3 out of which the least is 1.
Testcase2: x = 42 and y = 12. We return -1 as x and y don't exist in the array.       */

#include <stdio.h>
#include <iostream>
#include <stdlib.h> // for abs()
#include <limits.h> // for INT_MAX
using namespace std;
long long minDist(long long arr[], long long n, long long x, long long y);
int main()
{
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        long long x, y;
        cin >> x >> y;
        cout << minDist(a, n, x, y) << endl;
    }
    return 0;
}

long long minDist(long long arr[], long long n, long long x, long long y)
{
    // add code here.
    if (n == 1)
        return -1;

    long long prev;
    long long i = 0;
    long long mindist = INT_MAX;
    for (; i < n; i++) {
        if (arr[i] == x or arr[i] == y) {
            prev = i;
            break;
        }
    }

    for (; i < n; i++) {
        if (arr[i] == x or arr[i] == y) {
            if (arr[prev] != arr[i] and (i - prev) < mindist) {
                mindist = i - prev;
                prev = i;
            }
            else
                prev = i;
        }
    }

    if (mindist == INT_MAX)
        return -1;

    return mindist;
}
