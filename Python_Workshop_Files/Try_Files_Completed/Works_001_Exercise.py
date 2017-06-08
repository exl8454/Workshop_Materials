# Python 2.x Workshop
# File: Works_001_Exercise.py
# Refer to Works_001.py for reference.

# This first exercise will focus on string type variables
aString = "Hello World! I'm Python!"

# First, print entire string from variable aString
print aString

# Now, try to print only the "Hello World!" part
print aString[0:12]

# Now, try to print only the "I'm Python!" part
print aString[13:]

# Finally, try printing "World! I'm" part
print aString[6:16]

# This next exercise will go over List
# First, try creating a List with name fruits. Then add 5 fruits of your choice
fruits = ['Apple', 'Banana', 'Orange', 'Grape', 'Strawberry']

# Try to print out entire list.
print fruits

# Try to print out third element from list!
print fruits[2]

# Try to print out STARTING from second element
print fruits[1:]

# Try to print out from second to fourth elements!
print fruits[1:4]

# Now, create a List with name veggies. Then add 3 vegitables of your choice
veggies = ['Cabbage', 'Carrot', 'Cucumber']

# Try to merge and print fruits and veggies list!
# Hint: No need to create another List variable!
print fruits + veggies

# This last exercise will handle Dictionary. A Dictionary variable is given.
aDict = {'Brown':'Fox', 'Lazy':'Dog'}

# First, try to print out the VALUE 'Fox', what will be its KEY?
print aDict['Brown']

# Next, try to print out the VALUE 'Dog', what will be its KEY?
print aDict['Lazy']

# This time, try to create a set of KEY and VALUE with
# KEY 'Quick' and VALUE 'Jump'
aDict['Quick'] = 'Jump'

# Now, try printing out KEYs only!
print aDict.keys()

# This time, try printing out VALUEs only!
print aDict.values()

