class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left, right, count, size=s.size();
        int ans=0, result;
        count=0, left=0, right=0;
        while(left<size)
        {
            right=left;
            while(count>=0&&right<size)
            {
                if(s[right]=='(')
                    count++;
                else
                {
                    if(count>0)
                    {
                        count--;
                        if(count==0)
                        {
                            result=right-left+1;
                            if(ans<result)
                                ans=result;
                        }
                    }
                    else
                        break;
                }
                right++;
            }
            left=right+1;
        }

        count=0, left=size-1, right=size-1;
        while(right>=0)
        {
            left=right;
            while(count>=0&&left>=0)
            {
                if(s[left]==')')
                    count++;
                else
                {
                    if(count>0)
                    {
                        count--;
                        if(count==0)
                        {
                            result=right-left+1;
                            if(ans<result)
                                ans=result;
                        }
                    }
                    else
                        break;
                }
                left--;
            }
            right=left-1;
        }

        return ans;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right;
        int count;
        int length, max_length = 0;
        while(left < s.size())
        {
            right = left;
            count = 0;
            while(right < s.size())
            {
                if(s[right] == '(')
                {
                    ++count;
                }
                else
                {
                    if(count > 0)
                    {
                        --count;
                        if(count == 0)
                        {
                            length = right - left + 1;
                            if(max_length < length)
                            {
                                max_length = length;
                            }
                        }
                    }
                    else if(count == 0)
                    {
                        break;
                    }
                }
                ++right;
            }
            while(right < s.size() && s[right] == ')')
            {
                ++right;
            }
            left = right;
        }
        right = s.size() - 1;
        while(right >= 0)
        {
            left = right;
            count = 0;
            while(left >= 0)
            {
                if(s[left] == ')')
                {
                    ++count;
                }
                else
                {
                    if(count > 0)
                    {
                        --count;
                        if(count == 0)
                        {
                            length = right - left + 1;
                            if(max_length < length)
                            {
                                max_length = length;
                            }
                        }
                    }
                    else if(count == 0)
                    {
                        break;
                    }
                }
                --left;
            }
            while(left >= 0 && s[left] == '(')
            {
                --left;
            }
            right = left;
        }
        return max_length;
    }
};