
object Solution {
  def longestPalindrome(s: String): String = {
    var maxSize = 0
    var maxStart = 0
    
    for (i <- 0 to s.length() - 1) {
      for (d <- 0 to 1) {
        var StartIdx = i
        var EndIdx = i + d
        
        while ((StartIdx >= 0) && (EndIdx < s.length()) && ((s.charAt(StartIdx) == s.charAt(EndIdx)))) {
          StartIdx = StartIdx - 1
          EndIdx = EndIdx + 1
        }
        
        if (StartIdx < 0 || EndIdx >= s.length() || ((s.charAt(StartIdx) != s.charAt(EndIdx)))) { 
          StartIdx = StartIdx + 1
          EndIdx = EndIdx - 1
        }
        
        var thisSize = EndIdx - StartIdx + 1
        
        if (thisSize > maxSize) {
          maxSize = thisSize
          maxStart = StartIdx
        }
      }
    }
    
    return s.substring(maxStart, maxStart + maxSize)
  }
}

