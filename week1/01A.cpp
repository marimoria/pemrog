#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;

  double rataan = (a + b + c + d) / 4.0;

  cout << fixed << setprecision(2) << rataan << endl;
  return 0;
}
