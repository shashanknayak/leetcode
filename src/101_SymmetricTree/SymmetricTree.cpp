#include "TreeUtils.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            //cout << "both null" << endl;
            return true;
        }
        
        if (root1 != nullptr &&
            root2 != nullptr &&
            root1->val == root2->val) {
            
            //cout << root1->val << " " << root2->val << endl;
            return isSame(root1->left, root2->right) &&
                isSame(root1->right, root2->left);
        }
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if (root == nullptr) {
            return true;
        }
        
        return isSame(root->left, root->right);
        
    }
};