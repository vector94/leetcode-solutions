class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long N = nums.size();
        long long pos = 0;
        long long interesting_subarrays = 0;
        long long prefix_count = 0;
        unordered_map<long long, long long> mod_freq;
        mod_freq[0] = 1;
        
        while(pos < N) {
            if(nums[pos] % modulo == k){
                prefix_count++;   
            }

            prefix_count %= modulo;
            
            if(mod_freq.count((prefix_count - k + modulo) % modulo)){
                interesting_subarrays += mod_freq[(prefix_count - k + modulo) % modulo];
            }
                
            mod_freq[prefix_count]++;
            pos++;
        }
        
        return interesting_subarrays;
    }
};