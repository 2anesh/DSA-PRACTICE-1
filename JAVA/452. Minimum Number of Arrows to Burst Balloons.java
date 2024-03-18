class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,(a,b)->Integer.compare(a[1],b[1]));
        int arrows=1,arrowpos=points[0][1];
        for(int i=1;i<points.length;i++)
        {
            if(arrowpos>=points[i][0])
                continue;
            arrowpos=points[i][1];
            arrows++;
        }
        return arrows;
    }
}
