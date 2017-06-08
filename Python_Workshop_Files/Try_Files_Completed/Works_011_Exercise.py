# Python 2.X workshop
# File: Works_011_Exercise.py
# Classes

# Let's create a class...
class Computer(object):
    device = "No Device Type"
    color = "None"

    def __init__(self, device, color):
        self.device = device
        self.color = color
        return

    def GetDevice(self):
        return self.device

    def GetColor(self):
        return self.color

    def SetDevice(self, device):
        self.device = device
        return

    def SetColor(self, color):
        self.color = color
        return

# Now, let's create this class object!
desktop = Computer("Desktop", "Black")

# Print some attributes...
print desktop.GetDevice()
print desktop.GetColor()

# Let's change some attributes...
desktop.SetDevice("Laptop")
desktop.SetColor("Blue")

# Print attributes...
print desktop.GetDevice()
print desktop.GetColor()

# Now, lets try creating inherited class
class Laptop(Computer):
    price = 0

    def __init__(self, name, color, price):
        self.price = price
        super(Laptop, self).__init__(name, color)
        return

    def GetPrice(self):
        return self.price

# Create this class object...
laptop = Laptop("Laptop", "Red", 600)

# Print some attributes...
print laptop.GetDevice()
print laptop.GetColor()
print laptop.GetPrice()

# Go to Works_Try_007
