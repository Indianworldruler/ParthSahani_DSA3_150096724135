class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];

        // Move accessed element to front
        cache.splice(cache.begin(), cache, it);

        return it->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            it->second = value;

            // Move updated element to front
            cache.splice(cache.begin(), cache, it);
            return;
        }

        // Remove least recently used element
        if (cache.size() == capacity) {
            int oldKey = cache.back().first;
            mp.erase(oldKey);
            cache.pop_back();
        }

        // Insert new element at front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};