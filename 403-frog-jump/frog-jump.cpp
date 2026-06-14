class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> dp;

    bool check(vector<int>& stones, int id, int jump) {
        if(id == stones.size() - 1) {
            return true;
        }

        if(dp[id][jump] != -1) {
            return dp[id][jump];
        }

        int curr = stones[id];
        // k+1
        auto it = mp.find(curr + jump + 1);
        if(it != mp.end()) {
            if(check(stones, it->second, jump + 1)) {
                return dp[id][jump] = true;
            }
        }
        // k
        it = mp.find(curr + jump);
        if(it != mp.end()) {
            if(check(stones, it->second, jump)) {
                return dp[id][jump] = true;
            }
        }
    // k 
        if(jump > 1) {
            it = mp.find(curr + jump - 1);

            if(it != mp.end()) {
                if(check(stones, it->second, jump - 1)) {
                    return dp[id][jump] = true;
                }
            }
        }

        return dp[id][jump] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(n < 2 || stones[1] != 1) {
            return false;
        }

        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        dp.resize(n, vector<int>(n + 1, -1)); // -1 

        return check(stones, 1, 1);
    }
};