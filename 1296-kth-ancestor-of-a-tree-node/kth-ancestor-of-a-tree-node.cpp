class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;

    TreeAncestor(int n, vector<int>& parent) {

        LOG = 17; // 2^16 > 50000

        up.assign(n, vector<int>(LOG, -1));

        // 2^0 ancestor
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // Build Binary Lifting Table
        for (int j = 1; j < LOG; j++) {

            for (int i = 0; i < n; i++) {

                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for (int i = 0; i < LOG; i++) {

            if (k & (1 << i)) {

                node = up[node][i];

                if (node == -1)
                    return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */