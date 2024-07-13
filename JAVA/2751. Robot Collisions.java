class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        Robot[] robots = new Robot[n];        
        for (int i = 0; i < n; i++) {
            robots[i] = new Robot(i, positions[i], healths[i], directions.charAt(i));
        }        
        Arrays.sort(robots);       
        Stack<Robot> stack = new Stack<>();
        List<Robot> survivors = new ArrayList<>();        
        for (Robot robot : robots) {
            if (robot.direction == 'R') {
                stack.push(robot);
            } else {
                while (!stack.isEmpty() && stack.peek().health < robot.health) {
                    robot.health--;
                    stack.pop();
                }
                if (!stack.isEmpty() && stack.peek().health == robot.health) {
                    stack.pop();
                } else if (stack.isEmpty() || stack.peek().health > robot.health) {
                    if (!stack.isEmpty()) {
                        stack.peek().health--;
                    } else {
                        survivors.add(robot);
                    }
                }
            }
        }        
        while (!stack.isEmpty()) {
            survivors.add(stack.pop());
        }        
        Collections.sort(survivors, Comparator.comparingInt(r -> r.index));        
        List<Integer> result = new ArrayList<>();
        for (Robot robot : survivors) {
            result.add(robot.health);
        }        
        return result;
    }
}
class Robot implements Comparable<Robot> {
    int index;
    int position;
    int health;
    char direction;    
    Robot(int index, int position, int health, char direction) {
        this.index = index;
        this.position = position;
        this.health = health;
        this.direction = direction;
    }    
    @Override
    public int compareTo(Robot other) {
        return Integer.compare(this.position, other.position);
    }
}
