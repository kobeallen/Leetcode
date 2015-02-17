class Solution {
public:
    void Reverse(string &num)
    {
        int left=0, right=num.size()-1;
        while(left<right)
        {
            char t=num[left];
            num[left]=num[right];
            num[right]=t;
            left++, right--;
        }
    }

    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        int i, j;
        for(i=0;i<num1.size()+num2.size();i++)
            ans.push_back('0');
        Reverse(num1);
        Reverse(num2);
        int digit, result;
        for(i=0;i<num1.size();i++)
        {
            digit=0;
            for(j=0;j<num2.size();j++)
            {
                result=(num1[i]-'0')*(num2[j]-'0')+(ans[i+j]-'0')+digit;
                digit=result/10;
                ans[i+j]=(result%10)+'0';
            }
            while(digit>0)
            {
                result=(ans[i+j]-'0')+digit;
                digit=result/10;
                ans[i+j]=(result%10)+'0';
                j++;
            }
        }
        int pos=num1.size()+num2.size()-1;
        while(pos>0&&ans[pos]=='0')
            pos--;
        if(pos<num1.size()+num2.size()-1)
            ans.erase(pos+1);
        Reverse(ans);
        return ans;
    }
};
