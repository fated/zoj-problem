#include <iostream>
using namespace std;

int flag1, flag2;

void search(int n, int m, int fac = 100){
	if(flag1)
		return;
	if(n == 1 && m == 1){
		flag1 = 1;
		flag2 = 1;
		return;
	}
	if(m == 1){
		flag2 = 1;
	}
	if (fac < 2)
		return;
	if(n % fac == 0)
		search(n / fac, m, fac - 1);
	if(m % fac == 0)
		search(n, m / fac, fac - 1);
	search(n, m, fac - 1);
}

int main(){
	int n, m;
	while((cin >> n >> m)){
		if(m > n){
			n = m ^ n;
			m = m ^ n;
			n = m ^ n;
		}
		flag1 = 0;
		flag2 = 0;
		search(n, m);
		if(flag1 || !flag2)
			cout << n << endl;
		else
			cout << m << endl;
	}
	return 0;
}
