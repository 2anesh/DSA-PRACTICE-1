class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        List<Integer> list = new ArrayList<>();
        int prev = head.val;
        int index = 1;
        head = head.next;
        while(head != null){
            int curr = head.val;
            if(head.next != null){
                int next = head.next.val;
                if((curr>prev && curr>next) || (curr<prev && curr<next)){
                    list.add(index);
                }
            }
            head = head.next;
            index++;
            prev = curr;
        }
        int n = list.size();
        if(n < 2){
            return new int[] {-1,-1};
        }
        int min = Integer.MAX_VALUE;
        for(int i=0; i<n-1; i++){
            min = Math.min(min,list.get(i+1)-list.get(i));
        }
        int max = list.get(n-1) - list.get(0);
        return new int[] {min,max};
    }
}
