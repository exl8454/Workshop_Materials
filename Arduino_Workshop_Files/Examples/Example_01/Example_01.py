# Practical Example
# IoT device...of sort
# This practical example shows how to link Python with Arduino, then send message
# when button is pressed.

import time
import datetime
import smtplib
import serial

# Variables
port = serial.Serial('COM7', 9600)

startedTime = datetime.datetime.now()

TO = 'hsmchul@hotmail.com'
FROM = 'cshinIoT@gmail.com'
PASS = 'ILoveLaprasSoMuch!'
SUBJECT = 'IoT - Button was Pressed!'

running = True;

HEADER = "To: " + TO + "\n" + "From: " + FROM + "\n" + "Subject: " + SUBJECT + "\n\n"

def sendMail():
    print "Sending mail"
    timeNow = datetime.datetime.now()
    smtpserver = smtplib.SMTP("smtp.gmail.com", 587)
    smtpserver.ehlo()
    smtpserver.starttls()
    smtpserver.ehlo
    smtpserver.login(FROM, PASS)
    text = "Button was pressed on Arduino: \nSent at " + timeNow.isoformat(' ') + "\n\n"
    message = HEADER + text
    smtpserver.sendmail(FROM, TO, message)
    smtpserver.close()
    print "Mail sent"
# End of function

while running:
    data = port.readline()
    print(data[0])
    if data[0] == 'T':
        sendMail()
    elif data[0] == 'S':
        running = False
        port.close();
# End of while loop
