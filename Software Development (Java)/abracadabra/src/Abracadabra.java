
public class Abracadabra {

	public static void main(String[] args) {
		String s3 = "abrbcadabra";
		
		int firstB = s3.indexOf('b');
		int secondB = firstB + s3.substring(firstB+1).indexOf('b') + 1;
		
		String newWord = s3.substring(0, secondB) + 'a' + s3.substring(secondB+1);
		System.out.println(newWord);
		
		String firstPart = s3.substring(0, s3.indexOf('b')+1); //stores ab
		String secondPart = s3.substring(s3.indexOf('b')+1); //stores rbcadabra
		
		secondPart = secondPart.substring(0,  secondPart.indexOf('b')) + 'a' + secondPart.substring(secondPart.indexOf('b')+1);
		
		newWord = firstPart + secondPart;
		System.out.println(newWord);
		

	}

}
