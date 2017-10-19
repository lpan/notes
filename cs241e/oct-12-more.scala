// First-class functions = function values
// Lambdas = anonymous functions

object Obj {
  def procedure(x: Int) = x + 1

  var increase: (Int) => (Int) = procedure

  increase(5) // => 6

  increase = { x => x + 2 }

  increase(5) // => 7

  List(5, 6, 7).map(increase) // List(7, 8, 9)
}

