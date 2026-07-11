// Topic : Linkden List

/*
Question :

Given head of a singly linked list. Find the length of the linked list,
where length is defined as the number of nodes in the linked list.

Examples :

Input: head: 1 -> 2 -> 3 -> 4 -> 5

Output: 5
Explanation: Length of the linked list is 5, as there are 5 nodes present in it.
Input: head: 2 -> 4 -> 6 -> 7 -> 5 -> 1 -> 0
 
Output: 7
Explanation: Length of the linked list is 7, as there are 7 nodes present in it.

Constraints:
1  ≤  number of nodes  ≤  4*104
1  ≤  node->data  ≤  103
*/

// solution :

 // Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        int count=0;
        Node* temp=head;
        
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        
        return count;
    }
};

// TC:0(n)

// SC:0(1)

/*
# Approach

1. Initialize a variable `count` to `0` to keep track of the number of nodes.
2. Create a pointer `temp` and point it to the `head` of the linked list.
3. Traverse the linked list until `temp` becomes `NULL`.
4. For each node visited:
   - Increment `count` by `1`.
   - Move `temp` to the next node using `temp = temp->next`.
5. After reaching the end of the linked list, return the value of `count`.

*/