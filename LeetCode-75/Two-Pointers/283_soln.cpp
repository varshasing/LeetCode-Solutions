class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // one pointer keeping track of ptr placeholder for non zeroelements
        // another that goes through the array, swap each time encounter a zero
        int nz = 0;
        int z = 0;
        int num = 0;
        while(z < nums.size())
        {
            if(nums[nz] == 0)
            {
                while(z < nums.size())
                {
                    if(nums[z] != 0)
                    {
                        num++;
                        swap(nums[z], nums[nz]);
                        nz++;
                        z++;
                    }
                    else
                    {
                        z++;
                    }
                }
            }
            else
            {
                nz++;
                z++;
            }
        }
        std::cout<<"operations done: "<<num<<endl;
    }
};
