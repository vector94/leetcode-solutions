class Solution {    
    vector<pair<int, int>> graph[105];
    
public:
    struct Node{
        int node, weight;
        Node(int node, int weight): node(node), weight(weight){
        }
    };
    struct CompareWeight {
        bool operator()(Node const& n1, Node const& n2){
            return n1.weight > n2.weight;
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (int i = 0; i < times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        } 
        priority_queue<Node, vector<Node>, CompareWeight> myQueue;
        vector<bool> mark(105, false);
    
        myQueue.push(Node(k, 0));
        
        Node curNode = Node(12, 12);
        
        int result = 0;
        
        while (!myQueue.empty()){
            int curNode = myQueue.top().node;
            int curWeight = myQueue.top().weight;
            
            myQueue.pop();
            
            if (mark[curNode])  continue;
            
            mark[curNode] = true;
            result = max(result, curWeight);
            
            for (pair<int, int> nextNode : graph[curNode]){
                if (!mark[nextNode.first]){
                    //cout << nextNode.first << " " << curWeight + nextNode.second << endl;
                    myQueue.push(Node(nextNode.first, curWeight + nextNode.second));
                }
            }
        }
        
        bool allMarked = true;
        for (int i = 1; i <= n; i++){
            if (!mark[i]){
                allMarked = false;
            }
        }
        
        if (allMarked)  return result;
        return -1;
        
        return result;
    }
};