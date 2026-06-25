class LFUCache {
public:
    int cap, minFreq;
    unordered_map<int, list<int>> freqMap;
    unordered_map<int, tuple<int,int,list<int>::iterator>> keyMap;
    LFUCache(int capacity){
        cap=capacity;
        minFreq=0;
    }
    void promote(int key) {
        auto& [val, freq, it] = keyMap[key];
        freqMap[freq].erase(it);
        if (freqMap[freq].empty()) {
            freqMap.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        freq++;
        freqMap[freq].push_front(key);
        it = freqMap[freq].begin();
    }
    int get(int key) {
        if (!keyMap.count(key)) return -1;
        promote(key);
        return get<0>(keyMap[key]);
    }
    void put(int key, int value) {
        if (!cap) return;
        if (keyMap.count(key)) {
            get<0>(keyMap[key]) = value;
            promote(key);
            return;
        }
        if (keyMap.size() == cap) {
            int evict = freqMap[minFreq].back();
            freqMap[minFreq].pop_back();
            keyMap.erase(evict);
        }
        freqMap[1].push_front(key);
        keyMap[key] = {value, 1, freqMap[1].begin()};
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */