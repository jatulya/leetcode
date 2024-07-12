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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while (temp){
            n++;
            temp = temp->next;
        }

        if (n==0 || n==1)
            return head;
        
        k = k%n;
        if (!k)
            return head;

        int i = n-k-1;
        temp = head;
        while (i){
            temp=temp->next;
            i--;
        }
        ListNode* temp2 = temp->next;
        temp->next = nullptr;
        temp = temp2;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return temp2;
    }
};
