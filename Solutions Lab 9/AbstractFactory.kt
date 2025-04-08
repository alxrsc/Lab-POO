// Pros:
// - este mai flexibil, separand crearea obiectelor de utilizarea lor, premitand schimbarea tipurilor de produse create fara a modifica codul client
// - este consistent, asigura ca obiectele dintr-o familie de produse sunt compatibile intre ele
// - este extensibil, adaugarea unor noi familii de produse este simpla, fara a afecta codul deja existent

// Cons:
// - mai complex, crescand numarul de clase din cod, ineficient pentru proiecte mici
// - dificil de configurat, este nevoie de setari suplimentare pentru a determina fabrica utilizata
// - relativ ridig, adaugarea de noi metode la fabrica abstracta necesita modificari in toate clasele ce o mostentesc
/// Sursa informatiilor : geeksforgeeks.org/abstract-factory-pattern-c-design-patterns/

// Abstract product interface
class Airplane {
    private var model: String = ""
    private var engine: String = ""
    private var enginesNumber: Int = 0

    fun setModel(model: String) {
        this.model = model
    }

    fun setEngine(engine: String) {
        this.engine = engine
    }

    fun setEnginesNumber(enginesNumber: Int) {
        this.enginesNumber = enginesNumber
    }

    fun getModel(): String {
        return model
    }

    fun getEngine(): String {
        return engine
    }

    fun getEnginesNumber(): Int {
        return enginesNumber
    }
}

// Abstract Factory interface
interface AirplaneFactory {
    fun createBoeingAirplane(): Airplane?
    fun createBombardierAirplane(): Airplane?
}

// Concrete Factories
class BoeingFactory : AirplaneFactory {
    override fun createBoeingAirplane(): Airplane {
        val airplane = Airplane()
        airplane.setModel("Boeing 747")
        airplane.setEngine("GE CF6-80C2B1F")
        airplane.setEnginesNumber(4)
        return airplane
    }

    override fun createBombardierAirplane(): Airplane? {
        return null
    }
}

class BombardierFactory : AirplaneFactory {
    override fun createBoeingAirplane(): Airplane? {
        return null
    }

    override fun createBombardierAirplane(): Airplane {
        val airplane = Airplane()
        airplane.setModel("De Havilland Canada DHC-8-315")
        airplane.setEngine("PW123E made in 1995")
        airplane.setEnginesNumber(2)
        return airplane
    }
}

fun main() {
    val boeingFactory: AirplaneFactory = BoeingFactory()
    var airplane = boeingFactory.createBoeingAirplane()

    // ? - safe call operator
    println("Model: ${airplane?.getModel()}")
    println("Engine: ${airplane?.getEngine()}")
    println("Engines number: ${airplane?.getEnginesNumber()}")
    println()

    val bombardierFactory: AirplaneFactory = BombardierFactory()
    airplane = bombardierFactory.createBombardierAirplane()

    println("Model: ${airplane?.getModel()}")
    println("Engine: ${airplane?.getEngine()}")
    println("Engines number: ${airplane?.getEnginesNumber()}")
}
