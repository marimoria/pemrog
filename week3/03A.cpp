#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class PersegiPanjang {
private:
  int panjang;
  int lebar;

public:
  PersegiPanjang(int p, int l) : panjang(p), lebar(l) {}

  int hitungLuas() { return panjang * lebar; }
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> luas;

  for (int i = 0; i < n; i++) {
    int panjang, lebar;
    cin >> panjang >> lebar;
    PersegiPanjang batu(panjang, lebar);
    luas.push_back(batu.hitungLuas());
  }

  sort(luas.begin(), luas.end());

  for (int i = 0; i < k; i++) {
    cout << luas[i] << "\n";
  }

  return 0;
}
