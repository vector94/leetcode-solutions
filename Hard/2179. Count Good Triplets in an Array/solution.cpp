class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();

        unordered_map<int, int> myMap;
        for (int i = 0; i < nums2.size();  i++){
            myMap[nums2[i]] = i + 1;
        }

        vector<long long> tree(N * 4, 0);
        update(1, 1, N, tree, myMap[nums1[0]]);

        long long ans = 0;
        for (int i = 1; i < N - 1; i++){
            int midIdx = myMap[nums1[i]];

            long long leftCommon = query(1, 1, N, 1, midIdx - 1, tree);
            long long leftUncommon = i - leftCommon;
            long long rightCommon = (N - midIdx) - leftUncommon;

            ans += (leftCommon * rightCommon);
            update(1, 1, N, tree, midIdx);
        }

        return ans;
    }

private:
    void update(int node, int left, int right, vector<long long>& tree, int idx){
        if (left == right && left == idx){
            tree[node] = 1;
            return;
        }
        if (idx < left || idx > right){
            return;
        }

        int mid = (left + right) / 2;
        update(node * 2, left, mid, tree, idx);
        update(node * 2 + 1, mid + 1, right, tree, idx);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int left, int right, int leftQuery, int rightQuery, vector<long long>& tree){
        if (rightQuery < left || leftQuery > right){
            return 0;
        }
        if (left >= leftQuery && right <= rightQuery){
            return tree[node];
        }

        int mid = (left + right) / 2;
        int countLeft = query(node * 2, left, mid, leftQuery, rightQuery, tree);
        int countRight = query(node * 2 + 1, mid + 1, right, leftQuery, rightQuery, tree);

        return countLeft + countRight;
    }
};