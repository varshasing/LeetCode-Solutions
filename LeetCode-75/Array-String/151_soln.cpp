class Solution {
public:
    string reverseWords(string s) {
        // create a stack that holds each word and create a new string with this
        std::stack<std::string> stack;
        std::string returned = "";
        int b = 0;
        int e = 0;
        // until the end of the word
        while(e < s.size() && b < s.size())
        {
            // start of a new word found
            if(s[b] != ' ')
            {
                e = b;
                while(e < s.size())
                {
                    if(s[e] != ' ')
                    {
                        e++;
                    }
                    else
                    {
                        stack.push(s.substr(b, e-b));
                        break;
                    }
                }
                if(e == s.size() && s[e-1] != ' ')
                {
                    stack.push(s.substr(b));
                }
                b = e;
            }
            else
            {
            b++;
            }
        }
        while(!stack.empty())
        {
            returned = returned + stack.top() + " ";
            stack.pop();
        }
        returned.resize(returned.size()-1);
        return returned;
    }
};
