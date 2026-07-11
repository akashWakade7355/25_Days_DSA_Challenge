// Topic : Linked List

/*
Question:

You are given an array arr[] of integers. You have to construct a singly linked list from the elements of the arr[] and return the head of the linked list.

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: 1 -> 2 -> 3 -> 4 -> 5 
Explanation: Linked list for the given array will be,
      
Input: arr[] = [10, 11, 12, 13, 14]
Output: 10 -> 11 -> 12 -> 13 -> 14
Explanation: Linked list for the given array will be,
     
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

// solution
// Representation of a node

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};


class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        // code here
        int n =arr.size();
        Node* h=new Node(arr[0]);
        
        Node* temp=h;
        
        for(int i=1;i<n;i++){
            Node* newNode= new  Node(arr[i]);
            
            temp->next=newNode;
            temp=newNode;
        }
        
        return h;
        
    }
};

// TC:0(n)

// SC:0(1)


/*
Apprach:

1. Create the first node using the first element of the array and make it the **head** of the linked list.
2. Initialize a pointer `temp` that points to the head. This pointer will always keep track of the last node in the linked list.
3. Traverse the array starting from the second element (`i = 1`).
4. For each element:
   - Create a new node.
   - Connect it to the current last node using `temp->next`.
   - Move `temp` to the newly created node.
5. After processing all elements, return the `head` of the linked list.

*/