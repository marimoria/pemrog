#include <iomanip>
#include <iostream>
using namespace std;

class MinumanKemasan {
private:
  string namaProduk;
  int kapasitas;
  int isiSekarang;

public:
  MinumanKemasan(string n, int k): namaProduk(n), kapasitas(k), isiSekarang(k) {}

  void minum(int jumlah) {
    isiSekarang -= jumlah;
    if (isiSekarang < 0) {
      isiSekarang = 0;
    }
  }

  void isiUlang(int jumlah) {
    isiSekarang += jumlah;
    if (isiSekarang > kapasitas) {
      isiSekarang = kapasitas;
    } 
  }

  void show() {
    cout << "Nama Produk : " << namaProduk << endl;
    cout << "Kapasitas   : " << kapasitas << " ml" << endl;
    cout << "Isi Sekarang: " << isiSekarang << " ml" << endl;
  }

  void setNamaProduk(string n) { namaProduk = n; }

  void setKapasitas(int k) {
    kapasitas = k;
    if (isiSekarang > kapasitas) {
      isiSekarang = kapasitas;
    }
  }

  void setIsiSekarang(int i) {
    isiSekarang = i;
    if (isiSekarang > kapasitas) {
      isiSekarang = kapasitas;
    }
  }

  string getNamaProduk() { return namaProduk; }
  int getKapasitas() { return kapasitas; }
  int getIsiSekarang() { return isiSekarang; }
};

int main() {
  string n;
  int k;

  // tidak pakai getline karna mereka cuma dipisah oleh spasi
  // cin membelah berdasarkan spasi
  if (!(cin >> n >> k)) { return 0; }

  MinumanKemasan minuman(n, k);

  string perintah;

  while (cin >> perintah) {
    if (perintah == "minum") {
      int jml;
      cin >> jml;
      minuman.minum(jml);
    } else if (perintah == "isi") {
      int jml;
      cin >> jml;
      minuman.isiUlang(jml);
    } else if (perintah == "show") {
      minuman.show();
      break;
    }
  }

  return 0;
}
