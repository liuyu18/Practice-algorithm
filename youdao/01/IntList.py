import IntNode
class SLList(object):
    """docString for IntNode """
    def __init__(self,x):
        self.__first = IntNode(x,None)
        self.__size = 1

    def add_first(self,x):
        self.__first = IntNode(x,self.__first)
        self.__size += 1

    def get_first(self):
        return self.__first.item

    def add_last(self,x):
        self.__size += 1
        p = self.__first
        while p.next is not None:
            p = p.next

        p.next = IntNode(x,None)

    def size(self):
        return self.__size

    def output(self):
        s = ''
        p = self.__first
        count = 0
        while count < self.__size - 1:
            s += p.item + '->'
            p = p.next
            count += 1
        s += p.item
        print(s)

    def reverse(self,m,n):
        p1 = self.__first
        count = 0
        while count < m - 1:
            p1 = p1.next
            count += 1

        if m == 0:
            left_tail = None
            new_tail = p1
        else:
            left_tail = p1
            p1 = p1.next
            new_tail = p1
            count += 1

        pre = p1
        if p1.next is not None:
            current = p1.next
            p1 = current.next
            count += 1
            while count <= n:
                current.next = pre
                pre = current
                current = p1
                if p1 is not None:
                    p1 = p1.next
                count += 1
            if left_tail is not None:
                left_tail.next = pre
            else:
                self.__first = pre
            new_tail.next = current