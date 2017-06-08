# Python 2.7.X
# Try_006.py
# Modules

# Objective: Create a new module and import it
# to this script
# Requirement 1: Create a new script called
# MyMath.py, then add 5 functions we created from
# Works_Try_004 and 005.
# Requirement 2: Using imported module, perform
# 5 functions with given variables

a = 2
b = 8

# Writer your code here
import MyMath

print "A + B:", MyMath.add(a, b)
print "A - B:", MyMath.sub(a, b)
print "A * B:", MyMath.mul(a, b)
print "A / B:", MyMath.div(a, b)
print "A ^ B:", MyMath.exp(a, b)
