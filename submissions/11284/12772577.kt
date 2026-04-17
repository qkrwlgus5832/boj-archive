/**
 * We declare a package-level function main which returns Unit and takes
 * an Array of strings as a parameter. Note that semicolons are optional.
 */
import java.util.*
 class Hangul {
    companion object {
      const val BASE_CODE = '가'.toInt() // '\\uac00'
      const val INITIAL_CONSONANT_COUNT = 19
      const val VOWEL_COUNT = 21
      const val FINAL_CONSONANT_COUNT = 28
      const val LBase = 0x1100
      const val VBase = 0x1161
      const val TBase = 0x11A7
    }
	var resultcho: Int = 0
    var resultjung: Int = 0
    var resultjong: Int = 0
     
    constructor(input: Char) {
    	resultcho = LBase + (input.toInt()) / (VOWEL_COUNT * FINAL_CONSONANT_COUNT)
        resultjung = VBase + ((input.toInt()) % (VOWEL_COUNT * FINAL_CONSONANT_COUNT)) / 28
        resultjong = TBase + ((input.toInt()) % (VOWEL_COUNT * FINAL_CONSONANT_COUNT)) % 28
    }
     
	fun print(){
        println(resultcho.toChar())
        println(resultjung.toChar())
        if (resultjong == 4519)
        	println()
        else
        	println(resultjong.toChar())
	}	
  }



    fun main() = with(Scanner(System. `in`)) {
		 var name = next()
         var nameChar = ' '
          nameChar = (name[0].toInt() -Hangul.BASE_CODE).toChar()
         val hangul = Hangul(nameChar)
         hangul.print()
        
        
    }

