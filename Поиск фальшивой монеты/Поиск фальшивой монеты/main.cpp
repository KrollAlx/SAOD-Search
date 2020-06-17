#include<iostream>
#include<ctime>
using namespace std;

int sum(int* array, int bound) {
	int result = 0;
	for (int i = 0; i < bound; ++i) {
		result += array[i];
	}
	return result;
}

int search_fake(int* coins, int N) {
	int low = 0;
	int high = N - 1;
	int mid;
	while (low <= high) {
		mid = round((double)(low + high) / 2.0);
		if (coins[mid] == 0) {
			return mid;
		}
		if (sum(coins, mid) != mid) {
			high = mid - 1;
		}
		else {
			low = mid;
		}
	}
	return -1;
}

int main() {

	bool exit = false;
	while (!exit) {
		srand(time(0));
		int N;
		do {
			cout << "Enter size of array ";
			cin >> N;
		} while (N < 1);

		int* coins = new int[N];
		for (int i = 0; i < N; ++i) {
			coins[i] = 1;
		}
		coins[rand() % N] = 0;
		for (int i = 0; i < N; ++i) {
			cout << coins[i] << " ";
		}
		cout << endl;

		cout << "Index of fake coin = " << search_fake(coins, N) << endl;
		delete[] coins;

		int choice;
		do {
			cout << "Close the programm?" << endl
				<< "1)Yes" << endl
				<< "2)No" << endl;
			cin >> choice;
		} while (choice < 1 || choice > 2);
		if (choice == 1) {
			exit = true;
		}
	}
	return 0;
}