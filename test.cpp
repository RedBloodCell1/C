#include<stdio.h>
#include<string.h>

unsigned int factorial(unsigned int x)
{
    if (x==0)
        return 1;
        
    return x * factorial(x - 1);
}

unsigned int result(unsigned int n, unsigned r){
	return factorial(n) / ((factorial(r)*factorial(n-r)));
}

void printCombi(char a[255], char combi[], unsigned int start, unsigned int end, unsigned int idx, unsigned int r){
	
	if(idx == r){
		for(int i=0; i<r; i++){
			printf("%c", combi[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=start; i<=end && end-i+1>=r-idx; i++){
		combi[idx] = a[i];
		printCombi(a, combi, i+1, end, idx+1, r);
	}
}

void print(char a[255] , unsigned int n, unsigned int r){
	
	char combi[r];
	
	printCombi(a, combi, 0, n-1, 0, r);
}

bool check(char a[255]){
	int x=0;
	bool flag = true;
	x=strlen(a);
	
	for(int i=0 ; i<x; i++){
		if(flag == false){
			break;
		}
		for(int j=i+1; j<x ;j++){
			if(a[i] == a[j]){
				flag = false;
				printf("Character cant be the same");
				break;
			}
		}
	}
	
	return flag;
}



int main(){
	
	unsigned int r=0;
	char b[255];
	
	scanf("%[^\n]s", b);
	scanf("%u", &r);
	
	unsigned int n=0;
	n=strlen(b);
	
	if(check(b)==false){
		return 0;
	}
	
	print(b, n, r);
	printf("%u", result(n,r));
	
}
