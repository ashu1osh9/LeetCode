
class Solution {
public:
    int days(string s) {
        vector<int> month = {31,28,31,30,31,30,31,31,30,31,30,31};

        int m = stoi(s.substr(0,2));
        int d = stoi(s.substr(3,2));

        int sum = d;

        for(int i = 0; i < m-1; i++) {
            sum += month[i];
        }

        return sum;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int a = days(arriveAlice);
        int b = days(leaveAlice);
        int c = days(arriveBob);
        int d = days(leaveBob);

        int start = max(a,c);
        int end = min(b,d);

        return max(0,end-start+1);
    }
};
