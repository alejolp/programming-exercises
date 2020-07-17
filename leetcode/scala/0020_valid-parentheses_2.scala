
import java.util.ArrayDeque

object Solution {
    def isValid(s: String): Boolean = {
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
              case _ => '.'
            }
            if (y != z) return false
          }
        }
        return stack.isEmpty()
    }
}

