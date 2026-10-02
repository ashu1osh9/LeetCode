class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        vector<string> v(numRows);

        int row = 0;
        int dir = 1;

        for(char ch : s){

            v[row] += ch;

            if(row == 0)
                dir = 1;

            if(row == numRows-1)
                dir = -1;

            row += dir;
        }

        string ans = "";

        for(auto x : v)
            ans += x;

        return ans;
    }
};