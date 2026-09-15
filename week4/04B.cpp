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

    string getKendaraan() {
      return "Mobil";
    }

    int hitungTarif() {
      return (5000 + ((hitungDurasi()-1)*3000));
    }

    void tampilkanInfo() {
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

    string getKendaraan() {
      return "Motor";
    }

    int hitungTarif() {
      return (2000 + ((hitungDurasi()-1)*1000));
    }

    void tampilkanInfo() {
      Kendaraan::tampilkanInfo();
      cout << "Tipe Motor      : " << jenisMotor << endl;
      cout << "Total Tarif     : " << "Rp " << hitungTarif() << endl;
    }
};

int main() {
  int n;
  cin >> n;

  vector<Kendaraan*> daftarKendaraan;

  for (int i = 1; i <= n; i++) {
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

  for (int i = 0; i < n; i++) {
    cout << "--- DATA PARKIR KENDARAAN " << (i + 1) << " ---" << endl;
    daftarKendaraan[i]->tampilkanInfo();

    if (i != n - 1) {
      cout << endl;
    }
  } 

  return 0;
}