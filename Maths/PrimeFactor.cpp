#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;
#define sf scanf
#define pf printf
#define pub push_back
#define po  pop
#define pob pop_back
#define puf push_front
#define mp make_pair
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> si;
typedef multiset<int> msi;
typedef long int i32;
typedef unsigned long int ui32;
typedef long long int ll;
typedef unsigned long long int  ui64;
vector<string> split(const string& s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}
vi primes;
bitset<10000010> bs;
void sieve(ll upperbound) {          
  ll _sieve_size = upperbound + 1;      
  bs.set();   //Assigning all to 1                       
  bs[0] = bs[1] = 0;                 
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);  
	} 
} 
int main(int argc, char const *argv[])
{
	sieve(1000000);
	int N,p_index=0,PF=primes[p_index];
	sf("%d",&N);
	vi factors;
	while(N!=1 && (PF*PF)<=N){
		while(N%PF==0){
			N/=PF;pf("%d ",PF);
		}
		PF=primes[++p_index];
	}
	if(N!=1)	pf("%d",N);
	pf("\n");
	return 0;
}