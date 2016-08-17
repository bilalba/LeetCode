class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    multimap<int,int> key_index;
    unordered_map<int,int> index_key;
    int size;
    RandomizedCollection() {
        size = 0;    
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool contained = true;
        if (key_index.count(val)) contained =  false;
        key_index.insert(pair<int,int>(val,size));
        index_key[size] = val;
        size++;
        return contained;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (key_index.count(val) > 0) {
            int index = key_index.find(val)->second; // index of value to be removed.
            int size_val = index_key[size-1]; // value of max index.
            
            multimap<int,int>::iterator k = key_index.find(size_val);
            key_index.erase(k);
            
            key_index.insert(pair<int,int>(size_val,index));
            index_key[index] = size_val;
            key_index.erase(key_index.find(val));
            index_key.erase(size-1);
            size--;
            return true;
            
        } else return false;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if (size == 0)
            return NULL;
        int randNum = rand()%(size);
        return index_key[randNum];// when removing. replace with max index and then remove.
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */