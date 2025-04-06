/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //Detecting the cycle in the linkedList
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                //Cycle detected Ab ek pointer ko head prr rakh do
                ListNode* entry = head;
                while(entry != fast){
                    entry = entry->next;
                    fast = fast->next;
                }
                return entry;
            }
            
        }
        return NULL;
    }
};