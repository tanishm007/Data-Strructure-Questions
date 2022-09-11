//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int dp[501] ; // contraint dp size
    bool isPalindrome(int start,int end, string &str){ // checking if the given string is in palindrome or not
        
        
        while(start<=end)
        {
            if(str[start] != str[end])
            return false;
            
            start++;
            end--;
        }
        
        return true;
        
        
        
        
    }
  
// exapmle test case  abcba   a | bcb | a minimum 2 partitions

    int solve(string &str,int indx) 
    {
        int ans = 9999999; // INT_MAX 
        if(indx == str.length()) return 0; // agr indx last mei pahunch jaye then koi partition nahi hoga so return 0
        string temp = "";
        if(dp[indx]!=-1) return dp[indx];
        for(int j=indx;j<str.length();j++) // indx se aage jata jayega and jha bhi possible string mili palindrome ki wha pe partition krke uske
                                            // aage check krta jayega again kha partition milega
        {
            temp += str[j];
            if(isPalindrome(0,temp.length()-1,temp))
           { int cost = 1 + solve(str,j+1);
            ans = min(ans,cost);} // min return krna ans ka
        }
        
        return dp[indx] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        
        
       
        return solve(str,0) - 1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
