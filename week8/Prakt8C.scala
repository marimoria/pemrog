import java.util.Scanner

object Main {
  def main(args: Array[String]): Unit = {
    val scanner = new Scanner(System.in)
    val n = scanner.nextInt()
    println(faktorial(n))
  }

  def faktorial(n: Int): BigInt = {
    if (n <= 1) 1
    else n * faktorial(n - 1)
  }
}