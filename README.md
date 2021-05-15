Cool code that can be used for building a cryptocurrency price ticker tool using Python and Arduino.

Simple Requirements:
1) PySerial Python Library
2) Binance Python API Library. (https://github.com/sammchardy/python-binance)
3) Storing your Binance API keys in the config.py file as strings. (This is a local file that doesn't risk you secret keys)
4) Make sure to have the right COM port in dataSender.py

5) Any Arduino computer, I personally used a Nano
6) Your favorite display, I used a 16x2 LCD screen
7) Red & Green LEDs
8) A buzzer


How does it work:
1) The dataSender.py file is responsible to query prices automatically using the Binance Python API, then distribute that data to the Arduino computer.
2) The Arduino computer then processes the sent data and prints the real-time price on your display.
3) If the previously displayed price is greater than the current displayed price, the buzzer is activated and the red LED is turned on, indicating a negative price change. Otherwise, the green LED turns on.

After you download the required libraries and configure the software to work with your preferred crypto, setup the hardware as noted above and simply connect the Arduino to your computer with a USB cable.

Have Fun!!!!
