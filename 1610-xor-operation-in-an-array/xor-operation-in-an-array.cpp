class Solution {
public:
    int xorOperation(int n, int start) {
        int xr = 0 ;
        int current = start ;
        for(int i=0 ;i<n ;i++){
             xr ^= current ;
             current+=2 ;
        }
        return xr ;
    }
};