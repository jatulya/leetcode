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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next){
            delete head;
            return nullptr;
        }
        
        ListNode* temp = new ListNode(0, head);
        ListNode* left = temp;
        ListNode* right = head;

        while (n>0){
            right = right->next;
            n-=1;
        }

        while(right){
            left=left->next;
            right=right->next;
        }

        ListNode* todelete = left->next;
        left->next = todelete->next;
        delete todelete;
        return temp->next;
    }
};
