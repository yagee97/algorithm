
n = int(input())
p = list(map(int, input().split()))
total = [0] * (n+1)


for i in range(1,n+1):
    for j in range(1,i+1):
        total[i] = max(total[i],total[i-j]+p[j-1])

print(total[n])