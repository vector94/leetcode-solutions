class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream s(title);
        string str;
        
        vector<string> v;
        
        while (getline(s, str, ' ')){
            v.push_back(str);
        }
        
        for (int i = 0; i < v.size(); i++){
            if (v[i].size() <= 2){
                for (int j = 0; j < v[i].size(); j++){
                    v[i][j] = tolower(v[i][j]);
                }
            }
            else{
                for (int j = 0; j < v[i].size(); j++){
                    if (j == 0){
                        v[i][j] = toupper(v[i][j]);
                    }
                    else{
                        v[i][j] = tolower(v[i][j]);
                    }
                }
            }
        }
        
        string result = "";
        for (int i = 0; i < v.size(); i++){
            result += v[i];
            if (i != v.size() - 1)  result += " ";
        }
        
        return result;
    }
};