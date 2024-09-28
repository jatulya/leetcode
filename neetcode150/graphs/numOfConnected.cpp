class Node{
public:
    int val;
    vector<Node*> child;

    Node(int val){
        this->val = val;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        unordered_map<int, Node*> map;
        unordered_set<int> notVisited;

        for(int i=0; i<n; i++){
            map[i] = new Node(i);
            notVisited.insert(i);
        }

        for(const auto& edge: edges){
            map[edge[0]]->child.push_back(map[edge[1]]);
            map[edge[1]]->child.push_back(map[edge[0]]);
        }

        while(notVisited.size()){
            dfs(notVisited, map[*notVisited.begin()]);
            count++;
        }

        for (auto& pair:map)
            delete pair.second;

        return count;
    }

private: 
    void dfs(unordered_set<int>& set, Node* curr){
        if (!set.count(curr->val)) return;

        set.erase(curr->val);

        for(Node* node: curr->child)
            dfs(set, node);
    }
};

/*
 using union-find algorithm
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents;
        vector<int> ranks;
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(1);
        }
        
        int result = n;
        for (int i = 0; i < edges.size(); i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            result -= doUnion(parents, ranks, n1, n2);
        }
        return result;
    }
    
private:
    int doUnion(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        int p1 = parents[n1];
        int p2 = parents[n2];
        if (p1 == p2) {
            return 0;
        }
        
        if (ranks[p1] > ranks[p2]) {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        } else {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        
        return 1;
    }
}; */
