class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int  sum=0;
        for(int k=0;k<nums.size();k++)
        {
            sum+=nums[k];
        }
        if(sum%2!=0)
            return false;
        sum/=2;
        int i,j,n=nums.size();
        bool t[n+1][sum+1];
        for(i=0;i<n+1;i++)
        {
            for(j=0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j]=false;
                if(j==0)
                    t[i][j]=true;   
            }
        }
        for(i=1;i<n+1;i++)
        {
            for(j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[i-1][j-1];
        
    }
};