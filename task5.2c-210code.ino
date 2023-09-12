// Matangini Gupta
// 22109948810
// TASK 5.2C - 210 Embedded systems

// Import necessary libraries
from tkinter import *  // Import the tkinter library for GUI
import tkinter.font
import RPi.GPIO as GPIO  // Import RPi.GPIO library for Raspberry Pi GPIO control
from gpiozero import LED  // Import LED class from gpiozero for controlling LEDs

// Set the GPIO mode to BCM
GPIO.setmode(GPIO.BCM)

// Initialize LED objects for three different colors
red = LED(14)
blue = LED(15)
green = LED(18)

// Initialize the GUI window
win = Tk()
win.title("GUI Interface")  // Set the window title
win.geometry("250x180")  // Set the window size
myFont = tkinter.font.Font(family='Helvetica', size=12, weight="bold")  // Define a custom font
uv = StringVar()  // Create a StringVar to hold a variable for radio buttons

// Define functions for controlling LEDs
def ledRed():
    red.on()
    blue.off()
    green.off()

def ledBlue():
    red.off()
    blue.on()
    green.off()

def ledGreen():
    red.off()
    blue.off()
    green.on()

def allOn():
    red.on()
    blue.on()
    green.on()

def allOFF():
    red.off()
    blue.off()
    green.off()

// Define a function to clean up GPIO and close the window
def close():
    GPIO.cleanup()  // Cleanup GPIO resources
    win.destroy()  // Destroy the GUI window

// Create GUI Widgets
Label(win, text="Choose an option!!", font=myFont, padx=14).pack()  // Label widget
Radiobutton(win, text="Red", font=myFont, command=ledRed, bg='red', height=1, width=27, bd=3, variable=uv,
            value="LED: Red").pack(anchor="w")  // Red LED radio button
Radiobutton(win, text="Blue", font=myFont, command=ledBlue, bg='blue', height=1, width=27, bd=3, variable=uv,
            value="LED: Blue").pack(anchor="w")  // Blue LED radio button
Radiobutton(win, text="Green", font=myFont, command=ledGreen, bg='green', height=1, width=27, bd=3, variable=uv,
            value="LED: Green").pack(anchor="w")  // Green LED radio button
Radiobutton(win, text="All", font=myFont, command=allOn, bg='yellow', height=1, width=27, bd=3, variable=uv,
            value="LED: All").pack(anchor="w")  // All LEDs on radio button
Radiobutton(win, text="None", font=myFont, command=allOFF, bg='purple', height=1, width=27, bd=3, variable=uv,
            value="LED: None").pack(anchor="w")  // All LEDs off radio button
Button(win, text="Exit", font=myFont, command=close, bg='grey').pack(anchor="w")  // Exit button

// Handle window close event
win.protocol("WM_DELETE_WINDOW", close)

// Start the GUI main loop
win.mainloop()
