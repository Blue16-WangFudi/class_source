print("Main-Hello ESP32!")
from machine import Pin
from machine import UART
import time

led = Pin(2, Pin.OUT)


# 定义UART引脚为GPIO1和GPIO3，波特率为9600
uart = UART(2, baudrate=9600)
while True:
    print("wait for response")
    led.value(1)
    time.sleep(0.3)
    led.value(0)
    if uart.any():
        led.value(1)
        time.sleep(0.1)
        led.value(0)
        time.sleep(0.1)
        led.value(1)
        time.sleep(0.1)
        led.value(0)
        data = uart.read()
        print("接收到的数据：", data)
        uart.write("Hello, UART! Received data = "+str(data))
    time.sleep(1)

