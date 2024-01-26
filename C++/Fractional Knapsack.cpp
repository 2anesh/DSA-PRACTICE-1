class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={arr[i].value/(1.0*arr[i].weight),i};
        }
        sort(v.begin(),v.end(),greater<pair<double,int>>());
        double wt=W,res=0;
        int i;
        for(i=0;i<n;i++){
            double objwt= arr[v[i].second].weight;
            if( (wt - objwt) >= 0 ){
                wt = wt -objwt;
                res+=( v[i].first*objwt);
            }
            else{
                res+=(v[i].first *wt);
                break;
            }
        }
        return res;
    }
};
