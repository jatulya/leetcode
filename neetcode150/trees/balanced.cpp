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
    bool isBalanced(TreeNode* root) {
        return countnodes(root) != -1;
    }
private:
    int countnodes(TreeNode* node){
        if (!node)
            return 0;
        if (!node->right && !node->left)
            return 1;
        int left =countnodes(node->left);
        int right = countnodes(node->right);
        if (right==-1 || left==-1 || abs(left-right)>1)
            return -1;
        return 1 + max(left, right);
    }
};
