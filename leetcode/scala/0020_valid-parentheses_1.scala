import java.util.ArrayDeque

object Solution {
  def isValid1(s: String): Boolean = {
    var stack: ArrayDeque[Char] = new ArrayDeque
    for (x <- s) {
      if (x == '(' | x == '[' | x == '{') {
        stack.addLast(x)
      } else {
        if (stack.isEmpty()) return false
        val y = stack.removeLast()
        val z = x match {
          case ')' => '('
          case ']' => '['
          case '}' => '{'
          case _   => '.'
        }
        if (y != z) return false
      }
    }
    return stack.isEmpty()
  }

  def isValid2(s: String): Boolean = {
    var stack = new Array[Char](s.length)
    var ptr: Int = 0
    for (x <- s) {
      if (x == '(' | x == '[' | x == '{') {
        stack(ptr) = x
        ptr = ptr + 1
      } else {
        if (ptr == 0) return false
        if (x == ')' && stack(ptr - 1) != '(') {
          return false
        } else if (x == ']' && stack(ptr - 1) != '[') {
          return false
        } else if (x == '}' && stack(ptr - 1) != '{') {
          return false
        }
        ptr = ptr - 1
      }
    }
    return (ptr == 0)
  }
  
  def isValid(s: String): Boolean = isValid2(s)
}
