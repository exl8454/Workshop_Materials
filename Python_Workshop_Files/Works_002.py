# Python 2.X workshop
# File: Works_002.py
# Data conversion and arithmetic operators

# Sometimes you need to convert from one type to other...
c = "6"

# To convert string to integer, use built in function...
c = int(c) # Converts c into base of 10 integer
print c, " is now an int"

# To convert string to long, use built in function...
c = long(c) # Converts c into base of 10 long type
print c, " is now a long"

# To convert string to float, use built in function...
c = float(c) # Converts c into base of 10 floating type
print c, " is now a float"

# Of course if you want to convert any object into a string...
c = str(c)
print c, " is now a string"

# Just like any other programming languages, Python supports basic
# Arithmatic functions
a = 10.0
b = 12.0
result = 0

print # This will print empty line
print "a:",a," b:",b
result = a + b
print "a + b: ", result
result = a - b
print "a - b: ", result
result = a * b
print "a * b: ", result
result = a / b
print "a / b: ", result

# Modulus is also available!
result = b % a
print "b % a: ", result
# Exponent is available in Python
result = a ** b
print "a ^ b: ", result
# Python also has floor division. This simply means Python will floor
# Any value after decimal points.
result = a // b
print "a // b: ", result
print # This will print empty line

# Python performs arithmatic operation by following order
# Multiply, divide, modulo and floor division
# Addition and subtraction
a = 7
b = 3
c = 2

result = a + b * c # What will be the result?
print "a + b * c:", result
result = (a + b) * c # How about this?
print "(a + b) * c:", result

# Go to Works_002_Exercise
