/* Given an array A of size N, construct a Product Array P (of same size) such that P is equal to the product of all the elements of A except A[i].

Example 1:

Input:
N = 5
A[] = {10,3,5,6,2}
Output: 180 600 360 300 900
Explanation: For the product array P, at
i=0 we have 3*5*6*2. At i=1 10*5*6*2. At
i=2 we have 10*3*6*2. At i=3 we have
10*3*5*2. At i=4 we have 10*3*5*6 So P
is 180 600 360 300 900
Example 2:

Input:
N = 2
A[] = {12,0}
Output: 0 12

Your Task:
You do not have to read input. Your task is to complete productExceptSelf() function and returns the Product vector P that holds 
product except for self at each index. If the array has only one element the returned vector/array/array (depending on the language cpp/java/python)
should contains one value i.e {1}

Note: Try to solve this problem without using the division operation.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 1000
0 <= Ai <= 200

 */

#include <bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int);

int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }

        vec = productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
{

    // Allocate memory for product array andinitialise it by 1
    vector<long long int> vec(n, 1ll);
    if (n == 1) {
        return vec;
    }

    // In this loop temp will store the product of values on the left side of nums[i]
    long long temp = 1ll;
    for (int i = 0; i < n; i++) {
        vec[i] *= temp;
        temp *= nums[i];
    }
    for (int i = 0; i < vec.size(); i++)

        // In this loop temp will store the product of values on the right side of nums[i]
        temp = 1ll;
    for (int i = n - 1; i >= 0; i--) {
        vec[i] *= temp;
        temp *= nums[i];
    }

    return vec; // return the expected vector
}
