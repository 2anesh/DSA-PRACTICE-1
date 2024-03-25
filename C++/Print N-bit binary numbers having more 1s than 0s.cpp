class Solution{
public:	
    bool isValid(string s){
        int c1 = 0;
        int c0 = 0;
        for(auto i : s){
            if(i == '0')
                c0++;
            else c1++;
            if(c0 > c1)
                return false;
        }
        return true;
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string> res;

	    queue<string> q;
	    q.push("1");
	    while(q.size() && q.front().size() <= n){
	        int sz = q.size();
	        while(sz--){
	            string t = q.front();
	            q.pop();
	            if(t.size() == n && isValid(t))
	                res.push_back(t);
	            if(t.size() >= n)
	                continue;
	            q.push(t+"1");
	            q.push(t+"0");
	        }
	    }
	    
	    return res;
	}
};
