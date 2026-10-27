import java.util.Scanner;

abstract class Ruang2D {
    abstract double hitungLuas();
    abstract double hitungKeliling();
}

class Segiempat extends Ruang2D {
    private double panjang;
    private double lebar;

    public Segiempat(double panjang, double lebar) {
        this.panjang = panjang;
        this.lebar = lebar;
    }

    @Override
    double hitungLuas() {
        return panjang * lebar;
    }

    @Override
    double hitungKeliling() {
        return 2 * (panjang + lebar);
    }
}

class Segitiga extends Ruang2D {
    private double alas;
    private double tinggi;

    public Segitiga(double alas, double tinggi) {
        this.alas = alas;
        this.tinggi = tinggi;
    }

    @Override
    double hitungLuas() {
        return 0.5 * alas * tinggi;
    }

    @Override
    double hitungKeliling() {
        double sisiMiring = Math.sqrt((alas * alas) + (tinggi * tinggi));
        return alas + tinggi + sisiMiring;
    }
}

class Praktikum7B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        double totalLuasSegiempat = 0;
        double totalKelilingSegiempat = 0;
        double totalLuasSegitiga = 0;
        double totalKelilingSegitiga = 0;
        
        while (scanner.hasNext()) {
            String tipe = scanner.next();
            if (tipe.equals("X")) {
                break;
            }
            
            double besaranSatu = scanner.nextDouble();
            double besaranDua = scanner.nextDouble();
            
            if (tipe.equals("R")) {
                Ruang2D segiempat = new Segiempat(besaranSatu, besaranDua);
                totalLuasSegiempat += segiempat.hitungLuas();
                totalKelilingSegiempat += segiempat.hitungKeliling();
            } else if (tipe.equals("T")) {
                Ruang2D segitiga = new Segitiga(besaranSatu, besaranDua);
                totalLuasSegitiga += segitiga.hitungLuas();
                totalKelilingSegitiga += segitiga.hitungKeliling();
            }
        }
        
        System.out.println("LUAS");
        System.out.printf("- Segiempat : %.2f\n", totalLuasSegiempat);
        System.out.printf("- Segitiga : %.2f\n", totalLuasSegitiga);
        System.out.println("KELILING");
        System.out.printf("- Segiempat : %.2f\n", totalKelilingSegiempat);
        System.out.printf("- Segitiga : %.2f\n", totalKelilingSegitiga);
        
        scanner.close();
    }
}
