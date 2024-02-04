class Solution
{
   static Node removeLeadingZeros(Node a)
  {
      if (a != null && a.data == 0)
          return removeLeadingZeros(a.next);
      else
          return a;
  }
  static Node reverse(Node head)
  {
      Node prev = null, curr = head, ptr = null;
      while(curr!=null)
      {
          ptr = curr.next;
          curr.next = prev;
          prev = curr;
          curr = ptr;
      }
      return prev;
  }
  static int length (Node head){
      int count = 0;
      while(head != null){
          count ++;
          head = head.next;
      }
      return count;
  }
  static Node findlarger (Node l1, int len1, Node l2, int len2){
       Node temp1 = l1;
       Node temp2 = l2;
       if(len1>len2)
       {
          temp1 = l1;
          temp2 = l2;
      }
      else if(len1<len2)
      {
          temp1 = l2;
          temp2 = l1;
      }
      else 
      {
          while (temp1 != null && temp2 != null)
          {
              if (temp1.data > temp2.data)
              {
                  temp1 = l1;
                  temp2 = l2;
                  break;
              }
              else if(temp1.data < temp2.data)
              {
                  temp1 = l2;
                  temp2 = l1;
                  break;
              }
              temp1 = temp1.next;
              temp2 = temp2.next;
          }
          if(temp1==null && temp2==null) 
          {
              return new Node(0);
          }
      }
      return subtract(temp1, temp2);
  }
  static Node subtract(Node n1, Node n2){
           Node l1 = n1;
           Node l2 = n2;
           l1 = reverse(l1);
           l2 = reverse(l2);
           Node res = new Node(-1);
           Node temp = res;
           int borrow = 0;
           int diff = 0;
           while(l1 != null){
               diff = borrow + l1.data - ((l2 != null)?l2.data:0);
               if(diff < 0){
                   borrow = -1;
                   diff = 10 + diff;
               }else {
                   borrow = 0;
               }
               temp.next = new Node(diff);
               temp = temp.next;

               if(l1 != null){
                   l1=l1.next;
               }
               if(l2 != null){
                   l2=l2.next;
               }
           }
           res = reverse(res.next);
           res = removeLeadingZeros(res);
           return res;
       }
 static Node subLinkedList(Node l1, Node l2)
       {
           l1 = removeLeadingZeros(l1);
           l2 = removeLeadingZeros(l2);
           int len1 = length(l1);
           int len2 = length(l2);
           if(len1 == 1 && l1.data == 0){
               return l2;
           }
           if(len2 == 1 && l2.data == 0){
               return l1;
           }
           return findlarger(l1, len1, l2, len2);
       }
}  
