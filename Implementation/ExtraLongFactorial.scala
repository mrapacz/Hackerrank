/**
  * Created by maciej on 16.04.16.
  */

import scala.annotation.tailrec

object Solution {

  @tailrec
  def factorial(n: Int, res: BigInt): BigInt = {
    if (n == 1) res
    else factorial(n - 1, res * n)
  }

  def main(args: Array[String]) {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    println(factorial(n, 1))
  }
}
