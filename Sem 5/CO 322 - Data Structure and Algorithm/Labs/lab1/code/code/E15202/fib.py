#!/usr/bin/python
import time

def fib_r(x) :
    if (x <= 2):
        return 1
    return fib_r(x-1) + fib_r(x-2)


def fib_i(x) :
    a = 1
    b = 1
    fib = 1
    i = 2
    while i < x:
        fib = a +b
        a = b
        b = fib
        i+=1
        
    return fib


for x in range (1,41):
    start_time_r = time.time()
    fib_r(x)

    print time.time() - start_time_r," ",

    x = x + 1

print "\----------------------------"

for y in range (1,41):
    
    start_time_i = time.time()    
    fib_i(y)

    print time.time() - start_time_i," ",

    y = y + 1



