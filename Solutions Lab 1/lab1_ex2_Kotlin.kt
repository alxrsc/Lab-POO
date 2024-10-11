class Sorter {
    private fun swap(arr: IntArray, i: Int, j: Int) {
        val temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
    }

    private fun partition(arr: IntArray, low: Int, high: Int): Int {
        val pivot = arr[high]
        var i = low - 1

        for (j in low ..< high) {
            if(arr[j] > pivot) {
                i++
                swap(arr, i, j)
            }
        }

        swap(arr, i + 1, high)

        return i + 1
    }

    private fun quickSortDescending(arr: IntArray, low: Int, high: Int) {
        if(low < high) {
            val pi = partition(arr, low, high)

            quickSortDescending(arr, low, pi - 1)
            quickSortDescending(arr, pi + 1, high)
        }
    }

    fun sortingAlg(arr: IntArray, size: Int) {
        quickSortDescending(arr, 0, size-1)
    }

    fun printArray(arr: IntArray, size: Int) {
        for(i in 0 ..< size) {
            print("${arr[i]} ")
        }
    }

}

fun main() {

    val arr: IntArray = intArrayOf(40, 8, 11, 2, 99)

    val sorting = Sorter()

    sorting.sortingAlg(arr, arr.size)
    sorting.printArray(arr, arr.size)
}