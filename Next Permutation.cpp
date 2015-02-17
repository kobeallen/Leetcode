class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()==0)
            return ;
        vector<int> result;
        int i, j;
        int pos=num.size()-1;
        while(pos>=0)
        {
            int t=1000000;
            int id;
            for(i=0;i<result.size();i++)
            {
                if(num[pos]<result[i])
                {
                    if(t>result[i])
                    {
                        t=result[i];
                        id=i;
                    }
                }
            }
            if(t==1000000)
            {
                result.push_back(num[pos]);
                pos--;
            }
            else
            {
                int temp=result[id];
                result[id]=num[pos];
                num[pos]=temp;
                break;
            }
        }
        if(pos<0)
            sort(num.begin(), num.end());
        else
        {
            sort(result.begin(), result.end());
            for(i=pos+1, j=0;j<result.size();i++, j++)
            {
                num[i]=result[j];
            }
        }
    }
};
