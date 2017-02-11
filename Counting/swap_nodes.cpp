#include <iostream>
#include <algorithm>
using namespace std;


/*
Swap adjacent nodes of a singly linked list
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

       /* Base cases */       
       if (head == NULL) return NULL;
       ListNode *next = head->next;
       if (next == NULL) return head;

       /* Recursive step */
       next->next = swapPairs(next->next);       
       head->next = next->next;
       next->next = head;
       return next;
       
    }
};
