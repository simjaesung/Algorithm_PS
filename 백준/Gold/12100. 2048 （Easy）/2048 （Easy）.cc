#include<iostream>
#include<vector>

using namespace std;

int arr[25][25], cas[25][25], c[5];
//arr 원본 , cas 복사본, c는 중복순열
int n, ans = 2;

void s_left()
{
	for (int i = 0; i < n; i++) {
		vector<int>v;
		for (int j = 0; j < n; j++) {
			if (cas[i][j] != 0) v.push_back(cas[i][j]);
		}

		//0을 더 채워 넣어서 부족한 행수 채우기
		int initsize = v.size();
		int size = n - initsize;
		while (size--) v.push_back(0);

		//붙어있는 두값이 같으면 더해줘야함, 
		// 더해준 후 공백을 위한 0 채우기
		for (int k = 1; k < initsize; k++) {
			if (v[k] == v[k - 1]) {
				v[k - 1] += v[k];
				v[k] = -1; v.push_back(0);
			}
		}

		int tmp = 0;
		for (auto x : v) {
			if (x != -1) cas[i][tmp++] = x;
		}
	}
}


void s_right()
{
	for (int i = 0; i < n; i++) {
		vector<int>v;
		for (int j = n-1; j >= 0; j--) {
			if (cas[i][j] != 0) v.push_back(cas[i][j]);
		}

		//0을 더 채워 넣어서 부족한 행수 채우기
		int initsize = v.size();
		int size = n - initsize;
		while (size--) v.push_back(0);

		//붙어있는 두값이 같으면 더해줘야함, 더해준 후 
		for (int k = 1; k < initsize; k++) {
			if (v[k] == v[k - 1]) {
				v[k - 1] += v[k];
				v[k] = -1; v.push_back(0);
			}
		}

		int tmp = n - 1;
		for (auto x : v) {
			if (x != -1) cas[i][tmp--] = x;
		}
	}
}

void s_up()
{
	for (int i = 0; i < n; i++) {
		vector<int>v;
		for (int j = 0; j < n; j++) {
			if (cas[j][i] != 0) v.push_back(cas[j][i]);
		}

		//0을 더 채워 넣어서 부족한 행수 채우기
		int initsize = v.size();
		int size = n - initsize;
		while (size--) v.push_back(0);

		//붙어있는 두값이 같으면 더해줘야함, 
		// 더해준 후 공백을 위한 0 채우기
		for (int k = 1; k < initsize; k++) {
			if (v[k] == v[k - 1]) {
				v[k - 1] += v[k];
				v[k] = -1; v.push_back(0);
			}
		}

		int tmp = 0;
		for (auto x : v) {
			if (x != -1) cas[tmp++][i] = x;
		}
	}
}

void s_down()
{
	for (int i = 0; i < n; i++) {
		vector<int>v;
		for (int j = n - 1; j >= 0; j--) {
			if (cas[j][i] != 0) v.push_back(cas[j][i]);
		}

		//0을 더 채워 넣어서 부족한 행수 채우기
		int initsize = v.size();
		int size = n - initsize;
		while (size--) v.push_back(0);

		//붙어있는 두값이 같으면 더해줘야함
		for (int k = 1; k < initsize; k++) {
			if (v[k] == v[k - 1]) {
				v[k - 1] += v[k];
				v[k] = -1; v.push_back(0);
			}
		}

		int tmp = n - 1;
		for (auto x : v) {
			if (x != -1) cas[tmp--][i] = x;
		}
	}
}



void go(int select)
{
	//1 : ↑ , 2: ↓, 3: →, 4: ←
	if (select == 5) {
		for (int i = 0; i < 5; i++) {
			if (c[i] == 1) s_up();
			else if (c[i] == 2) s_down();
			else if (c[i] == 3) s_right();
			else s_left();

			//한번의 이동 마다 최댓값 갱신
			for (int k = 0; k < n; k++) {
				for (int j = 0; j < n; j++) {
					ans = max(ans, cas[k][j]);
				}
			}
		}
		//초기화
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < n; j++) {
				cas[k][j] = arr[k][j];
			}
		}
		return;
	}

	for (int i = 1; i <= 4; i++) {
		c[select] = i;
		go(select + 1);
	}

}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			cas[i][j] = arr[i][j];
		}
	}
	
	go(0);

	cout << ans;
	return 0;
}