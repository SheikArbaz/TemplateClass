#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;
#define sf scanf
#define pf printf
int main(int argc, char const *argv[])
{
	freopen ("a.txt","w",stdout);
	int T,N;
	unsigned long long fib[61];
	fib[0]=0;fib[1]=1;
	for (int i = 2; i <61; ++i){
		fib[i]=fib[i-1]+fib[i-2];
	}
	sf("%d",&T);
	while(T--){
		sf("%d",&N);
		if(std::binary_search (fib,fib+61, N))
	    std::cout << "IsFibo\n"; else std::cout << "IsNotFibo\n";
	}
}