n = int(input().strip())

def get(f, c1, v1):
  v1 = int(v1)
  return f + v1 if c1 == '+' else f - v1 if c1 == '-' else f * v1

f = 0
g = 0

for _ in range(n):
  c1, v1, c2, v2 = input().strip().split()

  v1, v2 = int(v1), int(v2)

  nf = max(get(f, c1, v1), get(f, c2, v2), get(g, c1, v1), get(g, c2, v2))
  ng = min(get(f, c1, v1), get(f, c2, v2), get(g, c1, v1), get(g, c2, v2))
  f, g = nf, ng


print(f)