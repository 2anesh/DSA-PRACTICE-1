class Solution {
public:
int wateringPlants(vector& plants, int capacity) {
int cancap = capacity - plants[0];
int ans = 1, i = 0;
while(i < plants.size() - 1 ){

        if(cancap >= plants[i + 1]){
            ans++;
            cancap = cancap - plants[i + 1];
        }
        else{
            ans += 2*i + 3;
            cancap = capacity - plants[i + 1];
        }
    i++;
    }
    return ans;
}
};
