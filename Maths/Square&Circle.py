#!/bin/python3
import sys
w,h = map(int, input().strip().split(' '))
cx,cy,r = map(int, input().strip().split(' '))
x1,y1,x3,y3 = map(int, input().strip().split(' '))
sx = (x1+x3)/2
sy = (y1+y3)/2
x1,y1,x3,y3 = x1-sx,y1-sy,x3-sx,y3-sy
x2,y2 = -y1, x1
x4,y4 =  y1,-x1
def incircle(x,y):
    return (x-cx)**2 + (y-cy)**2 <= r**2
def insquare(x,y):
    x -= sx
    y -= sy
    return (x-x1)*(x2-x1) + (y-y1)*(y2-y1) >= 0 and \
           (x-x2)*(x3-x2) + (y-y2)*(y3-y2) >= 0 and \
           (x-x3)*(x4-x3) + (y-y3)*(y4-y3) >= 0 and \
           (x-x4)*(x1-x4) + (y-y4)*(y1-y4) >= 0

for y in range(h):
    for x in range(w):
        if incircle(x,y) or insquare(x,y):
            print('#',end='')
        else:
            print('.',end='')
    print()