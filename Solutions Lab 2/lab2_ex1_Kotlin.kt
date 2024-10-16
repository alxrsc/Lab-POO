class Time{
    var hour: Int = 0
    var minute: Int = 0
    var second: Int = 0
    var day: Int = 0
    var month: Int = 0
    var year: Int = 0

    constructor() {
        // get time in 24 hour format
        val current = java.util.Calendar.getInstance()
        hour = current.get(java.util.Calendar.HOUR_OF_DAY)
        minute = current.get(java.util.Calendar.MINUTE)
        second = current.get(java.util.Calendar.SECOND)
        day = current.get(java.util.Calendar.DAY_OF_MONTH)
        month = current.get(java.util.Calendar.MONTH) + 1
        year = current.get(java.util.Calendar.YEAR)
        println("Current date and time is: $day/$month/$year $hour:$minute:$second")
        println("Hours left of today: ${23 - hour}:${59 - minute}:${59 - second}")
    }


    fun showTime(){
        println("$hour:$minute:$second")
    }
}

fun main() {
    
    val time = Time()

}