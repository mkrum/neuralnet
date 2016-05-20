import neuron.Neuron

class sigmoidneuron(size: Int, stepSize: Double)  extends Neuron(size, stepSize) {
  override def activation(x : Double): Double  = 1/(1 + scala.math.exp(-x))
  override def activationDer(x: Double): Double  = activation(x) * (1 - activation(x))
 
}
