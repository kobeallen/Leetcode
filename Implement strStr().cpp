class Solution {
public:
    void ComputePrefix(char *p, vector<int> &prefix)
    {
        int length=strlen(p);
        prefix[1]=0;
        int longest=0;
        for(int i=2;i<=length;i++)
        {
            while(longest>0&&p[longest]!=p[i-1])
                longest=prefix[longest];
            if(p[longest]==p[i-1])
                longest++;
            prefix[i]=longest;
        }
    }

    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> prefix;
        int len1=strlen(haystack), len2=strlen(needle);
        if(len2==0)
            return haystack;
        prefix.resize(len2+1);
        ComputePrefix(needle, prefix);
        int match=0;
        for(int i=1;i<=len1;i++)
        {
            while(match>0&&needle[match]!=haystack[i-1])
                match=prefix[match];
            if(needle[match]==haystack[i-1])
                match++;
            if(match==len2)
                return haystack+i-len2;
        }
        return NULL;
    }
};
