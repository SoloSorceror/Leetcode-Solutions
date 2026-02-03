/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool detect(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow ->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_set<ListNode*> st;
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        bool cycle = detect(head);
        if(!cycle) return nullptr;

        while(!st.count(temp) && temp->next){
            st.insert(temp);
            temp = temp->next;
        }
        return temp;
    }
};