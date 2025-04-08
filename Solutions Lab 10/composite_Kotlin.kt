import java.lang.RuntimeException

// sursa de informare (same with c++): https://www.geeksforgeeks.org/composite-pattern-cpp/
// sursa de informare aditionala: ChatGPT

// pros:
// - permite clientului sa trateze obiectele individuale si compuse uniform
// - usor de adaugat noi tipuri de componente fara a modifica codul existent
// - usor de modificat structura unui obiect compus

// cons:
// - poate face design-ul prea generalizat
// - poate sa faca design-ul prea complex pentru anumite scenarii

// Base class
abstract class Employee(protected val name: String, protected val department: String) {
    abstract fun showDetails()

    open fun add(employee: Employee) {
        // Default implementation for leaf objects
        throw RuntimeException("Cannot add employees to a leaf employee.")
    }
}

// Leaf class
class Developer(name: String, department: String) : Employee(name, department) {
    override fun showDetails() {
        println("Developer: $name in $department")
    }
}

// Leaf class
class Designer(name: String, department: String) : Employee(name, department) {
    override fun showDetails() {
        println("Designer: $name in $department")
    }
}

// Composite class
class Manager(name: String, department: String) : Employee(name, department) {
    private val employees = mutableListOf<Employee>()

    override fun showDetails() {
        println("Manager: $name in $department")
        for (employee in employees) {
            print("\t")
            employee.showDetails()
        }
    }

    override fun add(employee: Employee) {
        employees.add(employee)
    }
}

fun main() {
    val developer1 = Developer("Steve Jobs", "Apple")
    val developer2 = Developer("Mark Zuckerberg", "Meta")
    val designer1 = Designer("Jeff Bezos", "Amazon")
    val designer2 = Designer("Sundar Pichai", "Google")

    val manager = Manager("Donald Trump", "Management")
    manager.add(developer1)
    manager.add(developer2)
    manager.add(designer1)
    manager.add(designer2)

    manager.showDetails()
}
