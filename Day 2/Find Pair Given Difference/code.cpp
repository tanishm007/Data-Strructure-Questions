// { Driver Code Starts


// TIME COMPLEXITY : O(N*LOGN)


#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int low =0;
    int high = 1;
    while(low<size && high<size)
    {
        if(arr[high]-arr[low]<n)
        high++;
        
      
         
        else if(arr[high]-arr[low]==n && low!=high)
         return true;
         
         else
         low++;
        
        
    }
    return false;
}
