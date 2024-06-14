class Solution {
    static String armstrongNumber(int n){
        int sumOfCubes = 0;
        int number = n;
        while (number > 0) {
            int modulus = number % 10;
            sumOfCubes += (modulus * modulus * modulus);
            if (sumOfCubes > n) {
                return "false";
            }
            number = number / 10;
        }
        if (n == sumOfCubes) {
            return "true";
        }
        return "false";
    }
}
