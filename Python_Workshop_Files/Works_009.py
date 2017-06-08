# Python 2.X workshop
# File: Works_009.py
# Modules

# Modules are just like packages we import in other programming languages
# You do not need to create your own, unless you want to
import support

# You do not need to call import again, but you will have to define
# Module's location
print "Using import support"
support.printString("Hello World!")
result = support.add(10, 11)
print result
print # This will print out empty line

# from...import allows you to import specific functions
from support import sub
result = sub(10, 11)
print result

print # This will print out empty line

# If you are not sure which one to import, you can use asterisk (*)
from support import *
result = div(10, 11)
print result

print # This will print out empty line

# As long as Python recognize that modules are in the same location as other
# scripts. Otherwise you must edit the module paths

# Namespaces and scoping
# When global variable has same name as local variable, global variable
# is 'shadowed' by local variable. This means global variable is not
# modified, but the local variable is.
# To fix this, add 'global' keyword to a variable to point to global variable
Value = 10
def addValue():
    global Value
    Value = Value + 1

print "Value:", Value
addValue()
print "Value After addvAlue():", Value

# To see what functions are in a module, use dir() function
print dir(support)
# To check available namespaces in globals...
print globals()
# To check available namespaces in locals...
print locals()

# Go to Works_Try_006
