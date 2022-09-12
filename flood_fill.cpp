class Solution {
public:
   bool visited[51][51];
    
    bool isSafe(vector<vector<int>>& image, int i, int j, int color,int colmatch) // checking if it is possible to fill
    {
        if(i>=0 && j>=0 && i<image.size() && j<image[0].size() && !visited[i][j] && image[i][j] == colmatch)  // col match becoz check karne ke liye jo color fill krre wo color image[sr][sc] wala hi ho 
            return true;
        return false;
    }
    
    void solve(vector<vector<int>>& image, int i, int j, int color, int colmatch)
    {
        
                if(isSafe(image,i,j,color,colmatch))
                {
                    image[i][j] = color;
                    visited[i][j] = true;
                    solve(image,i+1,j,color,colmatch); // all in four directions recursive calls
                    solve(image,i-1,j,color,colmatch);
                    solve(image,i,j+1,color,colmatch);
                    solve(image,i,j-1,color,colmatch);
                    
                }
            
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        memset(visited,0,sizeof(visited));   
        int colmatch = image[sr][sc];
        
        solve(image,sr,sc,color,colmatch);
        return image;
        
        
    }
};

// time : O(N)
// space : O(N)
