// Pros:
// - flexibil, permite crearea obiectelor complexe pas cu pas
// - ofera cod clar prin separarae componentelor, logica si constructia obiectului
// - ofera cod reutilizabil, putem avea acelasi proces de constructie pentru a crea diferite reprezentari ale unui obiect

// Cons:
// - introduce mai multe clase si interfete, complicand inutil proiectele mici
// - excesiv pentru obiecte simple, adauga complexitate inutila
// - consuma mai multe resurse

/// Sursa informatiilor : geeksforgeeks.org/builder-pattern-c-design-patterns/

class Salad {
    private var dressing: String = ""
    private var vegetables: String = ""
    private var toppings: String = ""

    fun setDressing(dressing: String) {
        this.dressing = dressing
    }

    fun setVegetables(vegetables: String) {
        this.vegetables = vegetables
    }

    fun setToppings(toppings: String) {
        this.toppings = toppings
    }

    fun getDressing(): String {
        return dressing
    }

    fun getVegetables(): String {
        return vegetables
    }

    fun getToppings(): String {
        return toppings
    }
}

// Builder interface
interface SaladBuilder {
    fun buildDressing(dressing: String)
    fun buildVegetables(vegetables: String)
    fun buildToppings(toppings: String)
    fun getSalad(): Salad
}

// Concrete Builder for Caesar Salad
class CaesarSaladBuilder : SaladBuilder {
    private val salad = Salad()

    override fun buildDressing(dressing: String) {
        salad.setDressing(dressing)
    }

    override fun buildVegetables(vegetables: String) {
        salad.setVegetables(vegetables)
    }

    override fun buildToppings(toppings: String) {
        salad.setToppings(toppings)
    }

    override fun getSalad(): Salad {
        return salad
    }
}

// Director for Caesar Salad
class CaesarSaladAssembler {
    fun assembleCaesarSalad(builder: SaladBuilder): Salad {
        builder.buildDressing("Caesar")
        builder.buildVegetables("Lettuce, Spinach, Kale")
        builder.buildToppings("Croutons, Parmesan Cheese")
        return builder.getSalad()
    }
}

// Concrete Builder for Greek Salad
class GreekSaladBuilder : SaladBuilder {
    private val salad = Salad()

    override fun buildDressing(dressing: String) {
        salad.setDressing(dressing)
    }

    override fun buildVegetables(vegetables: String) {
        salad.setVegetables(vegetables)
    }

    override fun buildToppings(toppings: String) {
        salad.setToppings(toppings)
    }

    override fun getSalad(): Salad {
        return salad
    }
}

// Director for Greek Salad
class GreekSaladAssembler {
    fun assembleGreekSalad(builder: SaladBuilder): Salad {
        builder.buildDressing("Greek")
        builder.buildVegetables("Tomatoes, Cucumbers, Onions")
        builder.buildToppings("Feta Cheese, Olives")
        return builder.getSalad()
    }
}

fun main() {
    val caesarBuilder = CaesarSaladBuilder()
    val caesarAssembler = CaesarSaladAssembler()
    val caesarSalad = caesarAssembler.assembleCaesarSalad(caesarBuilder)

    println("New salad")
    println("Salad dressing: ${caesarSalad.getDressing()}")
    println("Salad vegetables: ${caesarSalad.getVegetables()}")
    println("Salad toppings: ${caesarSalad.getToppings()}")
    println()

    val greekBuilder = GreekSaladBuilder()
    val greekAssembler = GreekSaladAssembler()
    val greekSalad = greekAssembler.assembleGreekSalad(greekBuilder)

    println("New salad")
    println("Salad dressing: ${greekSalad.getDressing()}")
    println("Salad vegetables: ${greekSalad.getVegetables()}")
    println("Salad toppings: ${greekSalad.getToppings()}")
}
