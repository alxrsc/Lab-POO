import kotlin.math.abs

fun generateHashMap(): HashMap<String, Int> {
    var hashMap = HashMap<String, Int>()

    hashMap.put("Alba", 1)
    hashMap.put("Arad", 2)
    hashMap.put("Arges", 3)
    hashMap.put("Bacau", 4)
    hashMap.put("Bihor", 5)
    hashMap.put("Bistrita-Nasaud", 6)
    hashMap.put("Botosani", 7)
    hashMap.put("Brasov", 8)
    hashMap.put("Braila", 9)
    hashMap.put("Buzau", 10)
    hashMap.put("Caras-Severin", 11)
    hashMap.put("Cluj", 12)
    hashMap.put("Constanta", 13)
    hashMap.put("Covasna", 14)
    hashMap.put("Dambovita", 15)
    hashMap.put("Dolj", 16)
    hashMap.put("Galati", 17)
    hashMap.put("Gorj", 18)
    hashMap.put("Harghita", 19)
    hashMap.put("Hunedoara", 20)
    hashMap.put("Ialomita", 21)
    hashMap.put("Iasi", 22)
    hashMap.put("Ilfov", 23)
    hashMap.put("Maramures", 24)
    hashMap.put("Mehedinti", 25)
    hashMap.put("Mures", 26)
    hashMap.put("Neamt", 27)
    hashMap.put("Olt", 28)
    hashMap.put("Prahova", 29)
    hashMap.put("Satu Mare", 30)
    hashMap.put("Salaj", 31)
    hashMap.put("Sibiu", 32)
    hashMap.put("Suceava", 33)
    hashMap.put("Teleorman", 34)
    hashMap.put("Timis", 35)
    hashMap.put("Tulcea", 36)
    hashMap.put("Vaslui", 37)
    hashMap.put("Valcea", 38)
    hashMap.put("Vrancea", 39)
    hashMap.put("Bucuresti", 40)
    hashMap.put("Calarasi", 51)
    hashMap.put("Giurgiu", 52)

    return hashMap
}

class Student(lastname: String, firstname: String, CNP: String, yearOfBirth: Int, faculty: String, foundationYear: Int) {
    private var lastname: String = lastname
    private var firstname: String = firstname
    private var CNP: String = CNP
    private var yearOfBirth: Int = yearOfBirth
    private var faculty: String = faculty
    private var foundationYear: Int = foundationYear

    fun generateCNP(): String {
        var newCNP: String = ""
        var c: Char
        var month: Int
        var day: Int
        var placeOfBirth: String
        var hashMapOfPlaces = generateHashMap()

        println("Introduceti sexul (m/f): ")
        c = readLine()!![0]

        // stabilim prima cifra din CNP
        if(yearOfBirth < 1900) {
            if(c == 'm') {
                newCNP += "3"
            } else {
                newCNP += "4"
            }
        }
        else if(yearOfBirth < 2000) {
            if(c == 'm') {
                newCNP += "1"
            } else {
                newCNP += "2"
            }
        }
        else {
            if(c == 'm') {
                newCNP += "5"
            } else {
                newCNP += "6"
            }
        }

        // stabilim urmatoarele 6 cifre in baza zilei de nastere
        newCNP += yearOfBirth.toString().substring(2, 4)

        println("Introdceti luna nasterii: ")
        month = readLine()!!.toInt()
        if(month < 10) {
            newCNP += "0" + month.toString()
        } else {
            newCNP += month.toString()
        }

        println("Introduceti ziua nasterii: ")
        day = readLine()!!.toInt()
        if(day < 10) {
            newCNP += "0" + day.toString()
        } else {
            newCNP += day.toString()
        }

        // stabilim locul nasterii pentru urmatoarele 2 cifre
        println("Introduceti locul nasterii (judet, se exclud sectoarele Bucurestiului): ")
        placeOfBirth = readLine()!!
        if(hashMapOfPlaces[placeOfBirth]!! < 10) {
            newCNP += "0" + hashMapOfPlaces[placeOfBirth].toString()
        } else {
            newCNP += hashMapOfPlaces[placeOfBirth].toString()
        }

        // stabilim urmatoarele 3 cifre
        /*
         NNN - reprezintă un număr de secvenţă (între 001 şi 999), repartizat pe puncte de atribuire,
         prin care se diferenţiază persoanele de acelaşi sex, născute în acelaşi loc şi cu aceeaşi dată de naştere (an, lună, zi).
         */
        // nu am gasit mai clar de atat cum se aloca, asa ca voi folosi un numar random intre 001 si 999

        newCNP += (1..999).random().toString()

        // stabilim cifra de control
        var control = "279146358279"
        var test = 0

        for(i in 0..11) {
            test += newCNP[i].toString().toInt() * control[i].toString().toInt()
        }

        test %= 11

        if(test == 10) {
            newCNP += "1"
        } else {
            newCNP += test.toString()
        }

        return newCNP
    }

    fun getLastName(): String {
        return lastname
    }

    fun getFirstName(): String {
        return firstname
    }

    fun getCNP(): String {
        return CNP
    }

    fun getYearOfBirth(): Int {
        return yearOfBirth
    }

    fun getFaculty(): String {
        return faculty
    }

    fun getFoundationYear(): Int {
        return foundationYear
    }

    fun setLastName(lastname: String) {
        this.lastname = lastname
    }

    fun setFirstName(firstname: String) {
        this.firstname = firstname
    }

    fun setCNP(CNP: String) {
        this.CNP = CNP
    }

    fun setYearOfBirth(yearOfBirth: Int) {
        this.yearOfBirth = yearOfBirth
    }

    fun setFaculty(faculty: String) {
        this.faculty = faculty
    }

    fun setFoundationYear(foundationYear: Int) {
        this.foundationYear = foundationYear
    }

    fun getGender(): String {
        if(CNP[0] == '1' || CNP[0] == '3' || CNP[0] == '5') {
            return "M"
        } else {
            return "F"
        }
    }

    fun getAge(): Int {
        var year: Int
        var month: Int
        var day: Int
        var age = 0

        // stabilim anul nasterii
        if(CNP[0] == '1' || CNP[0] == '2') {
            year = 1900 + CNP.substring(1, 3).toInt()
        } else if(CNP[0] == '3' || CNP[0] == '4') {
            year = 1800 + CNP.substring(1, 3).toInt()
        } else {
            year = 2000 + CNP.substring(1, 3).toInt()
        }

        // extragem luna nasterii
        month = CNP.substring(3, 5).toInt()

        // extragem ziua nasterii
        day = CNP.substring(5, 7).toInt()

        // calculam varsta in functie de momentul rularii codului
        val current = java.util.Calendar.getInstance()

        if(current.get(java.util.Calendar.MONTH) + 1 < month) {
            age = current.get(java.util.Calendar.YEAR) - year - 1
        }
        else if(current.get(java.util.Calendar.MONTH) + 1 == month) {
            if(current.get(java.util.Calendar.DAY_OF_MONTH) < day) {
                age = current.get(java.util.Calendar.YEAR) - year - 1
            }
            else if(current.get(java.util.Calendar.DAY_OF_MONTH) == day) {
                age = current.get(java.util.Calendar.YEAR) - year
                println("\nHAPPY BIRTHDAY! :D\n")
            }
            else {
                age = current.get(java.util.Calendar.YEAR) - year
            }
        }
        else {
            age = current.get(java.util.Calendar.YEAR) - year
        }

        return age
    }

    fun getDifference(): Int {
        return abs(this.foundationYear - this.yearOfBirth)
    }

}


fun main() {
    val student1: Student = Student("Roșca", "Alexandru", "5040224373249", 2004, "Facultatea de Automatica si Calculatoare", 1967)
    val student2: Student = Student("Surugiu", "Maria", "6041130279382", 2004, "Facultatea de Automatica si Calculatoare", 1967)
    val student3: Student = Student("Dan", "Nicușor", "1691220401233", 1969, "Facultatea de Automatica si Calculatoare", 1967)

    println("CNP generat: " + student1.generateCNP())
    println("Pentru studentul " + student1.getFirstName() + " " + student1.getLastName() + ": ")
    println("Sexul extras din CNP este: " + student1.getGender())
    println("Varsta studentului este: " + student1.getAge())
    println("Diferenta dintre anul nasterii si anul infiintarii facultatii este: " + student1.getDifference() + " ani\n")

    println("Pnetru studentul " + student2.getFirstName() + " " + student2.getLastName() + ": ")
    println("Sexul extras din CNP este: " + student2.getGender())
    println("Varsta studentului este: " + student2.getAge())
    println("Diferenta dintre anul nasterii si anul infiintarii facultatii este: " + student2.getDifference() + " ani\n")

    student2.setFaculty("Facultatea de Psihologie")
    student2.setFoundationYear(2000)

    println("Noua facultate a studentului " + student2.getFirstName() + " " +student2.getLastName() + " este: " + student2.getFaculty())
    println("Noua diferenta dintre anul nasterii si anul infiintarii facultatii este: " + student2.getDifference() + " ani\n")

    println("Pentru studentul" + student3.getFirstName() + " " + student3.getLastName() + ": ")
    println("Sexul extras din CNP este: " + student3.getGender())
    println("Varsta studentului este: " + student3.getAge())
    println("Diferenta dintre anul nasterii si anul infiintarii facultatii este: " + student3.getDifference() + " ani\n")

    student3.setFaculty("Facultatea de Matematica")
    student3.setFoundationYear(1864)

    println("Noua facultate a studentului " + student3.getFirstName() + " " + student3.getLastName()+ " este: " + student3.getFaculty())
    println("Noua diferenta dintre anul nasterii si anul infiintarii facultatii este: " + student3.getDifference() + " ani\n")
}