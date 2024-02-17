// https://leetcode.com/problems/binary-tree-paths/description/
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
    void dfs(TreeNode *p, string s, vector<string> &c)
    {
        if(p){
        if(s.empty()) s.append(to_string(p->val));
        else s.append("->" + to_string(p->val));
        if(!p->right && !p->left) c.push_back(s);
        dfs(p->left, s, c);
        dfs(p->right, s, c);}
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> c;
        dfs(root,"",c);
        return c;
    }
};
