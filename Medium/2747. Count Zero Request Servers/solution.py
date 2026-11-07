class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key = lambda x: x[1])

        queryList = [] # (time, idx)
        for i in range(len(queries)):
            queryList.append([queries[i], i])

        queryList.sort(key = lambda x: x[0])

        freq = defaultdict(int)
        cur_unique_key = 0
        result = [0] * len(queries)

        left = right = 0
        for query in queryList:
            query_idx = query[1]
            l = query[0] - x
            r = query[0]

            while (right < len(logs) and logs[right][1] <= r):
                cur_server = logs[right][0]
                freq[cur_server] += 1
                if freq[cur_server] == 1:
                    cur_unique_key += 1
                right += 1

            while (left < right and logs[left][1] < l):
                cur_server = logs[left][0]
                freq[cur_server] -= 1
                if freq[cur_server] == 0:
                    cur_unique_key -= 1
                left += 1
                
            result[query_idx] = n - cur_unique_key

        return result