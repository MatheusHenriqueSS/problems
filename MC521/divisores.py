a,b,c,d=[int(x) for x in  input().split()]
div=[1,c]
def divisores():

    i=2
    while i*i<=c:
        if c%i==0:
            div.append(i)
            div.append(c//i)

        i+=1
    div.sort()
    return div
divisores()

def teste():
    for i in div:
        if i%a==0 and i%b!=0 and d%i!=0:
            return i
    return -1
print(teste())
