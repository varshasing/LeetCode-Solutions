class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // first soln too complex, prefix sum for all changes
        int length = s.size();
        vector<int> prefix(length, 0);
        int start, end, dir;
        int change = 0;
        int shift;

        // calculate total amt of shifts in range
        for(int query = 0; query < shifts.size(); query++)
        {
            start = shifts[query][0];
            end = shifts[query][1];
            dir = shifts[query][2];
            if(dir == 1)
            {
                prefix[start]++;
                if(end != s.size()-1)
                {
                    prefix[end+1]--;
                }
            }
            else
            {
                prefix[start]--;
                if(end != s.size()-1)
                {
                    prefix[end+1]++;
                }
            }
        }

        // apply shift based on sum
        for(int i = 0; i < prefix.size(); i++)
        {
            change += prefix[i];
            s[i] = 'a' + ((s[i] - 'a' + change % 26 + 26) % 26);
        }
        return s;
    }
};
