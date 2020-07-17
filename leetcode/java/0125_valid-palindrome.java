class Solution {
    public boolean isPalindrome(String s) {
        StringBuffer b = new StringBuffer();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isLetterOrDigit(c)) {
                char x = Character.toLowerCase(c);
                b.append(x);
            }
        }
        String w = b.toString();
        for (int i = 0, k = w.length() - 1; i < k; i++, k--) {
            if (w.charAt(i) != w.charAt(k)) {
                return false;
            }
        }
        return true;
    }
}