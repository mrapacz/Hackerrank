import scala.annotation.tailrec

/**
  * Created by maciej on 16.04.16.
  */
object TaumAndBday {
  def task(b: Int, w: Int, x: Int, y: Int, z: Int): Long = {
    @tailrec
    def solution(b: Int, w: Int, x: Int, y: Int, z: Int, res: Long): Long = {
      if (b == 0 && w == 0) res
      else solution(0, 0, x, y, z, b.toLong * x + w * y.toLong)
    }
    if (z + x < y) solution(b, w, x, z + x, z, 0)
    else if (z + y < x) solution(b, w, z + y, y, z, 0)
    else solution(b, w, x, y, z, 0)
  }

  def main(args: Array[String]) {
    val sc = new java.util.Scanner(System.in);
    var Z = sc.nextInt()

    while (Z > 0) {
      var b = sc.nextInt();
      var w = sc.nextInt();
      var x = sc.nextInt();
      var y = sc.nextInt();
      var z = sc.nextInt();
      println(task(b, w, x, y, z))
      Z -= 1
    }
  }
}
