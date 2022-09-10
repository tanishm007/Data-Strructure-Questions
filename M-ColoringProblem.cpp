//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(bool graph[101][101], int m, int n,int node,int curcol,vector<int> &color) // for checking ke adjacent nodes mei same color to present nhi jo hum
                                                                                                //fill karne jare
    {
        for(int k=0;k<n;k++)
        {
            if(graph[node][k] && color[k]==curcol) // agr adjacent mei same color hai then false
            return false;
        }
        return true;
    }
    
    bool colornode(bool graph[101][101], int m, int n,int node,vector<int> &color)
    {
        
        if(node==n) return true;
        
        for(int c =1 ;c<=m;c++)  // node mei har color fill krke check krre
        {
            if(isSafe(graph,m,n,node,c,color)) // checking ke same color na ho adjacent nodes mei
            {
                color[node] = c; 
                
                if(colornode(graph,m,n,node+1,color)) return true; 
                
                color[node] = 0; // agr upar wale ne false diya then backtrack kremnge 0 fill krke
            }
        }
        
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        
       vector<int> color(n,0);
        if(colornode(graph,m,n,0,color))
        return true;
        return false;
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
