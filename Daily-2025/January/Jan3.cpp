class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // have left and right sum that changes each time and checks
        int validSplit = 0;
        long long leftsum = 0;
        long long rightsum = 0;
        int length = nums.size();
        for(int i = 0; i < length; i++)
        {
            rightsum += nums[i];
        }
        for(int i = 0; i < length-1; i++)
        {
            leftsum += nums[i];
            rightsum -= nums[i];

            if(leftsum >= rightsum)
            {
                validSplit++;
            }
        }
        return validSplit;
    }
};
