import scala.collection.mutable.HashMap

object Solution {
    def lengthOfLongestSubstring(s: String): Int = {
        var R : Int = 0
        var L : Int = 0
        var M : HashMap[Int, Int] = HashMap.empty
        
        for ((e, i) <- s.zipWithIndex) {
            val x = M.get(e)
            
            if (x.isEmpty) {
              L += 1
            } else if (x.get >= (i - L)) {
              L = i - x.get 
            } else {
              L += 1
            }
            
            R = Math.max(R, L)
            M.put(e, i)
        }
        
        return R
    }
}
