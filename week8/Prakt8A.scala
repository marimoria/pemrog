import scala.io.StdIn

object Prakt8A {
  def main(args: Array[String]): Unit = {
    val inputN = StdIn.readLine()
      
    if (inputN != null) {
      val n = inputN.trim.toInt
      val inputBilangan = StdIn.readLine()
        
      if (inputBilangan != null) {
        val bilangan = inputBilangan.trim.split("\\s+").map(_.toInt)
        val ganjil = bilangan.filter(x => x % 2 != 0)
        
        if (ganjil.nonEmpty) {
          println(s"${bilangan.min} ${bilangan.max} ${ganjil.sum}")
        } else {
		      println(s"${bilangan.min} ${bilangan.max} 0")
	      }
      }
    }
  }
}
