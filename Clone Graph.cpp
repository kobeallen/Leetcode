/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(node == NULL)
            return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> Hash;
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        Hash.insert({node, root});
        queue<UndirectedGraphNode *> Q;
        Q.push(node);
        while(!Q.empty())
        {
            UndirectedGraphNode *now = Q.front();
            Q.pop();
            UndirectedGraphNode *clone_now = Hash.find(now)->second;
            for(int i = 0; i < now->neighbors.size(); ++i)
            {
                UndirectedGraphNode *next = now->neighbors[i];
                unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator search = Hash.find(next);
                if(search == Hash.end())
                {
                    UndirectedGraphNode *clone_next = new UndirectedGraphNode(next->label);
                    Hash.insert({next, clone_next});
                    Q.push(next);
                    clone_now->neighbors.push_back(clone_next);
                }
                else
                {
                    clone_now->neighbors.push_back(search->second);
                }
            }
        }
        return root;
    }
};
