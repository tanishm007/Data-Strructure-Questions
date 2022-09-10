//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int helper(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
         if(n==0 || W==0) return 0; // n is the number of items in the bag and if no item is present then return 0
       
       if(dp[n][W] != -1) return dp[n][W];
       if(wt[n-1]<=W) // checking for weight it must be less then or equal to the current weight present
       {
           return dp[n][W] = max((val[n-1] + helper(W-wt[n-1],wt,val,n-1,dp)),helper(W,wt,val,n-1,dp));
       }
       
       else if(wt[n-1] > W)
       return dp[n][W] = helper(W,wt,val,n-1,dp);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       
      return helper(W,wt,val,n,dp);
       
       
    }
};

// time : N*W
   // space : N*W + N(stack stack)

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
