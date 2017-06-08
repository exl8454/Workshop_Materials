# Python 2.7.X
# Try_008.py
# File I/O and exception handling

# Objective: To check if file exist, then create a new file
# Using File I/O
# Requirement 1: Create a file with a name "output.txt"
# Requirement 2: Display file properties, such as
# name of the file and access mode of the file
# Requirement 3: Ask user to enter a line. Write that
# line to the file and close the file.
# Requirement 4: Open the "output.txt" file and read the line,
# then print out the line, then close the file.
# Requirement 5: Delete the file, and try to read in the same file.
# (Be sure to read the file as read only in this case)
# Script must catch any exceptions

import os
# Write your code here
fileToMake = open("output.txt", "a+", -1)

print "File name:", fileToMake.name
print "Access mode:", fileToMake.mode

lineToWrite = raw_input("Write something! ")
fileToMake.write(lineToWrite)
fileToMake.close()

fileToOpen = open("output.txt", "a+", -1)
print fileToOpen.read()
fileToOpen.close()

os.remove("output.txt")

try:
    aFile = open("output.txt", "r")
except IOError:
    print "No such file!"
