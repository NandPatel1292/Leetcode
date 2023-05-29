class MyLinkedList {
public:
    vector<int> v;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        for(int i = 0; i<v.size(); i++){
            if(i == index){
                return v[i];
            }
        }
        return -1;

    }
    
    void addAtHead(int val) {
        v.insert(v.begin(),val);
    }
    
    void addAtTail(int val) {
        v.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < v.size()){
            v.insert(v.begin()+index,val);
        }
        else if(index == v.size()){
            v.push_back(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < v.size()){
            v.erase(v.begin()+index);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */