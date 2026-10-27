import java.util.Scanner;

interface Number {
    double absoluteValue();
}

class Rational implements Number {
    private int pembilang;
    private int penyebut;

    public Rational(int pembilang, int penyebut) {
        this.pembilang = pembilang;
        this.penyebut = penyebut;
    }

    @Override
    public double absoluteValue() {
        return Math.abs((double) pembilang / penyebut);
    }
}

class Real implements Number {
    private double nilai;

    public Real(double nilai) {
        this.nilai = nilai;
    }

    @Override
    public double absoluteValue() {
        return Math.abs(nilai);
    }
}

class Complex implements Number {
    private double bagianRiil;
    private double bagianImajiner;

    public Complex(double bagianRiil, double bagianImajiner) {
        this.bagianRiil = bagianRiil;
        this.bagianImajiner = bagianImajiner;
    }

    @Override
    public double absoluteValue() {
        return Math.sqrt((bagianRiil * bagianRiil) + (bagianImajiner * bagianImajiner));
    }
}

class Praktikum7C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) {
            scanner.close();
            return;
        }

        int jumlahData = scanner.nextInt();
        double totalNilaiMutlak = 0;

        for (int i = 0; i < jumlahData; i++) {
            String tipe = scanner.next();
            Number angka = null;

            if (tipe.equals("R")) {
                double nilaiRiil = scanner.nextDouble();
                angka = new Real(nilaiRiil);
            } else if (tipe.equals("P")) {
                int pembilang = scanner.nextInt();
                int penyebut = scanner.nextInt();
                angka = new Rational(pembilang, penyebut);
            } else if (tipe.equals("C")) {
                double bagianRiil = scanner.nextDouble();
                double bagianImajiner = scanner.nextDouble();
                angka = new Complex(bagianRiil, bagianImajiner);
            }

            if (angka != null) {
                totalNilaiMutlak += angka.absoluteValue();
            }
        }

        System.out.printf("%.2f\n", totalNilaiMutlak);

        scanner.close();
    }
}
