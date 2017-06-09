# Python 2.X workshop
# File: Works_011.py
# Classes

# To create a custom class...
class Person(object):

    name = "Defacto"
    age = 21

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def getName(self):
        return self.name

    def getAge(self):
        return self.age

    def setName(self, name):
        self.name = name
        return

    def setAge(self, age):
        self.age = age
        return

# To create an object using the class
person1 = Person("Charlie", 26)
# Above code will call __init__ function to initialize class variables
# To call attributes within a class, you may call it via function
print "Name:", person1.getName()
print "Age:", person1.getAge()

# You may directly access to an attributes
# To check if class has attributes...
print "Has Age Attributes?:", hasattr(person1, "age")
# To get attribute in a class...
print "Age:", getattr(person1, "age")
# To change value of an attribute in a class...
setattr(person1, "age", 25)
print "Age:", person1.getAge()
# To delete an attribute in a class...
delattr(person1, "age")
print "Age:", person1.getAge()
# Note that delattr does not delete attributes, but reset the value to default value

print #Empty line

print id(person1)
# To delete an object we created...
del person1

# Just like any other Object-Oriented programming, you can inherit a class
class Student(Person):
    
    year = "Junior"

    def __init__(self, name, age, year):
        self.year = year
        super(Student, self).__init__(name, age)

student1 = Student("Charlie", 25, "Senior")
print "Name:", student1.getName()
print "Age:", student1.getAge()
print "Year:", student1.year

# Go to Works_011_Exercise.py
