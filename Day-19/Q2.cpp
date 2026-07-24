// Topic : Subarray

/*
Question :

Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.


Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66


Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000
*/

// solution

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        vector<int> ps(n);

        ps[0] = arr[0];

        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + arr[i];

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {

                if ((j - i) % 2 == 0)
                {

                    if (i == 0)
                        sum += ps[j];
                    else
                        sum += ps[j] - ps[i - 1];
                }
            }

        return sum;
    }
};

/*
# Approach

### Step 1: Build the Prefix Sum Array
- Create a prefix sum array `ps` where:
  - `ps[0] = arr[0]`
  - `ps[i] = ps[i-1] + arr[i]`
- The prefix sum array helps us calculate the sum of any subarray in **O(1)** time.


### Step 2: Generate All Possible Subarrays
- Use two nested loops:
  - The outer loop (`i`) represents the starting index.
  - The inner loop (`j`) represents the ending index.

Thus, every possible subarray `arr[i...j]` is considered.

### Step 3: Check for Odd-Length Subarrays
- The length of a subarray is:
  
  (j - i + 1)
  
- A subarray has an odd length if:
  
  (j - i) % 2 == 0
  
  because:
  Odd Length = (j - i + 1)
             = Even + 1
             = Odd
  

### Step 4: Find the Sum of the Odd-Length Subarray
- If the subarray starts from index `0`:
  sum = ps[j];
  
- Otherwise:
  sum = ps[j] - ps[i - 1];
  
- Add this subarray sum to the final answer.

### Step 5: Return the Final Sum
- After checking all possible odd-length subarrays, return the accumulated sum.

# Dry Run

### Input
arr = [1, 4, 2]


### Prefix Sum Array
ps = [1, 5, 7]

### Odd-Length Subarrays

| Subarray | Sum |
|----------|----:|
| [1] | 1 |
| [4] | 4 |
| [2] | 2 |
| [1,4,2] | 7 |

### Final Answer

1 + 4 + 2 + 7 = 14


# Time Complexity

- Building the prefix sum array: **O(N)**
- Generating all subarrays using nested loops: **O(N²)**
- Calculating each subarray sum using prefix sums: **O(1)**

### Overall Time Complexity
O(N²)


# Space Complexity

- Prefix sum array of size `N`.

### Overall Space Complexity
O(N)
*/