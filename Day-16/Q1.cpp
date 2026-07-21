// Topic : Carry Forward

/*
Question :
You are given an array arr of positive integers. Your task is to find all the leaders in the array.
An element is considered a leader if it is greater than or equal to all elements to its right. The
rightmost element is always a leader.

Examples:

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.

Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side

Input: arr = [5, 10, 20, 40]
Output: [40]
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.

Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
Explanation: When an array is sorted in non-increasing order, all elements are leaders.

Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 106
*/

// solution :

class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        // code here
        vector<int> leaders;
        int n = arr.size();
        int max = arr[n - 1];

        leaders.push_back(max);

        for (int i = n - 2; i >= 0; i--)
            if (arr[i] >= max)
            {
                max = arr[i];
                leaders.push_back(max);
            }

        reverse(leaders.begin(), leaders.end());

        return leaders;
    }
};

/*
# Approach

### Step 1:
Initialize a variable `max` with the last element of the array because the rightmost element is always a leader.

### Step 2:
Create an answer vector `leaders` and insert the last element into it.

### Step 3:
Traverse the array from right to left starting from the second last element.

### Step 4:
For each element, compare it with the current `max`.
- If `arr[i] >= max`, then it is a leader.
- Add it to the `leaders` vector.
- Update `max = arr[i]`.

### Step 5:
Since leaders are collected while traversing from right to left, reverse the `leaders` vector to restore the original left-to-right order.

### Step 6:
Return the reversed `leaders` vector.

# Time Complexity (TC)

- Traversing the array once: **O(n)**
- Reversing the answer vector: **O(n)**

**Overall Time Complexity:** **O(n)**


# Space Complexity (SC)

- Extra space used for storing the leaders: **O(k)**, where `k` is the number of leaders.
- In the worst case (when every element is a leader), `k = n`.

**Overall Space Complexity:** **O(n)**
*/