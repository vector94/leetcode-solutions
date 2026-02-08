class FindSumPairs {
public:
    unordered_map<int, int> freq;
    vector<int> list1, list2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        list1 = nums1;
        list2 = nums2;

        for (int n : nums2){
            freq[n]++;
        }
    }
    
    void add(int index, int val) {
        freq[list2[index]]--;
        list2[index] += val;
        freq[list2[index]]++;
    }
    
    int count(int tot) {
        int ret = 0;

        for (int n : list1){
            int need = tot - n;
            ret += freq[need];
        }

        return ret;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */