class Solution {
public:
    
    bool Check(int num, int pos){
        return num & (1 << pos);
    }
    int Reset(int num, int pos){
        return num & ~(1 << pos);
    }
    int Set(int num, int pos){
        return num | (1 << pos);
    }
    
    struct node{
        node *next[2];
        node (){
            next[0] = next[1] = NULL;
        }
    };
    
    node *root;
    
    void Add(int num){
        node *cur = root;
        for (int bit = 31; bit >= 0; bit--){
            int id = Check(num, bit);
            if (cur -> next[id] == NULL){
                cur -> next[id] = new node();
            }
            cur = cur -> next[id];
        }
    }
    
    int query(int num){
        node *cur = root;
        int ret = 0;
        for (int bit = 31; bit >= 0; bit--){
            int id = !Check(num, bit);
            if (cur -> next[id]){
                ret = Set(ret, bit);
                cur = cur -> next[id];
            }
            else{
                cur = cur -> next[id^1];
            }
        }
        return ret;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        root = new node();
        
        for (int n : nums){
            Add(n);
        }
        
        int result = 0;
        
        for (int n : nums){
            result = max(result, query(n));
        }
        
        return result;
    }
};