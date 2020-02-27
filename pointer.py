# pip install pyserial
# pip install pynput

import serial
import sys

def hello(a):
    ser = serial.Serial(
        port=a,\
        baudrate=9600,\
        parity=serial.PARITY_NONE,\
        stopbits=serial.STOPBITS_ONE,\
        bytesize=serial.EIGHTBITS,\
        timeout=0)

    print("connected to: " + ser.portstr)
    count=1

    from pynput.keyboard import Key, Controller
    keyboard = Controller()

    while True:
        for line in ser.read():
            print(str(count) + str(': ') + chr(line) )
            if chr(line) == 'A':
                keyboard.press(Key.page_up)
                keyboard.release(Key.page_up)
            if chr(line) == 'B':
                keyboard.press(Key.page_down)
                keyboard.release(Key.page_down)
            if chr(line) == 'C':
                keyboard.press('B')
                keyboard.release('B')
            if chr(line) == 'D':
                keyboard.press(Key.f5)
                keyboard.release(Key.f5)
    ser.close() 

if __name__ == "__main__":
    a = sys.argv[1]
    hello(a)

