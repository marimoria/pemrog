#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  double M;
  cin >> N >> M;

  vector<double> bobot(N);

  for (int i = 0; i < N; i++) {
    cin >> bobot[i];
  }

  sort(bobot.begin(), bobot.end(), greater<double>());

  double total = 0;

  for (int i = 0; i < N; i++) {
    total += bobot[i];
    if (total >= M) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
