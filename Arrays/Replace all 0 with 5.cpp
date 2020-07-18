/* for a number n convert all the zeros to 5 

Constraints:
1 <= T <= 100
1 <= n <= 10000

Example:
Sample Input:
2
1004
121

Sample Output:
1554
121

Explanation:
Test Case 1: There are two zeroes in "1004", on replacing all zeroes with "5", the new number will be "1554".
Test Case 2: Since there are no zeroes in "121", the number remains as "121".

*/

/* Hint - Start Extracting digits from the end. 
Check if it needs to be replaced with 5.
Make a recursion call for the number with remaining digits 
and append the last digit again to the number returned by recursive call. */

#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}

int convertfunction(int n)
{
    if (n == 0)
        return 0;
    int d = n % 10;
    if (d == 0)
        d = 5;

    return convertfunction(n / 10) * 10 + d;
}

int convertFive(int n)
{
    if (n == 0)
        return 5;
    else
        return convertfunction(n);
}
