/* Longest Common Subsequence
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of the longest common subsequence of the two strings.

Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters
 and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC
Output:
3
2
Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2. */

/* Hint -
Complete Solution:

A character may or may not be included in the subsequence. There are 2 cases:
If character of string1 and string2 match, then it may be a part of subsequence.
If not, then 2 more cases arise:
Either the matching character appears in string1 before the position of this character
Or matching character appears in string2 before the position of character
Therefore,
if character match then DP[i][j] = DP[i-1][j-1] + 1
else DP[i][j] = max(DP[i-1][j], DP[i][j-1])
Iterate for complete DP array
Return DP[m][n] (m, n - size of strings) */

#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--) {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input

        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2)
{

    int dp[100][100];

    for (int i = 0; i <= x; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= y; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= x; i++) {
        int q = 0;
        for (int j = 1; j <= y; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                q = 1 + dp[i - 1][j - 1];
            }
            else {
                q = max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] = q;
        }
    }

    return dp[x][y];
}
