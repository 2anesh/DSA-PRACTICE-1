class Solution {
    String compareFrac(String str) {
        double first = 0.0;
        double second = 0.0;
        int a = 0;
        int b = 0;
        String tmp1 = "";
        String tmp2 = "";
        boolean indication = false;
        for(int i=0; i<str.length(); i++){
            char x = str.charAt(i);
            if(x == '/'){
                indication = true;
                tmp2 += x;
                continue;
            }
            else if(x == ','){
                indication = false;
                first = (double)a/b;
                a = 0;
                b = 0;
                tmp1 = tmp2;
                tmp2 = "";
                continue;
            }
            else if(x == ' ')continue;
            tmp2 += x;
            if(!indication){
                a = a*10+(x-'0');
            }
            else{
                b = b*10+(x-'0');
            }
        }
        second = (double)a/b;
        if(first>second){
            return tmp1;
        }
        else if(second > first){
            return tmp2;
        }
        else{
            return "equal";
        }
    }
}
