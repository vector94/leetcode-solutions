class UnionFind {
private:
    static const int nax = 1e5 + 5;
    int n;                                  /// total number of nodes
    int group;                              /// total disconnected group;
    int sz[nax];                            /// size of a network
    int parent[nax];                        /// parent of a node
    int edge_cnt[nax];                      /// number of edge;
public:
    inline void Init(int n){
        this -> n = group = n;
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            sz[i] = 1;
            edge_cnt[i] = 0;
        }
    }
    inline int Find(int p){                 /// finds parent of p
        return p == parent[p] ? p : parent[p] = Find(parent[p]);
    }
    inline int Connected(int p, int q){     /// checks p and q is connected or not
        return Find(p) == Find(q);
    }
    inline int group_cnt(){                  /// gives number of disconnected group
        return group;
    }
    inline int Total(){                     /// gives total number of nodes in network
        return n;
    }
    inline int Size(int p){                 /// gives the size of the group of p
        return sz[ Find(p) ];
    }
    inline int Edge(int p){                 /// gives total number of edges in network
        return edge_cnt[ Find(p)];
    }
    inline void Union(int p, int q){        /// merges the group of p and q
        int par1 = Find(p);
        int par2 = Find(q);
        edge_cnt[par1]++;
        if(par1 == par2){
            if (p == q){
                edge_cnt[par1]++;
            }
            return;
        }
        else{
            group--;
        }
        if(sz[par1] > sz[par2]){
            parent[par2] = par1;
            sz[par1] += sz[par2];
            edge_cnt[par1] += edge_cnt[par2];
        }
        else{
            parent[par1] = par2;
            sz[par2] += sz[par1];
            edge_cnt[par2] += edge_cnt[par1];
        }
    }
}DSU;


class Solution {
public:
    const static int N = 100000;
    bool sieve[N + 5];
    vector<int> primes;
    void gen_prime(){
        int sqrtN = sqrt(N);
        for (int i = 3; i <= sqrtN; i+= 2){
            if (!sieve[i]){
                for (int j = i * i; j <= N; j += 2 * i){        /// i * i may overflow
                    sieve[j] = true;
                }
            }
        }
        primes.push_back(2);
        for (int num = 3; num <= N; num+= 2){
            if (!sieve[num]){
                primes.push_back(num);
            }
        }
    }
    
    vector<int> prime_factors(int num){
        vector<int> ret;
        int sqrtN = sqrt(num);
        for (int i = 0, limit = primes.size(); i < limit && primes[i] <= sqrtN; i++){
            if (num % primes[i] == 0){
                ret.push_back(primes[i]);
                num /= primes[i];
                while (num % primes[i] == 0){
                    num /= primes[i];
                }
                sqrtN = sqrt(num);
            }
        }
        if (num > 1){
            ret.push_back(num);
        }
        return ret;
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        gen_prime();
        DSU.Init(nums.size());
        
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++){
            vector<int> primeFactors = prime_factors(nums[i]);
            for (int pf : primeFactors){
                if (myMap.find(pf) == myMap.end()){
                    myMap[pf] = i;
                }
                else{
                    DSU.Union(myMap[pf], i);
                }
            }
        }
        
        return DSU.group_cnt() == 1;
    }
};