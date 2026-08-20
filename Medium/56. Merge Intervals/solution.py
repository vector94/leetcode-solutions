class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ret = []

        l = intervals[0][0]
        r = intervals[0][1]

        for i in range(1, len(intervals)):
            if r < intervals[i][0]:
                ret.append([l, r])
                l = intervals[i][0]
                r = intervals[i][1]

            else:
                r = max(intervals[i][1], r)
        
        ret.append([l, r])

        return ret