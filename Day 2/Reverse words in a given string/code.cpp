// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    
    // Time compexity : O(N)
    // Space complexity : O(1)
    
    void revers(string &S, int start, int end)
    {
        while(start<=end)
        {
            swap(S[start],S[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string S) 
    { 
        // code here 
        int start = 0;
        int end;
        for( end = 0 ;end<S.length();end++)
        {
            if(S[end]=='.')
            {
            revers(S,start,end-1);
            start=end+1;
            }
        }
        revers(S,start,end-1);
        revers(S,0,S.length()-1);
        return S;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
