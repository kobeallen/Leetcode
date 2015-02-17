class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int need[256];
        int found[256];
        memset(need, 0, sizeof(need));
        memset(found, 0, sizeof(found));
        int i, j;
        for(i=0;i<T.size();i++)
            need[T[i]]++;
        int count=0, start=0, end=0;
        int min_length=1000000, pos;
        while(end<S.size())
        {
            if(need[S[end]]==0)
            {
                end++;
                continue;
            }
            if(found[S[end]]<need[S[end]])
                count++;
            found[S[end]]++;
            if(count==T.size())
            {
                while(need[S[start]]==0||found[S[start]]>need[S[start]])
                {
                    if(found[S[start]]>need[S[start]])
                        found[S[start]]--;
                    start++;
                }
                if(min_length>end-start+1)
                {
                    min_length=end-start+1;
                    pos=start;
                }
            }
            end++;
        }
        string ans;
        if(min_length==1000000)
            return ans;
        else
        {
            ans=S.substr(pos, min_length);
            return ans;
        }
    }
};



class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> contain(256, 0);
        vector<int> need(256, 0);
        for(int i = 0; i < T.size(); ++i)
        {
            ++need[T[i]];
        }
        int count = 0;
        int min_length = 1000000;
        int pos;
        int left = 0, right = 0;
        while(right < S.size())
        {
            while(right < S.size() && count < T.size())
            {
                ++contain[S[right]];
                if(contain[S[right]] <= need[S[right]])
                    ++count;
                ++right;
            }
            if(count == T.size())
            {
                while(left < right && contain[S[left]] > need[S[left]])
                {
                    --contain[S[left]];
                    ++left;
                }
                if(min_length > right - left)
                {
                    min_length = right - left;
                    pos = left;
                }
                --contain[S[left]];
                ++left;
                --count;
            }
        }
        string ans;
        if(min_length == 1000000)
            return ans;
        else
        {
            ans = S.substr(pos, min_length);
            return ans;
        }
    }
};};