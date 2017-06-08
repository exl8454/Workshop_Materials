def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mul(a, b):
    return a * b

def div(a, b):
    return a / b

def exp(a, b):
    if(b == 0):
        return 1
    else:
        return a * exp(a, b - 1)
