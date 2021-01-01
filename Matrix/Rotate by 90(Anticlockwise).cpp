/* Given a square matrix[][] of size N x N.
 The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Example 1:

Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]
Output:
3 6 9
2 5 8
1 4 7
Your Task:
You only need to implement the given function rotate().
 Do not read input, instead use the arguments given in the function.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 50
1 <= matrix[][] <= 100 */


/* Hint - Take the transpose of the matrix first and then reverse the elements column wise. */




#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    // Take the transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // Rotate columnwise

    for (int j = 0; j < n; j++) {
        int li = 0;
        int ri = n - 1;
        while (li < ri) {
            int temp = matrix[li][j];
            matrix[li][j] = matrix[ri][j];
            matrix[ri][j] = temp;

            li++;
            ri--;
        }

    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}

