class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        int i = 0, n = path.size();
        string temp = "";
        for(int i=0;i<n;i++) {
            if(path[i] == '/') {
                if(temp == "..") {
                    if(!dq.empty())
                        dq.pop_back();
                }else if(temp == ".") {
                    temp = "";
                    continue;
                }else if(temp != "")
                    dq.push_back(temp);
                temp = "";
                continue;
            }
            temp += path[i];
        }
        // for(const auto& fol : dq)
        //     cout << fol << " ";
        if(temp == "..") {
            if(!dq.empty())
                dq.pop_back();
        } else if(temp != "" && temp != ".") {
            dq.push_back(temp);
        }
        // while(!st.empty()) {
        //     cout << st.top() << " ";
        //     st.pop();
        // }
        string dir = "";
        for(const auto& fol : dq) {
            // cout << fol << " ";
            dir += "/";
            dir += fol;
        }
        return dir == "" ? "/" : dir;
    }
};