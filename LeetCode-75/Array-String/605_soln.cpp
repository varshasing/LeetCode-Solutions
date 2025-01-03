class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // can place a flower if there is no flower adjacent to it, only check right for start
        // and left for end
        int i = 0;
        int numplaced = 0;
        // check first place
        if(flowerbed.size() > 1)
        {
            if(flowerbed[0] == 0)
            {
                if(flowerbed[1] == 0)
                {
                    numplaced++;
                    flowerbed[0] = 1;
                }
            }
            for(i = 1; i < flowerbed.size()-1; i++)
            {
                if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0)
                {
                    numplaced++;
                    flowerbed[i] = 1;
                }
            }
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0)
            {
                numplaced++;
                flowerbed[i] = 1;
            }
            return (numplaced >= n);
        }
        else
        {
            if(flowerbed.size() == 1 && flowerbed[0] == 0)
            {
                return (++numplaced >= n);
            }
            else
            {
                return (numplaced >= n);
            }
        }
    }
};
