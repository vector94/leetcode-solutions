class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        string revision1, revision2;
        while (true){
            auto &e1 = getline(ss1, revision1, '.');
            auto &e2 = getline(ss2, revision2, '.');
            
            if (!e1 && !e2) break;
            
            if (!e1)    revision1 = "0";
            if (!e2)    revision2 = "0";
            
            int r1 = stoi(revision1);
            int r2 = stoi(revision2);
            
            if (r1 < r2)        return -1;
            else if (r1 > r2)   return 1;
        }
        return 0;
    }
};