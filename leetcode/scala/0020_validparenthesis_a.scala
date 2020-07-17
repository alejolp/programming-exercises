import java.util.ArrayDeque

object Solution {
  def isValid(s: String): Boolean = {
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
}
