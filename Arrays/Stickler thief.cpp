/* Stickler Thief 
Stickler the thief wants to loot money from a society having n houses in a single line. 
He is a weird person and follows a certain rule when looting the houses. According to the rule,
 he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots.
 The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy.
 He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow.
 Each test case contains an integer n which denotes the number of houses. Next line contains space separated numbers denoting the amount of money in each house.

Output:
For each testcase, in a newline, print an integer which denotes the maximum amount he can take home.

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).

Constraints:
1 <= T <= 200
1 <= n <= 104
1 <= a[i] <= 104

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4 */

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    // If there is only one home then return the value of that house.
    if (n < 2) {
        return arr[0];
    }

    // Array to store maximum stolen value till givin house
    ll dp[n];

    // Save base conditions for first and second value.
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    // Iterate from i = 2 to n.
    for (int i = 2; i < n; i++) {

        // maximum value till ith house will be
        // maximum of (i-1)th house without including current house
        // and inculuding ith house + maxVlue till (i-2)th house.
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    // return last value which will be the final Answer
    return dp[n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        cout << FindMaxSum(a, n) << endl;
    }
    return 0;
}
