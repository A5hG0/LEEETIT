class Solution {
public:
    int candy(vector<int>& rat) {
        int i=1, sum = 1, n = rat.size();
        while(i < n) {
            while(i < n && rat[i] == rat[i-1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && rat[i] > rat[i-1]) {
                peak += 1;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i<n && rat[i] < rat[i-1]) {
                sum += down;
                down += 1;
                i++;
            }
            if(down > peak) {
                sum += down - peak;
            }
        }
        return sum;
    }
};