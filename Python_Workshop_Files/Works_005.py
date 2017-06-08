# Python 2.X workshop
# File: Works_005.py
# Logical, membership, and identity operators

# Logical operator operates by comparing and negating values
a = True
b = False
c = True
# Suppose you need to check if two values are true
print "a and b:", a and b # This prints out false since b is false
print "a and c:", a and c # This prints out true since a and c are both true
print # This will print out empty line

# Suppose you need to check if at least one value is true
print "a or b:", a or b # This prints out true since a is true
print "a ro c:", a or c # This prints out true since both values are true
print # This will print out empty line

# Suppose you need to negate one value and compare
print "a and not(c):", a and not(c) # This prints out false since c is negated as false
print "a and not(b):", a and not(b) # This prints out true since b is negated as true
print "not(a and b):", not(a and b) # This prints out true since (a and b) is negated
print # This will print out empty line

# Membership operator checks if a given value is within a list
a = 10
aList = [1, 2, 3, 4, 5];
# To check if a value is within a list
if a in aList:
    print "a is in the list"
else:
    print "a is not in the list"

a = 3
if a in aList:
    print "a is in the list"
else:
    print "a is not in the list"

print # This will print out empty line

# To check if a value is not in a list
a = 10
if a not in aList:
    print "a is not in the list"
else:
    print "a is in the list"

a = 3
if a not in aList:
    print "a is not in the list"
else:
    print "a is in the list"

print # This will print out empty line

# Identity operator checks memory location of two objects
a = 10
b = 20
print id(a), a
print id(b), b

# To check if two variables points to same memory location...
if a is b:
    print "a and b points same memory"
else:
    print "a and b points different memory"

print # This will print out empty line

b = 10
print id(a), a
print id(b), b
if a is b:
    print "a and b points same memory"
else:
    print "a and b points different memory"

print # This will print out empty line
# to check if two variables points to different memory location...
a = 10
b = 20
print id(a), a
print id(b), b
if a is not b:
    print "a and b points different memory"
else:
    print "a and b points same memomry"

# Go to Works_Try_001
