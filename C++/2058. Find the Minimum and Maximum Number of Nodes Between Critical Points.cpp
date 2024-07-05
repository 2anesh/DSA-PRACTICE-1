class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {       
        vector<int> dummy({-1, -1});
        vector<int> res;         
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *next = curr->next;
        if(next == NULL){
            return dummy;
        }
        int i = 1;
        while(next != NULL){
            i++;
            if((prev->val < curr->val && curr->val > next->val) || (prev->val > curr->val && curr->val < next->val))
                res.push_back(i);
            prev = curr;
            curr = next;
            next = next->next;  
        }
        if(res.size() < 2){
            return dummy;
        }
        int max_val = res.back() - res.front();
        int min_val = 10000000;
        for(int i = 1; i < res.size(); ++i)
            min_val = min(min_val, res[i] - res[i - 1]);
        res.clear();
        res.push_back(min_val);
        res.push_back(max_val);     
        return res;
    }
};
