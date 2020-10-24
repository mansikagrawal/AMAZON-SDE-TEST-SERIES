/* Given arrival and departure times of all trains that reach a railway station.
Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day.
 Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other.
 In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train
  and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case,
first line will contain an integer N, the number of trains. Next two lines will consist of N space separated time intervals
 denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the first two charcters represent hour (between 00 to 23 )
 and last two characters represent minutes (between 00 to 59).

Output:
For each test case, print the minimum number of platforms required for the trains to arrive and depart safely.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= A[i] < D[i] <= 2359

Example:
Input:
2
6
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240

Output:
3
1

Explanation:
Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains. */

/* Hint

So what we need to do is we ned to get the number of platforms required.
sort the arrival and departure time. ( we need to do it because we want to give a platform to coming train so if we will
know the arrrival and departure time in increasing order we will allot the platforms that are empty.
)
take two variables maxplat and reqplat which are maximum and required platforms
take two pointers i and j
iterate through it if the dep[j] < arr[i]
decrement reqplat
increment j

   else
   increment reqplat
   increment i

   find max of maxplat and reqplat

   return max







*/







#include <bits/stdc++.h>
using namespace std;

int minplat(vector<int> &ar, vector<int> &dep, int n)
{
	sort(ar.begin(), ar.end());
	sort(dep.begin(), dep.end());
	int maxplat = 1;
	int reqplat = 1;
	int i = 1; int j = 0;
	while (i < n and j < n)
	{
		if (dep[j] < ar[i])
		{
			maxplat -= 1;
			j++;
		}
		else
		{
			maxplat += 1;
			i++;
		}
		reqplat = max(reqplat, maxplat);
	}
	return reqplat;
}
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> ar(n);
		vector<int> dep(n);
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		for (int i = 0; i < n; i++)
			cin >> dep[i];
		cout << minplat(ar, dep, n) << "\n";
		ar.clear();
		dep.clear();
	}
	return 0;
}