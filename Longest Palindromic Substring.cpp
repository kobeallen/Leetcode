class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return "";
        int max_length=1, pos=0, length;
        int i, j, size=s.size();
        vector<vector<bool> > dp;
        dp.resize(size);
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
                dp[i].push_back(false);
        }
        for(i=0;i<size;i++)
            dp[i][i]=true;
        for(i=0;i<size-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                max_length=2;
                pos=i;
            }
        }
        for(length=3;length<=size;length++)
        {
            for(i=0;i+length-1<size;i++)
            {
                j=i+length-1;
                if(dp[i+1][j-1]==true&&s[i]==s[j])
                {
                    dp[i][j]=true;
                    if(length>max_length)
                    {
                        max_length=length;
                        pos=i;
                    }
                }
            }
        }
        return s.substr(pos, max_length);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_length = 1;
        int pos = 0;
        int size = s.size();
        int start, end, length;
        for(int i = 0; i < 2 * size - 1; ++i)
        {
            if(i % 2 == 0)
            {
                start = i / 2 - 1;
                end = i / 2 + 1;
                length = 1;
            }
            else
            {
                start = i / 2;
                end = i / 2 + 1;
                length = 0;
            }
            while(start >= 0 && end < size && s[start] == s[end])
            {
                length += 2;
                --start;
                ++end;
            }
            if(max_length < length)
            {
                max_length = length;
                pos = start + 1;
            }
        }
        return s.substr(pos, max_length);
    }
};


class Solution {
public:
    string Convert(string s)
    {
        string str;
        for(int i = 0; i < s.size(); ++i)
        {
            str += '#';
            str += s[i];
        }
        str += '#';
        return str;
    }
    
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str = Convert(s);
        int size = str.size();
        int id = 0;
        int max = 0;
        vector<int> P(size, 1);
        for(int i = 1; i < size; ++i)
        {
            if(i <= max)
            {
                int j = 2 * id - i;
                if(j - P[j] + 1 >= 2*id - max)
                    P[i] = P[j];
                else
                    P[i] = max - i + 1;
            }
            while(i-P[i] >= 0 && i+P[i] < size && str[i-P[i]] == str[i+P[i]])
                ++P[i];
            if(max < i + P[i] - 1)
            {
                max = i + P[i] - 1;
                id = i;
            }
        }
        int ans = 1;
        int index = 0;
        string array;
        for(int i = 0; i < size; ++i)
        {
            if(ans < P[i])
            {
                ans = P[i];
                index = i;
            }
        }
        for(int i = index - ans + 1; i <= index + ans - 1; ++i)
        {
            if(str[i] != '#')
                array += str[i];
        }
        return array;
    }
};