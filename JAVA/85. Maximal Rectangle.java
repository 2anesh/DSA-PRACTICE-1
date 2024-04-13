class Solution {
    public int findMaxArea(char[] arr,int n){
        Stack<Integer> st=new Stack<>();
        int[] leftMin=new int[n];
        int[] rightMin=new int[n];
        for(int i=0;i<n;i++){
            if(arr[i]=='0'){
                st.push(i);
                continue;
            }
            while(!st.isEmpty() && arr[st.peek()]>=arr[i])st.pop();
            leftMin[i]= st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }
        st=new Stack<>();
        for(int i=n-1;i>=0;i--){
            if(arr[i]=='0'){
                st.push(i);
                continue;
            }
            while(!st.isEmpty() && arr[st.peek()]>=arr[i])st.pop();
            rightMin[i]= st.isEmpty() ? n : st.peek();
            st.push(i);
        }
        int maxArea=-1;
        for(int i=0;i<n;i++){
            int area=(rightMin[i]-leftMin[i]-1)*(arr[i]-48);
            maxArea=Math.max(maxArea, area);
        }
        return maxArea;
    }
    public int maximalRectangle(char[][] mat) {
        int m=mat.length,n=mat[0].length;
        int area=findMaxArea(mat[0],n);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='0')continue;
                mat[i][j]=(char)((mat[i][j]-48)+(mat[i-1][j]-48)+48);
            }
            area =Math.max(area,findMaxArea(mat[i],n));
        }
        return area;
    }
}
