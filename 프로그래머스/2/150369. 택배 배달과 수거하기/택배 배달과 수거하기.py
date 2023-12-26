import sys
sys.setrecursionlimit(10**6)

def count(cap,idx,l,Max):
    nextIdx=-1
    now=0
    for i in range(idx,-1,-1):
        if l[i]==0: 
            continue
        if now+l[i]<cap:
            now+=l[i]
            if Max==-1:
                Max=i+1
            continue
        elif now+l[i]>cap: 
            remain=cap-now
            now=cap
            l[i]-=remain 
            if Max==-1:
                Max=i+1 
            nextIdx=i 
            break
        else:
            now=cap
            if Max==-1:
                Max=i+1
            nextIdx=i-1
            while l[nextIdx]==0:
                nextIdx-=1;
            break
    return [Max,nextIdx]

def find(cap,n,D,P):
    global total,d,p
    
    dmax=-1
    if D>=0:
        [dmax,D]=count(cap,D,d,dmax)
    
    pmax=-1
    if P>=0:
        [pmax,P]=count(cap,P,p,pmax)
    
    if pmax!=-1 or dmax!=-1: # 배달 혹은 수거를 했다면
        total+=max(pmax,dmax)*2
    
    if D>=0 or P>=0: # 배달 혹은 수거할 것이 남아있다면
        find(cap,n,D,P)
        
def sol(n):
    global total,d,p
    idx_d=n-1
    idx_p=n-1
    
    while idx_d>=0 or idx_p>=0:
        [max_d,idx_d] = remove(d,idx_d)
        [max_p,idx_p] = remove(p,idx_p)
        total += max(max_d, max_p)
        #print(max_d,max_p,total)
    
    return total
        
def remove(arr,idx):
    max_idx = -1
    for i in range(idx, -1, -1):
        if arr[i] > 0:
            max_idx = i
            arr[i]-=1
            break
    return [(max_idx+1)*2,max_idx]
   

def solution(cap, n, deliveries, pickups):
    global total,d,p
    total=0
    d = deliveries
    p = pickups
    if cap==1:
        sol(n)
    else:
        find(cap,n,n-1,n-1)
    return total