class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegree = [0] * numCourses
        graph = [[] for _ in range(numCourses)]

        for i in range(len(prerequisites)):
            inDegree[prerequisites[i][0]] += 1
            graph[prerequisites[i][1]].append(prerequisites[i][0])

        q = deque()
        for i in range(numCourses):
            if inDegree[i] == 0:
                q.append(i)
        
        n = 0
        while q:
            cur = q.pop()
            n += 1
            for i in range(len(graph[cur])):
                inDegree[graph[cur][i]] -= 1
                if inDegree[graph[cur][i]] == 0:
                    q.append(graph[cur][i])

        return n == numCourses
        