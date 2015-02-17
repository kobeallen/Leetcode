class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        if(n==0)
            return ans;
        vector<int> num;
        vector<bool> hash;
        num.push_back(1);
        num.push_back(1);
        int i, j;
        for(i=2;i<=n;i++)
            num.push_back(num[i-1]*i);
        for(i=0;i<=n;i++)
            hash.push_back(false);
        for(i=1;i<=n;i++)
        {
            int minus=num[n-i];
            for(j=1;j<=n;j++)
            {
                if(hash[j]==false)
                {
                    if(k-minus>0)
                        k-=minus;
                    else
                        break;
                }
            }
            hash[j]=true;
            ans+=(j+'0');
        }
        return ans;
    }
};
