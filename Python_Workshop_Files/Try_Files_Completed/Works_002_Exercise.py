# Python 2.x Workshop
# File: Works_002_Exercise.py
# Refer to Works_002.py for reference

# Lets start with arithmetic operators first...
a = 5
b = 7
result = 0

# 1. Add a and b, save the result to result variable, then print out the result.
result = a + b
print "a + b:", result

# 2. Do rest for subtraction, multiplication, and division!
result = a - b
print "a - b:", result
result = a * b
print "a * b:", result
result = a / b
print "a / b:", result

# 3. Notice a / b gives you 0. This is because both variables are integer type
# So try changing variables type into float
a = float(a)
b = float(b)

# Try division again
result = a / b
print "a / b:", result

# From here, try doing modulus and exponent!
result = a % b
print "a % b:", result
result = a ** b
print "a ^ b:", result

# Go to Works_Try_000.py
