struct node{
    node* link[26];
    bool flag = false;
    bool containKey(char ch){
        return (link[ch - 'a'] != NULL);
    }
    
    void put(char ch,node* Node){
        link[ch - 'a'] = Node;
    }
    
    node* get(char ch){
        return link[ch - 'a'];
    }
    
    void end(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
    
private:
    node* root;
    
public:
    // unordered_map<string,int> mp1,mp2;
    Trie() {
       root = new node(); 
    }
    
    void insert(string word) {
        // mp1[word]++;
        // string s;
        // for(auto x: word){
        //     s.push_back(x);
        //     if(mp2[s] == 0){
        //         mp2[s]++;
        //     }
        // }
        
        node* tmp = root;
        for(int i = 0; i<word.size(); i++){
            if(!tmp->containKey(word[i])){
                tmp->put(word[i],new node());
            }
            tmp = tmp->get(word[i]);
        }
        
        tmp->end();
    }
    
    bool search(string word) {
        // if(mp1[word]){
        //     return true;
        // }
        // return false;
        
        node* tmp = root;
        for(int i = 0; i<word.size(); i++){
            if(!tmp->containKey(word[i])){
                return false;
            }
            tmp = tmp->get(word[i]);
        }
        
        return tmp->isEnd();
    }
    
    bool startsWith(string prefix) {
        // if(mp2[prefix]){
        //     return true;
        // }
        // return false;
        node* tmp = root;
        for(int i = 0; i<prefix.size(); i++){
            if(!tmp->containKey(prefix[i])){
                return false;
            }
            tmp = tmp->get(prefix[i]);
            
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */