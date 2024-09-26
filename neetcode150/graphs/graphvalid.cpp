class Node{
public:
    int val;
    vector<Node* > edge;
    Node(int v){
        val = v;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;

        unordered_map<int, Node* > map;
        for(int i=0; i<n; i++)
            map[i] = new Node(i);
        
        for(auto const e: edges){
            Node* p = map[e[0]];
            Node* c = map[e[1]];
            p->edge.push_back(c);
            c->edge.push_back(p);
        }

        unordered_set<Node*>visited;
        int i=0;
        return dfs(visited, map[0], nullptr) && visited.size()==n;
                    
    }
private:
    bool dfs(unordered_set<Node*>& met, Node* curr, Node* prev){      
        if (met.count(curr)) return false;

        met.insert(curr);
        for(Node* child: curr->edge)
            if (child!= prev && !dfs(met, child, curr)) 
                return false;

        return true;
    }
};
