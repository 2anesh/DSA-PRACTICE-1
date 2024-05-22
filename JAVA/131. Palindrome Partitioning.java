class Solution {
    public boolean palindrome(String s , int index,int last){
        while(index<=last){
        if(s.charAt(index)!=s.charAt(last)){
            return false;
        }
        index++;
        last--;
        }
        return true;
    } 
    public void partitioning(int index ,String s, List<List<String>> ans ,  List<String> temp ){
        if(index == s.length()){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i = index ; i<s.length(); i++){
            if(palindrome(s,index,i)){
                temp.add(s.substring(index,i+1));
                partitioning(i+1,s,ans,temp);
                temp.remove(temp.size()-1);
            }

        }
    }
    public List<List<String>> partition(String s) {
       List<List<String>> ans = new ArrayList<>();
        List<String> temp = new ArrayList<>();    
        partitioning(0,s,ans,temp);
        return ans;    
    }
}
