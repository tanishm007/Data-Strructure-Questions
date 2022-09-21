class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        
        if(hand.size() % groupSize != 0)
            return false;
        map<int,int> freq;
        for(auto x:hand)
            freq[x]++;
        
        while(!freq.empty())
        {
            int curr = freq.begin()->first; // key
            
            for(int i=0;i<groupSize;i++)
            {
                if(freq.find(curr + i) == freq.end()) // groupsize tk ke consecutive hone hi chahiye
                    return false;
                
                     freq[curr + i]--; // decrement freq
                if(freq[curr + i] == 0) // if after decremet is 0 then remove
                    freq.erase(curr + i);
               

            }
            
            
            
            
        }
        return true;
        
        
        
    }
};
