#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>
using namespace std;

class Ruang2D {
  private:
    int noObjek;
    string namaBidang;
    double luas;

  public:
    Ruang2D(int no, string nb): noObjek(no), namaBidang(nb), luas(0.0) {}
    ~Ruang2D() {}

    int getNoObjek() {
      return noObjek;
    }
    void setLuas(int no) {
      noObjek = no;
    }

    double getLuas() {
      return luas;
    }
    void setLuas(double l) {
      luas = l;
    }

    string getNamaBidang() {
      return namaBidang;
    }
    void setNamaBidang(string nb) {
      namaBidang = nb;
    }

    virtual void hitungLuas() {
      setLuas(0.0);
    }

    virtual void show() {
      cout << "-----------------------------" << endl;
      cout << "Nomor Objek    : " << noObjek << endl;
      cout << "Bidang         : " << namaBidang << endl;
    }
};

class Lingkaran: public Ruang2D {
  private:
    double pi = 3.14;
    double radius;

  public:
    Lingkaran(int no, double r): Ruang2D(no, "Lingkaran"), radius(r) {}

    double getRadius() {
      return radius;
    }
    void setRadius(double r) {
      radius = r;
    }
    
    virtual void hitungLuas() override {
      setLuas(pi*radius*radius);
    }

    virtual void show() {
      Ruang2D::show();
      cout << "Jari-jari      : " << fixed << setprecision(2) << radius << endl;
      cout << "Luas Permukaan : " << fixed << setprecision(2) << getLuas() << endl;
    }
};

class Segitiga: public Ruang2D {
  private:
    double alas;
    double tinggi;

  public:
    Segitiga(int no, double a, double t): Ruang2D(no, "Segitiga"), alas(a), tinggi(t) {}

    double getAlas() {
      return alas;
    }
    void setAlas(double a) {
      alas = a;
    }

    double getTinggi() {
      return tinggi;
    }
    void setTinggi(double t) {
      tinggi = t;
    }

    virtual void hitungLuas() override {
      setLuas((alas*tinggi)/2.0);
    }

    virtual void show() {
      Ruang2D::show();
      cout << "Alas           : " << fixed << setprecision(2) << alas << endl;
      cout << "Tinggi         : " << fixed << setprecision(2) << tinggi << endl;
      cout << "Luas Permukaan : " << fixed << setprecision(2) << getLuas() << endl;
    }
};

class Segiempat: public Ruang2D {
  private:
    double panjang;
    double lebar;

  public:
    Segiempat(int no, string nse, double p, double l): Ruang2D(no, nse), panjang(p), lebar(l) {}

    double getPanjang() {
      return panjang;
    }
    void setPanjang(double p) {
      panjang = p;
    }

    double getLebar() {
      return lebar;
    }
    void setLebar(double l) {
      lebar = l;
    }

    virtual void hitungLuas() override {
      setLuas(panjang*lebar);
    }

    virtual void show() {
      Ruang2D::show();
      cout << "Panjang        : " << fixed << setprecision(2) << panjang << endl;
      cout << "Lebar          : " << fixed << setprecision(2) << lebar << endl;
      cout << "Luas Permukaan : " << fixed << setprecision(2) << getLuas() << endl;
    }
};

class Persegi: public Segiempat {
  private:
    double sisi;

  public:
    Persegi(int no, double s): Segiempat(no, "Persegi", s, s), sisi(s) {}

    double getSisi() {
      return sisi;
    }
    void setSisi(double s) {
      sisi = s;
    }

    virtual void hitungLuas() override {
      setLuas(sisi*sisi);
    }

    virtual void show() {
      Ruang2D::show();
      cout << "Panjang Sisi   : " << fixed << setprecision(2) << sisi << endl;
      cout << "Luas Permukaan : " << fixed << setprecision(2) << getLuas() << endl;
    }
};

int main() {
  int n;
  cin >> n;

  vector<Ruang2D*> daftarBangun;

  for (int i = 0; i < n; i++) {
    string namaBangun;
    cin >> namaBangun;

    Ruang2D *bangun = nullptr;

    if (namaBangun == "Lingkaran") {
      double r;
      cin >> r;
      bangun = new Lingkaran(i+1, r);
    } else if (namaBangun == "Segitiga") {
      double a;
      double t;
      cin >> a >> t;
      bangun = new Segitiga(i+1, a, t);
    } else if (namaBangun == "Segiempat") {
      double p;
      double l;
      cin >> p >> l;
      bangun = new Segiempat(i+1, "Segiempat", p, l);
    }  else if (namaBangun == "Persegi") {
      double s;
      cin >> s;
      bangun = new Persegi(i+1, s);
    }

    if (bangun != nullptr) {
      daftarBangun.push_back(bangun);
    }
  }

  int start;
  int end;
  double sumLuas = 0.0;

  cin >> start >> end;

  for (int i = start-1; i < end; i++) {
    daftarBangun[i]->show();
    daftarBangun[i]->hitungLuas();
    sumLuas += daftarBangun[i]->getLuas();
  }

  cout << "-----------------------------" << endl;
  cout << "TOTAL LUAS     : " << fixed << setprecision(2) << sumLuas << endl;
  cout << "-----------------------------" << endl;

  for (Ruang2D* bangun : daftarBangun) {
    delete bangun;
  }

  return 0;
}