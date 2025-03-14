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
    // Creating a custom Compare operator for minHeap cause by Default humari Priority Queue Max element   upar rkhti h
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* createLinkedList(vector<int> nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Initiallizing a minHeap
        priority_queue<ListNode*, vector<ListNode*>, Compare>minHeap;

        //Insert First node of each list into the heap
        for(ListNode* list : lists){
            if(list){
                minHeap.push(list);
            }
        }
        //Dummy node for final list construction
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        //Process on the heap: Aage se pop krenge cause that is chota element and piche add krte jaenge
        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            //Atach to result
            current->next = smallest;
            current = current->next;

            //If next node exits then add it into the heap
            if(smallest->next){
                minHeap.push(smallest->next);
            }
        }
        return dummy->next;
    }
};