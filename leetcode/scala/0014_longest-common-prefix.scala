import scala.util.Sorting

object Solution {
    def longestCommonPrefix(strs: Array[String]): String = {
        Sorting.quickSort(strs)
        if (strs.length == 0) return ""
        val lim = Math.min(strs(0).length(), strs(strs.length - 1).length())
        var i = 0
        while (i < lim && strs(0).charAt(i) == strs(strs.length - 1).charAt(i)) {
          i = i + 1
        }
        return strs(0).substring(0, i)
    }
}
