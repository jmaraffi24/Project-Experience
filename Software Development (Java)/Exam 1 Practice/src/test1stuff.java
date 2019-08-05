/* as sorta mini practice you could look at the lines of code separated by [but not including!] green long lines of explanation and predict what would be output
 * SPOILER ALERT: do NOT read these green long lines of explanation
 * to see the answers, press play, and the program should output the answers with one line of nothing between each answer
 * if you need or want an explanation i think i have accurate explanations for the code above each green long line within said green long lines
 * at the end i have a few lines of info that may or may not be helpful (jsyk)
 */

public class test1stuff {

	public static void main(String[] args) {
				
		System.out.println("i \nt \na \n\tc \nh\ni\n");
		
		//this outputs everything inside the quotations except for any "\" and any letters directly following these "\". the command \n moves the next segment of output to the next line, and the command \t moves the next segment of output "	" far from the segment previous. combining the two will first move the segment to the next line and then 'tab' or indent it.
		
		String apple;
		apple = "test grade >= 80";
		int apple2;
		apple2 = apple.length();
		System.out.println(apple2 + "\n");
		
		//this outputs the length of the string apple. this length value can be displayed as an int because it cannot be anything other than an integer. this value is 'counted' with the first character being 1, not 0.
		
		String grape;
		grape = "kaemani";
		String grape2;
		grape2 = grape.substring(3,6);
		System.out.println(grape2 + "\n");
		
		//this outputs a segment, or a substring, of grape. this substring begins at the character found at index "a" and ends at the character found at index "b"-1, where the substring is computed as grape.substring(a,b), given that a>=0 and b<=(the index of the last character in grape) or ends at the end of grape if "b" is not privided.
		
		String banana;
		banana = "microsoft";
		int banana2;
		banana2 = banana.indexOf("i");
		System.out.println(banana2 + "\n");
		
		//this outputs the index value, or the distance from the beginning of banana, of the character "i". when counting this distance, the first character will be 0, the second will be 1, the third will be 2, etc. etc.
		
		String pineapple;
		pineapple = "parameter";
		int pineapple2;
		pineapple2 = pineapple.charAt(3);
		System.out.println(pineapple2 + "\n");
		
		//this outputs the ascii value associated with the character, or char, at index 3. in this case, that index was 3, which resulted in a char of a. the ascii value for a is 97, so the program outputs "97". (dont worry u dont need to know ascii values on ur own i just thought it would be beneficial to know that this would output an ascii value)
		
		String orange;
		orange = "hinata";
		int orange2;
		orange2 = orange.lastIndexOf("a");
		System.out.println(orange2 + "\n");
		
		//this outputs the index value of the last occurrence of "a", which is 5 in this case, so the output is "5".
		
		String pear;
		pear = "hyuga";
		char pear2; char pear3; char pear4;
		pear2 = pear.charAt(3); pear3 = pear.charAt(3);
		System.out.print(pear2); System.out.println(pear3 + "\n");
		
		//this outputs the character that occurs within String pear at index 3, where h==0, y==1, u==2, g==3, and a==4.
		
		int peach;
		peach = 29;
		double peach2;
		peach2 = peach - 1;
		System.out.println(peach2 + "\n");
		
		//this outputs the value of peach minus 1. peach is 29, and 29-1=28. therefore, the program outputs "68".
		
		byte bite;
		bite = 2;
		int bite2;
		bite2 = bite - 1;
		System.out.println(bite2 + "\n");
		
		//this outputs the value of bite (2) minus 1, which is 1.
		
		float flote;
		flote = 1234;
		double dubble;
		dubble = flote + 11111;
		System.out.println(dubble + "\n");
		
		//this outputs the value of flote (1234) plus 11111, which is 12345.
		
		/** 
		 * primitive data types you can cast:
		 * 
		 * byte   -> short
		 * short  -> int
		 * int    -> long
		 * int    -> float
		 * float  -> int
		 * float  -> double
		 * long   -> double
		 * double -> long
		 */
		
		/*
		 *primitive data type sizes:
		 *byte     | 8
		 *short    | 16
		 *int      | 32
		 *long     | 64
		 *float    | 32
		 *double   | 64
		 *
		 *(prob doesnt really matter below this point but it's here just in case)
		 *
		 *char     | 16
		 *boolean  | 1 bit used in 32 bit integer
		 */
		
		/**
		 * types of conditional statements:
		 * 
		 * if else
		 * 
		 * switch
		 * 
		 * ?= 
		 */
		
		/*
		 * random info:
		 * 
		 * when counting indexes (is that plural of index?) of a string, remember to begin with 0. 
		 * 
		 * when converting from binary to decimal, remember that the first digit of the binary (from the right) is equivalent to 2^0, and the second digit from the right is equivalent to 2^1, etc., etc.
		 * when converting from decimal to binary, remember that you divide your decimal value by 2 and note the remainder (1 or 0). you continue to divide by 2 until your decimal value is 1. then, you conclude with the number in binary form by reading the 1s and 0s from the decimal value of 1 to the decimal value you began with.
		 * 
		 * if you need quotation marks within an output, use \" \" (the two \ will not be output)
		 * 
		 * \n makes a new line from the point of the command
		 * 
		 * \t makes a tab from the point of the command
		 * 
		 * to import a scanner, you must place "import java.util.Scanner" outside of the class.
		 * to import the data from a scanner into your code, use "Scanner keyboard = new Scanner(System.in);"
		 * you can use .nextDouble, .nextInt, .nextln, etc. when importing multiple pieces of information from a scanner
		 * 
		 * String1.trim( ); will eliminate white spaces from String1 that are at the beginning and end (assuming there are white spaces here)(if not then it will have no effect).
		 * 
		 * String1.replaceAll("a","o"); will replace all "a"s with "o"s within String1
		 * String1.replaceFirst("a","o"); will replace the FIRST occurrence of "a" within String1 with an "o". 
		 * 
		 * to eliminate white space in between words within a string, you can use the replace all method and replace all occurrences of "\\s+" with " ".
		 * 
		 * within a switch statement remember to use breaks when approriate
		 * 
		 * remember that java reads and executes from top to bottom.
		 * that being said, if int a = 1 on line 8 but int a = 2 on line 13, then all lines after line 13 will read int a as 2, not 1.
		 * so basically just know that java sees the most recent form of a data type. 
		 * so u have to initialize and declare a variable BEFORE you use it in your program (meaning you cannot use int a that is declared on line 8 on any lines before line 8).
		 * 
		 * remember semicolons haha
		 * 
		 * im sure there is more info i could put here but nothing else i can think of at the moment
		 */
	}

}
