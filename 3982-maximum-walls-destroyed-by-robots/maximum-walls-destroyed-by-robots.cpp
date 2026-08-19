class Solution {
public:
    vector<vector<int>> dp;

    int countWalls(vector<int>& walls, int l, int r) {
        int left = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        int right = upper_bound(walls.begin(), walls.end(), r) - walls.begin();

        return right - left;
    }

    int solve(int i, int dir,
              vector<pair<int,int>>& robot,
              vector<int>& walls) {

        if (i < 0)
            return 0;

        if (dp[i][dir] != -1)
            return dp[i][dir];

        int pos = robot[i].first;
        int dist = robot[i].second;

        // LEFT
        int left = pos - dist;

        if (i > 0) {
            left = max(left, robot[i - 1].first + 1);
        }

        int leftWalls = countWalls(walls, left, pos);

        int takeLeft =
            leftWalls + solve(i - 1, 0, robot, walls);


        // RIGHT
        int right = pos + dist;

        if (i + 1 < robot.size()) {

            int nextPos = robot[i + 1].first;
            int nextDist = robot[i + 1].second;

            if (dir == 0) {
                right = min(
                    right,
                    nextPos - nextDist - 1
                );
            }
            else {
                right = min(
                    right,
                    nextPos - 1
                );
            }
        }

        int rightWalls = countWalls(walls, pos, right);

        int takeRight =
            rightWalls + solve(i - 1, 1, robot, walls);


        return dp[i][dir] = max(takeLeft, takeRight);
    }


    int maxWalls(vector<int>& robots,
                 vector<int>& distance,
                 vector<int>& walls) {

        int n = robots.size();

        vector<pair<int,int>> robot;

        for (int i = 0; i < n; i++) {
            robot.push_back({
                robots[i],
                distance[i]
            });
        }

        sort(robot.begin(), robot.end());
        sort(walls.begin(), walls.end());

        dp.assign(n, vector<int>(2, -1));

        return solve(n - 1, 1, robot, walls);
    }
};