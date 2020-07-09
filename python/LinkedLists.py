class Node:
    def __init__(self, data):
        self.llink = None
        self.rlink = None
        self.data = data

class LinkedList:
    def __init__(self):
        self.head = None
    
    def push(self, data):
        node = Node(data)
        
        if not self.head:
            self.head = node
        
        cur = self.head
        while(cur.rlink):
            cur = cur.rlink
        cur.rlink = node
        node.llink = cur
        return

    def pushIndex(self, data, index):
        node = Node(data)
        
        if(index == 0):
            node.rlink = self.head
            self.head.llink = node
            self.head = node
            return
        if(index >= self.length()):
            self.push(data)
            return
        
        prev = cur = self.head
        c = index
        while(c > 0):
            prev = cur
            if(cur):
                cur = cur.rlink
            c = c-1
        prev.rlink = node
        node.llink = prev
        node.rlink = cur
        cur.llink = node
        return

    def printList(self):
        cur = self.head
        res = ""
        
        while(cur.rlink != None):
            res += str(cur.data) + "->"
            cur = cur.rlink
        res += str(cur.data)

        print(res)
        return
    
    def reverse(self):
        prev = nxt = None
        cur = self.head

        while(cur):
            nxt = cur.rlink
            cur.rlink = prev
            prev = cur
            cur = nxt
        
        self.head = prev
        return
    
    def length(self):
        cur = self.head
        count = 0
        if(not cur):
            return 0
        while(cur):
            count = count + 1
            cur = cur.rlink

        return count
    
    def middleNode(self):
        cur = self.head
        prev = self.head

        if self.head is not None:
            while(cur and cur.rlink):
                cur = cur.rlink.rlink
                prev = prev.rlink
        return prev.data

if __name__ == "__main__":
    print("\n--- Linked Lists ---")
    myList = LinkedList()
    myList.head = Node(10)
    second = Node(20)
    third = Node(30)

    myList.head.rlink = second
    second.llink = myList.head
    second.rlink = third
    third.llink = second

    myList.printList()
    print(myList.length())
    print(myList.middleNode())
    myList.push(40)
    myList.printList()
    print(myList.middleNode())
    myList.pushIndex(25, 2)
    myList.printList()
    myList.pushIndex(5, 0)
    myList.printList()
    myList.pushIndex(50, 7)
    myList.printList()
    myList.reverse()
    myList.printList()
    print("")