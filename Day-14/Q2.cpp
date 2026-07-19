// Topic : Searching

/*
Question :
Given a sorted array arr[] (following 0-based indexing) and a number target,
find the lower bound of the target in this given array. The lower bound of a number
is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array.

Examples :

Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 4
Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7
Explanation: As no element in arr[] is greater than 100, return the length of array.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106
*/

// solution :

class Solution
{
public:
    int lowerBound(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (high >= low)
        {
            int mid = (low + high) / 2;

            if (arr[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

/*
## Approach

Since the array is **sorted**, we can use **Binary Search** to efficiently find the **lower bound**.

The lower bound is defined as the **smallest index** where the element is **greater than or equal to the target**.

1. Initialize:
   - `low = 0`
   - `high = n - 1`
   - `ans = n` (Assume initially that no lower bound exists. If every element is smaller than the target, the answer will be `n`.)

2. Perform Binary Search while `low <= high`:
   - Calculate the middle index:
     ```cpp
     mid = low + (high - low) / 2;
     ```
   - If `arr[mid] >= target`:
     - `arr[mid]` is a valid lower bound candidate.
     - Store its index in `ans`.
     - Continue searching on the **left half** (`high = mid - 1`) to find an even smaller valid index.
   - Otherwise (`arr[mid] < target`):
     - The current element cannot be the lower bound.
     - Search on the **right half** (`low = mid + 1`).

3. After the loop ends:
   - If a valid lower bound exists, `ans` stores its smallest index.
   - Otherwise, `ans` remains `n`, indicating that all elements are smaller than the target.

## Time Complexity

- **O(log n)**

Binary Search halves the search space in every iteration.

## Space Complexity

- **O(1)**

Only a constant amount of extra space is used.
*/