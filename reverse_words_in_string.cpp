class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            string word;
            if(s[i]==' ') // agr koi space hai to skip
                continue;
            
            while(i<n && s[i]!=' ')
                {word += s[i];i++;} // character add krte jao before any space
            
            st.push(word); // word ko stack mei push
        }
        
        string ans;
        
        while(!st.empty())  // pushing words in ans
        {
            ans += st.top();
            st.pop();
            if(!st.empty())
                ans += " ";
        }
        
        return ans;
        
    }
};
