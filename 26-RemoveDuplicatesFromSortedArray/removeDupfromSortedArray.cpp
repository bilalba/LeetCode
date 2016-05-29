class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int last = nums[0];
        int length = nums.size();
        for (int i = 1;i < length; i++) {
            if (last == nums[i]) { // duplicate detected.
                nums.erase(nums.begin() + i);
                length--;
                i--;
            } else {
                last = nums[i];
            }
        }
        return nums.size();
    }
};