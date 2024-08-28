#include <iostream>
#include <string>

using namespace std;

void one() {
	int array[50];
	for (int i = 0; i < 50; i++) {
		array[i] = rand();
		if (i % 10 == 0) cout << endl;
		cout << array[i] << "\t";
	}
	cout << endl << endl << "Какое число необходимо искать? ";
	int n;
	cin >> n;

	int m = 0;
	for (int i = 0; i < 50; i++) {
		if (array[i] == n) {
			cout << endl << "Значение " << n << " находится в ячейке с номером " << i << endl;
			m += 1;
		}
	}
	if (m == 0) cout << endl << "В массиве нет такого значения" << endl;
}



void two() {
	int array[50];
	for (int i = 0; i < 50; i++) {
		array[i] = i;
		if (i % 10 == 0) cout << endl;
		cout << array[i] << "\t|";
	}
	cout << endl << endl << "Введите любое число: ";
	int n;
	cin >> n;

	int l = 0, r = 49;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (array[mid] <= n) {
			l = mid;
		}
		else r = mid;
	}
	if (array[l] == n) {
		cout << endl << "Указанное число находится в ячейке с индексом " << l << endl;
	}
	else if (array[r] == n) {
		cout << endl << "Указанное число находится в ячейке с индексом " << r << endl;
	}
	else cout << endl << "В массиве нет такого значения" << endl;
}



void three() {
	int array[50];
	for (int i = 0; i < 50; i++) {
		array[i] = i * i;
		if (i % 10 == 0) cout << endl;
		cout << array[i] << "\t";
	}
	cout << endl << endl << "Какое число необходимо искать? ";
	int n;
	cin >> n;

	int z, l = 0, r = 49;
	while (array[l] < n && array[r] > n) {
		z = l + (n - array[l]) * (r - l) / (array[r] - array[l]);
		if (array[z] <= n) {
			l = z + 1;
		}
		else r = z - 1;
	}
	if (array[l] == n) {
		cout << endl << "Указанное число находится в ячейке с индексом " << l << endl;
	}
	else if (array[r] == n) {
		cout << endl << "Указанное число находится в ячейке с индексом " << r << endl;
	}
	else cout << endl << "В массиве нет такого значения" << endl;
}



void four() {
	cout << endl << "Введите, до какого числа нужно искать простые ";
	int n;
	cin >> n;

	int* array = new int[n];
	for (int i = 0; i < n - 1; i++) {
		array[i] = i + 2;
	}

	int x, y;
	for (int i = 0; i < n - 1; i++) {
		if (array[i] != 0) {
			x = array[i] * array[i];
			y = x - 1;
			for (int j = i + 1; j < n - 1; j++) {
				y--;
				if (array[j] == x) {
					array[j] = 0;
				}
				if (y == 0) {
					y = array[i];
					x += array[i];
				}
			}
		}
	}
	cout << endl << "Просты числа до " << n << " : ";
	for (int i = 0; i < n - 1; i++) {
		if (array[i] != 0) cout << array[i] << " ";
	}
	cout << endl;
}



void five() {
	cout << endl << "Введите строку, в которой нужно провести поиск: ";
	string A, B;
	getline(cin, A);
	cout << endl << "Введите подстроку, которую нужно найти в строке: ";
	getline(cin, B);

	int m = 0, n = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == B[0]) {
			m = 1;
			for (int j = 1; j < B.size(); j++) {
				if (A[i + j] == B[j]) m++;
				else break;
			}
		}
		if (m == B.size()) {
			n = 1;
			break;
		}
		else cout;
	}
	if (n == 0) cout << endl << "Подстрока _" << B << "_ не содержится в строке _" << A << "_\n";
	else cout << endl << "Подстрока _" << B << "_ содержится в строке _" << A << "_\n";
}



void six() {
	cout << endl << "Введите количесвто элемнтов массива: ";
	int n;
	cin >> n;

	cout << endl << "Исходный массив: ";
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand();
		cout << A[i] << " ";
	}

	int min, k, l;
	for (int i = 0; i < n; i++) {
		min = A[i];
		k = i;
		l = A[i];
		for (int j = i + 1; j < n; j++) {
			if (min > A[j]) {
				min = A[j];
				k = j;
				l = A[i];
			}
		}
		A[i] = min;
		A[k] = l;
	}

	cout << endl << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}



void seven() {
	cout << endl << "Введите количесвто элемнтов массива: ";
	int n;
	cin >> n;

	cout << endl << "Исходный массив: ";
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand();
		cout << A[i] << " ";
	}

	int s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (A[j] > A[j + 1]) {
				s = A[j];
				A[j] = A[j + 1];
				A[j + 1] = s;
			}
		}
	}

	cout << endl << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}



void eight() {
	cout << endl << "Введите количесвто элемнтов массива: ";
	int n;
	cin >> n;

	cout << endl << "Исходный массив: ";
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand();
		cout << A[i] << " ";
	}

	int l = 0, r = n - 1, s;
	while (r - l > 0) {
		for (int i = l; i < r; i++) {
			if (A[i] > A[i + 1]) {
				s = A[i];
				A[i] = A[i + 1];
				A[i + 1] = s;
			}
		}
		r--;
		for (int j = r; j > l; j--) {
			if (A[j - 1] > A[j]) {
				s = A[j - 1];
				A[j - 1] = A[j];
				A[j] = s;
			}
		}
		l++;
	}

	cout << endl << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}



void nine() {
	cout << endl << "Введите количесвто элемнтов массива: ";
	int n;
	cin >> n;

	cout << endl << "Исходный массив: ";
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand();
		cout << A[i] << " ";
	}

	int j;
	for (int i = 1; i < n; i++) {
		int s = A[i];
		for (j = i - 1; j >= 0 && A[j] > s; j--) {
			A[j + 1] = A[j];
		}
		A[j + 1] = s;
	}

	cout << endl << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}



struct Branch {
	char Data; 
	Branch* LeftBranch; 
	Branch* RightBranch;
};

void Add(char aData, Branch*& aBranch) {
	if (!aBranch) { 
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else if (aBranch->Data > aData) { 
			Add(aData, aBranch->LeftBranch);
		}
	else { 
		Add(aData, aBranch->RightBranch);
	};
}

int ind = 0;

void print(Branch* aBranch) {
	if (!aBranch) return; 
	ind++;

	print(aBranch->LeftBranch); 

	for (int i = 0; i < ind; i++) cout << " ";
	cout << aBranch->Data << endl; 

	print(aBranch->RightBranch);

	ind--;
	return;
}

void FreeTree(Branch* aBranch) {
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}

void ten() {
	Branch* Root = 0;
	cout << endl << "Введите строку: ";
	char A[10000] = "";
	cin >> A;
	cout << endl << "Бинарное дерево" << endl;

	for (int i = 0; A[i]; i++) {
		Add(A[i], Root);
	}

	print(Root);
	FreeTree(Root);
}



int main() {

	setlocale(LC_ALL, "russian");

	while (true) {
		cout << endl << "--> Нажмите 1  -  Линейный поиск\n"
			"--> Нажмите 2  -  Двоичный (бинарный) поиск\n"
			"--> Нажмите 3  -  Интерполирующий поиск\n"
			"--> Нажмите 4  -  Решето Эратосфена\n"
			"--> Нажмите 5  -  Поиск подстроки в строке\n"
			"--> Нажмите 6  -  Сортировка выбором\n"
			"--> Нажмите 7  -  Пузырьковая сортировка\n"
			"--> Нажмите 8  -  <<Шейкерная>> сортировка\n"
			"--> Нажмите 9  -  Сортировка вставками\n"
			"--> Нажмите 10 -  Бинарное дерево\n"
			"--> Нажмите 11 -  Выход\n" << endl;
		string work = "";
		do { getline(cin, work); } while (work == "");
		if (work == "1") one();
		else if (work == "2") two();
		else if (work == "3") three();
		else if (work == "4") four();
		else if (work == "5") five();
		else if (work == "6") six();
		else if (work == "7") seven();
		else if (work == "8") eight();
		else if (work == "9") nine();
		else if (work == "10") ten();
		else if (work == "11") break;
	}
}