class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr){
            return head;
        } //if there are no elements or only one element

        ListNode* before=nullptr;
        ListNode* current = head;
        ListNode* after = nullptr;
  
        while(current != nullptr){
            after=current->next;
            current->next = before;
            before = current;
            current = after;
        }

        return before;
    }
};
