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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //Base Case
        if(!head || !head->next) return true;

        //Find the middle of the list 
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }

        //Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        //Compare the wo halves
        ListNode* first = head;
        ListNode* second = prev;

        while(second){
            if(first->val != second-> val) return false;
            first = first->next;
            second = second->next;

        }
        return true;
    }
};