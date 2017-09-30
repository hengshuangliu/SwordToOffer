#include <stack>
#include <vector>
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        std::stack<int> stk;
        ListNode* p = head;
        vector<int> result;
        while(p != NULL){
        	stk.push(p->val);
        	p = p->next;
		}
		while(!stk.empty()){
			result.push_back(stk.top());
			stk.pop();
		}
		return result;
    }
};
