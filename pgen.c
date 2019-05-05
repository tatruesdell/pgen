#include<stdio.h>

char head(int f){
	char hset[] = "abcdefghijklmnopqrstuvwxyz";
	int k= f%26;
	return hset[k];
}

char rad(int f){
	char rset[] = "!@#$%^&*`~()-_+={}[]|:;<>,./";
	int k= f%29;
	return rset[k]; 
}

char mid(int f){
	char mset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int k= f%26;
	return mset[k]; 
}

char tail(int f){
	char tset[] = "1234567890"; 
	int k = f%10; 
	return tset[k]; 
}

int pfib(int seed, int m){
	int c=0;
	int n = 0;
	int z = 0; 
	while(z < 1000){
		z = seed + n; 
		n = seed; 
		seed = z; 
		c++;
	}
	while(10000 > z){
		z = seed + n; 
		n = seed; 
		seed = z; 
		c++;
	}
	return (z-c)%m; 
}

int sq(int b){
	return b*b; 
}

int lcg(int a, int seed, int m){
	int c =0; 
	int k = a * seed; 
	while(c < 10){
		k = (a * k) % m; 
		c++;
		if(k==0){
			k = c+2;
		}
	} 
	return k;
}

int main(void){
	int n; 
	printf("How many passwords do you need? \n");
	scanf("%d", &n);
	FILE * outFile;
	outFile = fopen("out.txt", "a");
	int m1=26;
	int m2=9;
	int m3=29;
	char p[13];
	char h[3];
	char r;
	char m[4];
	int d=0; 
	char t[4];
	for(int i = 2; i<n+2; i++){
		for(int j=0; j<3; j++){
			int m = lcg(2, 2*d, i*m1); 
			char c = head(m);
			p[j]=c;
			d++; 
		}
		d++; 
		int z= lcg(3, i+d, 7); 
		r = rad(z);
		p[3]=r; 
		for(int j=4; j<8; j++){
			int n = lcg(7, 3*d, i*m1);
			char c = mid(n);
			p[j]=c;
			d++; 
		}
		d++;
		for(int j=8; j<=11; j++){
			int l = lcg(13, 5*d, i*m2);
			char c = tail(l); 
			p[j]=c; 
			d++; 
		}
		d++; 
		fprintf(outFile, "%s", p);
		fprintf(outFile, "\n");
	} 
	return 0; 
}