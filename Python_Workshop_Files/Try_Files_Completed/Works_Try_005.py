# Python 2.7.X
# Try_005.py
# Functions (2)

# Objective: Create a recursive function to find
# exponents
# With give a and b, perform a^b using recursive function
# Print out the result after.

a = 2
b = 8
result = 0

# Write your code here
def doExp(a, b):
    if(b == 0):
        return 1
    else:
        return a * doExp(a, b - 1)

result = doExp(a, b)
print "A ^ B:", result
