class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // sort in increasing order
        int lp = 0;
        int rp = nums.size()-1;
        int guess;
        int ops = 0;
        sort(nums.begin(), nums.end());
        while(lp < rp)
        {
            guess = nums[rp] + nums[lp];
            if(guess == k)
            {
                lp++;
                rp--;
                ops++;
            }
            else if(guess < k)
            {
                lp++;
            }
            else
            {
                rp--;
            }
        }
        return ops;
    }
};
