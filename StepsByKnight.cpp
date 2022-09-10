//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    
    bool isSafe(int row,int col,int n,vector<vector<int>> &visited) // check karne ke liye knight step rkh skta hai ke nai
    {
        if(row>=0 && col>=0 && row<n && col<n && !visited[row][col])
        return true;
        
        return false;
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int row[] = {1,1,-1,-1,2,2,-2,-2}; // steps in direction jo knight chl skta hai every possible step 
	    int col[] = {-2,2,-2,2,1,-1,1,-1};
	    
	    int x = KnightPos[0] - 1;  // 1 based indexing ko 0 based indexing mei change karne ke liye
	    int y  = KnightPos[1] - 1;
	    
	    int tx  = TargetPos[0] - 1;
	    int ty = TargetPos[1] - 1;
	    
	    queue<pair<pair<int,int>,int>> q; 
	    
	    vector<vector<int>> visited(N,vector<int>(N,0)); // visited mark karne ke liye
	    
	    q.push({{x,y},0});     // starting mei koi step ni liya 0 and coordinates push kare
	    visited[x][y] = 1;
	    
	    if(x==tx && y == ty)
	    return 0;
	     int tm = 0;
	    while(!q.empty())
	    {
	       
	        
	        auto k = q.front();
	         q.pop();
	        int kx = k.first.first;
	        int ky = k.first.second;
	    
	        int dis = k.second;
	        
	  
	        
	        
	        
	        for(int i=0;i<8;i++) // a knight can take step in 8 directions
	        {
	            x = kx + row[i];
	            y  = ky + col[i];
	             if(x==tx && y == ty) // if position and target is equal return steps
	            {
	                return dis + 1;
	            }
	            if(isSafe(x,y,N,visited)) 
	            {
	                visited[x][y] = 1;
	                q.push({{x,y},dis+1}); // push coordinates of new step and add step
	              
	                
	            
	           }
	            
	           
	        }
	        
	    
	    }
	    
	    
	       return -1;
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
