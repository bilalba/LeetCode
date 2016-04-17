#include <map>
#include <iostream>

using namespace std;

int* twosum(int array[], int array_size, int target) {
	map<int, bool> map;
	int* arr1 = new int[2];
	// add all the array elements to a hashmap
	for (int i = 0; i < array_size; i++) {
		map[array[i]] = i;
	}

	// find the corresponding number in the hashmap.
	for (int i = 0; i < array_size; i++) {
		int find = target - array[i];
		if (map.count(find) != 0) {
			arr1[1] = map[find];
			arr1[0] = i;
			return arr1;		
		}
		
	}
	return NULL;
}

int main() {
	int arr1[] = {3,4,5,6,1,7,83,21,34,12};
	int* abc = twosum(arr1, 10, 7);
	if (abc != NULL)
	cout << abc[0] << " " << abc[1];
}
