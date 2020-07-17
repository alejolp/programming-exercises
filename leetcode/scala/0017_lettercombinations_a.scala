
object Solution {
  def F(digits: String, idx: Int): List[String] = {
    if (idx == digits.length()) {
      List.empty
    } else {
      val p = digits(idx) match {
        case '2' => "abc"
        case '3' => "def"
        case '4' => "ghi"
        case '5' => "jkl"
        case '6' => "mno"
        case '7' => "pqrs"
        case '8' => "tuv"
        case '9' => "wxyz"
        case _   => ""
      }

      val w = F(digits, idx + 1)

      if (p.isEmpty()) {
        return w
      } else if (w.isEmpty) {
        return p.toList map (_.toString())
      } 
      
      for {
        a <- p.toList
        b <- w
      } yield a + b
    }
  }

  def letterCombinations(digits: String): List[String] = {
    F(digits, 0)
  }
}


