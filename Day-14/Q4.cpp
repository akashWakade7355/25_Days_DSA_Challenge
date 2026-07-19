// Topic : Seacrhing

/*
Question :
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

// solution :

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ansl = INT_MAX;
        int ansr = INT_MAX;

        while (high >= low)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                ansl = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        low = 0;
        high = n - 1;

        while (high >= low)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                ansr = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (ansr == INT_MAX || ansl == INT_MAX)
            return {-1, -1};

        return {ansl, ansr};
    }
};

/*
## Approach

Since the array is **sorted**, we can use **Binary Search** to find the **first** and **last** occurrence of the target in **O(log n)** time.

The idea is to perform **Binary Search twice**:

1. **First Binary Search** → Find the **leftmost (first) occurrence** of the target.
2. **Second Binary Search** → Find the **rightmost (last) occurrence** of the target.

---

### Step 1: Find the First Occurrence

1. Initialize:
   - `low = 0`
   - `high = n - 1`
   - `ansl = INT_MAX`

2. Perform Binary Search while `low <= high`:
   - Calculate:
     ```cpp
     mid = low + (high - low) / 2;
     ```
   - If `nums[mid] == target`:
     - Store `mid` in `ansl`.
     - Continue searching on the **left half** (`high = mid - 1`) to find an earlier occurrence.
   - If `nums[mid] < target`:
     - Search on the **right half** (`low = mid + 1`).
   - Otherwise:
     - Search on the **left half** (`high = mid - 1`).

After this search, `ansl` stores the index of the **first occurrence** of the target.

---

### Step 2: Find the Last Occurrence

1. Reset:
   - `low = 0`
   - `high = n - 1`
   - `ansr = INT_MAX`

2. Perform Binary Search again:
   - If `nums[mid] == target`:
     - Store `mid` in `ansr`.
     - Continue searching on the **right half** (`low = mid + 1`) to find a later occurrence.
   - If `nums[mid] < target`:
     - Search on the **right half**.
   - Otherwise:
     - Search on the **left half**.

After this search, `ansr` stores the index of the **last occurrence** of the target.

---

### Step 3: Return the Answer

- If either `ansl` or `ansr` was never updated, the target is not present, so return:
  ```cpp
  {-1, -1}
  ```
- Otherwise, return:
  ```cpp
  {ansl, ansr}
  ```

## Time Complexity

- **O(log n) + O(log n) = O(log n)**

Two Binary Searches are performed, each taking `O(log n)` time.


## Space Complexity

- **O(1)**

Only a constant amount of extra space is used.
*/