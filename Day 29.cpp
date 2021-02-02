// Day 29
// Question : Vertical Order Traversal of a Binary Tree

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
class Solution
{
public:
    map<int, vector<pair<int, int>>> mp;
    void inorder(TreeNode *root, int i, int h)
    {
        if (root == NULL)
        {
            return;
        }
        mp[i].push_back({h, root->val});
        inorder(root->left, i - 1, h + 1);
        inorder(root->right, i + 1, h + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        inorder(root, 0, 0);
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            vector<pair<int, int>> v = it->second;
            sort(v.begin(), v.end());
            vector<int> v1;
            for (int i = 0; i < v.size(); i++)
            {
                v1.push_back(v[i].second);
            }
            res.push_back(v1);
        }
        return res;
    }
};
