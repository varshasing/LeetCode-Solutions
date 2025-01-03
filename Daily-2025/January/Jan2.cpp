class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int i, j;
        vector<int> score;
        char first, last;
        std::string vowels = "aeiou";
        for(i = 0; i < words.size(); i++)
        {
            first = words[i][0];
            last = words[i].back();
            if(vowels.find(first) != std::string::npos && vowels.find(last) != std::string::npos)
            {
                score.push_back(1);
            }
            else
            {
                score.push_back(0);
            }
        }
        // running sum
        for(i = 1; i < score.size(); i++)
        {
            score[i] += score[i-1];
        }
        vector<int> result;
        for(i = 0; i < queries.size(); i++)
        {
            if(queries[i][0] == 0)
            {
                result.push_back(score[queries[i][1]]);
            }
            else
            {
                result.push_back(score[queries[i][1]] - score[queries[i][0] - 1]);
            }
        }
        return result;
    }
};
