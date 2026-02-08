class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> strV1, strV2;
        stringstream ssV1(version1);
        
        string num;
        
        while (getline(ssV1, num, '.')){
            strV1.push_back(num);
        }
        
        stringstream ssV2(version2);
        while (getline(ssV2, num, '.')){
            strV2.push_back(num);
        }
        
        for (int i = 0; i < min(strV1.size(), strV2.size()); i++){
            int num1 = stoi(strV1[i]);
            int num2 = stoi(strV2[i]);
            
            if (num1 < num2)    return -1;
            if (num1 > num2)    return 1;
        }
        
        if (strV1.size() > strV2.size()){
            for (int i = strV2.size(); i < strV1.size(); i++){
                int n = stoi(strV1[i]);
                if (n != 0) return 1;
            }
        }
        else if (strV1.size() < strV2.size()){
            for (int i = strV1.size(); i < strV2.size(); i++){
                int n = stoi(strV2[i]);
                if (n != 0) return -1;
            }
        }
        return 0;
    }
};