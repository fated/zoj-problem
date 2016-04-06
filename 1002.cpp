#include<iostream>
using namespace std;

int count = 0, n = 0;

bool isOk(char **map, int x, int y){
	int i;
	for (i = x-1; i>=0; i--){
		if(map[i][y] == '+') return false;
		if(map[i][y] == 'X') break;
	}
	for (i = y-1; i>=0; i--){
		if(map[x][i] == '+') return false;
		if(map[x][i] == 'X') break;
	}
	return true;
}

void search(char **map, int k, int step){
	int x, y;
	if(k == n * n)
	{
		if(step > count)
		{
			count = step;
			return;
		}
	} else {
		x = k / n;
		y = k % n;
		if(map[x][y] == '.' && isOk(map, x, y))
		{
			map[x][y] = '+';
			search(map, k+1, step+1);
			map[x][y] = '.';
			search(map, k+1, step);
		} else {
			search(map, k+1, step);
		}
	}
	return;
}

int main()
{
	while((cin >> n) && n){
		count = 0;
		char **map = new char*[n];
		for(int i = 0; i < n; i++){
			map[i] = new char[n];
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> map[i][j];
		search(map, 0, 0);
		cout << count << endl;
	}
	return 0 ;
}
