class ParkingSystem {
public:
    // int cb, cm, cs;
    // int b,m,s;
    vector<int>limit;
    vector<int>cnt;
    
    ParkingSystem(int big, int medium, int small) {
        // this->b = big;
        // this->m = medium;
        // this->s = small;
        this->limit = {big,medium,small};
        
        // this->cb = 0;
        // this->cm = 0;
        // this->cs = 0;
        this->cnt = {0,0,0};
    }
    
    bool addCar(int t) {
/*        if(t == 1){
            if(this->cb < this->b){
                this->cb++;
                return true;
            }
            else{
                return false;
            }
        }
        else if(t == 2){
            if(this->cm < this->m){
                this->cm++;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(this->cs < this->s){
                this->cs++;
                return true;
            }
            else{
                return false;
            }
        }
    */
    if(this->cnt[t-1] < this->limit[t-1]){
        this->cnt[t-1]++;
        return true;
    }
    return false;
}
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */