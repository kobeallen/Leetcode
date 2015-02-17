class Solution {
public:
    string trim(string s)
    {
        string ans;
        int pos = 0;
        while(pos < s.size() && s[pos] == ' ')
            ++pos;
        while(pos < s.size())
        {
            while(pos < s.size() && s[pos] != ' ')
            {
                ans += s[pos];
                ++pos;
            }
            while(pos < s.size() && s[pos] == ' ')
                ++pos;
            if(pos < s.size())
                ans += ' ';
        }
        return ans;
    }
    
    void reverse(string &s, int left, int right)
    {
        while(left < right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
    }
    
    void reverseWords(string &s) {
        s = trim(s);
        int size = s.size();
        reverse(s, 0, size - 1);
        int left = 0, right;
        while(left < size)
        {
            right = left + 1;
            while(right < size && s[right] != ' ')
                ++right;
            reverse(s, left, right - 1);
            left = right + 1;
        }
    }
};