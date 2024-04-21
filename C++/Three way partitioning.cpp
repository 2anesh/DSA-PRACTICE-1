class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int i = 0, n  = array.size();
        int j = n-1;
        while(i < j){
            if(array[j] < a){
                while(array[i] < a && i < j){
                    i++;
                }
                if(i < j){
                    swap(array[j], array[i]);
                    i++;
                }
            }
            j--;
        }
        if(i == n-1){
            return;
        }
        if(array[i] < a){
            i++;
        }
        j = n-1;
        while(i < j){
            if(array[j] >= a && array[j] <= b){
                while(array[i] >= a && array[i] <= b && i < j){
                    i++;
                }
                if(i < j){
                    swap(array[j], array[i]);
                    i++;
                }
                else{
                    return;
                }
            }
            j--;
        }
    }
};
