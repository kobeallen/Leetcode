class Solution {
public:
    int Convert(string array)
    {
        int ans = 0;
        int i = array[0] == '-' ? 1 : 0;
        for(; i < array.size(); ++i)
            ans = 10 * ans + array[i] - '0';
        if(array[0] == '-')
            ans *= -1;
        return ans;
    }
    
    int evalRPN(vector<string> &tokens) {
        stack<int> Stack;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i].size() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
            {
                int second = Stack.top();
                Stack.pop();
                int first = Stack.top();
                Stack.pop();
                if(tokens[i][0] == '+')
                    Stack.push(first + second);
                else if(tokens[i][0] == '-')
                    Stack.push(first - second);
                else if(tokens[i][0] == '*')
                    Stack.push(first * second);
                else
                    Stack.push(first / second);
            }
            else
                Stack.push(Convert(tokens[i]));
        }
        return Stack.top();
    }
};