#define MAX(a,b) ((a) > (b) ? (a) : (b))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max_area = 0;
        int curr;
        for (int i = 0; i < size-1; i++) {
            for (int k = i; k< size; k++) {
                curr =MAX(height[i], height[k])*(k-i);
                if (max_area > curr)
                    max_area = curr;
            }
        }
        return curr;
    }
};