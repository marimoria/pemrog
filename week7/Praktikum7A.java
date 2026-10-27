import java.util.Scanner;
import java.util.Locale;

class Praktikum7A {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);

        Scanner scanner = new Scanner(System.in);
        scanner.useLocale(Locale.US);

        if (!scanner.hasNextInt()) {
            scanner.close();
            return;
        }

        int n = scanner.nextInt();
        double[] daftarNilai = new double[n];
        double totalNilai = 0;

        for (int i = 0; i < n; i++) {
            daftarNilai[i] = scanner.nextDouble();
            totalNilai += daftarNilai[i];
        }

        double nilaiTerkecil = daftarNilai[0];
        double nilaiTerbesar = daftarNilai[0];

        for (int i = 1; i < n; i++) {
            if (daftarNilai[i] < nilaiTerkecil) {
                nilaiTerkecil = daftarNilai[i];
            }
            if (daftarNilai[i] > nilaiTerbesar) {
                nilaiTerbesar = daftarNilai[i];
            }
        }

        double rataan = totalNilai / n;
        double jumlahKuadratSelisih = 0;

        for (int i = 0; i < n; i++) {
            double selisih = daftarNilai[i] - rataan;
            jumlahKuadratSelisih += selisih * selisih;
        }

        double simpanganBaku = 0;
        if (n > 1) {
            simpanganBaku = Math.sqrt(jumlahKuadratSelisih / (n - 1));
        }

        System.out.printf("%.2f %.2f\n", nilaiTerkecil, nilaiTerbesar);
        System.out.printf("%.2f %.2f\n", rataan, simpanganBaku);
        scanner.close();
    }
}
