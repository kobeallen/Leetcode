// If we reverse the integer of x, it is possible that the reversion of x might overflow. Another way for reversion is to use long long or __int64

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0)
            return false;
        int power=1;
        while(x/power>=10)
            power*=10;
        int unit=10;
        while(x>0)
        {
            int a=x/power;
            int b=x%unit;
            if(a!=b)
                return false;
            x=x%power;
            x=x/unit;
            power=power/100;
        }
        return true;
    }
};
