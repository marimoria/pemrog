import java.util.Scanner
import math.abs

object Prakt8B {
  def main(args: Array[String]): Unit = {
    val scanner = new Scanner(System.in)
    val n = scanner.nextInt()
    
    val array1 = Array.fill(n)(abs(scanner.nextLong()))
    val array2 = Array.fill(n)(abs(scanner.nextLong()))
    
    println(array1.max * array2.max)
  }
}