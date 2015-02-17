class Solution
{
public:
    bool DFS(string s, string p, int s_pos, int p_pos)
    {
        if(s_pos==s.size()&&p_pos==p.size())
            return true;
        if(p_pos==p.size())
            return false;
        if(s_pos==s.size())
        {
            while(p_pos<p.size()-1&&p[p_pos+1]=='*')
                p_pos=p_pos+2;
            if(p_pos==p.size())
                return true;
            else
                return false;
        }
        if(p_pos==p.size()-1||p[p_pos+1]!='*')
        {
            if(s[s_pos]==p[p_pos]||p[p_pos]=='.')
                return DFS(s, p, s_pos+1, p_pos+1);
            else
                return false;
        }
        else
        {
            if(s[s_pos]==p[p_pos]||p[p_pos]=='.')
                return DFS(s, p, s_pos, p_pos+2)||DFS(s, p, s_pos+1, p_pos+2)||DFS(s, p, s_pos+1, p_pos);
            else
                return DFS(s, p, s_pos, p_pos+2);
        }
    }

    bool isMatch(const char *s, const char *p)
    {
        string ss;
        string pp;
        int i, length=strlen(s);
        while(i<length)
        {
            ss+=s[i];
            i++;
        }
        i=0, length=strlen(p);
        while(i<length)
        {
            if(i<length-1&&p[i+1]=='*')
            {
                int j=i+2;
                while(j<length-1&&p[i]==p[j]&&p[i+1]==p[j+1])
                    j+=2;
                pp+=p[i];
                pp+=p[i+1];
                i=j;
            }
            else
            {
                pp+=p[i];
                i++;
            }
        }
        return DFS(ss, pp, 0, 0);
    }
};



class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0)
        {
            if(*p == 0)
                return true;
            if(*(p + 1) != '*')
                return false;
            else
                return isMatch(s, p + 2);
        }
        if(*p == 0)
            return false;
        if(*(p + 1) == '*')
        {
            if(isMatch(s, p + 2) == true)
                return true;
            else if(*p == '.' || *s == *p)
                return isMatch(s + 1, p);
            else
                return false;
        }
        else if(*p == '.')
        {
            return isMatch(s + 1, p + 1);
        }
        else
        {
            if(*s == *p)
                return isMatch(s + 1, p + 1);
            else
                return false;
        }
    }
};
