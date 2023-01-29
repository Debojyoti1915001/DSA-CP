class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyVal;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        if (keyVal.find(key) == keyVal.end()) return -1;
        
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        auto itr = --freqList[keyVal[key].second].end();
        pos[key] = itr;
        if (freqList[minFreq].size() == 0) {
            minFreq++;
        }
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyVal.find(key) != keyVal.end()) {
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            auto itr = --freqList[keyVal[key].second].end();
            pos[key] = itr;
            if (freqList[minFreq].size() == 0) {
                minFreq++;
            }
            keyVal[key].first = value;
            return;
        }

        if (keyVal.size() == capacity) {
            int minFreqKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            pos.erase(minFreqKey);
            keyVal.erase(minFreqKey);
        }

        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};