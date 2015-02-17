class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        if(words.size()==0)
            return ans;

        int left, right, word_length, tot_length, num=words.size();
        left=0;
        while(left<num)
        {
            word_length=words[left].size();
            tot_length=words[left].size();
            right=left+1;
            while(right<num&&tot_length+words[right].size()+1<=L)
            {
                tot_length+=words[right].size()+1;
                word_length+=words[right].size();
                right++;
            }
            int count=right-left-1;
            int space_length=L-word_length;
            int pos=left;
            string result=words[pos];
            pos++;
            if(count==0||right==num)
            {
                while(pos<right)
                {
                    result+=' '+words[pos];
                    pos++;
                    space_length--;
                }
                for(int j=0;j<space_length;j++)
                    result+=' ';
                ans.push_back(result);
                left=right;
                continue;
            }
            for(int i=0;i<space_length%count;i++)
            {
                for(int j=0;j<space_length/count+1;j++)
                    result+=' ';
                result+=words[pos];
                pos++;
            }
            while(pos<right)
            {
                for(int j=0;j<space_length/count;j++)
                    result+=' ';
                result+=words[pos];
                pos++;
            }
            ans.push_back(result);
            left=right;
        }
        return ans;
    }
};
