class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
   
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2 != 0) // sabhi ko maximize kar rahe hain so that ek operation eliminate ho jaye
            {
                nums[i] *= 2;

            }
            mn = min(mn,nums[i]);
            mx = max(mx,nums[i]);
        }

        int min_deviation = mx - mn;

        priority_queue<int> pq;

        for(auto it:nums)
        {
            pq.push(it);
        }

        while(pq.top()%2==0) // odd hone ke baad decrease ni kr skte becaoz wahi maximum hoga
        {
            int top = pq.top();
            pq.pop();

            min_deviation = min(min_deviation,top - mn);

            

            top /= 2;  
            mn = min(mn,top); // minimum ko update krre in case new minimum nikl aya
            pq.push(top);
        }

        min_deviation = min(min_deviation, pq.top()-mn);

        return abs(min_deviation);
        
    }
};
