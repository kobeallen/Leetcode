class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string now="1";
        string next;
        int left, right, size;
        for(int i=2;i<=n;i++)
        {
            left=0, size=now.size();
            while(left<size)
            {
                right=left+1;
                while(right<size&&now[left]==now[right])
                    right++;
                next+=right-left+'0';
                next+=now[left];
                left=right;
            }
            now=next;
            next.clear();
        }
        return now;
    }
};