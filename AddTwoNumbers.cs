/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
  public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
  {
    ListNode returnList = new ListNode();
    ListNode currentNode = returnList;
    int carry = 0;
    while (l1 != null || l2 != null || carry == 1)
    {
      int first = 0;
      int second = 0;
      if (l1 != null)
      {
        first = l1.val;
        l1 = l1.next;
      }
      if (l2 != null)
      {
        second = l2.val;
        l2 = l2.next;
      }

      int sum = first + second + carry;
      carry = 0;

      if (sum >= 10)
      {
        carry = 1;
        sum = sum - 10;
      }

      currentNode.val = sum;

      if (l1 == null && l2 == null && carry == 0)
      {
        break;
      }

      currentNode.next = new ListNode();
      currentNode = currentNode.next;
    }
    return returnList;
  }
}