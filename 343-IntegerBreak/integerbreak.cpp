class Solution {
public:
    int integerBreak(int n) {
        int numthree = n/3;
        int mod = n%3;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
            
        if (mod == 1) {
            return powerof3(numthree-1) *4;
        } else if (mod == 2) {
            return powerof3(numthree) *2;
        } else if (mod == 0) {
            return powerof3(numthree);
        }
        return -3;
    }
    
    int powerof3(int n) {
        // 3^n
        int x = 1;
        for (int i =0; i < n; i++)
            x = x*3;
        return x;
    }
};