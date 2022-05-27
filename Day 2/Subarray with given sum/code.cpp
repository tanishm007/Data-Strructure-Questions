// { Driver Code Starts

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int index = 0;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            
            while(s<sum && index < i)
            {
               
                sum-=arr[index];
                index++;
                
            }
            if(sum==s)
        return {index+1,i+1};
        }
        return {-1};
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
