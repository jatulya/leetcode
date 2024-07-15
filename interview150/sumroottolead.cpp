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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        findAndAdd(root, 0,sum);
        return sum;
    }
private:
    void findAndAdd(TreeNode* node, int num, int& sum){
        if (!node) return;
        
        num = num*10 + node->val;
        if (!node->left && !node->right){
            sum +=  num;
            return;
        }
        findAndAdd(node->left, num, sum);
        findAndAdd(node->right,num, sum);
    }
};
