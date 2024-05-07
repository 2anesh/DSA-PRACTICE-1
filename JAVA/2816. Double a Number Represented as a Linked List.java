import java.math.BigInteger;
class Solution 
{
    public ListNode doubleIt(ListNode head) 
    {
        String number = "";
        while( head != null )
        {
            number += head.val;
            head = head.next;
        }
        BigInteger a = new BigInteger(number);
        BigInteger b = new BigInteger("2");
        number = String.valueOf(a.multiply(b));
        head = null;
		ListNode tail = null;
        for(int i = 0; i < number.length(); i++) 
        {
            ListNode node = new ListNode( Character.getNumericValue( number.charAt(i) ) );
            if( head == null && tail == null )
			{
			    head = tail = node;
			}
			else
			{
			    tail.next = node;
			    tail = node;
			}
        }
        return head;
    }
}
