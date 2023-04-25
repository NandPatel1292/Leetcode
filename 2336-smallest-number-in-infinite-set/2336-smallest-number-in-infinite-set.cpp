class SmallestInfiniteSet {
public:
    int curr;
    unordered_set<int> visit;
    priority_queue<int,vector<int>,greater<int>> add;
    
    
    SmallestInfiniteSet() {
        curr = 1;
        
    }
    
    int popSmallest() {
        int ans;
        
        if(!add.empty()){
            ans = add.top();
            visit.erase(ans);
            add.pop();
        }
        else{
            ans = curr;
            curr += 1;
            
        }
        
        return ans;
    }
    
    void addBack(int num) {
        if(curr <= num || visit.find(num) != visit.end()){
            return;
        }
        add.push(num);
        visit.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */