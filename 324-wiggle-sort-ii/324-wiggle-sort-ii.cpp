class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        vector<int> v(n);
        int i=1,j=n-1;
        while(i<n)
        {
            v[i]=nums[j];
            i+=2;
            j--;
            
        }
         i=0;
        while(i<n)
        {
            v[i]=nums[j];
            i+=2;
            j--;
            
        }
        for(int k=0;k<n;k++)
        {
            nums[k] = v[k];
        }
    
    }
};