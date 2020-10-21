/*  Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 10000   */


/* Hint
Create an array of N length where ith value will be the last valule for a subsequence of length (i+1).

Iterate over the array, use binary search to find best indexes to place new elements in the dp array. */



#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
	//taking total testcases
	int t, n;
	cin >> t;
	while (t--)
	{
		//taking size of array
		cin >> n;
		int a[n];

		//inserting elements to the array
		for (int i = 0; i < n; i++)
			cin >> a[i];

		//calling method longestSubsequence()
		cout << longestSubsequence(n, a) << endl;
	}
}


int longestSubsequence(int n, int a[])
{
	int dp[n];
	int osum = 0;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (dp[j] > max)
					max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (dp[i] > osum)
			osum = dp[i];
	}
	return osum;
}
