import sys
input = lambda: sys.stdin.readline().rstrip()

class AVLNode:
  
  
  def __init__(self, key, val: int):
    self.key = key
    self.val = val
    self.valsize = val
    self.size = 1
    self.left = None
    self.right = None
    self.balance = 0


class id6:

  

  

  def __init__(self, V=[]):
    self.node = None
    self.__build(V)

  def __build(self, V):
    for v in sorted(V):
      self.add(v)

  def id1(self, node: AVLNode) -> AVLNode:
    u = node.left
    u.size = node.size
    u.valsize = node.valsize
    node.size -= 1 if u.left is None else u.left.size + 1
    node.valsize -= u.val if u.left is None else u.left.valsize + u.val
    node.left = u.right
    u.right = node
    if u.balance == 1:
      u.balance, node.balance = 0, 0
    else:
      u.balance, node.balance = -1, 1
    return u

  def id3(self, node: AVLNode) -> AVLNode:
    u = node.right
    u.size = node.size
    u.valsize = node.valsize
    node.size -= 1 if u.right is None else u.right.size + 1
    node.valsize -= u.val if u.right is None else u.right.valsize + u.val
    node.right = u.left
    u.left = node
    if u.balance == -1:
      u.balance, node.balance = 0, 0
    else:
      u.balance, node.balance = 1, -1
    return u

  def id8(self, node: AVLNode) -> None:
    
    if node.balance == 1:
      node.right.balance, node.left.balance = -1, 0
    elif node.balance == -1:
      node.right.balance, node.left.balance = 0, 1
    else:
      node.right.balance, node.left.balance = 0, 0
    node.balance = 0

  def id13(self, node: AVLNode) -> AVLNode:
    
    
    
    
    
    
    
    
    E = node.left.right
    F1 = E.left
    F2 = E.right
    E.left = node.left
    E.left.right = F1
    E.right = node
    E.right.left = F2

    E.left.size = 1 + (0 if E.left.right is None else E.left.right.size) + (0 if E.left.left is None else E.left.left.size)
    
    E.size = 1 + E.left.size + E.right.size

    E.left.valsize = E.left.val + (0 if E.left.right is None else E.left.right.valsize) + (0 if E.left.left is None else E.left.left.valsize)
    E.right.valsize = E.right.val + (0 if E.right.right is None else E.right.right.valsize) + (0 if E.right.left is None else E.right.left.valsize)
    E.valsize = E.left.valsize + E.right.valsize + E.val

    self.id8(E)
    return E

  def id2(self, node: AVLNode) -> AVLNode:
    D = node.right.left
    F1 = D.left
    F2 = D.right
    D.right = node.right
    D.right.left = F2
    D.left = node
    D.left.right = F1

    
    D.right.size = 1 + (0 if D.right.left is None else D.right.left.size) + (0 if D.right.right is None else D.right.right.size)
    D.size = 1 + D.right.size + D.left.size

    D.left.valsize = D.left.val + (0 if D.left.left is None else D.left.left.valsize) + (0 if D.left.right is None else D.left.right.valsize)
    D.right.valsize = D.right.val + (0 if D.right.left is None else D.right.left.valsize) + (0 if D.right.right is None else D.right.right.valsize)
    D.valsize = D.right.valsize + D.left.valsize + D.val
    
    self.id8(D)
    return D

  def __discard(self, key) -> bool:
    
    path = []
    node = self.node
    while node is not None:
      if key < node.key:
        path.append((node, 1, 0))
        node = node.left
      elif key > node.key:
        path.append((node, -1, 0))
        node = node.right
      else:
        break

    if node.left is not None:
      path.append((node, 1, 0))
      lmax = node.left
      while lmax.right is not None:
        path.append((lmax, -1, 1))
        lmax = lmax.right
      id12 = lmax.val
      node.key = lmax.key
      node.val = id12
      node = lmax

    cnode = node.right if node.left is None else node.left
    if path:
      pnode, di, _ = path[-1]
      if di == 1:
        pnode.left = cnode
      else:
        pnode.right = cnode
    else:
      self.node = cnode
      return True

    while path:
      new_node = None
      pnode, di, flag = path.pop()
      pnode.balance -= di
      pnode.size -= 1
      pnode.valsize -= id12 if flag else 1

      if pnode.balance == 2:
        new_node = self.id13(pnode) if pnode.left.balance < 0 else self.id1(pnode)
      elif pnode.balance == -2:
        new_node = self.id2(pnode) if pnode.right.balance> 0 else self.id3(pnode)
      elif pnode.balance != 0:
        break

      if new_node is not None:
        if not path:
          self.node = new_node
          return    
        gnode, gdir, _ = path[-1]
        if gdir == 1:
          gnode.left = new_node
        else:
          gnode.right = new_node
        if new_node.balance != 0:
          break

    while path:
      pnode, _, flag = path.pop()
      pnode.size -= 1
      pnode.valsize -= id12 if flag else 1

    return True

  def discard(self, key, cnt=1) -> bool:
    path = []
    node = self.node
    while node is not None:
      path.append(node)
      if key < node.key:
        node = node.left
      elif key > node.key:
        node = node.right
      else:
        break
    else:
      return False
    if cnt > node.val:
      cnt = node.val - 1
      node.val -= cnt
      while path:
        path.pop().valsize -= cnt
    if node.val == 1:
      self.__discard(key)
    else:
      node.val -= cnt
      while path:
        path.pop().valsize -= cnt
    return True

  def discard_all(self, key) -> None:
    self.discard(key, self.count(key))
    return

  def id14(self, key):
    node = self.node
    while node:
      if node.key == key:
        return node.val
      elif key < node.key:
        node = node.left
      else:
        node = node.right
    raise KeyError

  def add(self, key, cnt=1) -> None:
    
    if self.node is None:
      self.node = AVLNode(key, cnt)
      return

    pnode = self.node
    path = []
    while pnode is not None:
      if key < pnode.key:
        path.append((pnode, 1))
        pnode = pnode.left
      elif key > pnode.key:
        path.append((pnode, -1))
        pnode = pnode.right
      else:
        pnode.val += cnt
        pnode.valsize += cnt
        while path:
          path.pop()[0].valsize += cnt
        return

    pnode, di = path[-1]
    if di == 1:
      pnode.left = AVLNode(key, cnt)
    else:
      pnode.right = AVLNode(key, cnt)
    
    new_node = None
    while path:
      pnode, di = path.pop()
      pnode.size += 1
      pnode.valsize += cnt
      pnode.balance += di
      if pnode.balance == 0:
        break

      if pnode.balance == 2:
        new_node = self.id13(pnode) if pnode.left.balance < 0 else self.id1(pnode)
        break
      elif pnode.balance == -2:
        new_node = self.id2(pnode) if pnode.right.balance> 0 else self.id3(pnode)
        break
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      

    if new_node is not None:
      if path:
        gnode, gdi = path[-1]
        if gdi == 1:
          gnode.left = new_node
        else:
          gnode.right = new_node
      else:
        self.node = new_node

    while path:
      pnode, _ = path.pop()
      pnode.size += 1
      pnode.valsize += cnt
    return

  
  def count(self, key) -> int:
    return self.id14(key)

  
  def le(self, key):
    res, node = None, self.node
    while node is not None:
      if key < node.key:
        node = node.left
      elif key > node.key:
        res = node.key
        node = node.right
      else:
        res = key
        break
    return res

  
  def lt(self, key):
    res, node = None, self.node
    while node is not None:
      if key < node.key:
        node = node.left
      elif key > node.key:
        res = node.key
        node = node.right
      else:
        break
    return res

  
  def ge(self, key):
    res, node = None, self.node
    while node is not None:
      if key < node.key:
        res = node.key
        node = node.left
      elif key > node.key:
        node = node.right
      else:
        res = key
        break
    return res

  
  def gt(self, key):
    res, node = None, self.node
    while node is not None:
      if key < node.key:
        res = node.key
        node = node.left
      elif key > node.key:
        node = node.right
      else:
        break
    return res

  
  def index(self, key) -> int:
    indx, node = 0, self.node
    while node:
      if key < node.key:
        node = node.left
      elif key > node.key:
        indx += node.val if node.left is None else node.left.valsize + node.val
        node = node.right
      else:
        indx += 0 if node.left is None else node.left.valsize
        break
    return indx

  
  def index_right(self, key) -> int:
    indx, node = 0, self.node
    while node:
      if key < node.key:
        node = node.left
      elif key > node.key:
        indx += node.val if node.left is None else node.left.valsize + node.val
        node = node.right
      else:
        indx += node.val if node.left is None else node.left.valsize + node.val
        break
    return indx

  def pop(self, p=-1):
    
    if p < 0:
      p += self.id19()
    assert 0 <= p < self.id19()
    x = self.id15(p)
    self.discard(x)
    return x

  def popleft(self):
    
    return self.pop(0)

  def items(self):
    indx = 0
    while indx < self.id11():
      yield self.id7(indx)
      indx += 1

  def keys(self):
    indx = 0
    while indx < self.id11():
      yield self.id7(indx)[0]
      indx += 1

  def values(self):
    indx = 0
    while indx < self.id11():
      yield self.id7(indx)[1]
      indx += 1

  def id15(self, k):
    return self.id10(k)[0]

  def id10(self, k) -> tuple:
    if k < 0:
      k += self.id19()
    now = 0
    node = self.node
    while node is not None:
      s = now + node.left.valsize if node.left is not None else now
      t = s + node.val
      if s <= k < t:
        return node.key, node.val
      elif t <= k:
        now = t
        node = node.right
      else:
        node = node.left
    raise IndexError

  def id7(self, k) -> tuple:
    if k < 0:
      k += self.id11()
    now = 0
    node = self.node
    while node is not None:
      t = now + node.left.size if node.left is not None else now
      if t == k:
        return node.key, node.val
      elif t < k:
        now = t + 1
        node = node.right
      else:
        node = node.left
    raise IndexError

  def id16(self, key):
    node = self.node
    while node:
      if node.key == key:
        return True
      elif key < node.key:
        node = node.left
      else:
        node = node.right
    return False

  def id18(self):
    self.__iter = 0
    return self

  def id9(self):
    if self.__iter == self.id19():
      raise StopIteration
    res = self.id10(self.__iter)
    self.__iter += 1
    return res

  def id5(self):
    for i in range(self.id19()):
      yield self.id10(-i-1)

  def id11(self):
    return 0 if self.node is None else self.node.size

  def id19(self):
    return 0 if self.node is None else self.node.valsize

  def id17(self):
    return True if self.node is not None else False

  def id4(self):
    return '{' + ', '.join(map(lambda x: ', '.join([str(x[0])]*x[1]), self.items())) + '}'

  def show(self):
    return '{' + ', '.join(map(lambda x: f'{x[0]}: {x[1]}', self.items())) + '}'

  def id4(self):
    return '{' + ', '.join(map(lambda x: ', '.join([str(x[0])]*x[1]), self.items())) + '}'

  def id0(self):
    
    return self.id11()





def main():
  n = int(input())
  A = list(map(int, input().split()))
  B = list(map(int, input().split()))
  for i in range(n):
    while A[i] % 2 == 0:
      A[i] //= 2

  st_a = id6(A)
  st_b = id6(B)
  while st_b:
    v = st_b.popleft()
    while v > 0:
      if v in st_a:
        st_a.discard(v)
        break
      v //= 2
    else:
      return 'NO'
  return 'YES'


print('\n'.join(str(main()) for _ in range(int(input()))))
