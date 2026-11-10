import scala.io.StdIn

object Prakt9A {
  def main(args: Array[String]): Unit = {
    val n = StdIn.readInt()
    val deret = StdIn.readLine().trim.split("\\s+").map(_.toLong)

    val hasil = deret.filter(x => x % 2 == 0).map(x => x * x).sum

    println(hasil)
  }
}