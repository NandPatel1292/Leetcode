class RandomizedSet {
public:
    set<int>v;
    
    RandomizedSet() {
        // v.resize();    
    }
    
    bool insert(int val) {
        if(v.find(val) == v.end()){
            v.insert(val);
            return true;
        }
        else{
            
            return false;
        }
    }
    
    bool remove(int val) {
        if(v.find(val) != v.end()){
            v.erase(v.find(val));
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        int r = rand()%v.size();
        auto it = v.begin();
        advance(it,r);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */