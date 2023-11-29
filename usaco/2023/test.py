def f(base, year):
  cur = base
  for i in range(year):
    cur = cur + cur * 0.1 + base

  return cur

print(f(20000, 15))