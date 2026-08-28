#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M;
  cin >> M;

  vector<int> data;
  int nilai;

  while (cin >> nilai && nilai != -1) {
    if (nilai >= M) {
      data.push_back(nilai);
    }
  }

  int n = data.size();
  double rataan = 0;

  for (int x : data) {
    rataan += x;
  }
  rataan /= n;

  double ragam = 0;

  for (int x : data) {
    ragam += (x - rataan) * (x - rataan);
  }
  ragam /= (n - 1);

  cout << fixed << setprecision(2) << rataan << " " << ragam << endl;

  return 0;
}
