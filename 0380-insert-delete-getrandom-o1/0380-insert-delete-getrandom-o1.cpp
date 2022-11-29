class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> dict;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.find(val) != dict.end()){
            return false;
        }
        v.push_back(val);
        dict[val] = v.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.find(val) == dict.end()){
            return false;
        }
        auto it = dict.find(val);
        int index = it->second;
        v[index] = v[v.size() - 1];
        v.pop_back();
        dict[v[index]] = index;
        dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};