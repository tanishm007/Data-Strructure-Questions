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
// SPACE COMPLEXITY :  O(N)
class Solution {
public:
    
    pair<bool,int> isbalancedfast(TreeNode* root)
    {
        if(root==NULL)
        {
            pair<bool,int> p = make_pair(1,0);
        return p;
        }
        
        pair<bool,int> left = isbalancedfast(root->left);
        pair<bool,int> right = isbalancedfast(root->right);
        
        int leftans = left.first;
        int rightans = right.first;
        
        bool diff = abs(left.second-right.second) <=1; // CALCULATING THE DIFFERENCE FROM THE HEIGTH WE ARE STRONG IN ans.second
        pair<bool,int>ans;
        ans.second = max(left.second,right.second)+1; // STORING THE HEIGHT IN SECOND INT VALUE
        if(leftans && rightans && diff)
        {
            ans.first = 1;                          
        }
        else
            ans.first = 0;
        
        return ans;
        
        
    }
    bool isBalanced(TreeNode* root) {
        return isbalancedfast(root).first;
       
        
    }
};
