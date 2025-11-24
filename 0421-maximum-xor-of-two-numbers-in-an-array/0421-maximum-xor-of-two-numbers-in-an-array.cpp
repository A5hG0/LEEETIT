class Solution {
public:
    struct node {
        node* child[2];

        node() {
            child[0] = child[1] = nullptr;
        }
    };

    void insert(node* root, int x) {
        node* cur = root;
        for(int i=31;i>=0;i--) {
            int bit = (x >> i) & 1;
            if(!cur->child[bit])
                cur->child[bit] = new node();
            cur = cur->child[bit];
        }
    }

    int solve(node* root, int x) {
        node* cur = root;
        int res = 0;
        for(int i=31;i>=0;i--) {
            int bit = (x >> i) & 1;
            int opp = 1 - bit;
            if(cur->child[opp]) {
                res |= (1 << i);
                cur = cur -> child[opp];
            }else
                cur = cur -> child[bit];
        }
        return res;
    }

    int findMaximumXOR(vector<int>& nums) {
        node* root = new node();
        insert(root, nums[0]);
        int xr = 0;
        for(int i=1;i<nums.size();i++) {
            xr = max(xr, solve(root, nums[i]));
            insert(root, nums[i]);
        }
        return xr;
    }
};