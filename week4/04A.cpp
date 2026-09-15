#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Bangun {
  private:
    double ukuran;
    double luas;
    double pi = 3.1425;

  public:
    Bangun(double u): ukuran(u), luas(0.0) {}
    virtual ~Bangun() {}

    virtual void hitungLuas() {
      luas = 0.0;
    }

    double getUkuran() { return ukuran; }
    void setUkuran(double u) { ukuran = u; }

    double getLuas() { return luas; }
    void setLuas(double l) { luas = l; }

    double getPi() { return pi; }
};

class Bangun3D: public Bangun {
  private:
    double volume;

  public:
    Bangun3D(double u): Bangun(u), volume(0.0) {}

    virtual void hitungVolume() {
      volume = 0.0;
    }
    
    double getVolume() { return volume; }
    void setVolume(double v) { volume = v; }
};

class Lingkaran: public Bangun {
  public:
    Lingkaran(double u): Bangun(u) {}

    void hitungLuas() {
      setLuas(getPi() * pow(getUkuran(),2.0));
    }
};

class Persegi: public Bangun {
  public:
    Persegi(double u): Bangun(u) {}

    void hitungLuas() {
      setLuas(pow(getUkuran(),2.0));
    }
};

class Bola: public Bangun3D {
  public:
    Bola(double u): Bangun3D(u) {}

    void hitungLuas() {
      setLuas(4 * getPi() * pow(getUkuran(), 2.0));
    }

    void hitungVolume() {
      setVolume((4.0/3.0) * getPi() * pow(getUkuran(),3.0));
    }
};

class Kubus: public Bangun3D {
  public:
    Kubus(double u): Bangun3D(u) {}

    void hitungLuas() {
      setLuas(6 * pow(getUkuran(), 2.0));
    }

    void hitungVolume() {
      setVolume(pow(getUkuran(),3.0));
    }
};

int main() {
  int n;
  cin >> n;

  double totalLuas = 0.0;
  double totalVolume = 0.0;

  for (int i = 0; i < n; i++) {
    string tipeBangun;
    double ukuranBangun;

    cin >> tipeBangun >> ukuranBangun;

    if (tipeBangun == "L") {
      Bangun* lingkaran = new Lingkaran(ukuranBangun);
      lingkaran->hitungLuas();

      totalLuas += lingkaran->getLuas();

      delete lingkaran;
    } else if (tipeBangun == "P") {
      Bangun* persegi = new Persegi(ukuranBangun);
      persegi->hitungLuas();

      totalLuas += persegi->getLuas();

      delete persegi;
    } else if (tipeBangun == "K" ) {
      Bangun3D* kubus = new Kubus(ukuranBangun);
      kubus->hitungLuas();
      kubus->hitungVolume();

      totalLuas += kubus->getLuas();
      totalVolume += kubus->getVolume();

      delete kubus;
    } else if (tipeBangun == "B") {
      Bangun3D* bola = new Bola(ukuranBangun);
      bola->hitungLuas();
      bola->hitungVolume();

      totalLuas += bola->getLuas();
      totalVolume += bola->getVolume();

      delete bola;
    }
  }

  cout << fixed << setprecision(2) << totalLuas << endl;
  cout << fixed << setprecision(2) << totalVolume << endl;

  return 0;
}
