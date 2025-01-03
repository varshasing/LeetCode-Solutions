class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        vector<bool> result;
        // what is the max number to beat
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] > maxCandies)
            {
                maxCandies = candies[i];
            }
        }
        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxCandies)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;

    }
};
