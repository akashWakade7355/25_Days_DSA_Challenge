// Topic : Seacrhing

/*
Question :
Given a sorted array arr consisting of 0s and 1s. The task is to find the index (0-based indexing) of the first 1 in the given array.

NOTE: If one is not present then, return -1.

Examples :

Input : arr[] = [0, 0, 0, 0, 0, 0, 1, 1, 1, 1]
Output : 6
Explanation: The index of first 1 in the array is 6.

Input : arr[] = [0, 0, 0, 0]
Output : -1
Explanation: 1's are not present in the array.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 1
*/

// solution :

class Solution
{
public:
    int firstIndex(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (high >= low)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == 1)
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

Since the array is **sorted** and contains only **0s and 1s**, all the `0`s appear before all the `1`s.

We can use **Binary Search** to efficiently find the **first occurrence of `1`**.

1. Initialize:
   - `low = 0`
   - `high = n - 1`
   - `ans = -1` (Assume initially that `1` is not present.)

2. Perform Binary Search while `low <= high`:
   - Calculate the middle index:
     ```cpp
     mid = low + (high - low) / 2;
     ```
   - If `arr[mid] == 1`:
     - Store `mid` in `ans` since it is a possible first occurrence.
     - Continue searching on the **left half** (`high = mid - 1`) to check if there is another `1` at a smaller index.
   - Otherwise (`arr[mid] == 0`):
     - The first `1` must be on the **right half**.
     - Move `low = mid + 1`.

3. After the loop ends:
   - If `ans` is `-1`, the array does not contain any `1`.
   - Otherwise, `ans` stores the index of the **first occurrence of `1`**.

## Time Complexity

- **O(log n)**

Binary Search halves the search space in every iteration.


## Space Complexity

- **O(1)**

Only a constant amount of extra space is used.
*/