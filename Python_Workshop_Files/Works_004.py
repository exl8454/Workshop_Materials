# Python 2.X workshop
# File: Works_004.py
# Bitwise operators

# Bitwise operators are VERY IMPORTANT in microprocessor programming
# Which means this part will be crucial part before we move onto
# Arduino and beyond

# Let's assign two variables first, in binary format
a = 0b00111100 # Value of 60
b = 0b00001111 # Value of 15

# Note that Python will remove any leading zeros when print binary
print bin(a), a
print bin(b), b
print # This will print out empty line

# Bitwise Operator 1
# BITWISE AND (&)
#   A   B   A&B
#   0   0   0
#   1   0   0
#   0   1   0
#   1   1   1
c = (a & b) # What this will print out?
# 0 0 1 1 1 1 0 0
# 0 0 0 0 1 1 1 1 &
# ---------------
# 0 0 0 0 1 1 0 0
print "a & b", bin(c), c
print # This will print out empty line

# Bitwise Operator 2
# BITWISE OR (|)
#   A   B   A|B
#   0   0   0
#   1   0   1
#   0   1   1
#   1   1   1
c = (a | b) # What this will print out?
# 0 0 1 1 1 1 0 0
# 0 0 0 0 1 1 1 1 |
# ---------------
# 0 0 1 1 1 1 1 1
print "a | b", bin(c), c
print # This will print out empty line

# Bitwise Operator 3
# BITWISE XOR (^)
#   A   B   A^B
#   0   0   0
#   1   0   1
#   0   1   1
#   1   1   0
c = (a ^ b) # What this will print out?
# 0 0 1 1 1 1 0 0
# 0 0 0 0 1 1 1 1 ^
# ---------------
# 0 0 1 1 0 0 1 1
print "a ^ b", bin(c), c
print # This will print out empty line

# Bitwise Operator 4
# BITWISE ONES COMPLEMENT (~)
#   A   ~A
#   0   1 
#   1   0  
c = ~a # What this will print out?
# 0 0 1 1 1 1 0 0 ~
# ---------------
# 1 1 0 0 0 0 1 1
print "~a", bin(c), c
print # This will print out empty line
c = ~b
print "~b", bin(c), c
print # This will print out empty line
# But it's suppose to be 195??
# This is because Python takes ones complement into two's complement
# So 1 1 0 0 0 0 1 1 becomes 0 0 1 1 1 1 0 1
# And convert from unsigned to signed

# Bitwise Operator 5
# BITWISE LEFT SHIFT (<<)
# Simply moves bits by given on right operand
c = a << 2 # What this will print out?
# 0 0 1 1 1 1 0 0 << 2
# 1 1 1 1 0 0 0 0
print "c = a << 2", bin(c), c
print # This will print out empty line

# Bitwise Operator 6
# BITWISE RIGHT SHIFT (>>)
# Simply moves bits by given on right operand
c = b >> 2 # What this will print out?
# 0 0 0 0 1 1 1 1 >> 2
# 0 0 0 0 0 0 1 1
print "c = b >> 2", bin(c), c
print # This will print out empty line
