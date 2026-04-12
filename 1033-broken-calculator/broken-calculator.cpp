class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int mini = 0;
        
        while(target> startValue){
            if(target%2==0){
                target = target/2;
                mini++;
            }else{
                target = target + 1;
                mini++;
            }
        }
        return mini+(startValue-target);

    }
};