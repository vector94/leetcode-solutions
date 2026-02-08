class Solution {
public:
    
    bool check(string ip){
        if (ip.size() > 3)  return false;
        return (ip.size() == 1 || ip.size() > 1 && ip[0] != '0' && stoi(ip) <= 255);
    }
    
    void backtrack(int start, int remainingDot, string &s, vector<int> &addresses, vector<string> &result){
        if (remainingDot == 0 && start < s.size()){
            string next = s.substr(start, s.size() - start);
            if (check(next)){
                addresses.push_back(stoi(next));
                string ipAddress = "";
                for (int x : addresses){
                    ipAddress += to_string(x);
                    ipAddress += ".";
                }
                ipAddress.pop_back();
                result.push_back(ipAddress);
                addresses.pop_back();
            }
            return;
        }
        if (start == s.size())  return;
        for (int end = start; end < s.size(); end++){
            string next = s.substr(start, end - start + 1);
            if (check(next)){
                addresses.push_back(stoi(next));
                backtrack(end + 1, remainingDot - 1, s, addresses, result);
                addresses.pop_back();
            }
            else{
                break;
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> addresses;
        backtrack(0, 3, s, addresses, result);
        return result;
    }
};