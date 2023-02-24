class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;

        while(low<high)
        {
            int mid = low + (high - low)/2;

            if(mid%2 == 1) // even index pe partition ho jayega left wale even and right wale odds
              mid--;

            if(nums[mid] == nums[mid + 1]) // agr equal hua to exact 2 2 elements honge to left wala ans ni hoga right mei search marenge
            low = mid + 2; // mid and mid +1 dono equal honge so usse bhi next wala 

            else
            high = mid;


        }

        return nums[low];
    }
};
