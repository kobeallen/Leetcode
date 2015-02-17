class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ans;
        if(S.empty() || L.empty())
            return ans;
        int str_size = S.size();
        int word_num = L.size();
        int word_size = L[0].size();
        int length = word_size * word_num;
        if(length > str_size)
            return ans;
        unordered_map<string, int> need;
        unordered_map<string, int> contain;
        for(int i = 0; i < word_num; ++i)
        {
            unordered_map<string, int>::iterator it = need.find(L[i]);
            if(it == need.end())
            {
                pair<string, int> word1(L[i], 1);
                pair<string, int> word2(L[i], 0);
                need.insert(word1);
                contain.insert(word2);
            }
            else
            {
                it->second = it->second + 1;
            }
        }
        for(int i = 0; i + length - 1 < str_size; ++i)
        {
            int j;
            for(j = 0; j < word_num; ++j)
            {
                string substring = S.substr(i + j * word_size, word_size);
                unordered_map<string, int>::iterator it1 = need.find(substring);
                unordered_map<string, int>::iterator it2 = contain.find(substring);
                if(it1 == need.end() || it1->second <= it2->second)
                {
                    for(unordered_map<string, int>::iterator it = contain.begin(); it != contain.end(); ++it)
                        it->second = 0;
                    break;
                }
                it2->second = it2->second + 1;
            }
            if(j == word_num)
            {
                for(unordered_map<string, int>::iterator it = contain.begin(); it != contain.end(); ++it)
                    it->second = 0;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
