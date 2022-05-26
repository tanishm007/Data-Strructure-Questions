class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];
        int ans = 0;
        left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(height[i],left[i-1]);
        }
        
        right[n-1] = height[n-1];
        for(int j=n-2;j>=0;j--)
        {
            right[j] = max(height[j],right[j+1]);
        }
        
        for(int k=0;k<n;k++)
        {
            ans += min(left[k],right[k])-height[k];
        }
        
        return ans;
        
    }
};

// Time complexity : O(N)
// Space Complexity : O(N)
