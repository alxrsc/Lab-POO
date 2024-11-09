open class Owner {
    open fun getSalary() {
        println("Banii se reinvestesc in companie!")
    }

    open fun greet() {
        println("Salut! Sunt patronul companiei!")
    }
}

open class Manager : Owner() {
    override fun getSalary() {
        println("Salariul este confidential!")
    }

    override fun greet() {
        println("Salut! Sunt managerul companiei!")
    }
}

class Employee : Manager() {
    override fun getSalary() {
        println("Salariul este \"motivant\"!")
    }

    override fun greet() {
        println("Salut! Sunt angajatul companiei!")
    }
}

fun main() {

    var owner = Owner()
    owner.greet()
    owner.getSalary()
    println()

    var manager = Manager()
    manager.greet()
    manager.getSalary()
    println()

    var employee = Employee()
    employee.greet()
    employee.getSalary()

}