from math import *
t=int(input())
for _ in range(0,t):
	n=int(input())
	r1=sqrt(5*(n**2)+4)
	r2=sqrt(5*(n**2)-4)
	is_square=(r1%1==0) or (r2%1==0)
	if(is_square):
		print("IsFib")
	else:
		print("IsNotFib")