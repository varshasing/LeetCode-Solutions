class Solution {
public:
    int compress(vector<char>& chars) {
        std::string s = "";
        int count;
        char letter;
        int totalspace = 0;
        for(int i = 0; i < chars.size(); i +=0)
        {
            letter = chars[i];
            count = 1;
            totalspace++;
            i++;
            // i will point to the end or a new letter
            while(i < chars.size())
            {
                if(chars[i] == letter)
                {
                    count++;
                    i++;
                }
                else
                {
                    break;
                }
            }
            s += letter;
            // need to add count or not
            if(count == 1)
            {
                // don't do anything else
            }
            else
            {
                std::string itoa = std::to_string(count);
                s += itoa;
            }
        }
        for(int i = 0; i < s.size(); i++)
        {
            chars[i] = s[i];
        }
        return s.size();
    }
};
