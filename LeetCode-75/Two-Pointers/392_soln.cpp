class Solution {
public:
    bool isSubsequence(string s, string t) {
        // pointer for each letter in s and t, increment the one in s if match
        int sp = 0;
        int tp = 0;
        while(sp < s.size() && tp < t.size())
        {
            if(s[sp] == t[tp])
            {
                sp++;
            }
            tp++;
        }
        if(sp == s.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
