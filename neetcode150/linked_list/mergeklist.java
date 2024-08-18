/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> minheap = new PriorityQueue<>((a,b)-> a.val-b.val);
        for(ListNode list: lists)
            if (list != null)
                minheap.add(list);

        ListNode temphead = new ListNode(0);
        ListNode curr = temphead;

        while(!minheap.isEmpty()){
            ListNode node = minheap.poll();
            curr.next = node;
            curr = curr.next;

            if (node.next != null)
                minheap.add(node.next);
        }  

        return temphead.next;      
    }
}
