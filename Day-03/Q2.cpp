// Topic : Hashmap

/*
Question :
Given a string consisting of lowercase english alphabets. Find the repeated character present 
first in the string.

NOTE - If there are no repeating characters return '#'.

Example 1:

Input:
S = "geeksforgeeks"
Output: g
Explanation: g, e, k and s are the repeating
characters. Out of these, g occurs first.
Example 2:

Input:
S = "abcde"
Output: -1
Explanation: No repeating character present. (You need to return '#')

Your Task:
You don't need to read input or print anything. Your task is to complete the function firstRep() which takes the string S as input and returns the the first repeating character in the string. In case there's no repeating character present, return '#'.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
*/

// solution

class Solution
{
public:
    char firstRep(string s)
    {
        // code here.
        int len = s.length();

        unordered_map<int, pair<int, int>> um;

        for (int i = 0; i < len; i++)
        {
            char ch = s[i];
            if (um.count(ch) == 0)
            {
                um[ch] = {i, 1};
            }
            else
            {
                um[ch].second++;
            }
        }

        int min = INT_MAX;

        for (auto i : um)
        {
            int freq = i.second.second;
            if (freq > 1)
            {
                int firstOccurance = i.second.first;
                if (firstOccurance < min)
                    min = firstOccurance;
            }
        }

        if (min == INT_MAX)
            return '#';

        return s[min];
    }
};

// Tc: 0(n)

// SC:0(1)

/*
Approach:

1. Create a HashMap to store two pieces of information for each character:
   - The index of its first occurrence.
   - The frequency of occurrence.

2. Traverse the given string.
   - If a character appears for the first time, store its index
     and initialize its frequency as 1.
   - If the character is already present in the HashMap,
     simply increment its frequency.

3. Traverse the HashMap.
   - Check all characters whose frequency is greater than 1.
   - Among them, keep track of the minimum first occurrence index.

4. Check whether any repeating character was found.
   - If no character has a frequency greater than 1,
     return '#'.
   - Otherwise, return the character present at the
     minimum first occurrence index in the original string.

*/