class Solution {
public:
    void DFS(int id, int target, vector<int> num, vector<int> &result, vector<vector<int> > &ans)
    {
        if(target==0)
        {
            ans.push_back(result);
            return ;
        }
        int left, right;
        left=id;
        while(left<num.size())
        {
            if(target-num[left]>=0)
            {
                result.push_back(num[left]);
                DFS(left+1, target-num[left], num, result, ans);
                result.pop_back();
            }
            right=left+1;
            while(right<num.size()&&num[left]==num[right])
                right++;
            left=right;
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        sort(num.begin(), num.end());
        DFS(0, target, num, result, ans);
        return ans;
    }
};


class Solution {
public:
    void DFS(int id, vector<int> num, int target, vector<int> result, vector<vector<int> > &ans)
    {
        if(target == 0)
        {
            ans.push_back(result);
            return ;
        }
        int left = id, right;
        while(left < num.size())
        {
            if(num[left] <= target)
            {
                result.push_back(num[left]);
                DFS(left + 1, num, target - num[left], result, ans);
                result.pop_back();
                right = left + 1;
                while(right < num.size() && num[left] == num[right])
                {
                    ++right;
                }
                left = right;
            }
            else
                break;
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<int> result;
        vector<vector<int> > ans;
        DFS(0, num, target, result, ans);
        return ans;
    }
};