class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] minutesBucket = new boolean[1440];
        for(String time : timePoints) {
            String[] parts = time.split(":");
            int hours = Integer.parseInt(parts[0]);
            int minutes = Integer.parseInt(parts[1]);
            int totalMinutes = hours * 60 + minutes;
            if(minutesBucket[totalMinutes]) {
                return 0;
            }
            minutesBucket[totalMinutes] = true;
        }
        int firstTime = -1, prevTime = -1, minDifference = Integer.MAX_VALUE;
        int firstInDay = -1, lastInDay = -1;
        for(int i = 0; i < 1440; i++) {
            if(minutesBucket[i]) {
                if(firstTime == -1) {
                    firstTime = i;  
                } else {
                    minDifference = Math.min(minDifference, i - prevTime);  
                }
                prevTime = i;
                lastInDay = i; 
                if(firstInDay == -1) {
                    firstInDay = i;  
                }
            }
        }
        minDifference = Math.min(minDifference, 1440 + firstInDay - lastInDay);
        return minDifference;
    }
}
