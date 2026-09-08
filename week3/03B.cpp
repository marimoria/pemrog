#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pegawai {
  protected:
    string id;
    int usia;
    int tipe;
    int income;

  public:
    Pegawai() {
      id = "";
      usia = 0;
      income = 0;
      tipe = 1;
    }

    void set(string pid, int u, int t) {
      id = pid;
      usia = u;
      tipe = t;
    }

    string getID() { return id; }

    void show() { 
      cout << id << " " << tipe << " " << income << "\n"; 
    }
};

class Tetap: public Pegawai {
  private:
    int gajiPokok;

  public:
    Tetap(): gajiPokok(0) {}

    void setGajiPokok(int gaji) {
      gajiPokok = gaji;
      income = gaji;
    }

    void tambahLembur(int uangLembur) {
      income = gajiPokok + uangLembur;
    }
};

class Harian: public Pegawai {
  public:
    Harian() { tipe = 2; }

    void setUpah(int upah) { income = upah; }
};

int main() {
  int n;
  cin >> n;

  vector<Tetap> pegawaiTetap;
  vector<Harian> pegawaiHarian;

  for (int i = 0; i < n; i++) {
    string idInput;
    int usia, tipe;
        
    cin >> idInput >> usia >> tipe; 

    if (tipe == 1) {
      int gajiPokok;
      cin >> gajiPokok;
            
      Tetap pegawai;
      pegawai.set(idInput, usia, tipe);
      pegawai.setGajiPokok(gajiPokok);
      pegawaiTetap.push_back(pegawai);
    } else {
      Harian pegawai;
      pegawai.set(idInput, usia, tipe);
      pegawaiHarian.push_back(pegawai);
    }
  }

  string idInput;
  int nilai;

  while (cin >> idInput) { 
    if (idInput == "END") break;
        
    cin >> nilai;
        
    for (int i = 0; i < pegawaiTetap.size(); i++) {
      if (pegawaiTetap[i].getID() == idInput) {
        pegawaiTetap[i].tambahLembur(nilai);
        break;
      }
    }
        
    for (int i = 0; i < pegawaiHarian.size(); i++) {
      if (pegawaiHarian[i].getID() == idInput) {
        pegawaiHarian[i].setUpah(nilai);
        break;
      }
    }
  }


  for (int i = 0; i < pegawaiTetap.size(); i++) {
    pegawaiTetap[i].show(); 
  }
  for (int i = 0; i < pegawaiHarian.size(); i++) {
    pegawaiHarian[i].show();
  }

  return 0;
}
