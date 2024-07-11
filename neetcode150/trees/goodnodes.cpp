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
    int nodes=0;

    void dfs(TreeNode* node, int highest){
        if (!node) return;

        if (node->val >= highest){
            highest = node->val;
            nodes++;
        }

        dfs(node->left, highest);
        dfs(node->right, highest);
    }
    
    int goodNodes(TreeNode* root) { 
        int highest=-10001;      
        dfs(root, highest);
        return nodes;
    }
};
