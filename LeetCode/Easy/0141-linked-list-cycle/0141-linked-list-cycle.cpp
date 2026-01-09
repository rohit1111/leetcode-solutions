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
    bool hasCycle(ListNode *head) {
        //slow & fast, dono pointer ek jagah se start
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            //dono pointer to dauda dijiye
            slow = slow->next;
            fast = fast->next->next;

            //aab check kijiye dono pints to same or not
            if(slow == fast){
                return true;
            }
        }
        //agar yaha aate he isk matlab he ki cycle nahi he.
        return false; 
    }
};