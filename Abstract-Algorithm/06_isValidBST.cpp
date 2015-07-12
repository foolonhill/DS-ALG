/**
 * source: https://leetcode.com/problems/validate-binary-search-tree/
 *
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/**
 * my first solution: inorder traverse the BST and put the value to a vecor, the check whethe the vector is sorted.
 *
 */
#include <vector>
using std::vector;

class Solution {
public:
    void getSorted(vector<int> &sorted, TreeNode *root)
    {
        // NOTE!!!!
        // -- must check the input root, if it is NULL, just return. Otherwise there will be a runtime answer.
        if (root == NULL)
            return;
        getSorted(sorted, root->left);
        sorted.push_back(root->val);
        getSorted(sorted, root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        
        vector<int> sorted;
        getSorted(sorted, root);
        
        if (sorted.size() == 1)
            return true;
        
        vector<int>::iterator it = sorted.begin();
        for (; it != sorted.end() - 1; ++it) {
            if (*it >= *(it+1))
                return false;
        }
        return true;
    }
};
