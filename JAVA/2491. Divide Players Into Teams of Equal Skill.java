class Solution {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);       
        long product = 0;
        int target = skill[0] + skill[skill.length - 1];
        int i = 0;
        int j = skill.length - 1;
        while (i < j) {
            if (skill[i] + skill[j] != target) return -1;
            product = product + (skill[i] * skill[j]);
            i++;
            j--;
        }
        return product;
    }
}
