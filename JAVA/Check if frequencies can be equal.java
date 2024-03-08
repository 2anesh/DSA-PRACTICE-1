class Solution {
    boolean sameFreq(String s) {
        // code here
        HashMap<Character, Integer> HM = new HashMap<Character, Integer>() ;
        for(int i = 0; i < s.length(); i++){
            HM.put(s.charAt(i), HM.getOrDefault(s.charAt(i), 0) + 1) ;
        }
        
        TreeMap<Integer, Integer> H = new TreeMap<Integer, Integer>() ;
        for(Map.Entry<Character, Integer> a : HM.entrySet()){
            H.put(a.getValue(), H.getOrDefault(a.getValue(), 0) + 1) ;
        }
        // System.out.println(H) ;
        if(H.size() > 2){
            return false ;
        }
        else{
            if(H.size() == 1){
                return true ;
            }
            else{
                int f = H.firstKey() ;
                int l = H.lastKey() ;
                if(f == l + 1){
                    if(H.get(f) == 1){
                        return true ;
                    }
                    else if(f == 1 && H.get(f) == 1){
                        return true ;
                    }
                    else if(l == 1 && H.get(l) == 1){
                        return true ;
                    }
                    else{
                        return false ;
                    }
                }
                else if(l == f + 1){
                    if(H.get(l) == 1){
                        return true ;
                    }
                    else if(f == 1 && H.get(f) == 1){
                        return true ;
                    }
                    else if(l == 1 && H.get(l) == 1){
                        return true ;
                    }
                    else{
                        return false ;
                    }
                }
                else{
                    return false ;
                }
            }
        }
    }
}
