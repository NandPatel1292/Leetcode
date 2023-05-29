class LRUCache {
public:
    map<int,int>mp;
    list<int> l;
    map<int,list<int>::iterator>ind;
    int limit;
    int s;
    LRUCache(int capacity) {
        limit = capacity;
        s = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        int ans = mp[key];
        list<int> ::iterator x = ind[key];
        l.erase(x);
        ind.erase(key);
        l.push_front(key);
        ind[key] = l.begin();
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            l.erase(ind[key]);
            ind.erase(key);
            mp.erase(key);
            s--;
        }
        if(s == limit){
            int k = l.back();
            l.pop_back();
            ind.erase(k);
            mp.erase(k);
            s--;
        }
        s++;
        l.push_front(key);
        ind[key] = l.begin();
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */