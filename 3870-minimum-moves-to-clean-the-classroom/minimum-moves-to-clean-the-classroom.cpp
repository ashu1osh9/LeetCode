class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int cnt = 0;

        // litter ka index store karenge
        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign index to every L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        // No litter
        if (cnt == 0)
            return 0;

        // All litter initially uncollected
        int fullMask = (1 << cnt) - 1;

        // state = {row, col, energy, mask}
        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, fullMask});

        /*
            visited[row][col][energy][mask]
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        visited[sx][sy][energy][fullMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            // One BFS level
            while (sz--) {

                auto [x, y, curEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // No energy left
                if (curEnergy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Outside grid
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n)
                        continue;

                    // Obstacle
                    if (classroom[nx][ny] == 'X')
                        continue;

                    // Every move costs 1 energy
                    int nextEnergy = curEnergy - 1;

                    // Reset cell
                    if (classroom[nx][ny] == 'R') {
                        nextEnergy = energy;
                    }

                    int nextMask = mask;

                    // Litter collected
                    if (classroom[nx][ny] == 'L') {

                        int bit = id[nx][ny];

                        nextMask &= ~(1 << bit);
                    }

                    // Already visited this exact state?
                    if (visited[nx][ny][nextEnergy][nextMask])
                        continue;

                    visited[nx][ny][nextEnergy][nextMask] = true;

                    q.push({
                        nx,
                        ny,
                        nextEnergy,
                        nextMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};