// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
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
    int dfs(TreeNode* p, string x)
    {
        if(!p) return 0;
        x.push_back(p->val + '0');
        if(!p->left && !p->right) 
        {
            int tmp = stoi(x);
            return tmp;
        }
        return dfs(p->left, x) + dfs(p->right, x);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, "");
    }
};
