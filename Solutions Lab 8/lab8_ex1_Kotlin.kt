// generic to add ints and chars, 1 + 2 -> 12, 'a' + 'b' -> 'ab'
fun add(a: Any, b: Any): Any {
    return a.toString() + b.toString()
}

fun main() {

    println(add(1,2))

    print(add('I', 'S'))
    print(" ")
    print(add('a', 'n'))
    print(" ")
    println(add('I', 'I'))


}