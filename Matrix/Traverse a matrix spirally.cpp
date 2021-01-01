/* Given a matrix of size R*C. Traverse the matrix in spiral form.

Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
R = 3, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output:
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above,
output for the 2nd testcase will be
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything.
 Complete the function spirallyTraverse() that takes matrix, R and C as input parameters and returns a list of integers denoting
 the spiral traversal of matrix.

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)

Constraints:
2 <= R, C <= 100
0 <= matrixi <= 100 */


/* Hint Print the first row from the remaining rows.
Print the last column from the remaining columns.
Print the last row from the remaining rows.
Print the first column from the remaining columns.
Continue this and step inwards in the matrix. */


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> spirallyTraverse(vector<vector<int> > A, int m, int n)
	{
		int T, B, L, R, dir;
		T = 0;
		B = m - 1;
		L = 0;
		R = n - 1;
		dir = 0;
		int i;
		vector<int> ans;

		while (T <= B && L <= R)
		{
			if (dir == 0)
			{
				for (i = L; i <= R; i++)
					ans.push_back(A[T][i]);
				T++;
			}
			else if (dir == 1)
			{
				for (i = T; i <= B; i++)
					ans.push_back(A[i][R]);
				R--;
			}
			else if (dir == 2)
			{
				for (i = R; i >= L; i--)
					ans.push_back(A[B][i]);
				B--;
			}
			else if (dir == 3)
			{
				for (i = B; i >= T; i--)
					ans.push_back(A[i][L]);
				L++;
			}
			dir = (dir + 1) % 4;
		}
		return ans;
	}
};



int main() {
	int t;
	cin >> t;

	while (t--)
	{
		int r, c;
		cin >> r >> c;
		vector<vector<int> > matrix(r);

		for (int i = 0; i < r; i++)
		{
			matrix[i].assign(c, 0);
			for ( int j = 0; j < c; j++)
			{
				cin >> matrix[i][j];
			}
		}

		Solution ob;
		vector<int> result = ob.spirallyTraverse(matrix, r, c);
		for (int i = 0; i < result.size(); ++i)
			cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}