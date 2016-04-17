class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	map<int, int> map;
    	vector<int> arr1(2);
    	// add all the array elements to a hashmap
    	for (int i = 0; i < nums.size(); i++) {
    		map[nums[i]] = i;
    	}
    
    	// find the corresponding number in the hashmap.
    	for (int i = 0; i < nums.size(); i++) {
    		int find = target - nums[i];
    		if (map.count(find) != 0) {
    		    if (map[find] == i)
    		        continue;
    			arr1[1] = map[find];
    			arr1[0] = i;
    			return arr1;		
    		}
    		
    	}
	return arr1;
    }
};