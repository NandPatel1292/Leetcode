struct node{
    node* link[26];
    bool flag = false; 
    bool containKey(char ch){
        return (link[ch - 'a'] != NULL);
    }
    
    void put(char ch, node* Node){
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
    
    bool search1(node* root,string& word) {
        node* tmp = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(ch=='.')
            {
                for(auto j:tmp->link)
                {
                    string s = word.substr(i+1);
                    if(j && j->search1(j,s)){
                        return true;    
                    }
                    
                }
                return false;
            }
            if(!tmp->containKey(word[i])){
                return false;
            }
            tmp = tmp->get(word[i]);
        }
        
        return tmp->isEnd();
    }
};


class WordDictionary {
private:
    node* root;

public:
    WordDictionary() {
       root = new node(); 
    }
    
    void addWord(string word) {
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
        node* tmp = root;
        return tmp->search1(tmp,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */