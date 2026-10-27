
class Solution {
public:
    int countPrimes(int n) {

        vector<bool> prime(n, true);

        if(n <= 2) return 0;

        prime[0] = false;
        prime[1] = false;

        for(int i = 2; i < n; i++){

            if(prime[i] == true){

       
                for(int j = i * 2; j < n; j += i){
                    prime[j] = false;
                }
            }
        }

        int ans = 0;

        for(int i = 2; i < n; i++){
            if(prime[i] == true){
                ans++;
            }
        }

        return ans;
    }
};
