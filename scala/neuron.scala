package neuron

abstract class Neuron(size : Int, val stepSize : Double){
  val r = new util.Random
  var bias = r.nextFloat
  var weights : Array[Double] = Array.fill(size)(r.nextFloat)
  def activation(x : Double) : Double = x;
  def activationDer(y: Double) : Double = y;
  var output : Double = _;
  var inputs : Array[Double] =  _;
  def feedForward(ins: Array[Double]) : Double = {
    var sum : Double = 0;
    inputs = ins;
    (inputs, weights).zipped.foreach{ (i,w)  => sum += i*w};
    output = activation(sum + bias);
    output
  }
  def backPropagate(error : Double) : Array[Double] = {
    var errors = (inputs, weights).zipped.map{ (i : Double, w : Double) => (error * activationDer(output) * w , w  - stepSize * error * activationDer(output) * i)};
    weights = errors.map{ case (i, w) => w};
    errors.map{ case (i,w) => i}
  }  
}
