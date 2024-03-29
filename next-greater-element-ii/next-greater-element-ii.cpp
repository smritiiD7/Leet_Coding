class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       stack<int> s;
        vector<int> v;
        int i;
        for(i=nums.size()-1;i>=0;i--)
        {
            s.push(nums[i]);
        }
        for(i=nums.size()-1;i>=0;i--)
        {
            if(s.size()==0)
                v.push_back(-1);
           else if(s.size()>0&&s.top()>nums[i])
            {
                v.push_back(s.top());
            }
            else if(s.size()>0 && s.top()<=nums[i])
            {
                while(s.size()>0 && s.top()<=nums[i])
                s.pop();
                if(s.size()==0)
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};