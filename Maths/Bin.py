t=int(input())
#a, b, c = map(int, raw_input().strip().split(' '))
for i in range(0,t):
	n=int(input())
	j=1
	while(True):
		x=int(str(bin(j))[2:].replace('1','9'))
		if(x%n==0):
			print(x)
			break;
		j=j+1