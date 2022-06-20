# 3369

t=int(input())
l=[]
ini={}
for i in range(t):
    inp = input()
    ini[inp[0]] = 1
    a={}
    for s in list(inp):
        a[s] = 1
    l.append(a)

for palavra in l:
    if palavra == ini:
        print('Y')
        exit()

print("N")