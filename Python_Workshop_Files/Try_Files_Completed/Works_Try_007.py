# Python 2.7.X
# Try_007.py
# Classes

# Objective a: To create a class and print the value
# Objective b: To create an inherited class and printn value
# Requirement 1: Create a Vehicle class containing type and
# number of wheels, and print the data
# Requirement 2: Create a Car and Motocycle class, and have
# color as attribute. Print the data for car and motocycle,
# including type, number of wheels, and color
# Both classes must get attributes by function(s)

# Write your code here
class Vehicle:
    type = "None"
    wheels = 0

    def __init__(self, type, wheels):
        self.type = type
        self.wheels = wheels

    def getType(self):
        return self.type

    def getWheels(self):
        return self.wheels

aVehicle = Vehicle("None", 0)
print "Type:", aVehicle.getType()
print "Wheels:", aVehicle.getWheels()

class Car(Vehicle):
    color = "None"

    def __init__(self, color):
        self.color = color

    def getColor(self):
        return self.color

class Motorcycle(Vehicle):
    color = "None"

    def __init__(self, color):
        self.color = color

    def getColor(self):
        return self.color

aCar = Car("Red")
setattr(aCar, "type", "Car")
setattr(aCar, "wheels", 4)

aMotorcycle = Motorcycle("Blue")
setattr(aMotorcycle, "type", "Motorcycle")
setattr(aMotorcycle, "wheels", 2)

print "Type:", aCar.getType();
print "Wheels:", aCar.getWheels();
print "Color:", aCar.getColor();
print "Type:", aMotorcycle.getType();
print "Wheels:", aMotorcycle.getWheels();
print "Color:", aMotorcycle.getColor();
