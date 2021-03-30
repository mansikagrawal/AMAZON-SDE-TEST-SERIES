/* Given two integer arrays. 
Sort the first array such that all the relative positions of the elements in the first array are the same as the elements in the second array.
See example for better understanding.

Example 1:

Input:
N = 11, M = 4
A1[] = {2,1,2,5,7,1,9,3,6,8,8}
A2[] = {2,1,8,3}
Output: 2 2 1 1 8 8 3 5 6 7 9
Explanation: Array elements of A1[] are
sorted according to A2[]. So 2 comes first
then 1 comes, then comes 8, then finally 3
comes, now we append remaining elements in
sorted order.
Example 2:

Input:
N = 11, M = 4
A1[] = {2,1,2,5,7,1,9,3,6,8,8}
A2[] = {99,22,444,56}
Output: 1 1 2 2 3 5 6 7 8 8 9
Explanation: No A2 elements are in A1
so we cannot sort A1 according to A2.
Hence we sort the elements in
non-decreasing order.
Input:
The first line of input contains the number of test cases. For each testcase,
the first line of input contains the length of arrays N and M and the next two lines contain N and M elements respectively.

Output:
For each testcase, in a new line, print the elements of A1 sorted relatively according to A2.

Your Task:
You don't need to read input or print anything. Your task is to complete
the function sortA1ByA2() which takes the array A1[], array A2[] and their respective size N and M as inputs and 
sorts the array A1[] such that the relative positions of the elements in A1[] are same as the elements in A2[].
For the elements not present in A2[] but in A1[], it appends them at the last in increasing order.

Expected Time Complexity: O(NlogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106 */

/* Try storing the frequencies of the elements present in the array A1[] in a hash table and
then traverse the array A2[] from its beginning and check the frequency of that element in the hash table we built. */

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;



void sortA1ByA2(int a1[], int n, int a2[], int m);


int main(int argc, char *argv[])
{

	int t;

	cin >> t;

	while (t--) {

		int n, m;
		cin >> n >> m;

		int a1[n];
		int a2[m];

		for (int i = 0; i < n; i++) {
			cin >> a1[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> a2[i];
		}

		sortA1ByA2(a1, n, a2, m);


		for (int i = 0; i < n; i++)
			cout << a1[i] << " ";

		cout << endl;


	}
	return 0;
}



//User function template in C++

// A1[] : the input array-1
// N : size of the array A1[]
// A2[] : the input array-2
// M : size of the array A2[]
void sortA1ByA2(int A1[], int N, int A2[], int M)
{

	map<int, int> m;
	// Add the frequencies of A1 in map
	for (int i = 0; i < N; i++)
		m[A1[i]]++;
	int k = 0;
	// Find the element in A2 and print it
	for (int i = 0; i < M; i++)
	{
		if (m.find(A2[i]) != m.end())
		{
			while (m[A2[i]] > 0)
			{
				A1[k++] = A2[i];
				m[A2[i]]--;
			}
			m.erase(A2[i]);
		}

	}

	// Put the rest of elements in A1  the rest of elements

	for (auto it = m.begin(); it != m.end(); it++)
	{
		while ((it->second)-- != 0)
			A1[k++] = it->first;
	}


}
