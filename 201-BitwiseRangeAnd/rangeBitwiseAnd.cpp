class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m==n)
            return m;
        int j = m&n;
        j &= (n+m)/2;
        for (int i = m+1; i<n && j!=0 ; i++) {
            int count = 0;
            j&=i;
            i = j;
            while(((i&1) == 0) && i !=0) {
                i = i >> 1;
                count++;
            }
            for(int k = 0; k < count; k++) {
                 i<<=1;
                i +=1;
            }
            if (i > n)
                return j;
            j&=i;
            
        }
        return j;
    }
};