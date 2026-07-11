// Topic : 2D Matrix

/*
Question :
You are given a matrix mat[][] . Return the boundary traversal on the matrix in a clockwise manner starting from the first row of the matrix.

Examples:

Input: mat[][] = [[1, 2, 3, 4],
                [5, 6, 7, 8],
                [9, 10, 11, 12],
                [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5]
Explanation: The boundary traversal is: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5]
Input:mat[][] = [[12, 11, 10, 9],
               [8, 7, 6, 5],
               [4, 3, 2, 1]]
Output: [12, 11, 10, 9, 5, 1, 2, 3, 4, 8]
Explanation: The boundary traversal is: [12, 11, 10, 9, 5, 1, 2, 3, 4, 8]
Input:mat[][] = [[12, 11],
                [4, 3]]
Output: [12, 11, 3, 4]
Explanation: The boundary traversal is: [12, 11, 3, 4]

Constraints:
1 ≤ mat.size()≤ 1000
1 ≤ mat[0].size() ≤ 1000
0 ≤ mat[i][j] ≤ 1000
*/

// solution

class Solution
{
public:
    vector<int> boundaryTraversal(vector<vector<int>> &mat)
    {
        // code here
        int Tr = 0;
        int Br = mat.size() - 1;
        int Lc = 0;
        int Rc = mat[0].size() - 1;

        vector<int> output;

        for (int j = Lc; j <= Rc; j++)
            output.push_back(mat[Tr][j]);

        for (int i = Tr + 1; i <= Br; i++)
            output.push_back(mat[i][Rc]);

        if (Tr != Br)
            for (int j = Rc - 1; j >= Lc; j--)
                output.push_back(mat[Br][j]);

        if (Lc != Rc)
            for (int i = Br - 1; i >= Tr + 1; i--)
                output.push_back(mat[i][Lc]);

        return output;
    }
};

/*
Traversing the top row takes O(m).
Traversing the right column takes O(n).
Traversing the bottom row takes O(m) (only when there is more than one row).
Traversing the left column takes O(n) (only when there is more than one column).

Overall,

Time Complexity: O(n + m)

/*

// SC: 0(1)

Approach

We traverse only the boundary elements of the matrix in a clockwise direction.

The traversal is performed in four steps:

step 1: Traverse the top row from left to right.

step 2: Traverse the rightmost column from top to bottom
        (starting from the second row to avoid repeating the top-right corner).

step 3: Traverse the bottom row from right to left, only if the matrix has more than one row (Tr != Br).

step 4 :Traverse the leftmost column from bottom to top, only if the matrix has more than one column (Lc != Rc).
         We skip the first and last rows to avoid duplicate corner elements.

The conditions Tr != Br and Lc != Rc ensure that elements are not repeated in the case of a single-row or single-column matrix.
*/