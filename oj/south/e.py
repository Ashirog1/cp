import sys

maxn = 2000
a = [0] * 5005
f = [[0] * 5005 for _ in range(5005)]
pos = [0] * 5005

f[0][0] = 1
for i in range(1, maxn + 1):
    f[i][0] = f[i - 1][1]

    for j in range(1, 1001):
        f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1]

for lin in sys.stdin:
    a = list(map(int, lin.split()))
        # a = list(map(int, sys.stdin.readline().split()))

    p = a[0]

    if p == 1:
        n, k = a[1], a[2]
        # print(p,n,k)
    else:
        n = a[1]
        a = a[2:]
        for i in range(1, 2 * n + 1):
            pos[a[i - 1]] = i

    if p == 1:
        d = 0
        for i in range(1, 2*n + 1):
            pos[i] = 0

        for i in range(1, 2 * n + 1):
            if d + 1 <= n and f[2 * n - i][d + 1] >= k:
                pos[i] = 1
                d += 1
            else:
                pos[i] = -1
                if d + 1 <= n:
                    k -= f[2 * n - i][d + 1]
                d -= 1

        l = [i for i in range(1, 2 * n + 1) if pos[i] > 0]
        r = [i for i in range(1, 2 * n + 1) if pos[i] < 0]
        print(*l, sep=' ', end=' ')
        print(*r)
    else:
        d = 0
        ans = 0

        for i in range(1, 2 * n + 1):
            if pos[i] <= n:
                d += 1
            else:
                ans += f[2 * n - i][d + 1]
                d -= 1

        print(ans + 1)
