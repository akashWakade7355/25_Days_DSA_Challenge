// Topic : Linkden List

/*
Question :
Given a linked list with the head node and a key, the task is to check if
the key is present in the linked list or not. Return true if key is present, else return false.

Example:

Input: key = 3,
      
Output: true 
Explanation: 3 is present in Linked List.
Input: key = 4,
   
Output: false
Explanation: 4 is not present in Linked List.

Constraint:
1 ≤ Number of nodes ≤ 105
1 ≤ node.data, key ≤ 105
*/

// solution :


class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; 

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* temp;
        temp=head;
        
        while(temp!=nullptr){
            if(temp->data == key)
               return true;
               
            temp=temp->next;
        }
        
        return false;
    }
};

//TC:0(n)

// SC:0(1)

/*
# Approach

1. Initialize a pointer `temp` and point it to the `head` of the linked list.
2. Traverse the linked list until `temp` becomes `NULL`.
3. At each node:
   - Compare `temp->data` with the given `key`.
   - If they are equal, return `true` since the key is found.
4. If the traversal reaches the end of the linked list without finding the key, return `false`.


*/