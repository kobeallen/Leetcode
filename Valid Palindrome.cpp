class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return true;
        string P;
        for(int i = 0; i < s.size(); ++i)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                P += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z')
                P += s[i] - 'A' + 'a';                        
        }
        int left = 0, right = P.size() - 1;
        while(left < right)
        {
            if(P[left] != P[right])
                return false;
            ++left, --right;
        }
        return true;
    }
};

class Solution {
public:
    int Convert(char c)
    {
        if(c >= 'a' && c <= 'z')
            return c -'a';
        else if(c >= 'A' && c <= 'Z')
            return c - 'A';
        else 
            return c - '0' + 26;
    }
    
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            while(left < right && !((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z') || (s[left] >= '0' && s[left] <= '9')))
                ++left;
            if(left == right)
                break;
            while(left < right && !((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z') || (s[right] >= '0' && s[right] <= '9')))
                --right;
            if(left == right)
                break;
            int l = Convert(s[left]);
            int r = Convert(s[right]);
            if(l != r)
                return false;
            ++left;
            --right;
        }
        return true;
    }
};
