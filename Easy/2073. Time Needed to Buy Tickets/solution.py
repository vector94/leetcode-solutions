class Solution:
    def timeRequiredToBuy(self, tickets: list[int], k: int) -> int:
        myQueue = deque()

        for i in range(len(tickets)):
            myQueue.append((tickets[i], i))

        time = 0
        while myQueue:
            t, idx = myQueue.popleft()

            time += 1
            t -= 1
            if t == 0:
                if idx == k:
                    break
                else:
                    continue

            myQueue.append((t, idx))

        return time