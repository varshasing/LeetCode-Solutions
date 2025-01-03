class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int smaller = min(word1.size(), word2.size());
        string ans = "";
        for(int i = 0; i < smaller; i++)
        {
            ans += word1[i];
            ans += word2[i];
        }
        if(word1.size() > smaller)
        {
            for(int i = smaller; i < word1.size(); i++)
            {
                ans += word1[i];
            }
        }
        if(word2.size() > smaller)
        {
            for(int i = smaller; i < word2.size(); i++)
            {
                ans += word2[i];
            }
        }
        return ans;
        
    }
};
