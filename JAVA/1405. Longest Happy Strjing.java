class obj {
    int cnt;
    char word;
    public obj(int cnt, char word) {
        this.cnt = cnt;
        this.word = word;
    }
}
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<obj> pq = new PriorityQueue<>((x, y) -> y.cnt - x.cnt);
        if (a > 0) pq.add(new obj(a, 'a'));
        if (b > 0) pq.add(new obj(b, 'b'));
        if (c > 0) pq.add(new obj(c, 'c'));        
        StringBuilder str = new StringBuilder();
        while (!pq.isEmpty()) {
            obj curr = pq.poll();
            if (str.length() >= 2 && str.charAt(str.length() - 1) == curr.word && str.charAt(str.length() - 2) == curr.word) {
                if (pq.isEmpty()) break;
                obj next = pq.poll();
                str.append(next.word);
                next.cnt--;
                if (next.cnt > 0) pq.add(next);
                pq.add(curr);
            } else {
                str.append(curr.word);
                curr.cnt--;
                if (curr.cnt > 0) pq.add(curr);
            }
        }
        return str.toString();
    }
}
