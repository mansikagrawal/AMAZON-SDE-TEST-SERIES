/*   Given an unsorted array A of size N of non-negative integers,
find a continuous sub-array which adds to a given number S.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements
from 2nd position to 4th position
is 12.
Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements
from 1st position to 5th position
is 15.
Your Task:
The task is to complete the function subarraySum() which returns
 starting and ending positions(1 indexing) of first such occurring
 subarray from the left if sum equals to subarray, else -1 is returned.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 105
1 <= Ai <= 1010     */


/* Hint
>Maintain start and last index to store and print these values
>Iterate the complete array.
>Add array elements to cuursum
>If currsum becomes greater than S, then remove elements starting from
start index, till it become less than or equal to S, and increement start.
if currsum becomes equals to S, then print the starting and last index
if the currsum never maches to S, then print -1   */



#include <bits/stdc++.h>
using namespace std;

// Function to find the subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int arr[], int n, int s) {

	int start = 0;
	int last = 0;

	unsigned long long currsum = 0;
	bool flag = false;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		currsum += arr[i];
		if (currsum >= s)
		{
			last = i;

			while (start < last and s < currsum)
			{
				currsum -= arr[start];

				++start;
			}
			if (currsum == s)
			{
				v.push_back(start + 1);
				v.push_back(last + 1);
				flag = true;
				break;
			}
		}
	}
	if (!flag)
		v.push_back(-1);

	return v;

}




int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long long s;
		cin >> n >> s;
		int arr[n];

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		vector<int>res;
		res = subarraySum(arr, n, s);

		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;

	}
	return 0;
