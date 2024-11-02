// fun fact: numele ciudate alese pentru unele settere si gettere, adica select si return, sunt alese din cauza
// faptului ca Kotlin nu permitea folosirea cuvintelor cheie get si set pentru a denumi metodele getType, getOrigin, etc. din cauza unei suprapuneri de nume
// cu niste functii get si set din Java pe care totusi nu le gasesc cand incerc eu sa le apelez... tot nu sunt lamurit, but now it works on my machine :D

open class Beer() {
    protected var type: String = "Unknown"
    protected var origin: String = "Unknown"

    fun selectType(type: String) {
        this.type = type
    }

    fun selectOrigin(origin: String) {
        this.origin = origin
    }

    fun returnType(): String {
        return type
    }

    fun returnOrigin(): String {
        return origin
    }

    constructor(type: String, origin: String) : this() {
        this.type = type
        this.origin = origin
    }
}

class BeerTypeA() : Beer() {
    private var length: Int = 0

    constructor(type: String, origin: String, length: Int) : this() {
        this.type = type
        this.origin = origin
        this.length = length
    }

    fun setLength(length: Int) {
        this.length = length
    }

    fun getLength(): Int {
        return length
    }

    fun getArea(): Int {
        return length * length
    }
}

class BeerTypeB() : Beer() {
    private var radius: Int = 0

    constructor(type: String, origin: String, radius: Int) : this() {
        this.type = type
        this.origin = origin
        this.radius = radius
    }

    fun setRadius(radius: Int) {
        this.radius = radius
    }

    fun getRadius(): Int {
        return radius
    }

    fun getArea(): Double {
        return 3.14 * radius * radius
    }
}

class BeerTypeC() : Beer() {
    private var length: Int = 0
    private var width: Int = 0

    constructor(type: String, origin: String, length: Int, width: Int) : this() {
        this.type = type
        this.origin = origin
        this.length = length
        this.width = width
    }

    fun setLength(length: Int) {
        this.length = length
    }

    fun setWidth(width: Int) {
        this.width = width
    }

    fun getLength(): Int {
        return length
    }

    fun getWidth(): Int {
        return width
    }

    fun getArea(): Int {
        return length * width
    }
}

fun main() {
    val beerTypeA = BeerTypeA("Heineken", "Netherlands", 5)
    println("Type: ${beerTypeA.returnType()}")
    println("Origin: ${beerTypeA.returnOrigin()}")
    println("Length: ${beerTypeA.getLength()}")
    println("Area: ${beerTypeA.getArea()}")

    val beerTypeB = BeerTypeB("Tuborg", "Denmark", 7)
    beerTypeB.setRadius(5)
    println()
    println("Type: ${beerTypeB.returnType()}")
    println("Origin: ${beerTypeB.returnOrigin()}")
    println("Radius: ${beerTypeB.getRadius()}")
    println("Area: ${beerTypeB.getArea()}")

    val beerTypeC = BeerTypeC("Timisoreana", "Romania", 3, 4)
    beerTypeC.setLength(5)
    beerTypeC.setWidth(10)
    println()
    println("Type: ${beerTypeC.returnType()}")
    println("Origin: ${beerTypeC.returnOrigin()}")
    println("Length: ${beerTypeC.getLength()}")
    println("Width: ${beerTypeC.getWidth()}")
    println("Area: ${beerTypeC.getArea()}")
}
