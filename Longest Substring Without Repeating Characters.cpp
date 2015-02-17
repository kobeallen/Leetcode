class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size=s.size();
        bool hash[256];
        memset(hash, 0, sizeof(hash));
        int left=0, right=0;
        int max_length=0, length;
        while(right<size)
        {
            if(hash[s[right]]==false)
            {
                hash[s[right]]=true;
                right++;
            }
            else
            {
                length=right-left;
                if(max_length<length)
                    max_length=length;
                while(left<right)
                {
                    hash[s[left]]=false;
                    left++;
                    if(hash[s[right]]==false)
                        break;
                }
            }
        }
        length=right-left;
        if(max_length<length)
            max_length=length;
        return max_length;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = 0;
        int length, max_length = 0;
        bool hash[256];
        memset(hash, 0, sizeof(hash));
        while(left < s.size())
        {
            while(right < s.size())
            {
                if(hash[s[right]] == false)
                {
                    hash[s[right]] = true;
                    ++right;
                }
                else
                    break;
            }
            length = right - left;
            if(max_length < length)
                max_length = length;
            if(right == s.size())
                break;
            while(left < right)
            {
                if(s[left] != s[right])
                {
                    hash[s[left]] = false;
                    ++left;
                }
                else
                {
                    ++left;
                    ++right;
                    break;
                }
            }
        }
        return max_length;
    }
};