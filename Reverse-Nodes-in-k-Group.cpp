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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        //Check kro phele ki k no. of nodes h bhi ki nhi?
        while(curr != NULL && count < k){
            curr = curr->next;
            count++;
        }

        if(count == k){
            ListNode* prev = reverseKGroup(curr, k);
            curr = head;

            while(count-- > 0){
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            return prev;
        }
        return head;

    }
};