class Solution {
public: // wordbreak must pre-requisite
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> set;
        for(auto x : wordDict)
            set.insert(x);
        
        string curr = ""; // string with spaces add karne ke liye
        vector<string> ans;
        
        solve(s,set,curr,0,ans);
        
        return ans;
    }
    
    
    void solve(string s, unordered_set<string> set,string curr,int indx,vector<string> &ans)
    {
        if(indx == s.length())
        {
            curr.pop_back(); // last wali extra space delete karne ke liye
            ans.push_back(curr);
        }
        
        string str = "";
        for(int i=indx;i<s.length();i++)
        {
            str.push_back(s[i]); // string ka every element push karne ke liye 
            
            if(set.find(str) != set.end())
            {
                solve(s,set,curr + str + " ",i+1,ans); // curr har word with space add kr rahe and next indx chck krre
            }
        }
    }
};
