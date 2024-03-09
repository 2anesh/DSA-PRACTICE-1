class Solution
{
    public char nthCharacter(String s, int r, int n)
    {
       String answer = s;
int i=0;
while(i<r){
    String temp = "";
    for(int j=0;j<s.length();j++){
        if(answer.charAt(j)=='1'){
            temp += "10";
        }else if(answer.charAt(j) == '0'){
            temp += "01";
        }
    }
    answer = temp;
    i++;
}
return answer.charAt(n);
    }
}
