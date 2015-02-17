class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> Hash;
        int left_length, right_length, length, ans = 1;
        for(int i = 0; i < num.size(); ++i)
        {
            if(Hash.find(num[i]) == Hash.end())
            {                
                unordered_map<int, int>::iterator left = Hash.find(num[i] - 1);
                unordered_map<int, int>::iterator right = Hash.find(num[i] + 1);
                if(left != Hash.end() && right != Hash.end())
                {
                    left_length = left->second;
                    left = Hash.find(num[i] - 1 - left_length + 1);
                    right_length = right->second;
                    right = Hash.find(num[i] + 1 + right_length - 1);
                    length = left_length + right_length + 1;                    
                    left->second = length;
                    right->second = length;
                    Hash.insert({num[i], length});
                }
                else if(left != Hash.end())
                {
                    left_length = left->second;
                    left = Hash.find(num[i] - 1 - left_length + 1);
                    length = left->second + 1;                    
                    left->second = length;
                    Hash.insert({num[i], length});
                }
                else if(right != Hash.end())
                {
                    right_length = right->second;
                    right = Hash.find(num[i] + 1 + right_length - 1);
                    length = right->second + 1;                    
                    right->second = length;
                    Hash.insert({num[i], length});
                }
                else
                {
                    Hash.insert({num[i], 1});
                    length = 1;
                }
                if(length > ans)
                    ans = length;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> Hash;
        int length, ans = 0;        
        for(int i = 0; i < num.size(); ++i)
        {
            if(Hash.find(num[i]) == Hash.end())
            {
                length = 1;
                unordered_map<int, int>::iterator left = Hash.find(num[i] - 1);
                unordered_map<int, int>::iterator right = Hash.find(num[i] + 1);
                if(left != Hash.end())
                {                                       
                    left = Hash.find(num[i] - left->second);
                    length += left->second;
                }
                if(right != Hash.end())
                {                                        
                    right = Hash.find(num[i] + right->second);
                    length += right->second;
                }
                Hash.insert({num[i], length});
                if(left != Hash.end())
                    left->second = length;
                if(right != Hash.end())
                    right->second = length;
                if(ans < length)
                    ans = length;
            }
        }
        return ans;
    }
};
