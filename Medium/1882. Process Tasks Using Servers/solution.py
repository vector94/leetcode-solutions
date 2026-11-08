class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        free_servers = []
        for i in range(len(servers)):
            heapq.heappush(free_servers, (servers[i], i))

        result = []
        used_servers = []
        for i in range(len(tasks)):
            while len(used_servers) > 0 and used_servers[0][0] <= i:
                _, server, idx = heapq.heappop(used_servers)
                heapq.heappush(free_servers, (server, idx))

            if len(free_servers) > 0:
                free_server, idx = heapq.heappop(free_servers)
                result.append(idx)
                heapq.heappush(used_servers, (i + tasks[i], free_server, idx))
            else:
                t, cur_busy_server, idx = heapq.heappop(used_servers)
                result.append(idx)
                heapq.heappush(used_servers, (t + tasks[i], cur_busy_server, idx))

        return result
            