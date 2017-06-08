# Python 2.X workshop
# File: Works_007.py
# Loop statemtns

# Loops basically goes through sequence over given parameters
# To start, FOR LOOP is looked
# To write FOR LOOP in Python...
print "FOR LOOP through a string"
for character in "Python":
    print character
print # This will print out empty line

# You can iterate through each elements inside a list
print "FOR LOOP for list"
aList = [0, 1, 2, 3]
for value in aList:
    print value
print # This will print out empty line

# Note that Python cannot iterate through integer itself
# However, if you need to iterate through a certain range...
print "Using range() function"
for value in range(2):
    print value
print # This will print out empty line

# Sometimes, you need to iterate through a list with unknown length.
# To iterate through specific size for a list...
print "Using len() function inside range() function"
for value in range(len(aList)):
    print aList[value]
print # This will print out empty line

# Function range can be used to iterate through integer
a = 10
print "Using range() function with limited range"
for b in range(0, a):
    print b
print # This will print out empty line

# Note that range(start, end) excludes end value
# Also note that for loop iterates in a increment of 1

# WHILE LOOP loops until given condition is met
a = 10
print "Simple conditional WHILE LOOP"
while a > 0:
    print "a:", a
    a -= 1
print # This will print out empty line

aList = ["Cats", "Dogs", "Birds", "Fish"]
b = 0
print "Second conditional WHILE LOOP"
while b < len(aList):
    print b, ":", aList[b]
    b += 1
print # This will print out empty line

# WHILE LOOP can be infinite as long as value is NOT false (0)
# To force quit from WHILE LOOP, use CTRL+C on your keyboard
#number = 0
#while 1:
    #print "number:", number
    #number += 1

# Of course you can break out of loop at certain condition
# To BREAK out of a loop
print "Using BREAK keyword in FOR LOOP"
for value in range(0,100):
    print value
    if value == 5:
        break
print # This will print out empty line

print "Using BREAK keyword in WHILE LOOP"
c = 10
while c > 0:
    print c
    c -= 1
    if c == 5:
        break
print # This will print out empty line

# You can also CONTINUE from loop statement
print "Using CONTINUE keyword in FOR LOOP"
for value in range(0, 10):
    if value == 5:
        continue
    print "Value: ", value
print # This will print out empty line

# You can PASS a statement, difference between PASS and CONTINUE is that
# PASS statemtent is a NULL block, while CONTINUE moves statement back to top
print "Using PASS keyword in FOR LOOP"
for value in range(0, 10):
    if value == 5:
        pass
    print "Value: ", value

# Go to Works_Try_003
