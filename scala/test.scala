import sigmoid.SigmoidNetwork

object test{
  def main(args: Array[String]) {
        var ner = new SigmoidNetwork(3, 3, .06)
        var test : Array[Double] = Array(.1, .1, .1)
        println(ner.feedForward(test).toString);
//        for( _ <- 1 to 100){
          ner.backPropagate(.5);
 //       }
        println(ner.feedForward(test).toString);
    }
}
