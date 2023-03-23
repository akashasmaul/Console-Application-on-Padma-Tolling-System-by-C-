package PadmaToll;
import java.util.Scanner;
import java.util.Random;

public class tax {
	Scanner cin = new Scanner(System.in);
	Random ran = new Random();
	
	
	
public static String date;
       int car_no;
	   int ticket_no;
	   
	   void addcar() {
		   System.out.print("Enter Vehicle Registration Number: ");
		   	 this.car_no = cin.nextInt();  	
		    this.ticket_no = ran.nextInt(10000);
		    System.out.println("Ticket number: "+ticket_no);
		     }
	
	void printdetails() //prints the details of the car
	{
		System.out.println("Date: "+tax.date);
		System.out.println("Vehicle Registration Number: " +car_no);
		System.out.println("Ticket number: "+ticket_no);
	}



	boolean  searchcar(int x) {
		if (car_no==x) {
			return true ;
		}
		return false;
		
	}
}
