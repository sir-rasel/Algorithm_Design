#include <bits/stdc++.h>
#define mx 1000000000
using namespace std;

//#define MAX 100000000
//#define LMT 10000

//unsigned flag[MAX>>6];
//
//#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
//#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))
//
//void sieve() {
//    unsigned i, j, k;
//    for(i=3; i<LMT; i+=2)
//        if(!ifc(i))
//            for(j=i*i, k=i<<1; j<MAX; j+=k)
//                isc(j);
//}

bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos){
    return N = N | (1<<pos);
}

int status[(mx>>6)+2];
void sieve()
{
     int sqrtN = int( sqrt( mx ) )+1;
     for(int i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>6],((i>>1)&31))==0 )
		 {
	 		 for(int j = i*i; j <= mx; j += (i<<1) )
			 {
				 status[j>>6]=Set(status[j>>6],((j>>1) & 31));
	 		 }
		 }
	 }
}

int main(){
    sieve();
    int n;
    printf("Enter the last number till that be prime print: ");
    scanf("%d",&n);
    for(int i=3;i<n;i+=2){
        //if(ifc(i)==false) printf("%d prime\n",i);
        if( Check(status[i>>6],((i>>1)&31))==0 ) printf("%d prime\n",i);
        else printf("not prime\n");
    }
    return 0;
}
