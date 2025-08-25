class Solution {
private:
    bool valid(vector<int> cnt1,vector<int> cnt2) {
        for(int ch = 0;ch < 52;ch++) {
            if(cnt2[ch] < cnt1[ch])
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> cnt1(52,0),cnt2(52,0);
        //initializing the count array
        for(auto ch : t) {
            if(ch >= 'A' && ch <= 'Z')
                cnt1[ch - 'A']++;
            else
                cnt1[ch - 'a' + 26]++;
        }
        int mn = INT_MAX,i = 0,end = 0,st = 0;
        for(int j=0;j<s.length();j++) {
            if(s[j] >= 'A' && s[j] <= 'Z')
                cnt2[s[j] - 'A']++;
            else
                cnt2[s[j] - 'a' + 26]++;
            // cnt2[s[j] - 'a']++;
            // valid(cnt1,cnt2);

            while(valid(cnt1,cnt2)) {
                // mn = min(mn,j - i + 1);
                if(mn > j - i + 1) {
                    mn = j-i+1;
                    st = i;
                    end = j;
                }
                // cnt2[s[i] - 'a']--;
                if(s[i] >= 'A' && s[i] <= 'Z')
                    cnt2[s[i++] - 'A']--;
                else
                    cnt2[s[i++] - 'a' + 26]--;
                // i++;
            }
        }
        cout << st << " " << end;
        if(mn == INT_MAX)
            return "";
        cout << "HI";
        return s.substr(st,end - st + 1);
        // return (mn == INT_MAX ? -1 : mn);
    }
};