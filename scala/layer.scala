import neuron.Neuron
import sigmoid.SigmoidNeuron

abstract class Layer {
  def neurons : Array[Neuron]
  def feedForward(inputs : Array[Double]) : Array[Double] = neurons map { x => x.feedForward(inputs) }
  def backPropagate(error : Array[Double]) : Array[Double] = (neurons, error).zipped.map{ (n,e)  => n.backPropagate(e) }.transpose.map{ _.sum }.toArray
}
