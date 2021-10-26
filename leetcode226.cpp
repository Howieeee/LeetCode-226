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
#include<queue>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) 
            return NULL;
        
        TreeNode *t_node = root->right; //先存著right subtree
        root->right = invertTree(root->left); //整個right subtree = left subtree的 invertTree
        root->left = invertTree(t_node);//整個left subtree = temp的 invertTree
        
        return root;
    }
};
