/* Given an array arr[] of N integers arranged in a circular fashion.
 Your task is to find the maximum contiguous subarray sum.

Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output: 22
Explanation:  Starting from the last
element of the array, i.e, 12, and
moving in a circular fashion, we
have max subarray as 12, 8, -8, 9,
-9, 10, which gives maximum sum
as 22.
Example 2:

Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output: 23
Explanation: Sum of the circular
subarray with maximum sum is 23
Your Task:
The task is to complete the function circularSubarraySum() which returns
 sum of the circular subarray with maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= Arr[i] <= 106 */


/* Hint
1. Try kadane's algorithm
2. There can be two cases for the maximum sum:

Case 1 (We get maximum sum using normal subarray) :
 The elements that contribute to the maximum sum are arranged such
 that no wrapping is there. Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

Case 2 (We get maximum sum using both corner elements):
 The elements which contribute to the maximum sum are arranged
  such that wrapping is there. Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we need to remove some (0 or more) middle elements with minimum sum. So the idea is to use Kadane's algorithm again to find the minimum sum subarray.  Instead of writing a separate function for minimum sum subarray, we can change signs of elements and call same maximum sum function again. */



#include<bits/stdc++.h>
using namespace std;

// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int circularSubarraySum(int a[], int num) {

	// your code here
	int sum = 0;
	int maxstraightsum = INT_MIN;
	int maxsum = 0;
	int minstraightsum = INT_MAX;
	int minsum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += a[i];
		maxsum += a[i];
		maxstraightsum = maxstraightsum < maxsum ? maxsum : maxstraightsum;
		maxsum = maxsum < 0 ? 0 : maxsum;
		minsum  += a[i];
		minstraightsum = minstraightsum > minsum ? minsum : minstraightsum;
		minsum = minsum > 0 ? 0 : minsum;
	}
	if (sum == minstraightsum)
		return maxstraightsum;
	return max(maxstraightsum, ( sum - minstraightsum));
}



int main()
{
	int T;

	//testcases
	cin >> T;

	while (T--)
	{
		int num;

		//size of array
		cin >> num;
		int arr[num];

		//inserting elements
		for (int i = 0; i < num; i++)
			cin >> arr[i];

		//calling function
		cout << circularSubarraySum(arr, num) << endl;

	}

	return 0;
}