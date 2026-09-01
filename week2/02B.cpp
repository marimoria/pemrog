#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Orang {
private:
  string nama;
  int usia;
  double tinggi;
  double berat;

public:
  Orang(string n, int u, double t, double b): nama(n), usia(u), tinggi(t), berat(b) {}

  void show() {
    cout << nama << " | " << usia << " | " << fixed << setprecision(2) << tinggi << " | " << setprecision(2) << berat << endl;
  }

  void setNama(string n) { nama = n; }
  void setUsia(int u) { usia = u; }
  void setTinggi(double t) { tinggi = t; }
  void setBerat(double b) { berat = b; }

  string getNama() { return nama; }
  int getUsia() { return usia; }
  double getTinggi() { return tinggi; }
  double getBerat() { return berat; }

};

int main() {
  string n;
  int u;
  double t;
  double b;

  // getline untuk menghindari whitespace problem
  if (!getline(cin, n)) { return 0; }
  if (!(cin >> u >> t >> b)) { return 0; }

  Orang orang(n, u, t, b);
  orang.show();

  return 0;
}