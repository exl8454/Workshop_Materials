# Python 2.X workshop
# File: Works_000.py
# This file shows basics of Python scripting

# This is a script
# Since Python is interpreter, it does not need to complie.
# Rather, Python reads each line as it executes
# Compare to compile and run like other programming languages.

# The script file itself becomes the main class of the program.
# There is no need for a 'main' function.

# To print out a sentence on the Python shell
print "To print out a sentence without variable..."
print "Hello World!"
print # This will print empty line

# To declar a variable, simply type the name of a variable
a = 10 # This will automatically assign variable 'a' with integer type
b = 10.1 # This will automatically assign variable 'b' with float type
total = 0
output = "a + b is:" # This will assign variable 'output' with string type

total = a + b
print "Using variable to print out result"
print output, total # Add a comma between variables to print them in one line
print # This will print empty line

# To print variables line-by-line, add print on each line!
print "Multi-line print"
print output
print total

print "a is:", a
print "b is:", b
print # This will print empty line

# Python offers to assign values to variables in a multiple ways
# First, if you want to store same value in two variables
c = d = 5
# Second, if you want to store different value in one line
e, f, result = 10.0, 25.0, "OUTPUT: "

output = (c + d) * e / 25
print "Multiple ways to assign value to variables"
print result, output
print # This will print empty line

# Note that we do not add any semicolons to indicate end of the line.
# However, if you want to execute muliple lines in a one line, add a semicolon
# between each line
print "Using single line to execute multiple commands"
output = (c - d) + e / 25; print result, output
print # This will print empty line

# If you want to execute multiple operations in multiple lines, use backward slash
# (\) to change line
output = (c * d) \
         * e / 25
print "Using multiple lines to execute single command"
print result, output

# Do note that all variables are declared with small case letters first
# We will look into more about grammar in Python later on
