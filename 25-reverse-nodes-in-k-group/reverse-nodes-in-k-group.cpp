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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while(true){
            ListNode* kthNode = prevGroup;
            for(int i=0; i<k && kthNode != nullptr; i++){
                kthNode = kthNode->next;
            }
            if(kthNode == nullptr) break;

            ListNode* groupStart = prevGroup->next;
            ListNode* nextGroupHead = kthNode->next;

            ListNode* prev = nextGroupHead; 
            ListNode* curr = groupStart;
            
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            prevGroup->next = kthNode;
            prevGroup = groupStart;
        }
        return dummy.next;
    }
};