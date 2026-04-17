import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
	Scanner s = new Scanner(System.in);
	
	 String [] input = new String [4];
	
	
	for (int i=0; i<4; i++)
	 input[i] = s.next();
	
	
	String dd1 = input[0] + input[1];
	String dd2 = input[2] + input[3];
	long  d1 = Long.parseLong(dd1);
	long d2 = Long.parseLong(dd2);
	
	System.out.println(d1+d2);
	}
}	