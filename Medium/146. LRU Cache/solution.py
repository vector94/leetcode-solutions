class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.mp = {}
        self.head = Node(0, 0)
        self.tail = Node(0, 0)

        self.head.next = self.tail
        self.tail.prev = self.head

    def removeNode(self, node):
        prevNode = node.prev
        nextNode = node.next

        prevNode.next = nextNode
        nextNode.prev = prevNode

    def addToFront(self, node):
        curHead = self.head.next

        node.prev = self.head
        node.next = curHead

        self.head.next = node
        curHead.prev = node

    def get(self, key: int) -> int:
        if key in self.mp:
            curNode = self.mp[key]
            
            self.removeNode(curNode)
            self.addToFront(curNode)

            return self.mp[key].value

        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            curNode = self.mp[key]

            self.removeNode(curNode) 
            self.addToFront(curNode)

            curNode.value = value
            return
        
        newNode = Node(key, value)
        self.addToFront(newNode)
        self.mp[key] = newNode

        if self.capacity < len(self.mp):
            lastNode = self.tail.prev
            del self.mp[lastNode.key]
            self.removeNode(lastNode)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)