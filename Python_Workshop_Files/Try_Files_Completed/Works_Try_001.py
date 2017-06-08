# Python 2.7.X
# Try_001.py
# Modifying the quadratic equation

# Continuing with quadratic equation, modify your code
# So it can check with imaginary numbers
# If 4 * a * c is negative, program must let user know
# quadratic equation is unsolvable

import math

a = 5.0
b = 2.0
c = 10.0

# Write your code here
if ((b**2) - 4 * a * c) < 0:
    print "This quadratic function cannot be solved!"
else:
    result = -b + math.sqrt((b**2) - 4 * a * c) / (2 * a)
    print "-b + sqrt((b**2) - 4 * a * c) / (2 * a) is", result
    result = -b - math.sqrt((b**2) - 4 * a * c) / (2 * a)
    print "-b - sqrt((b**2) - 4 * a * c) / (2 * a) is", result
