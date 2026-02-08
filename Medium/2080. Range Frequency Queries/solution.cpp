class RangeFreqQuery {
public:
    
    int block[10005][350];
    int n, block_size;
    vector<int> a;
    
    int block_id(int index){
        return (index / block_size);
    }
    
    void build(vector<int> &arr){
        a = arr;
        block_size = sqrt(n);
        for (int i = 1; i <= n; i++){
            block[arr[i - 1]][block_id(i)]++;
        }
    }
    
    int query(int left, int right, int value){
        left++;
        right++;
        int ret = 0;
        int left_block = block_id(left);
        int right_block = block_id(right);
        while (block_id(left) == left_block && left <= right){
            if (a[left - 1] == value){
                ret++;
            }
            left++;
        }
        while (block_id(right) == right_block && right_block != left_block){
            if (a[right - 1] == value){
                ret++;
            }
            right--;
        }
        for (int i = left_block + 1; i <= right_block - 1; i++){
            ret += block[value][i];
        }
        return ret;
    }
    
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        memset(block, 0, sizeof(block));
        build(arr);
    }
    
//     int query(int left, int right, int value) {
        
//     }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */