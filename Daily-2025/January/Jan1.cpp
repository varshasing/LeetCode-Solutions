class Solution {
public:
    int maxScore(string s) {
        // left: 0
        // right: 1
        // have an array the size of the string, init to zero
        int length = s.size();
        vector<int> score;
        // start from first split for left side, count number of zeros
        int leftscore = 0;
        int i;
        for(i = 0; i < length-1; i++)
        {
            if(s[i] == '0')
            {
                leftscore += 1;
            }
            score.push_back(leftscore);
            
        }
        score.push_back(leftscore);
        // same idea but on right side
        int rightscore = 0;
        int max = 0;
        for(i = length-1; i > 0; i--)
        {
            if(s[i] == '1')
            {
                rightscore += 1;
                score.at(i) = score.at(i) + rightscore;
            }
        }
        for(i = 0; i < length; i++)
        {
            if(max < score[i])
            {
                max = score[i];
            }
        }
        return max;
    }
};
