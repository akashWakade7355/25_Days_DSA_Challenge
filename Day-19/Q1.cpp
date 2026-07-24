// Topic : Subarray

/*
Question :
Given an array of integers arr[], return true if it is possible to split it in two subarrays
(without reordering the elements), such that the sum of the two subarrays are equal. If it is
not possible then return false.

Examples:

Input: arr[] = [1, 2, 3, 4, 5, 5]
Output: true
Explanation: We can divide the array into [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10.

Input: arr[] = [4, 3, 2, 1]
Output: false
Explanation: We cannot divide the array into two subarrays with equal sum.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/

// solution :

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++)
            totalSum += arr[i];

        vector<int> ps(n);

        ps[0] = arr[0];

        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + arr[i];

        for (int i = 0; i < n; i++)
            if (ps[i] == (totalSum - ps[i]))
                return true;
        return false;
    }
};

/*
# Approach

### Step 1: Find the Total Sum
- Traverse the array and calculate the sum of all elements.
- Let this be `totalSum`.

### Step 2: Build the Prefix Sum Array
- Create a prefix sum array `ps` where:
  - `ps[0] = arr[0]`
  - `ps[i] = ps[i-1] + arr[i]`
- Here, `ps[i]` represents the sum of elements from index `0` to `i`.

### Step 3: Check Every Possible Split
- Traverse the prefix sum array.
- For each index `i`:
  - **Left subarray sum** = `ps[i]`
  - **Right subarray sum** = `totalSum - ps[i]`
- If both sums are equal, then the array can be split into two subarrays with equal sum.
- Return `true`.

### Step 4: If No Valid Split Exists
- If no index satisfies the condition:
  ps[i] == totalSum - ps[i]
  
  return `false`.

# Dry Run

### Input
arr = [1, 2, 3, 4, 5, 5]

### Total Sum
20

### Prefix Sum Array
[1, 3, 6, 10, 15, 20]

### Checking Splits

| Index | Left Sum | Right Sum | Equal? |
|------:|---------:|----------:|:------:|
| 0 | 1 | 19 | ❌ |
| 1 | 3 | 17 | ❌ |
| 2 | 6 | 14 | ❌ |
| 3 | 10 | 10 | ✅ |

Hence, return **true**.

# Time Complexity

- Calculating total sum: **O(N)**
- Building prefix sum array: **O(N)**
- Traversing prefix sum array: **O(N)**

### Overall Time Complexity
O(N)

# Space Complexity

- Prefix sum array of size `N`.

### Overall Space Complexity
O(N)


*/