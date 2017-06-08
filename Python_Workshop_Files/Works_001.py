# Python 2.X workshop
# File: Works_001.py
# Some data types

# Python supports 4 numerical types
anSignedInteger = 1 # Signed integer
aLongNumber = 123456L # Long integers, can be represented as hex or octal
aFloatNumber = 1.23456 # Floating point number
aComplexNumber = 1.23j # A complex number

# Python handles string as array of characters
aString = "Hello World!"

# Which means they can be called by a character
print "Different techniques to print a string"
print aString # Print whole string first
print aString[0] # Print only the first character
print aString[6:] # Print from 6th element
print aString[0:5] # Print from first element to 4th element
print # This will print empty line

# Python takes asterisk (*) as repetition for string
print "String behaving with arithmatic symbols"
print aString * 2 # print string twice
print # This will print empty line

# Python takes plus (+) as concatenation
print "String concatenation"
print aString + ", I am Python!"
print # This will print empty line

# In Python, you may use single quote ('), double quote (") and triple quote
# (''') to declare string.
bString = 'This is allowed'
cString = "So is this"
dString = '''Only difference for this,
            you may change line to continue
            writing'''

# List is like an array in other programming languages.
aList = ["cat", "dog", "bird", "fish"]
bList = ["John", "Jane"]

print "Printing aList and bList"
print aList # Prints aList
print bList # Prints bList
print # This will print empty line

print "Printing a single element inside aList"
print aList[0] # Print first element in the aList
print # This will print empty line

# Prints first element in the bList, concatenate a word, then concatenate
# an element from aList
print "Element concatenation"
print bList[0] + " likes " + aList[0]
print # This will print empty line

print "Printing a range of elements in a single List"
print aList[1:] # Print aList from 2nd element
print aList[1:3] # Print aList from 2nd element to 3rd element
print # This will print empty line
# Notice boundary for right side is exclusive, compare to left side
# Which is inclusive

# You can concatenate lists by itself as well
print "Concatenating two lists"
print aList + bList # This will print out combined list
print # This will print empty line

# Tuple, like List, is another type of list
# The only difference is that Tuple is READ-ONLY
# This means you cannot modify values inside Tuple!

aTuple = (0, 1, 2, 3, 4, 5)
aList[0] = 10 # This is legal
#aTuple[0] = 10 # This is illegal

# Dictionary is a Hash Table, it contains KEY and VALUE
# KEY stores key data, which then will be used to search VALUE
aDict = {} # This creates empty dictionary
# This stores new value, with integer 0 as key, and string as value
aDict[0] = "This is first element"
# This ALSO stores new value, with string (two) as key, and string as value
aDict['two'] = "This is second element"

# To declare pre-defined dictionary, put colons between KEY and VALUE
bDict = {"One":"First", "Two":"Second", 3:"Third", 4:"Fourth"}

print "Printing VALUE with KEY 0"
print aDict[0] # Prints out VALUE with KEY 0
print # This will print empty line

print "Printing VALUE with KEY two"
print aDict['two'] # Prints out VALUE with KEY two
print # This will print empty line

print "Printing entire dictionary"
print bDict # Prints out entire dictionary
print # This will print empty line

print "Printing KEYs from bList"
print bDict.keys() # Prints out KEYs only
print # This will print empty line

print "Printing VALUEs from bList"
print bDict.values() # Prints out VALUEs only
print # This will print empty line
# DICTIONARY DOES NOT HAVE CONCEPT OF ORDERS. THIS DOES NOT MEAN THEY ARE
# UNORDERED; THEY ARE SIMPLY UNORDERED.

# To delete an entry within a dictionary, use del var_name[key]
del bDict[3] # Removes entry with key 3
# To clear entire dictionary, use clear() function within dictionary
aDict.clear()

print "Printing Dictionary after clearing"
print bDict
print aDict
