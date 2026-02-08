class Solution {
    vector<int> freq;
public:
    string frequencySort(string s) {
        freq.resize(300, 0);
        for (char ch : s){
            freq[ch]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b){
            if (freq[a] == freq[b]){
                return a < b;
            }
            return freq[a] > freq[b];
        });
        return s;
    }
};