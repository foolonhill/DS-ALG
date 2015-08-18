/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include <stack>

// iterative
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> ret;
        if (head == NULL)
            return ret;
		
        struct ListNode* list = head;
        std::stack<int> value;
        while (list != NULL) {
            value.push(list->val);
            list = list->next;
        }
        
        while (!value.empty()) {
            ret.push_back(value.top());
            value.pop();
        }
        return ret;
    }
};


// recursive
