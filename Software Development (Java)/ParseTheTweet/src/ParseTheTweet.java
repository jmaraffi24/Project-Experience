/*
* ParseTheTweet.java
* Author: Jacob Maraffi
* Submission Date: 9/8/16
*
* Purpose: A brief paragraph description of the
* program. What does it do?
* 
* The program is intended to take input from the user in the form of a "tweet"; parse
* the tweet based on certain predetermined groups and display output based on those
* results.
*
* Statement of Academic Honesty:
*
* The following code represents my own work. I have neither
* received nor given inappropriate assistance. I have not copied
* or modified code from any source other than the course webpage
* or the course textbook. I recognize that any unauthorized
* assistance or plagiarism will be handled in accordance with
* the University of Georgia's Academic Honesty Policy and the
* policies of this course. I recognize that my work is based
* on an assignment created by the Department of Computer
* Science at the University of Georgia. Any publishing
* or posting of source code for this project is strictly
* prohibited unless you have written consent from the Department
* of Computer Science at the University of Georgia.
*/
import java.util.Scanner;
public class ParseTheTweet {

	public static void main(String[] args) {
		
		//initializing the scanner class
		Scanner keyboard = new Scanner(System.in); 	
		//prompting the user to provide input
		System.out.print("Please enter your tweet:");
		//saving the input as a string
		String tweet = keyboard.nextLine();
		//closing the scanner class
		keyboard.close();
		
		//creating and parsing the "type"
		int typeStart = tweet.indexOf('#');
		int typeEnd = tweet.indexOf(';');
		String tweetType = tweet.substring(typeStart + 4, typeEnd);
		String tweetTypeTrimmed = tweetType.trim();
		
		//providing the output for the "type" of the tweet
		System.out.println("Type:\t\t" + tweetTypeTrimmed.toUpperCase());
		
		//creating and parsing the "detail"
		int detailStart = typeEnd + 6;
		String tweet2 = tweet.substring(detailStart);
		int detailEnd = tweet2.indexOf(';');
		String tweetDetail = tweet2.substring(0, detailEnd);
		String tweetDetailTrimmed = tweetDetail.trim();
		String tweetDetailTrimmedReplaced = tweetDetailTrimmed.replace(',', '-');
		
		//providing the output for the "detail" of the tweet
		System.out.println("Detail:\t\t" + tweetDetailTrimmedReplaced);
		
		//creating and parsing the "location"
		int locationStart = detailEnd + 6; 
		String tweet3 = tweet2.substring(locationStart);
		int locationEnd = tweet3.indexOf(';');
		String tweetLocation = tweet3.substring(0, locationEnd);
		String tweetLocationTrimmed = tweetLocation.trim();
		String tweetLocationTrimmedReplaced = tweetLocationTrimmed.replace(',', '-');
		
		//providing the output for the "location" of the tweet
		System.out.println("Location:\t" + tweetLocationTrimmedReplaced);
		
		//creating and parsing the "latitude"
		int latitudeStart = locationEnd + 6;
		String tweet4 = tweet3.substring(latitudeStart);
		int latitudeEnd = tweet4.indexOf(';');
		String tweetLatitude = tweet4.substring(0, latitudeEnd);
		String tweetLatitudeTrimmed = tweetLatitude.trim();
		
		//providing the output for the "latitude"
		System.out.println("Longitude:\t" + tweetLatitudeTrimmed);
		
		//creating and parsing "longitude"
		int longitudeStart = latitudeEnd + 6;
		String tweet5 = tweet4.substring(longitudeStart);
		int longitudeEnd = tweet5.indexOf(';');
		String tweetLongitude = tweet5.substring(0, longitudeEnd);
		String tweetLongitudeTrimmed = tweetLongitude.trim();
		
		//providing the output for the "longitude"
		System.out.println("Longitude:\t" + tweetLongitudeTrimmed);
	}

}
;