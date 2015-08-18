#include <iostream>
#include <vector>

using std::vector;


 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// 根据前序遍历结果和中序遍历结果重建树
class SolutionReconstuct {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> &pre, vector<int> &in) {
		if (pre.empty() || in.empty() || pre.size() != in.size())
            return NULL;
        return reConstructCore(pre, in);   
    }
    
    struct TreeNode* reConstructCore(vector<int> &pre, vector<int> &in) {

		int root_value = pre[0];
        struct TreeNode *tree = new TreeNode(0);
        tree->val = root_value;
        tree->left = tree->right = NULL;
        
        if (pre.size() == 1 && in.size() == 1)
            if (pre[0] == in[0])
            	return tree;
        
        size_t root_place = 0;
        for (vector<int>::iterator iter = in.begin(); iter != in.end(); ++iter) {
            if (*iter != root_value)
                root_place++;
            else
                break;
        }
        
        vector<int> pre_left_child(pre.begin()+1, pre.begin()+root_place+1);
        vector<int> pre_right_child(pre.begin()+root_place+1, pre.end());
        
        vector<int> in_left_child(in.begin(), in.begin()+root_place);
        vector<int> in_right_child(in.begin()+root_place+1, in.end());
        
        if (!pre_left_child.empty() && !in_left_child.empty())
            tree->left = reConstructCore(pre_left_child, in_left_child);
        
        if (!pre_right_child.empty() && !in_right_child.empty())
            tree->right = reConstructCore(pre_right_child, in_right_child);
            
        return tree;
    }
    
};
