class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int[] shiftCoefficients = new int[s.length() + 1];
        int shifting = 0;
        for (int[] shift : shifts) {
            shifting = shift[2] == 1 ? 1 : 25;
            shiftCoefficients[shift[0]] += shifting;
            shiftCoefficients[shift[1] + 1] -= shifting;
        }
        char[] chars = s.toCharArray();
        int currentCoefficient = 0;
        for (int i = 0; i < chars.length; i++) {
            currentCoefficient += shiftCoefficients[i];
            chars[i] = (char)('a' + (((chars[i] + currentCoefficient) - 97) % 26));
        }
        return new String(chars);
    }
}
