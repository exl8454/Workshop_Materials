# Python 2.X workshop
# File: Works_008.py
# Functions

# Functions in Python is similar to other programming languages
# You can set return type, name of a function, and parameters for function
# Stating no return value is equal to not returning anything
def addNumber(a, b):
    print "def addNumber(a, b)"
    return a + b

def addNumberThenPrint(a, b):
    print "def addNumberThenPrint(a, b)"
    result = a + b
    print "a + b: ", result
    return

a = 5
b = 3
c = addNumber(a, b)
print "a + b: ", c
print # This will print out empty line

a = 10
b = 5
addNumberThenPrint(a, b)
print # This will print out empty line

# Question is; is functions in Python pass by reference or value?
# To test this...
def passByRefTest(a, b):
    print "Pass by reference test with list"
    while a[0] > b:
        a[0] -= 1
        print a[0]
    return

def passByRefTest2(a, b):
    print "Pass by reference test with primitive data type"
    while a > b:
        a -= 1
        print a
    return

a = [10]
b = 3
passByRefTest(a, b)
print a
print # This will print out empty line
# So, we now know that Python passes variables as reference

# How about primitive data itself?
a = 10
b = 3
passByRefTest2(a, b)
print a
print # This will print out empty line
# Seems like primitve itself does not pass by reference!

# There are different ways of defining parameters
# Functions can have what they call default parameter
def defaultParamTest(string):
    print "def defaultParamTest(string)"
    print string
    return

# This will thrown you an error since 1 parameter must be passed down
#defaultParamTest()
defaultParamTest("Hello World!") # This works
#defaultParamTest() # This will not work
print # This will print out empty line

# To have functions have default parameter...
def defaultParamTest2(string = "Empty?"):
    print "def defaultParamTest2(string = \"Empty?\")"
    print string
    return

defaultParamTest2()
print # This will print out empty line

# Keyword parameter allows you to call functions without searching for specific
# parameter. This allows parameters to be out of order. However, parameter name
# MUST match when calling the fucntion!
def keywordFunction(string, a):
    print "def keywordFunction(string, a)"
    print string
    print a
    return
    
keywordFunction(a = 10, string = "Value:")
print # This will print out empty line

# Variable-length arguments allows parameters to have variable size.
# This is useful for taking variable size list or tuples, etc
def varlengthFunction(*aList):
    print "def varlengthFunction(*aList)"
    for value in aList:
        print value
    return

varlengthFunction('cat', 'dog', 'bird', 'fish')
print # This will print out empty line

# Anonymous function is not declared in a regular expression
# Anonymous function cannot be called directly either
print "Using LAMBDA keyword"
divTwo = lambda a, b : a / b
print "10 / 5:", divTwo(10, 5)
print # This will print out empty line

# Note the difference between local and global variables
# You can only use local variables within the function
globalVariable = 0
def multiplyTwo(a, b):
    print "def multiplyTwo(a, b)"
    return a * b
globalVariable = multiplyTwo(5, 2)
print globalVariable
print # This will print out empty line
# We will go over global variable more later on

# Go to Works_Try_004, Works_Try_005
