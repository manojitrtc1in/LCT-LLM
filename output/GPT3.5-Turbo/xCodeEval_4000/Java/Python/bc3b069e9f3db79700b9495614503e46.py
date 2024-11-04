import sys

def nextInt():
    return int(next(inB))

def nextString():
    return next(inB)

def lucky(n):
    c = str(n)
    for i in range(len(c)):
        if c[i] != '4' and c[i] != '7':
            return False
    return True

def println(o):
    print(o)

def exit(o=None):
    if o is not None:
        println(o)
    sys.exit(0)

