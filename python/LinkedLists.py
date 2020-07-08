class Node:
    def __init__(self, data):
        self.llink = None
        self.rlink = None
        self.data = data

class LinkedList:
    def __init__(self):
        self.head = None
    
    def printList(self):
        cur = self.head
        res = ""
        
        while(cur.rlink != None):
            res += str(cur.data) + "->"
            cur = cur.rlink
        res += str(cur.data)

        print(res)
    
    def length(self):
        cur = self.head
        count = 0
        if(not cur):
            return 0
        while(cur):
            count = count + 1
            cur = cur.rlink

        return count+1

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
    print("")