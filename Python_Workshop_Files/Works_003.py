# Python 2.X workshop
# File: Works_003.py
# Comparison and assignment operators

a = 10
b = 15
c = 10
print "a =", a, "b =", b, "c =", c
# Python supports various comparison operators
# To check if two values are equal...
print "a == b ?", (a == b)
print "a == c ?", (a == c)
# To check if two values are NOT equal...
print "a != b ?", (a != b)
print "a != c ?", (a != c)
# To check if one value is greater than other...
print "a > b ?", (a > b)
print "a > c ?", (a > c)
print "b > c ?", (b > c)
# To check if one value is less than other...
print "a < b ?", (a < b)
print "a < c ?", (a < c)
print "b < c ?", (b < c)
# To check if one value is greater than or equal to other...
print "a >= b ?", (a >= b)
print "a >= c ?", (a >= c)
print "b >= c ?", (b >= c)
# To check if one value is less than or equal to other...
print "a <= b ?", (a <= b)
print "a <= c ?", (a <= c)
print "b <= c ?", (b <= c)

# Python has various assignment operators
# With basic assignment type
name = "John"
age = 20
# Say you want to add one to age
age = age + 1 # We can do this, but we can make it shorter
# This is called ADD AND
# This adds right operand to left operand, then assign result
# to left operand
age += 1
# You can also perform SUBTRACT AND
age -= 1
# MULTIPLY AND
age *= 2
# DIVIDE AND
age /= 2
# MODULUS AND
age %= 100
# In Python, you can also do EXPONENT AND
age **= 1
# And FLOOD DIV AND
age //= 1
