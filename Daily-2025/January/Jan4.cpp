class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int leftS[26] = {0};
        int rightS[26] = {0};
        for(auto letter : s)
        {
            rightS[letter-'a']++;
        }
        unordered_set<int> S;
        for(int i = 0; i < s.size(); i++)
        {
            int t = s[i] - 'a';
            rightS[t]--;

            for(int j = 0; j < 26; j++)
            {
                if(leftS[j] > 0 && rightS[j] > 0)
                {
                    S.insert(26*t + j);
                }
            }
            leftS[t]++;
        }
        return S.size();

    }
};
