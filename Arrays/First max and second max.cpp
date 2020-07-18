

/* CPP code to find largest and
 second largest element in the array



Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

Example:
Input:
3
5
1 2 3 4 5
3
2 1 2
2
5 5

Output:
5 4
2 1
5 -1

Explanation:
Testcase 1: From the given array elements, 5 is the largest and 4 is the second largest.
Testcase 2: From the given array elements, 2 is the largest and 1 is the second largest.
Testcase 3: From the given array elements, 5 is the largest and -1 is the second largest.    */

#include <bits/stdc++.h>
using namespace std;

vector<int> largestAndSecondLargest(int, int[]);

// } Driver Code Ends

/* Function to find largest and second largest element
*n : number of elements in the array
* arr = input array
*/
vector<int> largestAndSecondLargest(int n, int arr[])
{
    int max1 = INT_MIN, max2 = INT_MIN;
    vector<int> v;
    v.clear();
    /*********************************
     * Your code here
     * This function should return a
     * vector with first element as
     * max and second element as
     * second max
     * *******************************/
    for (int i = 0; i < n; i++) {
        if (max1 < arr[i]) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] != max1 and arr[i] > max2)
            max2 = arr[i];
    }

    if (max2 == INT_MIN) {
        v.push_back(max1);
        v.push_back(-1);
    }
    else {
        v.push_back(max1);
        v.push_back(max2);
    }

    return v;
}

int main()
{

    int testcases;
    cin >> testcases;

    // Looping through all testcases
    while (testcases--) {
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        // Array input
        for (int index = 0; index < sizeOfArray; index++) {
            cin >> arr[index];
        }

        vector<int> ans = largestAndSecondLargest(sizeOfArray, arr);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
}
