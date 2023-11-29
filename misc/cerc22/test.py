import math
a = int(input())
b = int(input())
for n in range(1, 100):
  if n % a == 0 and (n + 1) % b == 0:
    print("first", n, n / a + (n + 1) / b)
  if n % b == 0 and (n + 1) % a == 0:
    print("sec", n, n / b + (n + 1) / a)