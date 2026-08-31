class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        prevNode = head
        curNode = head.next
        pos = 1

        firstPointIdx = -1
        prevCriticalPoint = -1
        minDistance = int(1e8)
        maxDistance = -1

        while curNode and curNode.next:
            if (curNode.val > prevNode.val and curNode.val > curNode.next.val) or \
               (curNode.val < prevNode.val and curNode.val < curNode.next.val):
                if firstPointIdx == -1:
                    firstPointIdx = pos
                else:
                    minDistance = min(minDistance, pos - prevCriticalPoint)
                    maxDistance = pos - firstPointIdx

                prevCriticalPoint = pos

            prevNode = curNode
            curNode = curNode.next
            pos += 1

        if maxDistance == -1:
            return [-1, -1]

        return [minDistance, maxDistance]