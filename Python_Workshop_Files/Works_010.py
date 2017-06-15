# Python 2.X workshop
# File: Works_010.py
# Files I/O and Exceptions

# To simply print to the Python shell, use the print keyword
print "Hello, Python!"

print # Empty line

# To read keyboard input within the shell...
print "User input Demo"
string = raw_input("Enter your name: ")
print "Hello, " + string + "!"

print # Empty line

# You can also use 'input' keyword. Difference between raw_input
# is that input only takes valid Python expression
#string = input("Enter your valid Python command: ")
#print string

# To access to a file, you use open() function
filename = "foo.txt"
access_mode = "a+" # Opens file for read and writing
buffering = -1
fileToRead = open(filename, access_mode, buffering)

# file object has different attributes, such as...
print "File Name:", fileToRead.name # Shows name of the file
print "File Mode:", fileToRead.mode # Shows access mode
print "Is File Closed?:", fileToRead.closed # Shows if file is closed

print # Empty line

# To read a file...
aLine = fileToRead.read()
# To read up to specific byte size...
aLine = fileToRead.read(10) # Reads up to 10 bytes
# To write to a file...
print "Writting to foo.txt"
fileToRead.write("Hello World!")
# To check where the current position is...
position = fileToRead.tell()
print "Current Position:", position
# To move the current position within the file...
position = fileToRead.seek(0, 0)
print "Current Position:", position
# To close a file
fileToRead.close()

print # Empty line

# To rename a file
import os
os.rename("foo.txt", "bar.txt")
# To remove a file
os.remove("bar.txt")

# Note the access_mode flag
# r+ allows file to be read and write, with file starting at the beginning
# w is for writting only, and it overwrites from beginning of the file
# w also creates file if file does not exist
# w+ allows file for read and write, overwriting the entire file
# a allows file to be writting, appended from the end of the file

# Exception is used along with try-catch block
try:
    aFile = open("Mmm.txt", "r")
except IOError:
    print "No such file!"

# If you are not sure which exception is needed, omit the specific exception
try:
    aFile = open("bar.txt", "r")
except:
    print "No such file!"

# Go to Works_010_Exercise.py
