// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here brute force
        
        /*if(n == 1) return {-1};
        bool flag = true;
        int index=0;
        vector<long long> ans;
        for(int i=0;i<n-1;i++)
        {
            flag=true;
            for(int j=i+1;j<n;j++)
            {
                
                if(arr[j]>arr[i]){
                ans.push_back(arr[j]);
                flag=false;
                break;
                }
            }
            if(flag==true)
            ans.push_back(-1);
        }
        ans.push_back(-1);
        return ans; */
         vector<long long> ans;
        stack<long long> st;
        if(n==1) return {-1};
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()==true)
            ans.push_back(-1);
            else if(st.size()>0 && st.top()>arr[i])
            ans.push_back(st.top());
            else if(st.size()>0 && st.top()<=arr[i])
            {
                while(st.size()>0 && st.top()<=arr[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                ans.push_back(-1);
                else
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends