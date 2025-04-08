// sursa de informare (same with c++): https://www.geeksforgeeks.org/facade-method-c-design-patterns/

// pros:
// - ascunde complexitatea sistemului
// - ofera o interfata simplificata pentru client

// cons:
// - poate duce la o interfata prea generalizata
// - poate fi prea complex in cazuri relativ simple


class Engine {
    fun start() {
        println("\tEngine started.")
    }
}

class SparkPlug {
    fun ignite() {
        println("\tSpark plug ignited.")
    }
}

class FuelInjector {
    fun inject() {
        println("\tFuel injected.")
    }
}

class DoTheBmwStart {
    fun leak() {
        println("\tLeaking oil. It means that there's oil inside, no need to worry!")
    }
}

class Car {
    private val engine = Engine()
    private val sparkPlug = SparkPlug()
    private val fuelInjector = FuelInjector()
    private val doTheBmwStart = DoTheBmwStart()

    fun start() {
        engine.start()
        sparkPlug.ignite()
        fuelInjector.inject()
        doTheBmwStart.leak()

        println("Car started. Ready to drive!")
    }
}

fun main() {
    val car = Car()
    car.start()
}