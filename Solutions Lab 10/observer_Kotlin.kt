// sursa de informare (same with c++): https://www.geeksforgeeks.org/observer-pattern-c-design-patterns/

// pros:
// - permite unui obiect sa notifice alte obiecte fara a fi nevoie sa stie detalii despre acele obiecte
// - incapsuleaza transmiterea update-urile parametrilor catre alte obiecte

// cons:
// - poate duce la o serie de update-uri in cascada
// - ma gandesc ca daca nu este suficient de securizat, pot aparea observeri nedoriti care sa citeasca eventualele date


// Observer interface
interface Observer {
    fun update(powerLeft: Int, timeLeft: Int)
}

// Subject class
class Battery {
    private var powerLeft: Int = 0
    private var timeLeft: Int = 0
    private val observers = mutableListOf<Observer>()

    fun registerObserver(observer: Observer) {
        observers.add(observer)
    }

    private fun notifyObservers() {
        for (observer in observers) {
            observer.update(powerLeft, timeLeft)
        }
    }

    fun setValues(powerLeft: Int, timeLeft: Int) {
        this.powerLeft = powerLeft
        this.timeLeft = timeLeft
        notifyObservers()
    }
}

// Concrete Observer class
class User : Observer {
    override fun update(powerLeft: Int, timeLeft: Int) {
        println("Power left: $powerLeft% -> Time left: $timeLeft minutes")
    }
}

fun main() {
    val battery = Battery()
    val user = User()

    battery.registerObserver(user)

    battery.setValues(50, 30)
    battery.setValues(20, 10)
}