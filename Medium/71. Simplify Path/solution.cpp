class Solution {
public:
    string simplifyPath(string path) {
        string p;
        for (char ch : path){
            if (ch == '/' && !p.empty() && p.back() == '/') continue;
            p.push_back(ch);
        }
        stringstream ss(p);
        string folder;
        vector<string> history;
        
        while (getline(ss, folder, '/')){
            if (folder == "." || folder.size() == 0)  continue;
            if (folder == ".."){
                if (!history.empty())   history.pop_back();
                continue;
            }
            history.push_back(folder);
        }
        
        string result = "";
        for (string f : history){
            result += "/";
            result += f;
        }
        if (result.size() == 0) result.push_back('/');
        return result;
    }
};