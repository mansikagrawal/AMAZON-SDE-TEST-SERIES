/* Mountain Subarray Problem 
We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not.
 All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing. 
More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exists an integer K, 1 <= K <= N such that,
a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN
You have to process Q queries. In each query you are given two integer L and R, denoting starting and last index of the subarrays respectively.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The following line contains N space-separated integers forming the array. Next line contains an integer Q, denoting the number of queries. For each query, you are given two space-separated integers L and R in a new line. 

Output:
For each query, print "Yes" (without quotes) if the subarray is in mountain form, otherwise print "No" (without quotes) in a new line.

Expected Time Complexity: O(N + Q).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N, Q <= 105
1 <= a[i] <= 106, for each valid i
0 <= L <= R <= N-1

Example:
Input:
1
8
2 3 2 4 4 6 3 2
2
0 2
1 3

Output:
Yes
No

Explanation:
For L = 0 and R = 2, a0 = 2, a1 = 3 and a2 = 2, since they are in the valid order,answer is Yes.
For L = 1 and R = 3, a1 = 3, a2 = 2 and a3 = 4, since a1 > a2 and a2 < a4 the order isn't valid, hence the answer is No. */

/* Hint We can solve this problem by first some preprocessing then we can answer for each subarray in a constant amount of time.
 We maintain two arrays left and right where left[i] stores the last index on the left side which is increasing i.e.
 greater than its previous element and right[i] will store the first index on the right side which is decreasing i.e.
 greater than its next element. Once we maintained these arrays we can answer each subarray in constant time. 

Suppose range [l, r] is given then only if right[l] >= left[r], the subarray will be in form of a mountain 
otherwise not because the first index in decreasing form (i.e. right[l]) should come later than the last index in increasing form (i.e. left[r]). */

#include <bits/stdc++.h>

using namespace std;

vector<bool> processQueries(int a[], int n, vector<pair<int, int> >& queries,
    int q);

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int> > queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        auto v = processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}

vector<bool> processQueries(int a[], int n, vector<pair<int, int> >& queries,
    int q)
{
    int left[n], right[n];
    vector<bool> v;
    int leftptr = 0, rightptr = n - 1;
    left[0] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            leftptr = i;

        left[i] = leftptr;
    }

    right[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1])
            rightptr = i;

        right[i] = rightptr;
    }

    for (int i = 0; i < queries.size(); i++) {

        if (right[queries[i].first] >= left[queries[i].second])
            v.push_back(true);
        else
            v.push_back(false);
    }

    
    return v;
}
