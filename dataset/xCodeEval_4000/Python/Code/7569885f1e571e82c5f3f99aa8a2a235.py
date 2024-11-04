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

        
        
        

        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        

        r1m = list(range(m))
        r1m.sort(key=lambda i: r1[i])
        r2m = list(range(m))
        r2m.sort(key=lambda i: r2[i])
        
        

        

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
            print(calc_ss(m, total, r1, r2, r1m, r2m, r2m))
            continue


        a.append(calc_ss(m, total, r1, r2, r1m, r2m, r2m))
        a.append(calc_ss(m, total, r1, r2, r1m, r2m, r1m, 1))
        a.append(calc_ss(m, total, r1, r2, r1m, r2m))
        
        
        

        if min(a) == total or a == [a[0]]*3:
            print(min(a))
            continue

        a_per_value = []

        for _ in range(m):
            
            r1m_index = r1m[-1]
            r2m_index = r2m[-1]
            if r1[r1m_index] >= r2[r2m_index]:
                rm_index = r1m_index
                rm = r1m
                
            else:
                rm_index = r2m_index
                rm = r2m
                
            rm.pop()

            a.append(calc_ss(m, total, r1, r2, r1m, r2m, rm, rm_index))
            

            if r1m and r2m:
                if rm is r1m:
                    v = r1[rm_index]
                    if not a_per_value or v != a_per_value[-1][0]:
                        a_per_value.append([v, []])
                    a_per_value[-1][1].append(a[-1])
                    if (r1m and v == r1[r1m[-1]]) or v == r2[r2m_index]:
                        continue
                else:
                    v = r2[rm_index]
                    if not a_per_value or v != a_per_value[-1][0]:
                        a_per_value.append([v, []])
                    a_per_value[-1][1].append(a[-1])
                    if (r2m and v == r2[r2m[-1]]) or v == r1[r1m_index]:
                        continue

            
            if len(a_per_value) >= 2 and min(a_per_value[-1][1]) > min(a_per_value[-2][1]):
                break

            
            

            

        
        

        
        print(min(a))

def calc_ss(m, total, r1, r2, r1m, r2m, rm=None, rm_index=0):
    
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
        

        if rm is r2m and step % 4 == 0 and rm_index - 1 <= start <= rm_index:
            s = ss
            for i in itertools.islice(r1, start + 1, None):
                s += 1 + (i - s if s < i else 0)
            for i in itertools.islice(reversed(r2), 0, m - start):
                s += 1 + (i - s if s < i else 0)
            
            return s
        elif rm is r1m and step % 4 == 2 and rm_index - 1 <= start <= rm_index:
            s = ss
            for i in itertools.islice(r2, start + 1, None):
                s += 1 + (i - s if s < i else 0)
            for i in itertools.islice(reversed(r1), 0, m - start):
                s += 1 + (i - s if s < i else 0)
            
            return s

        step += 1

    return ss

        
        
        
        
        
        

        
        

        
        
        
        
        
        
        
        
        
        

        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        

        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        

        

        

        
        
        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        

        
        
        
        
        
        

        
        

        
        


main()

