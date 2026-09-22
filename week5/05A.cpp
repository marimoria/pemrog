#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Karyawan {
  private:
    string noIdentitas;
    string nama;
    int gaji;

  public:
    Karyawan(string ni, string na):noIdentitas(ni), nama(na) {}

    virtual ~Karyawan() {}

    virtual void hitungGaji() {
      setGaji(0);
    }

    void printGaji(long long nilai) {
      if (nilai >= 1000) {
          printGaji(nilai / 1000);
          cout << "," << setfill('0') << setw(3) << nilai % 1000;
      } else {
          cout << nilai;
      }
    }

    void show() {
      cout << noIdentitas << " : ";
      printGaji(gaji);
      cout << endl;
    }

    void setNoIdentias(string ni) {
      noIdentitas = ni;
    }
    string getNoIdentitas() {
      return noIdentitas;
    }

    void setNama(string na) {
      nama = na;
    }
    string getNama() {
      return nama;
    }

    void setGaji(int g) {
      gaji = g;
    }
    int getGaji() {
      return gaji;
    }
};

class KaryawanTetap: public Karyawan {
  private:
    int gajiPokok;
    int tunjangan;
    int bonus;

  public:
    KaryawanTetap(string ni, string na, int gp, int t, int b):
      Karyawan(ni, na), gajiPokok(gp), tunjangan(t), bonus(b) {}

    void hitungGaji() override {
      setGaji(gajiPokok + tunjangan + bonus);
    }

    void setGajiPokok(int gp) {
      gajiPokok = gp;
    }
    int getGajiPokok() {
      return gajiPokok;
    }

    void setTunjuangan(int t) {
      tunjangan = t;
    }
    int getTunjangan() {
      return tunjangan;
    }

    void setBonus(int b) {
      bonus = b;
    }
    int getBonus() {
      return bonus;
    }
};

class KaryawanKontrak: public Karyawan {
  private:
    int nilaiKontrak;
    int tunjangan;

  public:
    KaryawanKontrak(string ni, string na, int nk, int t):
      Karyawan(ni, na), nilaiKontrak(nk), tunjangan(t) {}

    void hitungGaji() override {
      setGaji(llrint((nilaiKontrak / 12.0) + tunjangan));
    }

    void setNilaiKontrak(int nk) {
      nilaiKontrak = nk;
    }
    int getNilaiKontrak() {
      return nilaiKontrak;
    }

    void setTunjuangan(int t) {
      tunjangan = t;
    }
    int getTunjangan() {
      return tunjangan;
    }
};

class KaryawanHarian: public Karyawan {
  private:
    int totalHari;
    int upahHarian;
    int insentif;

  public:
    KaryawanHarian(string ni, string na, int th, int uh, int i):
      Karyawan(ni, na), totalHari(th), upahHarian(uh), insentif(i) {}

    void hitungGaji() override {
      setGaji(totalHari * (upahHarian + insentif));
    }

    void setUpahHarian(int uh) {
      upahHarian = uh;
    }
    int getUpahHarian() {
      return upahHarian;
    }

    void setTotalHari(int th) {
      totalHari = th;
    }
    int getTotalHari() {
      return totalHari;
    }
};

int main() {
  vector<Karyawan*> daftarDataKaryawan;
  string dataSatuKaryawan;

  while (getline(cin, dataSatuKaryawan)) {
    vector<string> dataPerKolom;
    stringstream ss(dataSatuKaryawan); 
    string token;

    while (getline(ss, token, ',')) {
      dataPerKolom.push_back(token);
    }

    Karyawan* karyawan = nullptr;

    if (dataPerKolom[0] == "1") {
      karyawan = new KaryawanTetap(dataPerKolom[1], dataPerKolom[2],
                                  atoi(dataPerKolom[3].c_str()),
                                  atoi(dataPerKolom[4].c_str()),
                                  atoi(dataPerKolom[5].c_str()));
    } else if (dataPerKolom[0] == "2") {
      karyawan = new KaryawanKontrak(dataPerKolom[1], dataPerKolom[2],
                                    atoi(dataPerKolom[3].c_str()),
                                    atoi(dataPerKolom[4].c_str()));
    } else if (dataPerKolom[0] == "3") {
      karyawan = new KaryawanHarian(dataPerKolom[1], dataPerKolom[2],
                                    atoi(dataPerKolom[3].c_str()),
                                    atoi(dataPerKolom[4].c_str()),
                                    atoi(dataPerKolom[5].c_str()));
    }

    if (karyawan != nullptr) {
      daftarDataKaryawan.push_back(karyawan);
    }
  }

  for (Karyawan* dataKaryawan : daftarDataKaryawan) {
    dataKaryawan->hitungGaji();
    dataKaryawan->show();
    delete dataKaryawan;
  }

  daftarDataKaryawan.clear();

  return 0;
}