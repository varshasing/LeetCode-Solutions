class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // palimdrome, therefore can check for divisor (gcd)
        if(str1+str2 == str2+str1)
        {
            int gcd = std::gcd(str1.size(), str2.size());
            string ans = "";
            for(int i = 0; i < gcd; i++)
            {
                ans += str2[i];
            }

            return ans;
        }
        else
        {
            return "";
        }
    }
};
