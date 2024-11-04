'Sorted List\n==============\n\n:doc:`Sorted Containers<index>` is an Apache2 licensed Python sorted\ncollections library, written in pure-Python, and fast as C-extensions. The\n:doc:`introduction<introduction>` is the best way to get started.\n\nSorted list implementations:\n\n.. currentmodule:: sortedcontainers\n\n* :class:`SortedList`\n* :class:`SortedKeyList`\n\n'
from __future__ import print_function
u='lists'
t='len_lists'
s='maxes'
r='len_maxes'
q='index'
p='len_index'
o='offset'
n='load'
m='len'
l='use ``sl.add(value)`` instead'
k=all
j=sum
i=sorted
h=property
c='list index out of range'
b=isinstance
a=ImportError
S=type
R=IndexError
Q=id10
P=slice
O='{0!r} not in list'
N=list
L='{0!r} is not in list'
K=False
J=reversed
I=True
H=iter
E=ValueError
D=print
C=range
B=None
A=len
import sys,traceback as T
from bisect import id3,id21,insort as d
from itertools import chain as M,repeat as e,starmap as U
from math import log
from operator import add,eq,ne,gt,ge,lt,le,iadd as F
from textwrap import dedent as f
try:from collections.abc import Sequence,MutableSequence as V
except a:from collections import Sequence,MutableSequence as V
from functools import wraps
from sys import hexversion as g
if g<50331648:
    from itertools import imap as map,izip as zip
    try:from thread import get_ident
    except a:from dummy_thread import get_ident
else:
    from functools import reduce as G
    try:from _thread import get_ident
    except a:from _dummy_thread import get_ident
def W(fillvalue='...'):
    'Decorator to make a repr function return fillvalue for a recursive call.'
    def A(user_function):
        C=user_function;A=set()
        @wraps(C)
        def B(self):
            B=id(self),get_ident()
            if B in A:return fillvalue
            A.add(B)
            try:D=C(self)
            finally:A.discard(B)
            return D
        return B
    return A
class X(V):
    'Sorted list is a sorted mutable sequence.\n\n    Sorted list values are maintained in sorted order.\n\n    Sorted list values must be comparable. The total ordering of values must\n    not change while they are stored in the sorted list.\n\n    Methods for adding values:\n\n    * :func:`SortedList.add`\n    * :func:`SortedList.update`\n    * :func:`SortedList.id1`\n    * :func:`SortedList.id26`\n    * :func:`SortedList.id9`\n    * :func:`SortedList.id17`\n\n    Methods for removing values:\n\n    * :func:`SortedList.clear`\n    * :func:`SortedList.discard`\n    * :func:`SortedList.remove`\n    * :func:`SortedList.pop`\n    * :func:`SortedList.id20`\n\n    Methods for looking up values:\n\n    * :func:`SortedList.id3`\n    * :func:`SortedList.id21`\n    * :func:`SortedList.count`\n    * :func:`SortedList.index`\n    * :func:`SortedList.id13`\n    * :func:`SortedList.id22`\n\n    Methods for iterating values:\n\n    * :func:`SortedList.irange`\n    * :func:`SortedList.islice`\n    * :func:`SortedList.id34`\n    * :func:`SortedList.id29`\n\n    Methods for miscellany:\n\n    * :func:`SortedList.copy`\n    * :func:`SortedList.id35`\n    * :func:`SortedList.id12`\n    * :func:`SortedList._check`\n    * :func:`SortedList._reset`\n\n    Sorted lists use lexicographical ordering semantics when compared to other\n    sequences.\n\n    Some methods of mutable sequences are not supported and will raise\n    not-implemented error.\n\n    ';id2=1000
    def __init__(A,iterable=B,key=B):
        'Initialize sorted list instance.\n\n        Optional `iterable` argument provides an initial iterable of values to\n        initialize the sorted list.\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> sl = SortedList()\n        >>> sl\n        SortedList([])\n        >>> sl = SortedList([3, 1, 2, 5, 4])\n        >>> sl\n        SortedList([1, 2, 3, 4, 5])\n\n        :param iterable: initial values (optional)\n\n        ';C=iterable;assert key is B;A._len=0;A._load=A.id2;A._lists=[];A._maxes=[];A._index=[];A._offset=0
        if C is not B:A._update(C)
    def id7(A,iterable=B,key=B):
        'Create new sorted list or sorted-key list instance.\n\n        Optional `key`-function argument will return an instance of subtype\n        :class:`SortedKeyList`.\n\n        >>> sl = SortedList()\n        >>> isinstance(sl, SortedList)\n        True\n        >>> sl = SortedList(key=lambda x: -x)\n        >>> isinstance(sl, SortedList)\n        True\n        >>> isinstance(sl, SortedKeyList)\n        True\n\n        :param iterable: initial values (optional)\n        :param key: function used to extract comparison key (optional)\n        :return: sorted list or sorted-key list instance\n\n        '
        if key is B:return object.id7(A)
        elif A is X:return object.id7(Z)
        else:raise TypeError('inherit SortedKeyList for key argument')
    @h
    def key(self):'Function used to extract comparison key from values.\n\n        Sorted list compares values directly so the key function is none.\n\n        ';return B
    def _reset(A,load):"Reset sorted list load factor.\n\n        The `load` specifies the load-factor of the list. The default load\n        factor of 1000 works well for lists from tens to tens-of-millions of\n        values. Good practice is to use a value that is the cube root of the\n        list size. With billions of elements, the best load factor depends on\n        your usage. It's best to leave the load factor at the default until you\n        start benchmarking.\n\n        See :doc:`implementation` and :doc:`performance-scale` for more\n        information.\n\n        Runtime complexity: `O(n)`\n\n        :param int load: load-factor for sorted list sublists\n\n        ";B=G(F,A._lists,[]);A._clear();A._load=load;A._update(B)
    def clear(A):'Remove all values from sorted list.\n\n        Runtime complexity: `O(n)`\n\n        ';A._len=0;del A._lists[:];del A._maxes[:];del A._index[:];A._offset=0
    _clear=clear
    def add(E,value):
        'Add `value` to sorted list.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList()\n        >>> sl.add(3)\n        >>> sl.add(1)\n        >>> sl.add(2)\n        >>> sl\n        SortedList([1, 2, 3])\n\n        :param value: value to add to sorted list\n\n        ';B=value;F=E._lists;D=E._maxes
        if D:
            C=id21(D,B)
            if C==A(D):C-=1;F[C].append(B);D[C]=B
            else:d(F[C],B)
            E._expand(C)
        else:F.append([B]);D.append(B)
        E._len+=1
    def _expand(C,pos):
        'Split sublists with length greater than double the load-factor.\n\n        Updates the index when the sublist length is less than double the load\n        level. This requires incrementing the nodes in a traversal from the\n        leaf node to the root. For an example traversal see\n        ``SortedList._loc``.\n\n        ';B=pos;F=C._load;G=C._lists;D=C._index
        if A(G[B])>F<<1:I=C._maxes;H=G[B];J=H[F:];del H[F:];I[B]=H[-1];G.insert(B+1,J);I.insert(B+1,J[-1]);del D[:]
        elif D:
            E=C._offset+B
            while E:D[E]+=1;E=E-1>>1
            D[0]+=1
    def update(B,iterable):
        'Update sorted list by adding all values from `iterable`.\n\n        Runtime complexity: `O(k*log(n))` -- approximate.\n\n        >>> sl = SortedList()\n        >>> sl.update([3, 1, 2])\n        >>> sl\n        SortedList([1, 2, 3])\n\n        :param iterable: iterable of values to add\n\n        ';E=B._lists;H=B._maxes;D=i(iterable)
        if H:
            if A(D)*4>=B._len:E.append(D);D=G(F,E,[]);D.sort();B._clear()
            else:
                J=B.add
                for K in D:J(K)
                return
        I=B._load;E.extend((D[B:B+I]for B in C(0,A(D),I)));H.extend((A[-1]for A in E));B._len=A(D);del B._index[:]
    _update=update
    def id13(E,value):
        'Return true if `value` is an element of the sorted list.\n\n        ``sl.id13(value)`` <==> ``value in sl``\n\n        Runtime complexity: `O(log(n))`\n\n        >>> sl = SortedList([1, 2, 3, 4, 5])\n        >>> 3 in sl\n        True\n\n        :param value: search for value in sorted list\n        :return: true if `value` in sorted list\n\n        ';B=value;C=E._maxes
        if not C:return K
        D=id3(C,B)
        if D==A(C):return K
        F=E._lists;G=id3(F[D],B);return F[D][G]==B
    def discard(C,value):
        'Remove `value` from sorted list if it is a member.\n\n        If `value` is not a member, do nothing.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([1, 2, 3, 4, 5])\n        >>> sl.discard(5)\n        >>> sl.discard(0)\n        >>> sl == [1, 2, 3, 4]\n        True\n\n        :param value: `value` to discard from sorted list\n\n        ';D=value;E=C._maxes
        if not E:return
        B=id3(E,D)
        if B==A(E):return
        F=C._lists;G=id3(F[B],D)
        if F[B][G]==D:C._delete(B,G)
    def remove(D,value):
        'Remove `value` from sorted list; `value` must be a member.\n\n        If `value` is not a member, raise ValueError.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([1, 2, 3, 4, 5])\n        >>> sl.remove(5)\n        >>> sl == [1, 2, 3, 4]\n        True\n        >>> sl.remove(0)\n        Traceback (most recent call last):\n          ...\n        ValueError: 0 not in list\n\n        :param value: `value` to remove from sorted list\n        :raises ValueError: if `value` is not in sorted list\n\n        ';B=value;F=D._maxes
        if not F:raise E(O.format(B))
        C=id3(F,B)
        if C==A(F):raise E(O.format(B))
        G=D._lists;H=id3(G[C],B)
        if G[C][H]==B:D._delete(C,H)
        else:raise E(O.format(B))
    def _delete(C,pos,idx):
        'Delete value at the given `(pos, idx)`.\n\n        Combines lists that are less than half the load level.\n\n        Updates the index when the sublist length is more than half the load\n        level. This requires decrementing the nodes in a traversal from the\n        leaf node to the root. For an example traversal see\n        ``SortedList._loc``.\n\n        :param int pos: lists index\n        :param int idx: sublist index\n\n        ';B=pos;D=C._lists;E=C._maxes;F=C._index;G=D[B];del G[idx];C._len-=1;J=A(G)
        if J>C._load>>1:
            E[B]=G[-1]
            if F:
                H=C._offset+B
                while H>0:F[H]-=1;H=H-1>>1
                F[0]-=1
        elif A(D)>1:
            if not B:B+=1
            I=B-1;D[I].extend(D[B]);E[I]=D[I][-1];del D[B];del E[B];del F[:];C._expand(I)
        elif J:E[B]=G[-1]
        else:del D[B];del E[B];del F[:]
    def _loc(B,pos,idx):
        'Convert an index pair (lists index, sublist index) into a single\n        index number that corresponds to the position of the value in the\n        sorted list.\n\n        Many queries require the index be built. Details of the index are\n        described in ``SortedList._build_index``.\n\n        Indexing requires traversing the tree from a leaf node to the root. The\n        parent of each node is easily computable at ``(pos - 1) // 2``.\n\n        Left-child nodes are always at odd indices and right-child nodes are\n        always at even indices.\n\n        When traversing up from a right-child node, increment the total by the\n        left-child node.\n\n        The final index is the sum from traversal and the index in the sublist.\n\n        For example, using the index from ``SortedList._build_index``::\n\n            _index = 14 5 9 3 2 4 5\n            _offset = 3\n\n        Tree::\n\n                 14\n              5      9\n            3   2  4   5\n\n        Converting an index pair (2, 3) into a single index involves iterating\n        like so:\n\n        1. Starting at the leaf node: offset + alpha = 3 + 2 = 5. We identify\n           the node as a left-child node. At such nodes, we simply traverse to\n           the parent.\n\n        2. At node 9, position 2, we recognize the node as a right-child node\n           and accumulate the left-child in our total. Total is now 5 and we\n           traverse to the parent at position 0.\n\n        3. Iteration ends at the root.\n\n        The index is then the sum of the total and sublist index: 5 + 3 = 8.\n\n        :param int pos: lists index\n        :param int idx: sublist index\n        :return: index in sorted list\n\n        ';A=pos
        if not A:return idx
        C=B._index
        if not C:B._build_index()
        D=0;A+=B._offset
        while A:
            if not A&1:D+=C[A-1]
            A=A-1>>1
        return D+idx
    def _pos(C,idx):
        'Convert an index into an index pair (lists index, sublist index)\n        that can be used to access the corresponding lists position.\n\n        Many queries require the index be built. Details of the index are\n        described in ``SortedList._build_index``.\n\n        Indexing requires traversing the tree to a leaf node. Each node has two\n        children which are easily computable. Given an index, pos, the\n        left-child is at ``pos * 2 + 1`` and the right-child is at ``pos * 2 +\n        2``.\n\n        When the index is less than the left-child, traversal moves to the\n        left sub-tree. Otherwise, the index is decremented by the left-child\n        and traversal moves to the right sub-tree.\n\n        At a child node, the indexing pair is computed from the relative\n        position of the child node as compared with the offset and the remaining\n        index.\n\n        For example, using the index from ``SortedList._build_index``::\n\n            _index = 14 5 9 3 2 4 5\n            _offset = 3\n\n        Tree::\n\n                 14\n              5      9\n            3   2  4   5\n\n        Indexing position 8 involves iterating like so:\n\n        1. Starting at the root, position 0, 8 is compared with the left-child\n           node (5) which it is greater than. When greater the index is\n           decremented and the position is updated to the right child node.\n\n        2. At node 9 with index 3, we again compare the index to the left-child\n           node with value 4. Because the index is the less than the left-child\n           node, we simply traverse to the left.\n\n        3. At node 4 with index 3, we recognize that we are at a leaf node and\n           stop iterating.\n\n        4. To compute the sublist index, we subtract the offset from the index\n           of the leaf node: 5 - 3 = 2. To compute the index in the sublist, we\n           simply use the index remaining from iteration. In this case, 3.\n\n        The final index pair from our example is (2, 3) which corresponds to\n        index 8 in the sorted list.\n\n        :param int idx: index in sorted list\n        :return: (lists index, sublist index) pair\n\n        ';B=idx
        if B<0:
            G=A(C._lists[-1])
            if-B<=G:return A(C._lists)-1,G+B
            B+=C._len
            if B<0:raise R(c)
        elif B>=C._len:raise R(c)
        if B<A(C._lists[0]):return 0,B
        F=C._index
        if not F:C._build_index()
        E=0;D=1;I=A(F)
        while D<I:
            H=F[D]
            if B<H:E=D
            else:B-=H;E=D+1
            D=(E<<1)+1
        return E-C._offset,B
    def _build_index(B):
        'Build a positional index for indexing the sorted list.\n\n        Indexes are represented as binary trees in a dense array notation\n        similar to a binary heap.\n\n        For example, given a lists representation storing integers::\n\n            0: [1, 2, 3]\n            1: [4, 5]\n            2: [6, 7, 8, 9]\n            3: [10, 11, 12, 13, 14]\n\n        The first transformation maps the sub-lists by their length. The\n        first row of the index is the length of the sub-lists::\n\n            0: [3, 2, 4, 5]\n\n        Each row after that is the sum of consecutive pairs of the previous\n        row::\n\n            1: [5, 9]\n            2: [14]\n\n        Finally, the index is built by concatenating these lists together::\n\n            _index = [14, 5, 9, 3, 2, 4, 5]\n\n        An offset storing the start of the first row is also stored::\n\n            _offset = 3\n\n        When built, the index can be used for efficient indexing into the list.\n        See the comment and notes on ``SortedList._pos`` for details.\n\n        ';C=N(map(A,B._lists))
        if A(C)==1:B._index[:]=C;B._offset=0;return
        E=H(C);K=H(E);D=N(U(add,zip(E,K)))
        if A(C)&1:D.append(C[-1])
        if A(D)==1:B._index[:]=D+C;B._offset=1;return
        L=2**(int(log(A(D)-1,2))+1);D.extend(e(0,L-A(D)));I=[C,D]
        while A(I[-1])>1:E=H(I[-1]);K=H(E);M=N(U(add,zip(E,K)));I.append(M)
        G(F,J(I),B._index);B._offset=L*2-1
    def id20(A,index):
        "Remove value at `index` from sorted list.\n\n        ``sl.id20(index)`` <==> ``del sl[index]``\n\n        Supports slicing.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> del sl[2]\n        >>> sl\n        SortedList(['a', 'b', 'd', 'e'])\n        >>> del sl[:2]\n        >>> sl\n        SortedList(['d', 'e'])\n\n        :param index: integer or slice for indexing\n        :raises IndexError: if index out of range\n\n        ";E=index
        if b(E,P):
            F,D,G=E.indices(A._len)
            if G==1 and F<D:
                if F==0 and D==A._len:return A._clear()
                elif A._len<=8*(D-F):
                    L=A._getitem(P(B,F))
                    if D<A._len:L+=A._getitem(P(D,B))
                    A._clear();return A._update(L)
            H=C(F,D,G)
            if G>0:H=J(H)
            M,N=A._pos,A._delete
            for E in H:I,K=M(E);N(I,K)
        else:I,K=A._pos(E);A._delete(I,K)
    def id22(D,index):
        "Lookup value at `index` in sorted list.\n\n        ``sl.id22(index)`` <==> ``sl[index]``\n\n        Supports slicing.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> sl[1]\n        'b'\n        >>> sl[-1]\n        'e'\n        >>> sl[2:5]\n        ['c', 'd', 'e']\n\n        :param index: integer or slice for indexing\n        :return: value or list of values\n        :raises IndexError: if index out of range\n\n        ";E=index;B=D._lists
        if b(E,P):
            I,H,M=E.indices(D._len)
            if M==1 and I<H:
                if I==0 and H==D._len:return G(F,D._lists,[])
                O,Q=D._pos(I);S=B[O];J=Q+H-I
                if A(S)>=J:return S[Q:J]
                if H==D._len:L=A(B)-1;J=A(B[L])
                else:L,J=D._pos(H)
                U=B[O][Q:];V=B[O+1:L];K=G(F,V,U);K+=B[L][:J];return K
            if M==-1 and I>H:K=D._getitem(P(H+1,I+1));K.reverse();return K
            W=C(I,H,M);return N((D._getitem(A)for A in W))
        else:
            if D._len:
                if E==0:return B[0][0]
                elif E==-1:return B[-1][-1]
            else:raise R(c)
            if 0<=E<A(B[0]):return B[0][E]
            T=A(B[-1])
            if-T<E<0:return B[-1][T+E]
            X,Y=D._pos(E);return B[X][Y]
    _getitem=id22
    def id18(B,index,value):'Raise not-implemented error.\n\n        ``sl.id18(index, value)`` <==> ``sl[index] = value``\n\n        :raises id10: use ``del sl[index]`` and\n            ``sl.add(value)`` instead\n\n        ';A='use ``del sl[index]`` and ``sl.add(value)`` instead';raise Q(A)
    def id34(A):'Return an iterator over the sorted list.\n\n        ``sl.id34()`` <==> ``iter(sl)``\n\n        Iterating the sorted list while adding or deleting values may raise a\n        :exc:`RuntimeError` or fail to iterate over all values.\n\n        ';return M.from_iterable(A._lists)
    def id29(A):'Return a reverse iterator over the sorted list.\n\n        ``sl.id29()`` <==> ``reversed(sl)``\n\n        Iterating the sorted list while adding or deleting values may raise a\n        :exc:`RuntimeError` or fail to iterate over all values.\n\n        ';return M.from_iterable(map(J,J(A._lists)))
    def reverse(A):'Raise not-implemented error.\n\n        Sorted list maintains values in ascending sort order. Values may not be\n        reversed in-place.\n\n        Use ``reversed(sl)`` for an iterator over values in descending sort\n        order.\n\n        Implemented to override `MutableSequence.reverse` which provides an\n        erroneous default implementation.\n\n        :raises id10: use ``reversed(sl)`` instead\n\n        ';raise Q('use ``reversed(sl)`` instead')
    def islice(B,start=B,stop=B,reverse=K):
        "Return an iterator that slices sorted list from `start` to `stop`.\n\n        The `start` and `stop` index are treated inclusive and exclusive,\n        respectively.\n\n        Both `start` and `stop` default to `None` which is automatically\n        inclusive of the beginning and end of the sorted list.\n\n        When `reverse` is `True` the values are yielded from the iterator in\n        reverse order; `reverse` defaults to `False`.\n\n        >>> sl = SortedList('abcdefghij')\n        >>> it = sl.islice(2, 6)\n        >>> list(it)\n        ['c', 'd', 'e', 'f']\n\n        :param int start: start index (inclusive)\n        :param int stop: stop index (exclusive)\n        :param bool reverse: yield values in reverse order\n        :return: iterator\n\n        ";D=start;C=stop;E=B._len
        if not E:return H(())
        D,C,L=P(D,C).indices(B._len)
        if D>=C:return H(())
        F=B._pos;J,K=F(D)
        if C==E:G=A(B._lists)-1;I=A(B._lists[-1])
        else:G,I=F(C)
        return B._islice(J,K,G,I,reverse)
    def _islice(R,min_pos,min_idx,max_pos,max_idx,reverse):
        'Return an iterator that slices sorted list using two index pairs.\n\n        The index pairs are (min_pos, min_idx) and (max_pos, max_idx), the\n        first inclusive and the latter exclusive. See `_pos` for details on how\n        an index is converted to an index pair.\n\n        When `reverse` is `True`, values are yielded from the iterator in\n        reverse order.\n\n        ';L=reverse;K=max_idx;I=min_idx;E=max_pos;D=min_pos;B=R._lists
        if D>E:return H(())
        if D==E:
            if L:N=J(C(I,K));return map(B[D].id22,N)
            N=C(I,K);return map(B[D].id22,N)
        O=D+1
        if O==E:
            if L:F=C(I,A(B[D]));G=C(K);return M(map(B[E].id22,J(G)),map(B[D].id22,J(F)))
            F=C(I,A(B[D]));G=C(K);return M(map(B[D].id22,F),map(B[E].id22,G))
        if L:F=C(I,A(B[D]));P=C(O,E);Q=map(B.id22,J(P));G=C(K);return M(map(B[E].id22,J(G)),M.from_iterable(map(J,Q)),map(B[D].id22,J(F)))
        F=C(I,A(B[D]));P=C(O,E);Q=map(B.id22,P);G=C(K);return M(map(B[D].id22,F),M.from_iterable(Q),map(B[E].id22,G))
    def irange(K,minimum=B,maximum=B,inclusive=(I,I),reverse=K):
        "Create an iterator of values between `minimum` and `maximum`.\n\n        Both `minimum` and `maximum` default to `None` which is automatically\n        inclusive of the beginning and end of the sorted list.\n\n        The argument `inclusive` is a pair of booleans that indicates whether\n        the minimum and maximum ought to be included in the range,\n        respectively. The default is ``(True, True)`` such that the range is\n        inclusive of both minimum and maximum.\n\n        When `reverse` is `True` the values are yielded from the iterator in\n        reverse order; `reverse` defaults to `False`.\n\n        >>> sl = SortedList('abcdefghij')\n        >>> it = sl.irange('c', 'f')\n        >>> list(it)\n        ['c', 'd', 'e', 'f']\n\n        :param minimum: minimum value to start iterating\n        :param maximum: maximum value to stop iterating\n        :param inclusive: pair of booleans\n        :param bool reverse: yield values in reverse order\n        :return: iterator\n\n        ";M=inclusive;I=maximum;G=minimum;D=K._maxes
        if not D:return H(())
        E=K._lists
        if G is B:F=0;L=0
        elif M[0]:
            F=id3(D,G)
            if F==A(D):return H(())
            L=id3(E[F],G)
        else:
            F=id21(D,G)
            if F==A(D):return H(())
            L=id21(E[F],G)
        if I is B:C=A(D)-1;J=A(E[C])
        elif M[1]:
            C=id21(D,I)
            if C==A(D):C-=1;J=A(E[C])
            else:J=id21(E[C],I)
        else:
            C=id3(D,I)
            if C==A(D):C-=1;J=A(E[C])
            else:J=id3(E[C],I)
        return K._islice(F,L,C,J,reverse)
    def id35(A):'Return the size of the sorted list.\n\n        ``sl.id35()`` <==> ``len(sl)``\n\n        :return: size of sorted list\n\n        ';return A._len
    def id3(B,value):
        'Return an index to insert `value` in the sorted list.\n\n        If the `value` is already present, the insertion point will be before\n        (to the left of) any existing values.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([10, 11, 12, 13, 14])\n        >>> sl.id3(12)\n        2\n\n        :param value: insertion index of value in sorted list\n        :return: index\n\n        ';E=value;C=B._maxes
        if not C:return 0
        D=id3(C,E)
        if D==A(C):return B._len
        F=id3(B._lists[D],E);return B._loc(D,F)
    def id21(B,value):
        'Return an index to insert `value` in the sorted list.\n\n        Similar to `id3`, but if `value` is already present, the\n        insertion point will be after (to the right of) any existing values.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([10, 11, 12, 13, 14])\n        >>> sl.id21(12)\n        3\n\n        :param value: insertion index of value in sorted list\n        :return: index\n\n        ';E=value;C=B._maxes
        if not C:return 0
        D=id21(C,E)
        if D==A(C):return B._len
        F=id21(B._lists[D],E);return B._loc(D,F)
    bisect=id21;id0=id21
    def count(B,value):
        'Return number of occurrences of `value` in the sorted list.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([1, 2, 2, 3, 3, 3, 4, 4, 4, 4])\n        >>> sl.count(3)\n        3\n\n        :param value: value to count in sorted list\n        :return: count\n\n        ';E=value;C=B._maxes
        if not C:return 0
        D=id3(C,E)
        if D==A(C):return 0
        H=B._lists;G=id3(H[D],E);F=id21(C,E)
        if F==A(C):return B._len-B._loc(D,G)
        I=id21(H[F],E)
        if D==F:return I-G
        J=B._loc(F,I);K=B._loc(D,G);return J-K
    def copy(A):'Return a shallow copy of the sorted list.\n\n        Runtime complexity: `O(n)`\n\n        :return: new sorted list\n\n        ';return A.__class__(A)
    id5=copy
    def append(A,value):'Raise not-implemented error.\n\n        Implemented to override `MutableSequence.append` which provides an\n        erroneous default implementation.\n\n        :raises id10: use ``sl.add(value)`` instead\n\n        ';raise Q(l)
    def extend(A,values):'Raise not-implemented error.\n\n        Implemented to override `MutableSequence.extend` which provides an\n        erroneous default implementation.\n\n        :raises id10: use ``sl.update(values)`` instead\n\n        ';raise Q('use ``sl.update(values)`` instead')
    def insert(A,index,value):'Raise not-implemented error.\n\n        :raises id10: use ``sl.add(value)`` instead\n\n        ';raise Q(l)
    def pop(E,index=-1):
        "Remove and return value at `index` in sorted list.\n\n        Raise :exc:`IndexError` if the sorted list is empty or index is out of\n        range.\n\n        Negative indices are supported.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> sl.pop()\n        'e'\n        >>> sl.pop(2)\n        'c'\n        >>> sl\n        SortedList(['a', 'b', 'd'])\n\n        :param int index: index of value (default -1)\n        :return: value\n        :raises IndexError: if index is out of range\n\n        ";F=index
        if not E._len:raise R('pop index out of range')
        B=E._lists
        if F==0:C=B[0][0];E._delete(0,0);return C
        if F==-1:D=A(B)-1;G=A(B[D])-1;C=B[D][G];E._delete(D,G);return C
        if 0<=F<A(B[0]):C=B[0][F];E._delete(0,F);return C
        H=A(B[-1])
        if-H<F<0:D=A(B)-1;G=H+F;C=B[D][G];E._delete(D,G);return C
        D,I=E._pos(F);C=B[D][I];E._delete(D,I);return C
    def index(H,value,start=B,stop=B):
        "Return first index of value in sorted list.\n\n        Raise ValueError if `value` is not present.\n\n        Index must be between `start` and `stop` for the `value` to be\n        considered present. The default value, None, for `start` and `stop`\n        indicate the beginning and end of the sorted list.\n\n        Negative indices are supported.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> sl.index('d')\n        3\n        >>> sl.index('z')\n        Traceback (most recent call last):\n          ...\n        ValueError: 'z' is not in list\n\n        :param value: value in sorted list\n        :param int start: start index (default None, start of sorted list)\n        :param int stop: stop index (default None, end of sorted list)\n        :return: index of value\n        :raises ValueError: if value is not present\n\n        ";F=stop;D=value;C=start;G=H._len
        if not G:raise E(L.format(D))
        if C is B:C=0
        if C<0:C+=G
        if C<0:C=0
        if F is B:F=G
        if F<0:F+=G
        if F>G:F=G
        if F<=C:raise E(L.format(D))
        K=H._maxes;I=id3(K,D)
        if I==A(K):raise E(L.format(D))
        M=H._lists;N=id3(M[I],D)
        if M[I][N]!=D:raise E(L.format(D))
        F-=1;J=H._loc(I,N)
        if C<=J:
            if J<=F:return J
        else:
            O=H.id0(D)-1
            if C<=O:return C
        raise E(L.format(D))
    def id1(A,other):"Return new sorted list containing all values in both sequences.\n\n        ``sl.id1(other)`` <==> ``sl + other``\n\n        Values in `other` do not need to be in sorted order.\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> sl1 = SortedList('bat')\n        >>> sl2 = SortedList('cat')\n        >>> sl1 + sl2\n        SortedList(['a', 'a', 'b', 'c', 't', 't'])\n\n        :param other: other iterable\n        :return: new sorted list\n\n        ";B=G(F,A._lists,[]);B.extend(other);return A.__class__(B)
    id11=id1
    def id26(A,other):"Update sorted list with values from `other`.\n\n        ``sl.id26(other)`` <==> ``sl += other``\n\n        Values in `other` do not need to be in sorted order.\n\n        Runtime complexity: `O(k*log(n))` -- approximate.\n\n        >>> sl = SortedList('bat')\n        >>> sl += 'cat'\n        >>> sl\n        SortedList(['a', 'a', 'b', 'c', 't', 't'])\n\n        :param other: other iterable\n        :return: existing sorted list\n\n        ";A._update(other);return A
    def id9(A,num):"Return new sorted list with `num` shallow copies of values.\n\n        ``sl.id9(num)`` <==> ``sl * num``\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> sl = SortedList('abc')\n        >>> sl * 3\n        SortedList(['a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'])\n\n        :param int num: count of shallow copies\n        :return: new sorted list\n\n        ";B=G(F,A._lists,[])*num;return A.__class__(B)
    id4=id9
    def id17(A,num):"Update the sorted list with `num` shallow copies of values.\n\n        ``sl.id17(num)`` <==> ``sl *= num``\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> sl = SortedList('abc')\n        >>> sl *= 3\n        >>> sl\n        SortedList(['a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'])\n\n        :param int num: count of shallow copies\n        :return: existing sorted list\n\n        ";B=G(F,A._lists,[])*num;A._clear();A._update(B);return A
    def id33(B,symbol,doc):
        'Make comparator method.'
        def C(self,other):
            'Compare method for sorted list and sequence.';C=other
            if not b(C,Sequence):return NotImplemented
            D=self._len;E=A(C)
            if D!=E:
                if B is eq:return K
                if B is ne:return I
            for (F,G) in zip(self,C):
                if F!=G:return B(F,G)
            return B(D,E)
        D=B.__name__;C.__name__='__{0}__'.format(D);E='Return true if and only if sorted list is {0} `other`.\n\n        ``sl.__{1}__(other)`` <==> ``sl {2} other``\n\n        Comparisons use lexicographical order as with sequences.\n\n        Runtime complexity: `O(n)`\n\n        :param other: `other` sequence\n        :return: true if sorted list is {0} `other`\n\n        ';C.__doc__=f(E.format(doc,D,symbol));return C
    id8=id33(eq,'==','equal to');id16=id33(ne,'!=','not equal to');id31=id33(lt,'<','less than');id14=id33(gt,'>','greater than');id24=id33(le,'<=','less than or equal to');id32=id33(ge,'>=','greater than or equal to');id33=staticmethod(id33)
    def id23(A):B=G(F,A._lists,[]);return S(A),(B,)
    @W()
    def id12(self):'Return string representation of sorted list.\n\n        ``sl.id12()`` <==> ``repr(sl)``\n\n        :return: string representation\n\n        ';return '{0}({1!r})'.format(S(self).__name__,N(self))
    def _check(B):
        'Check invariants of sorted list.\n\n        Runtime complexity: `O(n)`\n\n        '
        try:
            assert B._load>=4;assert A(B._maxes)==A(B._lists);assert B._len==j((A(C)for C in B._lists))
            for G in B._lists:
                for E in C(1,A(G)):assert G[E-1]<=G[E]
            for E in C(1,A(B._lists)):assert B._lists[E-1][-1]<=B._lists[E][0]
            for E in C(A(B._maxes)):assert B._maxes[E]==B._lists[E][-1]
            H=B._load<<1;assert k((A(C)<=H for C in B._lists));I=B._load>>1
            for E in C(0,A(B._lists)-1):assert A(B._lists[E])>=I
            if B._index:
                assert B._len==B._index[0];assert A(B._index)==B._offset+A(B._lists)
                for E in C(A(B._lists)):J=B._index[B._offset+E];assert J==A(B._lists[E])
                for E in C(B._offset):
                    F=(E<<1)+1
                    if F>=A(B._index):assert B._index[E]==0
                    elif F+1==A(B._index):assert B._index[E]==B._index[F]
                    else:K=B._index[F]+B._index[F+1];assert K==B._index[E]
        except:T.print_exc(file=sys.stdout);D(m,B._len);D(n,B._load);D(o,B._offset);D(p,A(B._index));D(q,B._index);D(r,A(B._maxes));D(s,B._maxes);D(t,A(B._lists));D(u,B._lists);raise
def Y(value):'Identity function.';return value
class Z(X):
    'Sorted-key list is a subtype of sorted list.\n\n    The sorted-key list maintains values in comparison order based on the\n    result of a key function applied to every value.\n\n    All the same methods that are available in :class:`SortedList` are also\n    available in :class:`SortedKeyList`.\n\n    Additional methods provided:\n\n    * :attr:`SortedKeyList.key`\n    * :func:`SortedKeyList.id19`\n    * :func:`SortedKeyList.id27`\n    * :func:`SortedKeyList.id25`\n\n    Some examples below use:\n\n    >>> from operator import neg\n    >>> neg\n    <built-in function neg>\n    >>> neg(1)\n    -1\n\n    '
    def __init__(A,iterable=B,key=Y):
        "Initialize sorted-key list instance.\n\n        Optional `iterable` argument provides an initial iterable of values to\n        initialize the sorted-key list.\n\n        Optional `key` argument defines a callable that, like the `key`\n        argument to Python's `sorted` function, extracts a comparison key from\n        each value. The default is the identity function.\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList(key=neg)\n        >>> skl\n        SortedKeyList([], key=<built-in function neg>)\n        >>> skl = SortedKeyList([3, 1, 2], key=neg)\n        >>> skl\n        SortedKeyList([3, 2, 1], key=<built-in function neg>)\n\n        :param iterable: initial values (optional)\n        :param key: function used to extract comparison key (optional)\n\n        ";C=iterable;A._key=key;A._len=0;A._load=A.id2;A._lists=[];A._keys=[];A._maxes=[];A._index=[];A._offset=0
        if C is not B:A._update(C)
    def id7(A,iterable=B,key=Y):return object.id7(A)
    @h
    def key(self):'Function used to extract comparison key from values.';return self._key
    def clear(A):'Remove all values from sorted-key list.\n\n        Runtime complexity: `O(n)`\n\n        ';A._len=0;del A._lists[:];del A._keys[:];del A._maxes[:];del A._index[:]
    _clear=clear
    def add(D,value):
        'Add `value` to sorted-key list.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList(key=neg)\n        >>> skl.add(3)\n        >>> skl.add(1)\n        >>> skl.add(2)\n        >>> skl\n        SortedKeyList([3, 2, 1], key=<built-in function neg>)\n\n        :param value: value to add to sorted-key list\n\n        ';F=value;H=D._lists;G=D._keys;E=D._maxes;C=D._key(F)
        if E:
            B=id21(E,C)
            if B==A(E):B-=1;H[B].append(F);G[B].append(C);E[B]=C
            else:I=id21(G[B],C);H[B].insert(I,F);G[B].insert(I,C)
            D._expand(B)
        else:H.append([F]);G.append([C]);E.append(C)
        D._len+=1
    def _expand(C,pos):
        'Split sublists with length greater than double the load-factor.\n\n        Updates the index when the sublist length is less than double the load\n        level. This requires incrementing the nodes in a traversal from the\n        leaf node to the root. For an example traversal see\n        ``SortedList._loc``.\n\n        ';B=pos;I=C._lists;G=C._keys;D=C._index
        if A(G[B])>C._load<<1:J=C._maxes;E=C._load;K=I[B];H=G[B];M=K[E:];L=H[E:];del K[E:];del H[E:];J[B]=H[-1];I.insert(B+1,M);G.insert(B+1,L);J.insert(B+1,L[-1]);del D[:]
        elif D:
            F=C._offset+B
            while F:D[F]+=1;F=F-1>>1
            D[0]+=1
    def update(B,iterable):
        'Update sorted-key list by adding all values from `iterable`.\n\n        Runtime complexity: `O(k*log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList(key=neg)\n        >>> skl.update([3, 1, 2])\n        >>> skl\n        SortedKeyList([3, 2, 1], key=<built-in function neg>)\n\n        :param iterable: iterable of values to add\n\n        ';E=B._lists;H=B._keys;I=B._maxes;D=i(iterable,key=B._key)
        if I:
            if A(D)*4>=B._len:E.append(D);D=G(F,E,[]);D.sort(key=B._key);B._clear()
            else:
                K=B.add
                for L in D:K(L)
                return
        J=B._load;E.extend((D[B:B+J]for B in C(0,A(D),J)));H.extend((N(map(B._key,A))for A in E));I.extend((A[-1]for A in H));B._len=A(D);del B._index[:]
    _update=update
    def id13(E,value):
        'Return true if `value` is an element of the sorted-key list.\n\n        ``skl.id13(value)`` <==> ``value in skl``\n\n        Runtime complexity: `O(log(n))`\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([1, 2, 3, 4, 5], key=neg)\n        >>> 3 in skl\n        True\n\n        :param value: search for value in sorted-key list\n        :return: true if `value` in sorted-key list\n\n        ';H=value;F=E._maxes
        if not F:return K
        G=E._key(H);B=id3(F,G)
        if B==A(F):return K
        L=E._lists;C=E._keys;D=id3(C[B],G);M=A(C);J=A(C[B])
        while I:
            if C[B][D]!=G:return K
            if L[B][D]==H:return I
            D+=1
            if D==J:
                B+=1
                if B==M:return K
                J=A(C[B]);D=0
    def discard(D,value):
        'Remove `value` from sorted-key list if it is a member.\n\n        If `value` is not a member, do nothing.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([5, 4, 3, 2, 1], key=neg)\n        >>> skl.discard(1)\n        >>> skl.discard(0)\n        >>> skl == [5, 4, 3, 2]\n        True\n\n        :param value: `value` to discard from sorted-key list\n\n        ';H=value;F=D._maxes
        if not F:return
        G=D._key(H);B=id3(F,G)
        if B==A(F):return
        K=D._lists;E=D._keys;C=id3(E[B],G);L=A(E);J=A(E[B])
        while I:
            if E[B][C]!=G:return
            if K[B][C]==H:D._delete(B,C);return
            C+=1
            if C==J:
                B+=1
                if B==L:return
                J=A(E[B]);C=0
    def remove(F,value):
        'Remove `value` from sorted-key list; `value` must be a member.\n\n        If `value` is not a member, raise ValueError.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([1, 2, 3, 4, 5], key=neg)\n        >>> skl.remove(5)\n        >>> skl == [4, 3, 2, 1]\n        True\n        >>> skl.remove(0)\n        Traceback (most recent call last):\n          ...\n        ValueError: 0 not in list\n\n        :param value: `value` to remove from sorted-key list\n        :raises ValueError: if `value` is not in sorted-key list\n\n        ';C=value;H=F._maxes
        if not H:raise E(O.format(C))
        J=F._key(C);B=id3(H,J)
        if B==A(H):raise E(O.format(C))
        L=F._lists;G=F._keys;D=id3(G[B],J);M=A(G);K=A(G[B])
        while I:
            if G[B][D]!=J:raise E(O.format(C))
            if L[B][D]==C:F._delete(B,D);return
            D+=1
            if D==K:
                B+=1
                if B==M:raise E(O.format(C))
                K=A(G[B]);D=0
    def _delete(C,pos,idx):
        'Delete value at the given `(pos, idx)`.\n\n        Combines lists that are less than half the load level.\n\n        Updates the index when the sublist length is more than half the load\n        level. This requires decrementing the nodes in a traversal from the\n        leaf node to the root. For an example traversal see\n        ``SortedList._loc``.\n\n        :param int pos: lists index\n        :param int idx: sublist index\n\n        ';B=pos;E=C._lists;D=C._keys;F=C._maxes;G=C._index;I=D[B];L=E[B];del I[idx];del L[idx];C._len-=1;K=A(I)
        if K>C._load>>1:
            F[B]=I[-1]
            if G:
                J=C._offset+B
                while J>0:G[J]-=1;J=J-1>>1
                G[0]-=1
        elif A(D)>1:
            if not B:B+=1
            H=B-1;D[H].extend(D[B]);E[H].extend(E[B]);F[H]=D[H][-1];del E[B];del D[B];del F[B];del G[:];C._expand(H)
        elif K:F[B]=I[-1]
        else:del E[B];del D[B];del F[B];del G[:]
    def irange(A,minimum=B,maximum=B,inclusive=(I,I),reverse=K):'Create an iterator of values between `minimum` and `maximum`.\n\n        Both `minimum` and `maximum` default to `None` which is automatically\n        inclusive of the beginning and end of the sorted-key list.\n\n        The argument `inclusive` is a pair of booleans that indicates whether\n        the minimum and maximum ought to be included in the range,\n        respectively. The default is ``(True, True)`` such that the range is\n        inclusive of both minimum and maximum.\n\n        When `reverse` is `True` the values are yielded from the iterator in\n        reverse order; `reverse` defaults to `False`.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([11, 12, 13, 14, 15], key=neg)\n        >>> it = skl.irange(14.5, 11.5)\n        >>> list(it)\n        [14, 13, 12]\n\n        :param minimum: minimum value to start iterating\n        :param maximum: maximum value to stop iterating\n        :param inclusive: pair of booleans\n        :param bool reverse: yield values in reverse order\n        :return: iterator\n\n        ';D=maximum;C=minimum;E=A._key(C)if C is not B else B;F=A._key(D)if D is not B else B;return A.id6(min_key=E,max_key=F,inclusive=inclusive,reverse=reverse)
    def id25(K,min_key=B,max_key=B,inclusive=(I,I),reverse=K):
        'Create an iterator of values between `min_key` and `max_key`.\n\n        Both `min_key` and `max_key` default to `None` which is automatically\n        inclusive of the beginning and end of the sorted-key list.\n\n        The argument `inclusive` is a pair of booleans that indicates whether\n        the minimum and maximum ought to be included in the range,\n        respectively. The default is ``(True, True)`` such that the range is\n        inclusive of both minimum and maximum.\n\n        When `reverse` is `True` the values are yielded from the iterator in\n        reverse order; `reverse` defaults to `False`.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([11, 12, 13, 14, 15], key=neg)\n        >>> it = skl.id25(-14, -12)\n        >>> list(it)\n        [14, 13, 12]\n\n        :param min_key: minimum key to start iterating\n        :param max_key: maximum key to stop iterating\n        :param inclusive: pair of booleans\n        :param bool reverse: yield values in reverse order\n        :return: iterator\n\n        ';M=inclusive;I=max_key;G=min_key;D=K._maxes
        if not D:return H(())
        E=K._keys
        if G is B:F=0;L=0
        elif M[0]:
            F=id3(D,G)
            if F==A(D):return H(())
            L=id3(E[F],G)
        else:
            F=id21(D,G)
            if F==A(D):return H(())
            L=id21(E[F],G)
        if I is B:C=A(D)-1;J=A(E[C])
        elif M[1]:
            C=id21(D,I)
            if C==A(D):C-=1;J=A(E[C])
            else:J=id21(E[C],I)
        else:
            C=id3(D,I)
            if C==A(D):C-=1;J=A(E[C])
            else:J=id3(E[C],I)
        return K._islice(F,L,C,J,reverse)
    id6=id25
    def id3(A,value):'Return an index to insert `value` in the sorted-key list.\n\n        If the `value` is already present, the insertion point will be before\n        (to the left of) any existing values.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([5, 4, 3, 2, 1], key=neg)\n        >>> skl.id3(1)\n        4\n\n        :param value: insertion index of value in sorted-key list\n        :return: index\n\n        ';return A.id30(A._key(value))
    def id21(A,value):'Return an index to insert `value` in the sorted-key list.\n\n        Similar to `id3`, but if `value` is already present, the\n        insertion point will be after (to the right of) any existing values.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedList([5, 4, 3, 2, 1], key=neg)\n        >>> skl.id21(1)\n        5\n\n        :param value: insertion index of value in sorted-key list\n        :return: index\n\n        ';return A.id28(A._key(value))
    bisect=id21
    def id19(B,key):
        'Return an index to insert `key` in the sorted-key list.\n\n        If the `key` is already present, the insertion point will be before (to\n        the left of) any existing keys.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([5, 4, 3, 2, 1], key=neg)\n        >>> skl.id19(-1)\n        4\n\n        :param key: insertion index of key in sorted-key list\n        :return: index\n\n        ';C=B._maxes
        if not C:return 0
        D=id3(C,key)
        if D==A(C):return B._len
        E=id3(B._keys[D],key);return B._loc(D,E)
    id30=id19
    def id27(B,key):
        'Return an index to insert `key` in the sorted-key list.\n\n        Similar to `id19`, but if `key` is already present, the\n        insertion point will be after (to the right of) any existing keys.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedList([5, 4, 3, 2, 1], key=neg)\n        >>> skl.id27(-1)\n        5\n\n        :param key: insertion index of key in sorted-key list\n        :return: index\n\n        ';C=B._maxes
        if not C:return 0
        D=id21(C,key)
        if D==A(C):return B._len
        E=id21(B._keys[D],key);return B._loc(D,E)
    id15=id27;id28=id27
    def count(E,value):
        'Return number of occurrences of `value` in the sorted-key list.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([4, 4, 4, 4, 3, 3, 3, 2, 2, 1], key=neg)\n        >>> skl.count(2)\n        2\n\n        :param value: value to count in sorted-key list\n        :return: count\n\n        ';J=value;F=E._maxes
        if not F:return 0
        G=E._key(J);B=id3(F,G)
        if B==A(F):return 0
        L=E._lists;C=E._keys;D=id3(C[B],G);H=0;M=A(C);K=A(C[B])
        while I:
            if C[B][D]!=G:return H
            if L[B][D]==J:H+=1
            D+=1
            if D==K:
                B+=1
                if B==M:return H
                K=A(C[B]);D=0
    def copy(A):'Return a shallow copy of the sorted-key list.\n\n        Runtime complexity: `O(n)`\n\n        :return: new sorted-key list\n\n        ';return A.__class__(A,key=A._key)
    id5=copy
    def index(H,value,start=B,stop=B):
        'Return first index of value in sorted-key list.\n\n        Raise ValueError if `value` is not present.\n\n        Index must be between `start` and `stop` for the `value` to be\n        considered present. The default value, None, for `start` and `stop`\n        indicate the beginning and end of the sorted-key list.\n\n        Negative indices are supported.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([5, 4, 3, 2, 1], key=neg)\n        >>> skl.index(2)\n        3\n        >>> skl.index(0)\n        Traceback (most recent call last):\n          ...\n        ValueError: 0 is not in list\n\n        :param value: value in sorted-key list\n        :param int start: start index (default None, start of sorted-key list)\n        :param int stop: stop index (default None, end of sorted-key list)\n        :return: index of value\n        :raises ValueError: if value is not present\n\n        ';G=start;F=value;C=stop;J=H._len
        if not J:raise E(L.format(F))
        if G is B:G=0
        if G<0:G+=J
        if G<0:G=0
        if C is B:C=J
        if C<0:C+=J
        if C>J:C=J
        if C<=G:raise E(L.format(F))
        P=H._maxes;N=H._key(F);D=id3(P,N)
        if D==A(P):raise E(L.format(F))
        C-=1;R=H._lists;M=H._keys;K=id3(M[D],N);S=A(M);Q=A(M[D])
        while I:
            if M[D][K]!=N:raise E(L.format(F))
            if R[D][K]==F:
                O=H._loc(D,K)
                if G<=O<=C:return O
                elif O>C:break
            K+=1
            if K==Q:
                D+=1
                if D==S:raise E(L.format(F))
                Q=A(M[D]);K=0
        raise E(L.format(F))
    def id1(A,other):'Return new sorted-key list containing all values in both sequences.\n\n        ``skl.id1(other)`` <==> ``skl + other``\n\n        Values in `other` do not need to be in sorted-key order.\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> from operator import neg\n        >>> skl1 = SortedKeyList([5, 4, 3], key=neg)\n        >>> skl2 = SortedKeyList([2, 1, 0], key=neg)\n        >>> skl1 + skl2\n        SortedKeyList([5, 4, 3, 2, 1, 0], key=<built-in function neg>)\n\n        :param other: other iterable\n        :return: new sorted-key list\n\n        ';B=G(F,A._lists,[]);B.extend(other);return A.__class__(B,key=A._key)
    id11=id1
    def id9(A,num):'Return new sorted-key list with `num` shallow copies of values.\n\n        ``skl.id9(num)`` <==> ``skl * num``\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> from operator import neg\n        >>> skl = SortedKeyList([3, 2, 1], key=neg)\n        >>> skl * 2\n        SortedKeyList([3, 3, 2, 2, 1, 1], key=<built-in function neg>)\n\n        :param int num: count of shallow copies\n        :return: new sorted-key list\n\n        ';B=G(F,A._lists,[])*num;return A.__class__(B,key=A._key)
    def id23(A):B=G(F,A._lists,[]);return S(A),(B,A.key)
    @W()
    def id12(self):'Return string representation of sorted-key list.\n\n        ``skl.id12()`` <==> ``repr(skl)``\n\n        :return: string representation\n\n        ';A=self;B=S(A).__name__;return '{0}({1!r}, key={2!r})'.format(B,N(A),A._key)
    def _check(B):
        'Check invariants of sorted-key list.\n\n        Runtime complexity: `O(n)`\n\n        '
        try:
            assert B._load>=4;assert A(B._maxes)==A(B._lists)==A(B._keys);assert B._len==j((A(C)for C in B._lists))
            for G in B._keys:
                for E in C(1,A(G)):assert G[E-1]<=G[E]
            for E in C(1,A(B._keys)):assert B._keys[E-1][-1]<=B._keys[E][0]
            for (H,I) in zip(B._lists,B._keys):
                assert A(H)==A(I)
                for (J,K) in zip(H,I):assert B._key(J)==K
            for E in C(A(B._maxes)):assert B._maxes[E]==B._keys[E][-1]
            L=B._load<<1;assert k((A(C)<=L for C in B._lists));M=B._load>>1
            for E in C(0,A(B._lists)-1):assert A(B._lists[E])>=M
            if B._index:
                assert B._len==B._index[0];assert A(B._index)==B._offset+A(B._lists)
                for E in C(A(B._lists)):N=B._index[B._offset+E];assert N==A(B._lists[E])
                for E in C(B._offset):
                    F=(E<<1)+1
                    if F>=A(B._index):assert B._index[E]==0
                    elif F+1==A(B._index):assert B._index[E]==B._index[F]
                    else:O=B._index[F]+B._index[F+1];assert O==B._index[E]
        except:T.print_exc(file=sys.stdout);D(m,B._len);D(n,B._load);D(o,B._offset);D(p,A(B._index));D(q,B._index);D(r,A(B._maxes));D(s,B._maxes);D('len_keys',A(B._keys));D('keys',B._keys);D(t,A(B._lists));D(u,B._lists);raise
v=Z

import sys
sys.setrecursionlimit(100000)

def _r(): return sys.stdin.buffer.readline()
def rs(): return _r().decode('ascii').strip()
def rn(): return int(_r())
def rnt(): return map(int, _r().split())
def rnl(): return list(rnt())



def solve(n, a):
    d = X()
    total = 0
    for x in a:
        l = d.id3(x)
        r = d.id21(x)
        total += min(l, len(d) - r)
        d.add(x)
    return total

for _ in range(rn()):
    n = rn()
    a = rnl()
    print(solve(n, a))