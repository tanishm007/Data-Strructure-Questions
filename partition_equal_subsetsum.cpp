//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int tot_sum = 0;
        for(int i=0;i<N;i++)
        tot_sum += arr[i];
        
        if(tot_sum%2!=0) return 0;
        
        int mid_sum = tot_sum/2; // isse problem same subset sum jaisa ban jayega
        
        bool dp[N+1][mid_sum + 1];
        
         for(int j=0;j<=(mid_sum);j++)
         dp[0][j] = false; // koi element present nhi hai and target given hai so can not be achieved
        
        for(int i=0;i<=N;i++)
        {
            dp[i][0] = true; // target 0 hai to koi bhi element mt lo
        }
        dp[0][0] = true; // koi element nhi hai and target sum bhi 0 hai can be achieved by taking no element
        
         for(int i=1;i<=N;i++)
            for(int j=1;j<=(mid_sum);j++)
        {
       
            if(arr[i] > j) 
            dp[i][j] = dp[i-1][j]; // agr target se greater hai
            
            else
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]]; // pick or notpick
                
            
            
        }
        
        return dp[N][mid_sum];
      
    }
};

// time : N*sum
  // space : N*sum

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
