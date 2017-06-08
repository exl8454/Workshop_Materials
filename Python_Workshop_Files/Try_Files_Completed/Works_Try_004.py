# Python 2.7.X
# Try_004.py
# Functions (1)

# Objective: To create a custom function and use it
# to do certain job(s)

# Requirement 1: Create 4 functions which will do basic
# arithmatic operation
# Requirement 2: Use variable a and b, and perform all 4
# arithmatic operations on two values, and print out the
# result
# Requirement 3: Make sure to print out values before
# printing any arithmatic operations!

a = 10
b = 5

# Write your code here
def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def div(a, b):
    return a / b

def mul(a, b):
    return a * b

print "A:", a, "B:", b
result = add(a, b); print "A + B:", result
result = sub(a, b); print "A - B:", result
result = div(a, b); print "A / B:", result
result = mul(a, b); print "A * B:", result
