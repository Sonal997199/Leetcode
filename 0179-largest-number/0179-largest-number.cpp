class Solution {
public:
    static bool comp(string a,string b)
    {
        string s1=a+b;
        string s2=b+a;
        return s1>s2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(to_string(nums[i]));
        }
        
        sort(ans.begin(),ans.end(),comp);
        
        if(ans[0]=="0")return "0";
        
        string res="";
        
        for(int i=0;i<ans.size();i++)res+=ans[i];
        return res;
    }
};