#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        ordered_set<int> os;
        for (int i = 0; i < k; i++){
            os.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> freq(k, 0);
        int max_load = 0;

        for (int i = 0; i < arrival.size(); i++){
            while (!pq.empty() && pq.top().first <= arrival[i]){
                int server = pq.top().second;
                pq.pop();

                os.insert(server);
            }

            if (os.size() == 0) continue;

            int x = i % k;
            int l = load[i];

            auto it = os.lower_bound(x);
            int free_server = *it;
            if (it == os.end()){
                free_server = *os.begin();
                os.erase(free_server);
            }
            else{
                os.erase(free_server);
            }

            // cout << i << " " << arrival[i] << " " << load[i] << " " << free_server << endl;

            pq.push({arrival[i] + load[i], free_server});
            freq[free_server]++;
            max_load = max(max_load, freq[free_server]);
        }

        vector<int> result;
        for (int i = 0; i < k; i++){
            if (freq[i] == max_load){
                result.push_back(i);
            }
        }

        return result;
    }
};