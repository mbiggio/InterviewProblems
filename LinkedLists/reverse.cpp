#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(): val(0) {};   
   ListNode(int val): val(val) {};
};

class Solution {
public:
    ListNode *reverse(ListNode *head, int n, int k, ListNode** p_new_tail, ListNode** p_rem) {

        ListNode* new_head = NULL;
        ListNode* new_tail = head;   
        for (int i=0; i<k; i++) {
            ListNode *tmp = new_head;
            new_head = head;
            head = head->next;
            new_head->next = tmp;
        }
        new_tail->next = head;
        *p_new_tail = new_tail;
        *p_rem = head;
        return new_head;   
    }

    ListNode *reverse_by_k(ListNode *head, int n, int k) { 
        if (k<=1 || k>n) return head;
        ListNode *tail;
        ListNode *rem;
        head = reverse(head,n,k,&tail,&rem);
        tail->next = reverse_by_k(rem,n-k,k);
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tmp = head;
        int n=0;
        while(tmp) {
            n++;
            tmp = tmp->next;
        }
        return reverse_by_k(head,n,k);
    }
};

ListNode *make_list() {
   ListNode *node, *tmp;

   node = new ListNode(5);
   
   tmp = node;
   node = new ListNode(4);
   node->next = tmp;

   tmp = node;
   node = new ListNode(3);
   node->next = tmp;

   tmp = node;
   node = new ListNode(2);
   node->next = tmp;

   tmp = node;
   node = new ListNode(1);
   node->next = tmp;

   
   return node;
}

void dump_list(ListNode *head) {
   while(head) {
      cout << head->val << " ";
      head = head->next;
   }
   cout << endl;
}

   
int main() {
   Solution sol;
   ListNode *head = make_list();
   dump_list(head);
   head = sol.reverseKGroup(head,3);
   dump_list(head);   
   return 0;
}
