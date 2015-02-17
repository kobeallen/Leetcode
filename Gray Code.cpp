class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size=1<<n;
        vector<int> ans;
        for(int i=0;i<size;i++)
        {
            int result=(i>>1)^i;
            ans.push_back(result);
        }
        return ans;
    }
};
