struct node
{
    string original;
    string transform;
};

bool CMP(const node &A, const node &B)
{
    return A.transform<B.transform;
}

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<node> array;
        vector<string> ans;
        int size=strs.size();
        array.resize(size);
        for(int i=0;i<size;i++)
        {
            array[i].original=strs[i], array[i].transform=strs[i];
            sort(array[i].transform.begin(), array[i].transform.end());
        }
        sort(array.begin(), array.end(), CMP);
        int left=0, right;
        while(left<size)
        {
            right=left+1;
            while(right<size&&array[left].transform==array[right].transform)
            {
                if(right==left+1)
                    ans.push_back(array[left].original);
                ans.push_back(array[right].original);
                right++;
            }
            left=right;
        }
        return ans;
    }
};
