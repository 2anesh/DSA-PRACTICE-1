class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position); 
        return MagneticForceOptimisation(position, m); 
    }
    public int MagneticForceOptimisation(int baskets[], int balls)
    {      
        int left = 1, right = baskets[baskets.length-1]-baskets[0], result = 1;
        while(left <= right) {      
            int middle = left + (right-left)/2;
            if(KMagneticForceAttained(baskets, balls, middle)) {
                left = middle+1;    
                result = middle;    
            }
            else right = middle-1;  
        }
        return result;
    }
    public boolean KMagneticForceAttained(int baskets[], int balls, int force)
    {
        int currentBasket = baskets[0]; balls--;
        for(int i = 0; i < baskets.length; i++) {
            if(baskets[i]-currentBasket >= force) {
                currentBasket = baskets[i]; 
                balls--;
            }
            if(balls == 0)  return true;    
        }
        return false;  
    }
}
