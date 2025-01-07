class Solution {
public:
    vector<int> minOperations(string boxes) {
        // have an array for prefix and postfix
        // on prefix side, note the number of operations to get all balls on left side
        // on postfix side, note the number of operations to get all balls on right side
        int num = boxes.size();
        int balls = 0;
        vector<int> prefix(num, 0);
        vector<int> postfix(num, 0);
        
        // prefix sum
        for(int i = 1; i < num; i++)
        {
            if(boxes[i-1] == '1')
            {
                balls++;
            }
            prefix[i] += prefix[i-1] + balls;
        }
        
        // postfix sum
        balls = 0;
        for(int i = num-2; i >= 0; i--)
        {
            if(boxes[i+1] == '1')
            {
                balls++;
            }
            postfix[i] += postfix[i+1] + balls;
        }

        for(int i = 0; i < num; i++)
        {
            prefix[i] += postfix[i];
        }
        return prefix;
    }
};
