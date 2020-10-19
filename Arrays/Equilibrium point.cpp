/* Given an array A of N positive numbers. The task is to find the first Equilibium Point in the array.
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

Input:
N = 1
A[] = {1}
Output: 1
Explanation: Since its the only
element hence its the only equilibrium
point.
Example 2:

Input:
N = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case
equilibrium point is at position 3
as elements before it (1+3) =
elements after it (2+2).


Your Task:
The task is to complete the function equilibriumPoint() which takes the array and N as input parameters and returns the point of equilibrium. Return -1 if no such point exists.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 106
1 <= A[i] <= 108   */



/* Hint
The idea is to get total sum of array first. Then Iterate through the array and keep updating the left sum which is initialized as zero. In the loop, we can get right sum by subtracting the elements one by one. */


#include <iostream>
using namespace std;

int equilibriumPoint(long long a[], int n);

int main() {

	long long t;

	//taking testcases
	cin >> t;

	while (t--) {
		long long n;

		//taking input n
		cin >> n;
		long long a[n];

		//adding elements to the array
		for (long long i = 0; i < n; i++) {
			cin >> a[i];
		}

		//calling equilibriumPoint() function
		cout << equilibriumPoint(a, n) << endl;
	}
	return 0;
}



// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return -1;
	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	long long  leftsum = 0;
	for (int i = 0; i < n; i++)
	{
		sum -= a[i];
		if (leftsum == sum)
			return i + 1;
		leftsum += a[i];

	}
	return -1;
}