// Topic : Searching

/*
Question :
Given a sorted array arr[] and an integer x, find the index (0-based)
of the largest element in arr[] that is less than or equal to x.
This element is called the floor of x. If such an element does not exist, return -1.

Note: In case of multiple occurrences of floor of x, return the index of the last occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 11
Output: 4
Explanation: Largest Number less than or equal to 11 is 10, whose indices are 3 and 4. The index of last occurrence is 4.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
Output: -1
Explanation: No element less than or equal to 0 is found. So, output is -1.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
0 ≤ x ≤ arr[n-1]
*/

// solution :

class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (high >= low)
        {
            int mid = (low + high) / 2;

            if (arr[mid] <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

/*
Approach

Since the array is **sorted**, we can efficiently solve the problem using **Binary Search**.

1. Initialize two pointers:
   - `low = 0`
   - `high = n - 1`
   - Also initialize `ans = -1` to store the index of the floor element.

2. Perform Binary Search while `low <= high`:
   - Calculate the middle index:
     ```cpp
     mid = low + (high - low) / 2;
     ```
   - If `arr[mid] <= x`:
     - `arr[mid]` is a valid floor candidate.
     - Store its index in `ans`.
     - Move to the **right half** (`low = mid + 1`) to check if there is another occurrence of the same value or a larger value that is still `<= x`.
   - Otherwise (`arr[mid] > x`):
     - The current element cannot be the floor.
     - Move to the **left half** (`high = mid - 1`).

3. After the loop ends:
   - If `ans` is still `-1`, no floor element exists.
   - Otherwise, `ans` contains the index of the **last occurrence** of the largest element less than or equal to `x`.


Time Complexity

- **O(log n)**

Binary Search reduces the search space by half in each iteration.

## Space Complexity

- **O(1)**

Only a constant amount of extra space is used.
*/