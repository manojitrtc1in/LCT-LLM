

subtests = int(input())
for subtest in range(subtests):
    n = int(input())
    s = input()
    cnt, ans = 0, 0
    for i in s:
        if i == ')':
            cnt -= 1
            if cnt < 0:
                cnt = 0
                ans += 1
        else: cnt += 1
    print(ans)
    
    
    
        
    
            
    
    
        