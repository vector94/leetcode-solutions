class Solution:
    def helper(self, o, c, n, p, ret):
        if o == n and c == n:
            ret.append(p)

        if o < n:
            self.helper(o + 1, c, n, p + "(", ret)
        
        if c < o:
            self.helper(o, c + 1, n, p + ")", ret)

    
    def generateParenthesis(self, n: int) -> List[str]:
        ret = []
        self.helper(0, 0, n, "", ret)

        return ret

        