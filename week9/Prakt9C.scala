import scala.io.StdIn

object Main {
  def main(args: Array[String]): Unit = {
    val Array(n, c) = StdIn.readLine().trim.split("\\s+")
    val huruf = c.head.toLower
    val daftarNama = List.fill(n.toInt)(StdIn.readLine().trim)

    val jumlah = daftarNama.count(nama => nama.toLowerCase.contains(huruf))

    println(jumlah)
  }
}