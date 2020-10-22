/* Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100}
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}
Your Task:
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 105 */


/* Hint
1. The concept of Longest Increasing Subsequence(LIS) will be useful here.
LIS: length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order

2. Keeping LIS concept in mind, we can add one more catch here instead of maintaining length of subsequence as criteria we can have sum as criteria to keep dp[i] update.   */






#include <bits/stdc++.h>
using namespace std;


class Solution {


public:
	int maxSumIS(int arr[], int n)
	{
		// Your code goes here
		int omax = INT_MIN;
		int dp[n];
		for (int i = 0; i < n; i++)
		{
			int max = INT_MIN;
			for (int j = 0; j < i; j++)
			{
				if (arr[j] < arr[i]) {
					if (max == INT_MIN)
						max = dp[j];
					else if (dp[j] > max)
						max = dp[j];
				}
			}
			if (max == INT_MIN)
				dp[i] = arr[i];
			else
				dp[i] = max + arr[i];


			if (dp[i] > omax)
				omax = dp[i];
		}
		return omax;
	}
};


int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];



		Solution ob;
		cout << ob.maxSumIS(a, n) << "\n";

	}
	return 0;
}

