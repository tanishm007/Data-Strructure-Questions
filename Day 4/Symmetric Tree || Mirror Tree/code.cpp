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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return 1;
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        int count;
        while(q.empty()==false)
        {
           
                
                TreeNode *currleft = q.front();
                
                q.pop();
                TreeNode* currright = q.front();
                q.pop();
                if(currleft==NULL && currright==NULL)
                    continue;
                
                if(currleft!=NULL && currright==NULL)
                    return false;
                if(currleft==NULL && currright!=NULL)
                    return false;
                if(currleft->val != currright->val)
                    return false;
               
                q.push(currleft->left);
                q.push(currright->right);
                q.push(currleft->right);
                q.push(currright->left);
                
                
            
        }
        return 1;
        
    }
};
