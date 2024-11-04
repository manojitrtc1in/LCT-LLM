import sys
import time
import random
import itertools, functools





def main():
    t = int(sys.stdin.readline())
    
    
    
    
    
    
    
    
    
    
    
    
    

    while t:
        t -= 1
        m = int(sys.stdin.readline())


        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        r1 = list(map(int, sys.stdin.readline().split()))
        r2 = list(map(int, sys.stdin.readline().split()))

        
        
        

        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        

        id2 = list(range(m))
        id2.sort(key=lambda i: r1[i])
        id1 = list(range(m))
        id1.sort(key=lambda i: r2[i])
        
        

        

        a = []
        total = m * 2 - 1

        
        is_same = True
        v = r1[1]
        for i in itertools.islice(r1, 1, None):
            if v != i:
                is_same = False
                break
        if is_same:
            for i in r2:
                if v != i:
                    is_same = False
                    break
        if is_same:
            print(calc_ss(m, total, r1, r2, id2, id1, id1))
            continue


        a.append(calc_ss(m, total, r1, r2, id2, id1, id1))
        a.append(calc_ss(m, total, r1, r2, id2, id1, id2, 1))
        a.append(calc_ss(m, total, r1, r2, id2, id1))
        
        
        

        if min(a) == total or a == [a[0]]*3:
            print(min(a))
            continue

        id0 = []

        for _ in range(m):
            
            id4 = id2[-1]
            id3 = id1[-1]
            if r1[id4] >= r2[id3]:
                rm_index = id4
                rm = id2
                
            else:
                rm_index = id3
                rm = id1
                
            rm.pop()

            a.append(calc_ss(m, total, r1, r2, id2, id1, rm, rm_index))
            

            if id2 and id1:
                if rm is id2:
                    v = r1[rm_index]
                    if not id0 or v != id0[-1][0]:
                        id0.append([v, []])
                    id0[-1][1].append(a[-1])
                    if (id2 and v == r1[id2[-1]]) or v == r2[id3]:
                        continue
                else:
                    v = r2[rm_index]
                    if not id0 or v != id0[-1][0]:
                        id0.append([v, []])
                    id0[-1][1].append(a[-1])
                    if (id1 and v == r2[id1[-1]]) or v == r1[id4]:
                        continue

            
            if len(id0) >= 2 and min(id0[-1][1]) > min(id0[-2][1]):
                break

            
            

            

        
        

        
        print(min(a))

def calc_ss(m, total, r1, r2, id2, id1, rm=None, rm_index=0):
    
    step = 0
    ss = 0

    while step <= total:
        
        

        start = step // 2
        

        if step:
            if step % 4 == 0 or (step - 3) % 4 == 0:
                i = r1[start]
                
                
                
            else:
                i = r2[start]
                
                
                
            ss += 1 + (i - ss if ss < i else 0)
        

        if rm is id1 and step % 4 == 0 and rm_index - 1 <= start <= rm_index:
            s = ss
            for i in itertools.islice(r1, start + 1, None):
                s += 1 + (i - s if s < i else 0)
            for i in itertools.islice(reversed(r2), 0, m - start):
                s += 1 + (i - s if s < i else 0)
            
            return s
        elif rm is id2 and step % 4 == 2 and rm_index - 1 <= start <= rm_index:
            s = ss
            for i in itertools.islice(r2, start + 1, None):
                s += 1 + (i - s if s < i else 0)
            for i in itertools.islice(reversed(r1), 0, m - start):
                s += 1 + (i - s if s < i else 0)
            
            return s

        step += 1

    return ss

        
        
        
        
        
        

        
        

        
        
        
        
        
        
        
        
        
        

        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        

        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        

        

        

        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        

        
        
        
        
        
        

        
        

        
        


main()

