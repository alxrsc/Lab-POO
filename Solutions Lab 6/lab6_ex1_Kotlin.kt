abstract class Country {
    protected var name: String = ""
    protected var population: Int = 0
    protected var foundationYear: Int = 0

    abstract fun printName()
    abstract fun printPopulation()
    abstract fun printFoundationYear()
}

class Romania : Country() {
    init {
        name = "Romania"
        population = 19
        foundationYear = 1918
    }

    override fun printName() {
        println("The name of the country is $name")
    }

    override fun printPopulation() {
        println("The population of $name is $population")
    }

    override fun printFoundationYear() {
        println("The foundation year of $name is $foundationYear")
    }
}

class Azerbaijan : Country() {
    init {
        name = "Azerbaijan"
        population = 10
        foundationYear = 1918
    }

    override fun printName() {
        println("The name of the country is $name")
    }

    override fun printPopulation() {
        println("The population of $name is $population")
    }

    override fun printFoundationYear() {
        println("The foundation year of $name is $foundationYear")
    }
}

class Khazakstan : Country() {
    init {
        name = "Khazakstan"
        population = 18
        foundationYear = 1991
    }

    override fun printName() {
        println("The name of the country is $name")
    }

    override fun printPopulation() {
        println("The population of $name is $population")
    }

    override fun printFoundationYear() {
        println("The foundation year of $name is $foundationYear")
    }
}

fun main() {

    val romania = Romania()

    romania.printName()
    romania.printPopulation()
    romania.printFoundationYear()
    println()

    val azerbaijan = Azerbaijan()

    azerbaijan.printName()
    azerbaijan.printPopulation()
    azerbaijan.printFoundationYear()
    println()

    val khazakstan = Khazakstan()

    khazakstan.printName()
    khazakstan.printPopulation()
    khazakstan.printFoundationYear()

}