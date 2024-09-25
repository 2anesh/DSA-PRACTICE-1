class Solution {
  public:
    bool isPalindrome(Node *head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->data);
            head = head->next;
        }
        int i = 0, j = arr.size()-1;
        while(i < j){
            if(arr[i]!=arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
