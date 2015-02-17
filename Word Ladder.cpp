class Solution {
public:
    bool Check(string s1, string s2)
    {
        int length = s1.size(), different = 0;
        for(int i = 0; i < length; ++i)
        {
            if(s1[i] != s2[i])
                ++different;
        }
        if(different > 1)
            return false;
        else
            return true;
    }
    
    vector<vector<bool> > BuildGraph(vector<string> S)
    {
        vector<vector<bool> > G;
        vector<bool> t;
        for(int i = 0; i < S.size(); ++i)
            t.push_back(false);
        for(int i = 0; i < S.size(); ++i)
            G.push_back(t);
        for(int i = 0; i < S.size(); ++i)
        {
            for(int j = 0; j < S.size(); ++j)
            {
                if(i != j)
                {
                    if(Check(S[i], S[j]))
                    {
                        G[i][j] = true;
                        G[j][i] = true;
                    }
                }
            }
        }
        return G;
    }
    
    int BFS(vector<vector<bool> > G)
    {
        vector<int> step;
        for(int i = 0; i < G.size(); ++i)
            step.push_back(-1);
        step[0] = 0;
        queue<int> Q;
        Q.push(0);
        while(!Q.empty())
        {
            int head = Q.front();
            Q.pop();
            for(int i = 0; i < G.size(); ++i)
            {
                if(G[head][i] == true && step[i] == -1)
                {
                    step[i] = step[head] + 1;
                    Q.push(i);
                }
            }
        }
        if(step[G.size() - 1] != -1)
            return step[G.size() - 1] + 1;
        else
            return 0;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> S;
        S.push_back(start);
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
            S.push_back(*it);
        S.push_back(end);
        vector<vector<bool> > G = BuildGraph(S);
        return BFS(G);
    }
};



struct node
{
    string S;
    int step;
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<string> visit;
        queue<node> Q;
        node next;
        node now;
        int step = 1;
        next.S = start, next.step = step;
        Q.push(next);
        visit.insert(start);
        while(!Q.empty())
        {
            now = Q.front();
            Q.pop();
            int size = now.S.size();
            for(int i = 0; i < size; ++i)
            {
                for(int j = 0; j < 26; ++j)
                {
                    if(now.S[i] == 'a' + j)
                        continue;
                    string tmp = now.S;
                    tmp[i] = 'a' + j;
                    if(tmp == end)
                        return now.step + 1;
                    if(visit.find(tmp) == visit.end() && dict.find(tmp) != dict.end())
                    {
                        next.S = tmp, next.step = now.step + 1;
                        Q.push(next);
                        visit.insert(tmp);
                    }
                }
            }
        }
        return 0;
    }
};