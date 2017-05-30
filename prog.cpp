#include "imageheaders.h"
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++>

using namespace std;

unsigned char* stream;
long index;

void appendBits(unsigned long n, int bits) {
	for (long i=0; i<bits; i++) {
		stream[index/8]=stream[index/8]&~((~n&1)<<(index%8));
		n=n>>1;
		index++;
	}
}

unsigned long getBits(int b) {
	unsigned long ans=0;
	for(;b>0; b--) {
		b=b<<1 & ~(~stream[index/8]&(1<<index%8));
		index++;
	}
	return ans;
}
int main() {
	index=0;
	int n;
	cin>>n;
	if (n==-1) {
		int b;
		cin>>b;
		b=b*8;
		stream=malloc(b);
		b-=1;
		if (b>=80000) {
			appendBits(0,1);
			compress(b);
		} else {
			appendBits(1,1);
			compressWithPolygons(b);
		}
	} else {
		vector<unsigned char> data;
		data.push_back(n);
		index=1;
		unsigned char c;
		while (cin>>c) {
			data.push_back(c);
		}
		stream=&data[0];
		if (n==0) {
			uncompress();
		} else {
			uncompressPolygons():
		}
	}
}
