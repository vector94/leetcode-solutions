class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> hashMap1, hashMap2;
        
        for (char ch : s1){
            hashMap1[ch]++;
        }
        
        int left, right;
        left = right = 0;
        
        while (right < s2.size()){
            
            cout << left << " " << right << endl;
            
            char cur = s2[right];
            
            if (hashMap1[cur] == 0){
                while (left < right){
                    hashMap2[s2[left]]--;
                    left++;
                }
                left++;
                right++;
            }
            
            else if (hashMap1[cur] > hashMap2[cur]){
                if (right - left + 1 == s1.size())  return true;
                
                hashMap2[cur]++;
                right++;
            }
            
            else{
                hashMap2[s2[left]]--;
                left++;
            }
        }
        
        return false;
    }
};