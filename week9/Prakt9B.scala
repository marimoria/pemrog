import scala.io.StdIn

object Main {
  def main(args: Array[String]): Unit = {
    val Array(n, k) = StdIn.readLine().trim.split("\\s+").map(_.toLong)
    val deret = StdIn.readLine().trim.split("\\s+").map(_.toLong)

    val ditemukan = deret.exists(x => x == k)

    println(if (ditemukan) 1 else 0)
  }
}