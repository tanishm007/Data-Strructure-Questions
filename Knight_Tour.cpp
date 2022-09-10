bool isSafe(int xn,int yn, vector<vector<int>> &sol,int n, int m){ // check if step can be taken not out of bounds
    
    if(xn>=0 && xn<n && yn>=0 && yn<m && sol[xn][yn]==-1 )
        return true;
    
    return false;
}

bool helper(int n, int m, vector<vector<int>> &sol,int x,int y, int movei,int row[8],int col[8] ){

    
    if(movei == n*m ) return 1; // if the  last box is also filled
   

    
    
    
    for(int i=0;i<8;i++)
    {
        int xn = x + row[i]; // taking steps for every box
        int yn = y + col[i];
        
        if(isSafe(xn,yn,sol,n,m))
        {
            
            sol[xn][yn] = movei; // marking the box as 1,2,3........
              
            if(helper(n, m,sol,xn,yn,movei + 1,row,col)) return true; // calling itself for checking next step to place
                    sol[xn][yn] = -1; // backtrack if upar wala return false krega then firse -1 ko place krdo
        }
       

        
    }
    
    return false;
}


vector<vector<int>> knightTour(int n, int m) {
    /* 
        Return matrix of size n*m where integer
        at cell(i, j) represent move number of knight to reach that
        cell. Move number start from 0.

        It may be possible that there is no possible order to visit each cell
        exactly once. In that case, return a matrix of size n*m having all the values
        equal to -1.
    */

    // Write your code here.
     vector<vector<int>> sol(n,vector<int>(m,-1));
    vector<vector<int>> nosol(n,vector<int>(m,-1));
    int x = 0;
    int y = 0;
        int row[] = {1,1,2,2,-1,-1,-2,-2};  // steps which knoght can take
           int col[] = {2,-2,1,-1,2,-2,1,-1};
    
    
    sol[0][0] = 0;
    if(helper(n,m,sol,x,y,1,row,col))
        return sol;
    
    else
        return nosol;
}
    
