// Pros:
// - permite crearea unei singure instante a unei clase, utila pentru resurse partajate, baze de date spre ex
// - evita crearea mai multor instante pentru acelasi obiect
// - fiind declarata global, instanta poate fi accesata de oriunde, simplificand design-ul aplicatiei

// Cons:
// - greu de testat, fiind greu de izolat blocuri de cod, avand in vedere ca este o variabila globala
// - dificil de gestionat in cazul aplicatiilor multithread
/// Sursa informatiilor : geeksforgeeks.org/implementation-of-singleton-class-in-cpp

class Punga private constructor() {

    // Membrii clasei
    private var continut: String = ""
    private var dataExpirarii: String = ""

    companion object {
        // Pointerul catre instantierea clasei
        // ? - safe call operator
        private var instance: Punga? = null

        @JvmStatic
        fun getInstance(): Punga {
            if (instance == null) {
                instance = Punga()
                println("Am deschis o punga noua!")
            } else {
                println("Avem o punga deja deschisa, nu deschidem alta!")
            }
            return instance!!
        }
    }

    fun setContinut(continut: String) {
        this.continut = continut
    }

    fun setDataExpirarii(dataExpirarii: String) {
        this.dataExpirarii = dataExpirarii
    }

    fun getContinut(): String {
        return continut
    }

    fun getDataExpirarii(): String {
        return dataExpirarii
    }
}

fun main() {
    val punga = Punga.getInstance()
    punga.setContinut("Chipsuri")
    punga.setDataExpirarii("12.12.2025")

    println("Continutul pungii este: ${punga.getContinut()}")
    println("Data expirarii pungii este: ${punga.getDataExpirarii()}")

    val punga2 = Punga.getInstance()

    println("Continutul pungii este: ${punga2.getContinut()}")
}
