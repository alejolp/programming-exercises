
object Solution {
    def firstMissingPositive(nums: Array[Int]): Int = {
        var a = 0
        var b = nums.size - 1
        
        // put negative numbers at the end of the array
        
        while (a < b) {
          if (nums(a) <= 0) {
            // swap a and b
            val t = nums(a)
            nums(a) = nums(b)
            nums(b) = t
            b = b - 1
          } else {
            a = a + 1
          }
        }
        
        // keep going until all positive numers are below a 
        
        while (a < nums.size && nums(a) > 0) {
          a = a + 1
        }
        
        println(nums.toList)
        println(a)
        
        val endidx = a
        var i = 0
        
        // use the values 
        while (i < endidx) {
          val x = Math.abs(nums(i))
          if (x - 1 < endidx && nums(x - 1) > 0) {
            nums(x - 1) = - nums(x - 1)
          }
          
          i = i + 1
        }

                println(nums.toList)

        b = 1
        
        while (b - 1 < endidx) {
          if (nums(b - 1) > 0) {
            return b
          }
          b = b + 1
        }
        
        return b
    }
}

