class Solution {
public:
    void Reverse(string &str)
    {
        int left=0, right=str.size()-1;
        while(left<right)
        {
            char t=str[left];
            str[left]=str[right];
            str[right]=t;
            left++, right--;
        }
    }

    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        Reverse(a);
        Reverse(b);
        int size_a=a.size(), size_b=b.size(), size;
        if(size_a>size_b)
            size=size_a;
        else
            size=size_b;
        string ans;
        ans.resize(size);
        int result, digit=0;
        for(int i=0;i<size;i++)
        {
            result=digit;
            if(i<size_a)
                result+=a[i]-'0';
            if(i<size_b)
                result+=b[i]-'0';
            digit=result/2;
            ans[i]=result%2+'0';
        }
        if(digit>0)
            ans.push_back(digit+'0');
        Reverse(ans);
        return ans;
    }
};
