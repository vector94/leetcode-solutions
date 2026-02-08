class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")   return 0;
        int ret = -1;
        int len = needle.length();
        for (int i = 0; i + len <= haystack.size(); i++){
            if (haystack.substr(i, len) == needle){
                return i;
            }
        }
        return -1;
    }
};