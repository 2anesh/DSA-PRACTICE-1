class Solution {
    long InternalCount(long[] point1, long[] point2, long[] point3) {
        long area = Math.abs(point1[0] * (point2[1] - point3[1]) + 
                             point2[0] * (point3[1] - point1[1]) + 
                             point3[0] * (point1[1] - point2[1]));
        long boundarySum = calculateGCD(point1, point2) + 
                           calculateGCD(point2, point3) + 
                           calculateGCD(point3, point1);
        return (area - boundarySum + 2) / 2;
    }
    long calculateGCD(long[] a, long[] b) {
        return computeGCD(Math.abs(a[0] - b[0]), Math.abs(a[1] - b[1]));
    }
    long computeGCD(long p1, long p2) {
        while (p2 != 0) {
            long temp = p2;
            p2 = p1 % p2;
            p1 = temp;
        }
        return p1;
    }
}
