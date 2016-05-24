package sigmoid

import neuron.Neuron
import layer.Layer
import network.Network

class SigmoidNeuron(size: Int, stepSize: Double)  extends Neuron(size, stepSize) {
  override def activation(x : Double): Double  = 1/(1 + scala.math.exp(-x))
  override def activationDer(x: Double): Double  = activation(x) * (1 - activation(x))
}

class SigmoidLayer(val width : Int, val stepSize : Double) extends Layer{
  def neurons : Array[Neuron] = Array.fill(width)(new SigmoidNeuron(width, stepSize)) 
}

class SigmoidNetwork(val length : Int, val width : Int, val stepSize : Double)  extends Network {
  override def layers = Array.fill(length)(new SigmoidLayer(width, stepSize))
  override def outputNeuron : Neuron = new SigmoidNeuron(width, stepSize)
  override def cost(actual : Double, test : Double) : Double = (test - actual) * (test - actual)
  override def costDer(actual : Double, test : Double) : Double = -(test-actual)
}
