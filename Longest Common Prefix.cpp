class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        if(strs.size()==0)
            return ans;
        sort(strs.begin(), strs.end());
        int size=strs.size();
        for(int i=0;i<strs[0].size()&&i<strs[size-1].size();i++)
        {
            if(strs[0][i]==strs[size-1][i])
                ans+=strs[0][i];
            else
                break;
        }
        return ans;
    }
};
