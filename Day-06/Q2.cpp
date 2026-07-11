// Topic : 2D Matrix 

/*
Question :
Given a matrix mat[][] and a number k, find the k-th element obtained while traversing the matrix in spiral order.

Note: Spiral traversal follows a pattern where we move left to right on the top row, top to bottom on the last column, right to left on the bottom row, and bottom to top on the first column, repeating this process for the inner layers until all elements are visited.

Examples:

Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], k = 10
Output: 13
Explanation:
 
The spiral order of matrix will look like 1->2->3->4->8->12->16->15->14->13->9->5->6->7->11->10. So the 10th element in this order is 13. 
Input: mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 4
Output: 6
Explanation: The spiral order of matrix will look like 1->2->3->6->9->8->7->4->5. So the 4th element in this order is 6.

Constraints:
1<=n,m<=10^3
1<=k<=n*m
-109 <= A[i][j] <= 109
*/

// solution 

class Solution {
  public:
    int findK(vector<vector<int>> &mat, int k) {
        // code here.
        int Tr=0;
        int Br=mat.size()-1;
        int Lc=0;
        int Rc=mat[0].size()-1;
        
        vector<int> output;
        
       
       while(Tr<=Br && Lc<=Rc){
           
         for(int j=Lc;j<=Rc;j++)
                output.push_back(mat[Tr][j]);
        
      
        for(int i=Tr+1;i<=Br;i++)
                output.push_back(mat[i][Rc]);
             
        if(Tr!=Br)     
            for(int j=Rc-1;j>=Lc;j--)
                output.push_back(mat[Br][j]);
            
        if(Lc!=Rc)    
             for(int i=Br-1;i>=Tr+1;i--)
                output.push_back(mat[i][Lc]);
                
        Tr++;
        Lc++;
        Br--;
        Rc--;
        
            
       }
       
       
            return output[k-1];
    }
};

// TC: 0(n * m)

// SC: 0(n * m)--> because of vector

/*
Apprach :
We simulate the spiral traversal of the matrix by maintaining four boundaries:

Top Row (Tr)
Bottom Row (Br)
Left Column (Lc)
Right Column (Rc)

At each iteration, we traverse the current boundary in the following order:

Traverse the top row from left to right.
Traverse the rightmost column from top to bottom.
Traverse the bottom row from right to left (only if Tr != Br to avoid duplicate traversal in a single-row matrix).
Traverse the leftmost column from bottom to top (only if Lc != Rc to avoid duplicate traversal in a single-column matrix).

After completing one layer, we move towards the inner layer by updating the boundaries:

Tr++
Br--
Lc++
Rc--

All visited elements are stored in a vector in spiral order. Finally, since k is 1-based, we return the element at index k - 1.
*/