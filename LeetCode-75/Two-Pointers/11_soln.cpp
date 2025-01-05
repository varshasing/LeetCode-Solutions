class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int check;
        int lend = 0;
        int rend = height.size()-1;
        while(lend < rend)
        {
            check = min(height[rend], height[lend])*(rend-lend);
            if(maxwater < check)
            {
                maxwater = check;
            }
            if(height[lend] < height[rend])
            {
                lend++;
            }
            else
            {
                rend--;
            }
        }
        return maxwater;
    }
};
