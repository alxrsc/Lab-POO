// generic class stack for int and chars
class Stack<T> {
    private val elements = mutableListOf<T>()
    fun push(element: T) = elements.add(element)
    fun pop(): T = elements.removeAt(elements.size - 1)
    fun isEmpty() = elements.isEmpty()
}

// generic class queue for int and chars
class Queue<T> {
    private val elements = mutableListOf<T>()
    fun enqueue(element: T) = elements.add(element)
    fun dequeue(): T = elements.removeAt(0)
    fun isEmpty() = elements.isEmpty()
}

fun main() {
    val stack = Stack<Int>()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    println(stack.pop())
    println(stack.pop())
    println(stack.pop())
    println(stack.isEmpty())
    println()

    val stack2 = Stack<Char>()
    stack2.push('a')
    stack2.push('b')
    stack2.push('c')
    println(stack2.pop())
    println(stack2.pop())
    println(stack2.pop())
    println(stack2.isEmpty())
    println()

    val queue = Queue<Int>()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    println(queue.dequeue())
    println(queue.dequeue())
    println(queue.dequeue())
    println(queue.isEmpty())
    println()

    val queue2 = Queue<Char>()
    queue2.enqueue('a')
    queue2.enqueue('b')
    queue2.enqueue('c')
    println(queue2.dequeue())
    println(queue2.dequeue())
    println(queue2.dequeue())
    println(queue2.isEmpty())

}