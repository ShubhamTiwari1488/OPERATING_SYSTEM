
import os

a=5

pid1 = os.fork()

pid2 = os.fork()

pid3 = os.fork()

a=a+1

print("Value of a is ",a)
