class Solution {
public:
    string reverseVowels(string s) {
        int fi, bi;
        std::string vowel = "aAeEiIoOuU";
        char temp;
        fi = 0;
        bi = s.size()-1;
        while(fi < bi)
        {
            // check if either are at a vowel. If so, then wait until the other is at the vowel
            if(vowel.find(s[fi]) != std::string::npos)
            {
                
                if(vowel.find(s[bi]) != std::string::npos)
                {
                    std::cout<<"found at: "<<s[bi]<<endl;
                    temp = s[fi];
                    s[fi] = s[bi];
                    s[bi] = temp;
                    fi++;
                    bi--;
                }
                else
                {
                    bi--;
                }
            }
            else
            {
                fi++;
            }
        }
        return s;
    }
};
