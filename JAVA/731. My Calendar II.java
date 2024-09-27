class MyCalendarTwo {
    List<int[]> bookings;
    List<int[]>overlappingIntervals;
    public MyCalendarTwo() {
        bookings=new ArrayList<>();
        overlappingIntervals=new ArrayList<>();
    }    
    public boolean book(int start, int end) {
        for(int[] i:overlappingIntervals)
        {
            if(start<i[1]  && end>i[0])
            {
                return false;
            }
        }       
        for(int[] b:bookings)
        {
            if(start<b[1] && end>b[0])
            {
                overlappingIntervals.add(new int[]{Math.max(start,b[0]),Math.min(end,b[1])});
            }
        }
        bookings.add(new int[]{start,end});
        return true;
    }
}
