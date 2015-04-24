#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main(void)
{
	int n;
	while (cin >> n&&n>0) {
	//	if (n == 0) break;

		int *Ti_s = new int[n];
		int *Ti_e = new int[n];

		for (int i = 0; i < n; ++i)
			cin >> Ti_s[i] >> Ti_e[i];
		//input.

		for (int i = 0; i < n-1; ++i) {
			int early = i;
			for (int j = i+1; j < n; ++j) {
				if (Ti_e[j] < Ti_e[early])
					early = j;
			}
			if (early != i) {
				Ti_e[i] ^= Ti_e[early];
				Ti_e[early] ^= Ti_e[i];
				Ti_e[i] ^= Ti_e[early];

				Ti_s[i] ^= Ti_s[early];
				Ti_s[early] ^= Ti_s[i];
				Ti_s[i] ^= Ti_s[early];
			}
		}	 //sort.
	
		//cout << endl;
		//for (int i = 0; i < n; ++i) {
		//	cout << Ti_s[i] << ' ' << Ti_e[i] << endl;
		//}

		
		int rec[25];
		for (int i = 0; i <= 24; ++i)
			rec[i] = 0;

		int j = 0;
		for (int i = 0; i <= 24; ++i)
		{
			if(i)
				rec[i] = rec[i - 1];
			while(j < n && i == Ti_e[j]) {
				if (rec[ Ti_s[j] ] + 1 > rec[i]){
					rec[i] = rec[ Ti_s[j] ] + 1;
				}
				++j;
			}
		}	//dp.
		
		//cout << endl;	//debug.
		cout << rec[24] << endl;
		
//		delete	[]Ti_s;
//		delete	[]Ti_e;
	}
	return 0;
}

