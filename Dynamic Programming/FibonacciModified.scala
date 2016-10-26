import java.util.Scanner

import scala.annotation.tailrec

/**
  * Created by maciej on 19.04.16.
  */
object FibonacciModified {
  @tailrec
  def fib(i: Int, n: Int, a: BigInt, b: BigInt): BigInt = {
    if (i == 1) a
    if (i == n) b
    else fib(i + 1, n, b, b * b + a)
  }

  def main(args: Array[String]) {
    val sc = new java.util.Scanner(System.in);
    val a = sc.nextInt()
    val b = sc.nextInt()
    val n = sc.nextInt()
    println(fib(2, n, a, b))
  }
}