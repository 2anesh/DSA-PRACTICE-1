class Solution
{
    public static Node insertionSort(Node head)
    {
        ArrayList<Integer> a = new ArrayList<>();
        Node temp = head;
        while(temp != null){
            a.add(temp.data);
            temp = temp.next;
        }
        Collections.sort(a);
        temp = head;
        int i = 0;
        while(temp != null){
            temp.data = a.get(i);
            i++;
            temp = temp.next;
        }
        return head;
    }
}
 
