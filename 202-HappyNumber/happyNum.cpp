class Solution {
public:
    bool isHappy(int n) {
        int next_sum = 0;
        int temp;
        map<int, int> map;
        while (true) {
            next_sum = 0;
            while (n != 0) {
                temp = (n%10);
                next_sum += temp*temp;
                n /= 10;
            }
            if (next_sum == 1)
                return true;
            if (map.count(next_sum) != 0)
                return false;
            map[next_sum] =1;
            n= next_sum;
        }
    }
};