#include <iostream>
#include <string>
using namespace std;

/*
Check if a singly-linked list is a palyndrome
*/

struct ListNode {
    char val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    int len = 0;
    ListNode *list = head;
    ListNode *next;
    while (list != 0) {
      len++;
      list = list->next;
    }
    return palyndrome(head,len,&next);
  }
    
  bool palyndrome(ListNode *head, int len, ListNode **next) {

    /* Base cases */
    if (len == 0) {
      *next = head;
      return true;
    } 
    if (len == 1) {
      *next = head->next;
      return true;
    } 

    /* Recursive step */
    if (palyndrome(head->next,len-2,next) && head->val == (*next)->val) {
      *next = (*next)->next;
      return true;
    }

    return false;
  }    

  ListNode* create_list(const string &s) {
    ListNode *head = NULL;
    ListNode *ptr;
    int n = s.size();
    for (int i=n-1; i>=0; i--) {
      ptr = new ListNode(s[i]);
      ptr->next = head;
      head = ptr;
    }
    return head;
  }

};

int main() { 
  Solution sol; 
  ListNode* list = sol.create_list("ab");
  cout << sol.isPalindrome(list) << endl;
  return 0;
}
