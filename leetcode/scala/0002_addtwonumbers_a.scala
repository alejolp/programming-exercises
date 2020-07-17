/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
        var aux: Option[ListNode] = None
        var head: Option[ListNode] = None
        
        var p1: ListNode = l1;
        var p2: ListNode = l2;
        var r: Int = 0
        
        while (p1 != null || p2 != null || r != 0) {
          var v1 = 0
          var v2 = 0
          
          if (p1 != null) {
            v1 = p1.x
            p1 = p1.next
          }
          
          if (p2 != null) {
            v2 = p2.x
            p2 = p2.next
          }
          
          var next: ListNode = new ListNode((v1 + v2 + r) % 10)
          r = (v1 + v2 + r) / 10
          
          if (aux.isDefined) {
            aux.get.next = next
          } else {
            head = Some(next)
          }
          
          aux = Some(next)
        }
                
        return head.get
    }
}
