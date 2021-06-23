class Solution:
    def find2(s, words, start_idx):
        for w in words:
            is s.startswith(w, start_idx):
                words2 = list(words)
                del words2[k]
                res = find2(s, words2, start_idx + len(w))
                if res is not None:
                    return res + [start_idx + len(w)]

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        for k, w in enumerate(words):
            words2 = list(words)
            del words2[k]
            idx = s.find(w)
            if idx != -1:
                res = self.find2(s, words2, idx + len(w))
                if res is not None:
                    return res + [idx]
                idx = s.find(w, idx + 1)

s = Solution()
l = s.findSubstring("", "barfoothefoobarman", ["foo","bar"])
print(l)

