class Volume {
    private var length: Int = 0
    private var radius: Double = 0.0
    private var height: Int = 0

    fun setLength(length: Int) {
        this.length = length
    }

    fun setRadius(radius: Double) {
        this.radius = radius
    }

    fun setHeight(height: Int) {
        this.height = height
    }

    fun getLength(): Int {
        return length
    }

    fun getRadius(): Double {
        return radius
    }

    fun getHeight(): Int {
        return height
    }

    fun getVolume() {
        println("Trying to calculate volume! \nPlease wait... \nFailed!")
    }

    fun getVolume(length: Int) {
        println("Volume of the cube is: ${length * length * length}")
    }

    fun getVolume(radius: Double) {
        // rotunjit la 3 zecimale
        println("Volume of the sphere is: ${"%.3f".format(4 / 3.0 * Math.PI * radius * radius * radius)}")
    }

    fun getVolume(length: Int, height: Int) {
        // rotunjit la 3 zecimale
        println("Volume of the pyramid is: ${"%.3f".format(1 / 3.0 * length * length * height)}")
    }

}


fun main() {

    var volume = Volume()

    volume.getVolume()

    volume.getVolume(5)

    volume.getVolume(5.0)

    volume.getVolume(5, 10)

}