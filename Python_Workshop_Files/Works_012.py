# Practical Example
# E-Mail Sender
# This practical example shows how to send E-Mail via Python

import datetime
import smtplib

# Variables
startedTime = datetime.datetime.now()

TO = 'targetmail@mail.com'
FROM = 'mymail@mail.com'
PASS = 'Password'
SUBJECT = 'IoT - Email From Python'

HEADER = "To: " + TO + "\n" + "From: " + FROM + "\n" + "Subject: " + SUBJECT + "\n\n"

def sendMail():
    print "Sending mail"
    timeNow = datetime.datetime.now()
    smtpserver = smtplib.SMTP("smtp.gmail.com", 587)
    smtpserver.ehlo()
    smtpserver.starttls()
    smtpserver.ehlo
    smtpserver.login(FROM, PASS)
    text = "Sent at " + timeNow.isoformat(' ') + "\n\n"
    message = HEADER + text
    smtpserver.sendmail(FROM, TO, message)
    smtpserver.close()
    print "Mail sent"
# End of function

while True:
    timeCheck = datetime.datetime.now()
    diff = timeCheck - startedTime
    if diff.total_seconds() >= 60:
        print "60 seconds passed, sending status..."
        sendMail()
        startedTime = timeCheck
# End of while loop
