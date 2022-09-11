class Solution {
public:
      // without using memoization
    bool solve(string &s,unordered_set<string> &set,int indx )
    {
        if(indx == s.length())
            return true;
        
        string str = "";
        
        for(int i=indx;i<s.length();i++){
            str += s[i];
            if(set.find(str) != set.end())
            {
                if(solve(s,set,i+1)) return true;
            }
        }
        
        return false;
        
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int indx = 0;
        
        unordered_set<string> set;
        
        for(auto x:wordDict)
            set.insert(x);
        return solve(s,set,indx);
        
    }
};




// using memoization

class Solution {
public:
    int dp[301]; // from contraint string size initialize dp
    bool solve(string &s,unordered_set<string> &set,int indx )
    {
        if(indx == s.length()) // agr last indx mei pahunch gya means we got all words present in dictionary or set
            return true;
        
        if(dp[indx] != -1) return dp[indx];
        
        string str = ""; // temp string jismei string ka har character insert krke check krre
        
        for(int i=indx;i<s.length();i++){
            str += s[i];
            if(set.find(str) != set.end()) // agr str dic ke word ke equal ho gya then set mei present hoga
            {
                if(solve(s,set,i+1)) return dp[indx] =  true; // agr word set mei present hai then uske just next indx se start krke dekhenge 
                                                               // because puri string ke words dic mei present hain isliye condition work krri hai
            }
        }
        
        return dp[indx] = false;
        
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int indx = 0;
        memset(dp,-1,sizeof(dp));
        unordered_set<string> set;
        
        for(auto x:wordDict)
            set.insert(x);
        return solve(s,set,indx);
        
    }
};



