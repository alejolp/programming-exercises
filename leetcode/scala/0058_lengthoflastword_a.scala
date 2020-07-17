object Solution {
    def lengthOfLastWord(s: String): Int = {
        var i = s.length() - 1
        while ((i >= 0) && (s.charAt(i) == ' ')) {
          i = i - 1
        }
        if (i < 0) {
          return 0
        }
        var k = i
        while ((k >= 0) && (s.charAt(k) != ' ')) {
          k = k - 1
        }
        return i - k
    }
}
