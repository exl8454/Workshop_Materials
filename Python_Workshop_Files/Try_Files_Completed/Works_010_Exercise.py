# Python 2.X workshop
# File: Works_010_Exercise.py
# Files I/O and Exceptions

# Lets setup a user input...
userInput = ""

# Now let's ask user to enter something
userInput = raw_input("Type something!:")
print "You typed:", userInput
print

# Let's create a file this time
filename = "foo.txt"
access_mode = "a+" # Read and write
buffering = -1

filetoread = open(filename, access_mode, buffering)

# Lets print out some attributes from file
print "File Name:", filetoread.name
print "File Mode:", filetoread.mode
print

# Let's combine user input and file!
flag = "close"
print "Type \"close\" to stop writing to file"
userInput = raw_input("Type something!:")
while userInput != flag:
    userInput += "\r\n"
    filetoread.write(userInput)

    userInput = raw_input("Type something!:")

filetoread.close()

# Now go ahead and onpen foo.txt; should have some text in there!

# Go to Works_Try_008
