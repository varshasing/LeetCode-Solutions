class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix[nums.size()];
        int suffix[nums.size()];
        vector<int> prod;
        int product = 1;
        prefix[0] = 1;
        suffix[nums.size()-1] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            product *= nums.at(i-1);
            prefix[i] = product;
        }
        product = 1;
        for(int j = nums.size()-2; j >= 0; j--)
        {
            product *= nums.at(j+1);
            suffix[j] = product;
        }
        for(int k = 0; k < nums.size(); k++)
        {
            prod.push_back(suffix[k]*prefix[k]);
        }
        return prod;
    }
};
