// Topic : Linked List

/*
Question :

Given the head of a singly linked list, return true if it is a
palindrome or false otherwise.
Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false


Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

// solution :

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Count the number of nodes
        int count = 0;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        // Step 2: Reach the starting node of the second half
        int mid = count / 2;

        temp = head;
        ListNode *prev = nullptr;

        for (int i = 0; i < mid; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        // For odd length, skip the middle node
        if (count % 2 != 0)
        {
            temp = temp->next;
        }

        // Break the list into two halves
        prev->next = nullptr;

        // Step 3: Reverse the second half
        ListNode *rhead = nullptr;

        while (temp != nullptr)
        {
            ListNode *nextNode = temp->next;
            temp->next = rhead;
            rhead = temp;
            temp = nextNode;
        }

        // Step 4: Compare the two halves
        ListNode *p1 = head;
        ListNode *p2 = rhead;

        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val != p2->val)
                return false;

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};

/*
# Approach

### Step 1: Count the Number of Nodes
- Traverse the linked list once and count the total number of nodes.
- Store this count in `count`.

### Step 2: Find the Start of the Second Half
- Compute the middle index using:
  ```cpp
  mid = count / 2;
  ```
- Traverse the linked list until the `mid` position.
- Keep track of the previous node (`prev`) so that the list can be split into two halves.
- If the length of the linked list is odd, skip the middle node since it does not affect whether the list is a palindrome.

### Step 3: Split the Linked List
- Disconnect the first half from the second half by setting:
  ```cpp
  prev->next = nullptr;
  ```
- Now there are two separate linked lists.

### Step 4: Reverse the Second Half
- Reverse the second half of the linked list using the standard iterative linked list reversal algorithm.
- After reversing, the last node of the original list becomes the head of the reversed second half.

### Step 5: Compare Both Halves
- Traverse both linked lists simultaneously.
- Compare the value of each corresponding node.
- If any pair of values is different, return `false`.
- If all nodes match, return `true`.

---

# Time Complexity

- Counting the nodes: **O(n)**
- Traversing to the middle: **O(n/2)**
- Reversing the second half: **O(n/2)**
- Comparing both halves: **O(n/2)**

Overall Time Complexity:

**O(n)**

---

# Space Complexity

- No extra data structures are used.
- Only a few pointer variables are maintained.

Overall Space Complexity:

**O(1)**

*/