class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int area=(j-i)*(min(height[i],height[j]));
        while(i<j+1)
        {
            area=max(area,(j-i)*(min(height[i],height[j])));
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return area;
    }
};