class UnionFind {
public: 
    vector<int> parent, rank; 
    UnionFind(int n) {
        parent.resize(n); 
        iota(begin(parent), end(parent), 0); 
        rank.resize(n); 
        fill(rank.begin(), rank.end(), 1); 
    } 
    
    int find(int p) {
        if (parent[p] != p) 
            parent[p] = find(parent[p]); 
        return parent[p]; 
    }
    
    bool connect(int p, int q) {
        /* union with rank */
        int prt = find(p), qrt = find(q); 
        if (prt == qrt) return false; 
        if (rank[prt] > rank[qrt]) swap(prt, qrt);
        parent[prt] = qrt; 
        rank[qrt] += rank[prt]; 
        return true; 
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans; 
        UnionFind *uf = new UnionFind(n); 
        for (auto& request : requests) {
            int u = uf->find(request[0]), v = uf->find(request[1]); 
            bool found = false; 
            for (auto& restriction : restrictions) {
                int x = uf->find(restriction[0]), y = uf->find(restriction[1]); 
                if ((u == x && v == y) || (u == y && v == x)) {
                    found = true; 
                    break; 
                }
            }
            ans.push_back(!found); 
            if (!found) uf->connect(u, v); 
        }
        delete uf; 
        return ans; 
    }
};
