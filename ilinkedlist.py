class Node:
    def __init__(self,init_data):
        self.data = init_data
        self.next = None
    
    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self,ndata):
        self.data = ndata

    def setNext(self,nnext):
        self.next = nnext


class linked_list:

    def __init__(self):
        self.head=None

    def add(self,item):
        temp = Node(item)
        temp.setNext(self.head)
        self.head=temp

    def size(self):
        current = self.head
        count =0
        while current != None:
            count+=1
            current = current.getNext()

        return count

    def search(self,item):
        current=self.head
        found = False
        while current !=None and not found:
            if current.getData()==item:
                found = True
            else:
                current = current.getNext()

        return found







