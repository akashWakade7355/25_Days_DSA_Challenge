// Topic : subarray

/*
Question :

Given an array arr of distinct numbers. Find the length of the shortest unordered
(neither increasing nor decreasing) subarray in the given array. If there is no
subarray then return 0.

Examples:

Input: arr[] = [7, 9, 10, 8, 11]
Output: 3
Explanation: Shortest unsorted subarray is 9, 10, 8 which is of 3 elements.

Input: arr[] = [1, 2, 3, 5]
Output: 0
Explanation: There is no unsorted subarray.

Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 105
*/

// solution :

class Solution
{
public:
    int shortestUnorderedSubarray(vector<int> &arr)
    {

        int n = arr.size();

        if (n < 3)
            return 0;

        for (int i = 0; i <= n - 3; i++)
        {

            if (arr[i] < arr[i + 1] && arr[i + 1] > arr[i + 2])
                return 3;

            if (arr[i] > arr[i + 1] && arr[i + 1] < arr[i + 2])
                return 3;
        }

        return 0;
    }
};

/*
# Approach

### Step 1: Observe the Minimum Possible Length
- Since all elements in the array are **distinct**, any subarray of length **2** is always:
  - Strictly increasing, or
  - Strictly decreasing.
- Therefore, the shortest unordered subarray must have **at least 3 elements**.


### Step 2: Check Every Window of Size 3
- Traverse the array using a single loop.
- For every index `i`, consider the subarray:
  arr[i], arr[i+1], arr[i+2]
  

### Step 3: Identify an Unordered Subarray
A subarray of size `3` is unordered if either of the following conditions is true:

- **Peak Pattern**
  arr[i] < arr[i+1] > arr[i+2]
  
  Example:
  2 5 3

- **Valley Pattern**

  arr[i] > arr[i+1] < arr[i+2]
  
  Example:
  5 2 7
  

If either pattern is found, the shortest unordered subarray has length **3**, so return `3`.

### Step 4: If No Such Window Exists
- If all windows of size `3` are either strictly increasing or strictly decreasing, then no unordered subarray exists.
- Return `0`.

# Dry Run

### Input
arr = [7, 9, 10, 8, 11]

### Checking Windows

| Window | Pattern | Result |
|--------|---------|--------|
| [7, 9, 10] | Increasing | ❌ |
| [9, 10, 8] | Peak (9 < 10 > 8) | ✅ Return 3 |

### Output
3


### Input
arr = [1, 2, 3, 5]


### Checking Windows

| Window | Pattern | Result |
|--------|---------|--------|
| [1, 2, 3] | Increasing | ❌ |
| [2, 3, 5] | Increasing | ❌ |

No unordered subarray exists.

### Output
0


# Time Complexity

- Single traversal of the array.

### Overall Time Complexity
O(N)

# Space Complexity

- No extra data structures are used.

### Overall Space Complexity
O(1)

*/