class Solution {
    private int[] reQueue(int[] students, int n){
        for(int i = 0; i < n - 1; i++){
            students[i] = students[i] + students[i+1];
            students[i+1] = students[i] - students[i+1];
            students[i] = students[i] - students[i+1];
        }
        return students;
    }
    public int countStudents(int[] students, int[] sandwiches) {
        int n = students.length;
        int currSandwich = 0;
        int counter = 0;
        while(counter < n){
            if(students[0] != sandwiches[currSandwich]){
                counter++;
                students = reQueue(students,n);
            }else{
                students = reQueue(students,n);
                n--;
                currSandwich++;
                counter = 0;
            }
        }
        return n;
    }
}
