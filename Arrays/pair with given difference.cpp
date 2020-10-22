/* Given an unsorted array Arr[] and a number N.
 You need to write a program to find if there exists a pair
 of elements in the array whose difference is N.

Input:
First line of input contains an integer T which denotes
the number of test cases. Then T test cases follows. First line of each test case contains two space separated integers L and N where L denotes the length of array or the number of elements in the array and N denotes the difference between two elements. Second line of each test case contains L space separated integers which denotes the elements of the array.

Output:
For each test case, in a new line print 1 if the pair
is found otherwise print -1 if there does not exist any such pair.

Constraints:
1<=T<=100
1<=L<=104
1<=Arr[i]<=105

Example:
Input:
2
6 78
5 20 3 2 5 80
5 45
90 70 20 80 50
Output:
1
-1 */


/* Hint
Sort the array
take 2 pointers i=0 and j=1
traverse it and check if arr[j] - arr[i] == diff return 1
if not
check if arr[j] - arr[i] < n
increase j
else increase i */



using namespace std;
int pairdiff(vector<int> &v, int n, int diff)
{
	sort(v.begin(), v.end());

	int i = 0; int j = 1;
	while (i < n and j < n)
	{
		if (i != j and v[j] - v[i] == diff)
			return 1;
		else if (v[j] - v[i] < diff)
			j++;
		else
			i++;
	}
	return -1;


}
int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n, diff;
		cin >> n >> diff;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << pairdiff(v, n, diff) << "\n";
		v.clear();
	}
	return 0;
}