/* Given a list of N integers. Find the contiguous sub-array with maximum sum.


Example 1:

Input:
N = 5
array = {1,2,3,-2,5}
Output: 9
Explanation:Max subarray sum is 9 of elements
(1, 2, 3, -2, 5) which is a contiguous subarray.

â€‹Example 2:

Input:
N = 4
array = {-1 , -2 , -3 , -4}
Output: -1
Explanation: Max subarray sum is -1 of elements
(-1) which is a contiguous subarray.


Your Task:
You don't need to read input or print anything. Your task is to complete the function maxSubArray() which takes a list of numbers as a parameter and returns an integer with a maximum subarray sum.


Expected Time Complexity : O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107
Sum of N over all testcases doesn't exceed 107 */



/* Hint -

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far */





#include<bits/stdc++.h>
using namespace std;

int maxSubArray( vector<int> array);

int main()
{
	int t;
	cin >> t; //input testcases

	while (t--) //while testcases exist
	{
		int n;
		cin >> n; //input size of array
		vector<int> vec(n);

		for (int i = 0; i < n; i++)
			cin >> vec[i]; //inputting elements of array

		cout << maxSubArray(vec) << "\n";
	}
}



int maxSubArray(vector<int> arr) {
	// code here
	int csum = arr[0];
	int osum = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (csum >= 0)
			csum += arr[i];
		else
			csum = arr[i];

		if (csum > osum)
			osum = csum;
	}
	return osum;
}