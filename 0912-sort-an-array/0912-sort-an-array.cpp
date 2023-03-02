class Solution {
public:
    // using merge sort
    void merge(vector<int> &n, int left,int mid, int right){
        int ls = mid - left + 1;
        int rs  = right - mid;

        vector<int> ar(rs);
        vector<int> al(ls);

        for(int i = 0; i<ls; i++){
            al[i] = n[left+i];

        }
        for(int j = 0; j<rs; j++){
            ar[j] = n[mid+1+j];
        }
        int i = 0;
        int j = 0;
        int k = left;

        while(i < ls && j< rs){
            if(al[i] <= ar[j]){
                n[k] = al[i];
                i++;
            }
            else{
                n[k] = ar[j];
                j++;
            }
            k++;
        }

        while(i < ls){
            n[k] = al[i];
            i++;
            k++;
        }

        while(j < rs){
            n[k] = ar[j];
            j++;
            k++;
        }

    }
    void mergesort(vector<int> &n, int left,int right){
        if(left >= right){
            return;
        }
        int mid = left + (right - left)/2;
        mergesort(n,left,mid);
        mergesort(n,mid+1,right);
        merge(n,left,mid,right);
    }

    void swap(int *a , int* b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void heapify(vector<int>&arr,int n,int i){
        int lmax = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[lmax]){
            lmax = left;
        }
        if(right < n && arr[right] > arr[lmax]){
            lmax = right;
        }
        if(lmax != i){
            swap(&arr[i],&arr[lmax]);
            heapify(arr,n,lmax);
        }
    }
    void heapsort(vector<int>&arr,int n){

        for(int i = n/2-1; i>=0; i--){
            heapify(arr,n,i);
        }
        for(int i = n-1; i>= 0; i--){
            swap(&arr[0],&arr[i]);
            heapify(arr,i,0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // mergesort(nums,0,nums.size()-1);
        int n = nums.size();
        heapsort(nums,n);
        return nums;
    }
};