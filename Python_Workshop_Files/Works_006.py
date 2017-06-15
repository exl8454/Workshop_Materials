# Python 2.X workshop
# File: Works_006.py
# Conditional statement

# Conditional statement is similar to other programming languages
a = 10
# For single value check
print "if a == 10:"
if a == 10:
    print "a = 10"
print # This will print out empty line
# Note that Python is very strict about indentation.
# Try changing a == 10 to a == 4. This will not print the second line.
if a == 10:
    print "a = 10"
    print "Still inside of if statement"
print "End of line"
print # This will print out empty line
# Note that Python also dose not use parenthesis for conditional statements
# If only single check is needed, you may put the whole statement in one line.
print "if a == 10: print \"a = 10\""
if a == 10: print "a = 10"
print # This will print out empty line

# For true-false statement
a = 5
print "if-else statement"
if a == 10:
    print "a = 10"
else:
    print "Changing value to 10"
    a = 10
print # This will print out empty line

# To check one condition then another condition
a = 6
print "if-else if-else"
if a == 10: print "a = 10"
elif a == 5: print "a =/= 10"   
else: print "Does not fit on any statement"
print # This will print out empty line
# Note: If-Else If-Else statement SKIPS next conditional statment if previous statment is TRUE!

# You can slo make nested conditional statment!
a = 10
b = 6
print "Nested conditional statement"
if a == 10:
    if b != 10:
        print "Changing b to 10!"
        b = 10

# Go to Works_Try_002
