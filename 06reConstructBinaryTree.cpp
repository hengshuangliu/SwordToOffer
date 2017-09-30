#include <vector>
#include <exception>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

class Solution {
	public:
		TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
			return constructCor(&pre, &vin, 0, pre.size(), 0, vin.size());
		}

		TreeNode* constructCor(vector<int>* pre, vector<int>* vin, int pre_s, int pre_e, \
		                       int vin_s, int vin_e) {
			TreeNode* root = new TreeNode((*pre)[pre_s]);
			if(pre_s == pre_e-1) {
				if(vin_s == vin_e - 1 && (*pre)[pre_s] == (*vin)[vin_s]) {
					return root;
				} else {
					throw std::exception();
				}
			}
			// find index in vin vector
			int root_vin = vin_s;
			while(root_vin != vin_e) {
				if((*vin)[root_vin] == (*pre)[pre_s]) {
					break;
				}
				root_vin++;
			}
			if(root_vin == vin_e) {
				throw std::exception();
			}

			if(root_vin > vin_s) {
				root->left = constructCor(pre, vin, pre_s+1, pre_s+root_vin-vin_s+1, vin_s, root_vin);
			}
			if(root_vin < vin_e - 1) {
				root->right = constructCor(pre, vin, pre_s+root_vin-vin_s+1, pre_e, root_vin+1, vin_e);
			}
			return root;
		}
};

int main() {
	return 0;
}
