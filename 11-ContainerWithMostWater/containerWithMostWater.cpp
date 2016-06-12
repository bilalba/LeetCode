#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define WHICH(a,b) ((a) > (b) ? (0) : (1))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if (size == 0)
        return 0;
        int i = 0;
        int j = size-1;
        int max_area = MIN(height[i],height[j])*j;
        int area;
        while (j != i) {
            area = MIN(height[i],height[j])*(j-i);
            if (area > max_area){
                max_area = area;
                
            }
            if (WHICH(height[i],height[j])) {
                i++;
            } else {
                j--;
            }
            
        }
        return max_area;
    }
};