class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length=strlen(s);
        int pos=length-1, size=0;
        while(pos>=0&&s[pos]==' ')
            pos--;
        while(pos>=0&&s[pos]!=' ')
        {
            pos--;
            size++;
        }
        return size;
    }
};
