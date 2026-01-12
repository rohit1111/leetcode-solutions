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
    // //TC: O(n), SC: O(n)
    // bool isPalindrome(ListNode* head) {
    //     ListNode *slow = head;
    //     vector<int> arr;
    //     while(slow!=NULL){
    //         arr.push_back(slow->val);
    //         slow = slow->next;
    //     }
    //     int start=0;
    //     int end=arr.size() -1;
    //     while(start<end){
    //         //cout<<arr[start]<<" "<<arr[end]<<endl;
    //         if(arr[start++]!=arr[end--])
    //             return false;
    //     }
    //     return true;
    // }
    bool isPalindrome(ListNode* head) {
        //FInd the middle of the linked list
        ListNode *mid = head;
        ListNode *fast = head;

        while(fast!= NULL && fast->next!=NULL){
            //mid = mid->next;  
            fast = fast->next->next;
            if(fast!=NULL){      //if fast is NULL means list is even 
                                //then dont move mid, 
                                //else move mid for last element
                mid = mid->next;
            }    
        }
        bool odd = false;
        if(fast!=NULL){
            // cout<<"ODD"<<endl;
            odd = true;
        }

        //create 2 linked list.
        ListNode *secondList = mid->next;
        mid->next = NULL;
        
        
        //reverse second list
        ListNode* prev = NULL;
        while(secondList!=NULL){
            ListNode *next = secondList->next;
            // if(next!=NULL){
            //    cout<<"Next Val"<<next->val<<endl;
            // }
            secondList->next = prev;
            prev = secondList;
            secondList = next;
            cout<<prev->val<<"-";
        }
        cout<<endl;
        secondList = prev;
        //Now compare two list are equal or not.
        ListNode* firstList = head;
        while(firstList!=NULL && secondList !=NULL){
            // cout<<firstList->val<<" "<<secondList->val<<endl;
            if(firstList->val != secondList->val){
                return false;
            }
            firstList = firstList->next;
            secondList = secondList->next;
        }
        while(firstList!=NULL){
            if(odd == true){
                return true;
            }
            // cout<<firstList->val<<endl;
            return false;
        }
        while(secondList!=NULL){
            return false;
        }
        return true;
    }
};