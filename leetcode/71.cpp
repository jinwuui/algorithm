class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string tmp;
        int start = 0;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                tmp = path.substr(start, i - start);
                if (tmp == "..") {
                    if (!v.empty()) 
                        v.pop_back();
                } else if (tmp != "." && tmp.size() > 0) {
                    v.push_back(tmp);
                }
                start = i + 1;
            }
        }
        
        tmp = path.substr(start, path.size() - start);
        if (tmp == "..") {
            if (!v.empty())
                v.pop_back();
        } else if (tmp != "." && tmp.size() > 0) {
            v.push_back(tmp);
        }
        
        string result;
        for (int i = 0; i < v.size(); i++) {
            result += "/" + v[i];
        }
        
        return result.empty() ? "/" : result;
    }
};