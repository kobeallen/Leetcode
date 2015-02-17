struct node
{
    string str;
    int count;
    int temp_c;
};

bool CMP(const node &A, const node &B)
{
    return A.str<B.str;
}

class Solution {
public:
    int BinarySearch(string str, vector<node> array)
    {
        int left=0, right=array.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(array[mid].str>=str)
                right=mid;
            else
                left=mid+1;
        }
        if(array[left].str!=str)
            return -1;
        return left;
    }
    
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if(L.size()==0)
                return ans;
        vector<node> array;
        int length=L[0].size(), size=S.size();
        int num=L.size();
        int i,j;
        for(i=0;i<num;i++)
        {            
            for(j=0;j<array.size();j++)
            {
                if(L[i]==array[j].str)
                    break;
            }
            if(j<array.size())
                array[j].count++;
            else
            {
                node t;
                t.str=L[i];
                t.count=1;
                t.temp_c=0;
                array.push_back(t);
            }
        }
        sort(array.begin(), array.end(), CMP);
        
        for(i=0;i+length*num<=size;i++)
        {            
            for(j=0;j<array.size();j++)
                array[j].temp_c=0;
            int start=i, count=0;
            while(count<num)
            {
                if(start+length>size)   break;
                string str=S.substr(start, length);
                start+=length;                
                int index=BinarySearch(str, array);
                if(index==-1)
                    break;
                if(array[index].temp_c<array[index].count)
                {
                    array[index].temp_c++;
                    count++;
                }
                else
                    break;
            }
            if(count==num)
                ans.push_back(i);
        }
        return ans;
    }
};