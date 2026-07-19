// Topic : Searching

/*
Question :
Given an array of n distinct elements. Check whether the given array is a k-sorted array or not. A k-sorted array is an array where each element is at most k distance away from its target position in the sorted array.
Return "Yes" if the array is a k-sorted array else return "No".

Examples

Input: n=6, arr[] = {3, 2, 1, 5, 6, 4}, k = 2
Output: Yes
Explanation: Every element is at most 2 distance away from its target position in thesorted array.

Input: n=7, arr[] = {13, 8, 10, 7, 15, 14, 12}, k = 1
Output: No

Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
1 ≤ n ≤ 105
0 ≤ k ≤ n
*/

// solution :

class Solution
{
public:
    string isKSortedArray(int arr[], int n, int k)
    {
        // code here.
        vector<int> temp(n);

        for (int i = 0; i < n; i++)
            temp[i] = arr[i];

        sort(temp.begin(), temp.end());

        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
            um[temp[i]] = i;

        for (int i = 0; i < n; i++)
            if (abs(i - um[arr[i]]) > k)
                return "No";

        return "Yes";
    }
};

/*
## Approach

A **k-sorted array** is an array in which every element is at most `k` positions away from its correct position in the sorted array.

To verify this:

1. Create a copy of the original array.
2. Sort the copied array.
3. Store the sorted position of every element in a hash map (`value -> sorted index`).
4. Traverse the original array.
5. For each element:
   - Find its correct index from the hash map.
   - Calculate the distance between its current index and its sorted index:
     ```cpp
     abs(i - sortedIndex)
     ```
   - If the distance is greater than `k`, the array is **not** k-sorted, so return `"No"`.
6. If every element is within `k` positions of its sorted position, return `"Yes"`.

## Time Complexity

- Copying the array: **O(n)**
- Sorting the copied array: **O(n log n)**
- Building the hash map: **O(n)**
- Traversing the original array: **O(n)**

Overall Time Complexity: **O(n log n)**

## Space Complexity

- Copy of the array: **O(n)**
- Hash map to store the sorted index of each element: **O(n)**

Overall Space Complexity: **O(n)**
*/