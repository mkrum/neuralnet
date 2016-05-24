package network
import neuron.Neuron
import layer.Layer

abstract class Network{
  def layers : Array[Layer]
  def outputNeuron : Neuron 
  var output : Double = _;
  def cost(actual : Double, test : Double) : Double = actual
  def costDer(actual: Double, test : Double) : Double = actual
  def feedForward(ins: Array[Double]) = {
    var inputs = ins;  
    layers foreach { x => inputs = x.feedForward(inputs);}
    outputNeuron.feedForward(inputs)
  }
  def backPropagate(target : Double) {
    var error : Array[Double]  = outputNeuron.backPropagate(costDer(output, target));
    layers.reverse.foreach{ x => error = x.backPropagate(error) };
  } 
  def computeError(values : Array[Array[Double]], targets : Array[Double]) = (values, targets).zipped.map{ case (v : Array[Double], t : Double) => cost(feedForward(v), t)}.sum  
} 
