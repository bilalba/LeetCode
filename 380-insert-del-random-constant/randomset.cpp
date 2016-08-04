#include <unordered_map>
using namespace std;
class RandomizedSet {
public:

    /** Initialize your data structure here. */
    
    unordered_map<int,int> key_index;
    unordered_map<int,int> index_key;
    int size;
    RandomizedSet() {
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (key_index.count(val)) return false;
        else {
            key_index[val ] = size;
            index_key[size] =  val;
            size++;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (key_index.count(val)) {
            int index = key_index[val]; // index of value to be removed.
            int size_val = index_key[size-1]; // value of max index.
            key_index[size_val] = index;
            index_key[index] = size_val;
            key_index.erase(val);
            index_key.erase(size-1);
            size--;
            return true;
            
        } else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randNum = rand()%(size);
        return index_key[randNum];// when removing. replace with max index and then remove.
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */