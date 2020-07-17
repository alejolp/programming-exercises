class Solution {
    public int numJewelsInStones(String J, String S) {
        long x = 0;
        int r = 0;
        boolean t[] = new boolean[256];
        
        for (int i = 0; i < J.length(); ++i)
            t[J.charAt(i)] = true;
        
        for (int i = 0; i < S.length(); ++i)
            if (t[S.charAt(i)]) ++r;
        
        /*
        for (int i = 0; i < J.length(); ++i)
            x |= 1L << (Character.getNumericValue(J.charAt(i)) - 65);
        for (int i = 0; i < S.length(); ++i) {
            if ((S.charAt(i) - 'A') < 0) throw new RuntimeException("qqq");
            if ((x & (1L << (Character.getNumericValue(S.charAt(i)) - 65))) != 0)
                r++;
        }*/
        return r;        
    }
}
