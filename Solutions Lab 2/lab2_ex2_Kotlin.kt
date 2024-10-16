class Motorbike(val manufacturer: String, val model: String) {
    var year: Int = 0
    var mileage: Int = 0
    var engineSize: Int = 0

    constructor(manufacturer: String, model: String, year: Int, mileage: Int, engineSize: Int) : this(manufacturer, model) {
        this.year = year
        this.mileage = mileage
        this.engineSize = engineSize
    }

    fun showInfo() {
        println("Manufacturer: $manufacturer")
        println("Model: $model")
        println("Year: $year")
        println("Mileage: $mileage")
        println("Engine size: $engineSize cc")
        println()
    }

}

fun main() {
    val motorbike = Motorbike("Yamaha", "YZF-R6", 2019, 0, 600)
    motorbike.showInfo()

    val motorbike2 = Motorbike("Kawasaki", "Ninja 300")
    motorbike2.showInfo()
}
