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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL) return 0;
        unordered_map<int, ListNode*> mp;
         ListNode*dummy = new ListNode(0);
         dummy->next = head;
         mp[0] = dummy;
         int prefix_sum = 0;
         while(head != NULL){
             prefix_sum+= head->val;
             if(mp.find(prefix_sum) != mp.end()){
                 ListNode* start = mp[prefix_sum];
                 int sum = prefix_sum;
                 while(start!=NULL && start!=head){
                     start = start->next;
                     sum+=start->val;
                     if(start != head)
                         mp.erase(sum);
                 }
                 mp[prefix_sum]->next = head->next;
             }
             else{
                 mp[prefix_sum] = head;
             }
             head = head->next;
         }
        return dummy->next;
    }
};
