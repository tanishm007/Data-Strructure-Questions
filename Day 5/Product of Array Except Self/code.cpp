// Time complexity : O(N)
// Space complexity : O(N)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        v[n-1] = 1;
        for(int i=n-2; i>=0 ; i--)
        {
            v[i] = nums[i+1]*v[i+1];
        }
        
        int leftpro = 1;
        
        
        for(int j=0 ; j<n;j++)
        {
            
            v[j] = v[j]*leftpro;
           
            leftpro = leftpro*nums[j];
        }
        return v;
    }
};
