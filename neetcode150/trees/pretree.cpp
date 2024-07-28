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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {      
        if (preorder.size()==1)
            return new TreeNode(preorder[0]);
        
        unordered_map<int,int> map;
        for(int i=0; i<inorder.size(); i++)
            map[inorder[i]] = i;
        
        return recur(preorder, inorder, 0, 0, inorder.size()-1, map);
    }

private:
    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd, unordered_map<int, int>& map) {
        if (inStart>inEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootindex = map[root->val];

        root->left = recur(preorder, inorder, preStart+1, inStart, rootindex-1, map);
        root->right = recur(preorder, inorder, preStart + rootindex - inStart + 1, rootindex+1, inEnd, map);

        //(rootindex - inStart) -> gives number of elements in the left subtree
        //right node will be coming after left subtree nodes => starting from preorder
        //to number of left subtree elements and element at index after them (+1) gives right tree ele
        return root;
    }    

};
