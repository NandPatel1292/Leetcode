class node{
public:
    int val;
    node* next;
    node(int x){
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    node* head;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0){
            return -1;
        } 
        node* tmp = head;;
        for(int i = 0; i<index; i++){
            tmp = tmp->next;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0){
            return;
        }
        node* tmp = head;
        node* nv = new node(val);
        
        if(index == 0){
            nv -> next = tmp;
            head = nv;
        }
        
        else{
            for(int i = 0; i<index-1; i++){
                tmp = tmp->next;
            }
            nv->next = tmp->next;
            tmp->next = nv;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0){
            return;
        }
        if(index == 0){
            node* nv = head->next;
            delete head;
            head = nv;
        }
        
        else{
            node* tmp = head;
            for(int i = 0; i<index - 1; i++){
                tmp = tmp->next;
            }
            node* nx = tmp->next->next;
            delete tmp->next;
            tmp->next = nx;
          
        }
        size--;
    }
    
    ~MyLinkedList()
    {
        node *p = head;
        // Delete node at head while head is not null
        while (head!=nullptr)
        {
            head= head->next;
            delete p;
            p=head;
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