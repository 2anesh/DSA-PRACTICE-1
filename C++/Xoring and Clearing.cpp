class Solution {
  public:
    void printArr(int n, int arr[]) {
        
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void setToZero(int n, int arr[]) {
        for(int i=0;i<n;i++)
            arr[i]=0;
        return;
    }
    void xor1ToN(int n, int arr[]) {
        for(int i=0;i<n;i++)
            arr[i]^=i;
        return;
    }
};
