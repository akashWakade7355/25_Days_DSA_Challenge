// Topic : 2D Matrix

/*
Question :

Given a n*n matrix mat[][] , check whether the matrix is a magic square or not.
A Magic Square is a n x n matrix of distinct elements from 1 to n * n where the sum of any row, column, or diagonal is always equal.

Examples:

Input: mat[][] = [[2, 7, 6],
                 [9, 5, 1],
                 [4, 3, 8]]
Output: true
Explanation: Sum of rows, columns, and diagonals are all equal to 15.
Input: mat[][] = [[1, 2],
                 [3, 4]]
Output: false
Explanation: Sum of all rows and columns are not same.
Input: mat[][] = [[1, 1, 1],
                 [1, 1, 1],
                 [1, 1, 1]]
Output: false
Explanation: All sums are same but all elements from 1 to n2 are not present.
Constraints:
1 ≤ n ≤ 103
*/

// solution :

class Solution
{
public:
    bool magicSquare(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();

        int targetSum = 0;
        for (int j = 0; j < n; j++)
            targetSum += mat[0][j];

        vector<bool> visited(n * n + 1, false);

        for (int i = 0; i < n; i++)
        {
            int rowSum = 0;
            for (int j = 0; j < n; j++)
            {
                int val = mat[i][j];

                if (val < 1 || val > n * n || visited[val])
                    return false;

                visited[val] = true;
                rowSum += val;
            }

            if (rowSum != targetSum)
                return false;
        }

        for (int j = 0; j < n; j++)
        {
            int colSum = 0;
            for (int i = 0; i < n; i++)
                colSum += mat[i][j];

            if (colSum != targetSum)
                return false;
        }

        int diag1 = 0;
        for (int i = 0; i < n; i++)
            diag1 += mat[i][i];

        if (diag1 != targetSum)
            return false;

        int diag2 = 0;
        for (int i = 0; i < n; i++)
            diag2 += mat[i][n - 1 - i];

        if (diag2 != targetSum)
            return false;

        return true;
    }
};

// TC: 0(N^2)

// SC:0(N^2)

/*
Step 1: Calculate the sum of the first row and store it as the target sum. Every row, column, and diagonal must have this same sum for the matrix to be a magic square.

Step 2: Create a visited array of size n × n + 1 to ensure that:

Every element lies in the range 1 to n².
Every element appears exactly once.

Step 3: Traverse each row:

Check whether every element is valid (between 1 and n²) and has not appeared before.
Mark the element as visited.
Compute the sum of the current row.
If the row sum is not equal to the target sum, return false.

Step 4: Traverse each column and calculate its sum.

If any column sum differs from the target sum, return false.

Step 5: Calculate the sum of the main diagonal.

If it is not equal to the target sum, return false.

Step 6: Calculate the sum of the secondary diagonal.

If it is not equal to the target sum, return false.

Step 7: If all rows, columns, diagonals have the same sum and all elements from 1 to n² are present exactly once, return true since the matrix is a Magic Square.
*/