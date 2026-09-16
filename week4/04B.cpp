#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

class Kendaraan {
  protected:
    string nomorPlat;
    string jenisKendaraan;
    int jamMasuk; // 24 jam
    int jamKeluar; // 24 jam

  public:
    Kendaraan(string np, string jenisK, int jm, int jk):
      nomorPlat(np), jenisKendaraan(jenisK), jamMasuk(jm), jamKeluar(jk) {}

    virtual ~Kendaraan() {}
    
    int hitungDurasi() {
      return (jamKeluar - jamMasuk);
    }

    virtual string getKendaraan() {
      return "Kendaraan";
    }

    virtual int hitungTarif() {
      return 0;
    }

    virtual void tampilkanInfo() {
      cout << "Kendaraan       : " << getKendaraan() << endl;
      cout << "Nomor Plat      : " << nomorPlat << endl;
      cout << "Jenis Kendaraan : " << jenisKendaraan << endl;
      cout << "Durasi Parkir   : " << hitungDurasi() << " Jam (" 
        << setfill('0') << setw(2) << jamMasuk << ":00 - "
        << setfill('0') << setw(2) << jamKeluar << ":00)" << endl;
    }
};

class Mobil: public Kendaraan {
  private:
    int kapasitasPenumpang;

  public:
    Mobil(string np, string jenisK, int jm, int jk, int kp):
      Kendaraan(np, jenisK, jm, jk), kapasitasPenumpang(kp) {}

    string getKendaraan() override {
      return "Mobil";
    }

    int hitungTarif() override {
      int durasiTambahan = max(0, hitungDurasi() - 1);
      return (5000 + (durasiTambahan * 3000));
    }

    void tampilkanInfo() override {
      Kendaraan::tampilkanInfo();
      cout << "Kapasitas       : " << kapasitasPenumpang << " Penumpang" << endl;
      cout << "Total Tarif     : " << "Rp " << hitungTarif() << endl;
    }
};

class Motor: public Kendaraan {
  private:
    string jenisMotor;

  public:
    Motor(string np, string jenisK, int jm, int jk, string jenisM):
      Kendaraan(np, jenisK, jm, jk), jenisMotor(jenisM) {}

    string getKendaraan() override {
      return "Motor";
    }

    int hitungTarif() override {
      int durasiTambahan = max(0, hitungDurasi() - 1);
      return (2000 + (durasiTambahan * 1000));
    }

    void tampilkanInfo() override {
      Kendaraan::tampilkanInfo();
      cout << "Tipe Motor      : " << jenisMotor << endl;
      cout << "Total Tarif     : " << "Rp " << hitungTarif() << endl;
    }
};

int main() {
  int n;
  cin >> n;

  vector<Kendaraan*> daftarKendaraan;

  for (int i = 0; i < n; i++) {
    string namaKendaraan;
    string platKendaraan;
    string jenisKendaraan;
    int jamMasukParkir;
    int jamKeluarParkir;

    cin >> namaKendaraan;

    if (namaKendaraan == "Mobil") {
      int kapasitasMobil;
      cin >> platKendaraan >> jenisKendaraan >> kapasitasMobil >> jamMasukParkir >> jamKeluarParkir;

      Kendaraan* mobil = new Mobil(platKendaraan, jenisKendaraan, jamMasukParkir, jamKeluarParkir, kapasitasMobil);
      daftarKendaraan.push_back(mobil);
    } else if (namaKendaraan == "Motor") {
      string jenisMotor;
      cin >> platKendaraan >> jenisKendaraan >> jenisMotor >> jamMasukParkir >> jamKeluarParkir;

      Kendaraan* motor = new Motor(platKendaraan, jenisKendaraan, jamMasukParkir, jamKeluarParkir, jenisMotor);
      daftarKendaraan.push_back(motor);
    }
  }

  for (int i = 0; i < daftarKendaraan.size(); i++) {
    cout << "--- DATA PARKIR KENDARAAN " << (i + 1) << " ---" << endl;
    daftarKendaraan[i]->tampilkanInfo();

    if (i != daftarKendaraan.size() - 1) {
      cout << endl;
    }
  }

  for (Kendaraan* k : daftarKendaraan) {
    delete k;
  }
  daftarKendaraan.clear();

  return 0;
}