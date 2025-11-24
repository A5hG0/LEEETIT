class Solution {
public:
    struct node {
        node* child[26];
        bool end;
        node() {
            for(int i=0;i<26;i++)
                child[i] = nullptr;
            end = false;
        }
    };

    void insert(node* root, string& str) {
        node* cur = root;
        for(int i=0;i<str.size();i++) {
            if(cur->child[str[i] - 'a'] == nullptr)
                cur->child[str[i] - 'a'] = new node();
            cur = cur->child[str[i] - 'a'];
        }
        cur->end = true;
    }

    string solve(node* root) {
        node* cur = root;
        string s = "";
        while(1) {
            int c = 0;
            int cindx = -1;
            for(int i=0;i<26;i++) {
                if(cur->child[i]) {
                    c++;
                    cindx = i;
                }
            }
            if(c == 1 && !cur->end) {
                cur = cur->child[cindx];
                s += char('a' + cindx);
            }else
                break;
        }
        return s;
    }

    string longestCommonPrefix(vector<string>& strs) {
        node* root = new node();
        string res = "";
        for(int i=0;i<strs.size();i++) {
            insert(root, strs[i]);
        }
        res = solve(root);
        return res;
    }
};