class Trie {
public:
    unordered_map<string,int> mp1,mp2;
    
    Trie() {
        
    }
    
    void insert(string word) {
        mp1[word]++;
        string s;
        for(auto x: word){
            s.push_back(x);
            if(mp2[s] == 0){
                mp2[s]++;
            }
        }
    }
    
    bool search(string word) {
        if(mp1[word]){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        if(mp2[prefix]){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */