class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int count=0,no=0;
        int finall=1;
        char arr[]=new char[allowed.length()];
        for(int i=0;i<allowed.length();i++){
            arr[i]=allowed.charAt(i);
        }
        for(int i=0;i<words.length;i++){
            String str=words[i];
            finall=1;
            for(int j=0;j<words[i].length();j++){
                char c=words[i].charAt(j);
                int found=0;
                for(int k=0;k<arr.length;k++){
                    if(c==arr[k]){
                        found=1;
                        break;
                    }
                }
                if(found==0){
                        no++;
                        finall=0;
                        break;
                    }
            }
            if(finall!=0){
                count++;
            }
        }
        return words.length-no;
    }
}
