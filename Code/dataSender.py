from binance.client import Client
import config
import time
import serial

try:
    client = Client(config.api_key, config.api_secret)
    serialComm = serial.Serial('COM2', 9600)
    serialComm.timeout = 1
    print('Connected to Binance Servers & Arduino Hardware')

except:
    print('Connection Error')


while True:
    tickerPrice = str(client.get_symbol_ticker(symbol = 'BTCUSDT')['price'])
    serialComm.write(tickerPrice.encode())
    time.sleep(1.5)
