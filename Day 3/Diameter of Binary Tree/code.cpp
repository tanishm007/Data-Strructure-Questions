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

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)
class Solution {
    private:
    pair<int,int> diameterfast(TreeNode* root)  
    {
        if(root==NULL)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterfast(root->left);
        pair<int,int> right = diameterfast(root->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.second = max(left.second,right.second)+1;  // storing height in second integer
        
        ans.first = max(op1,max(op2,op3));   // storing diameter in first integer
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       return diameterfast(root).first-1;
            
    }
};
