import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {

	public static void main(String[] args) {
		Main m = new Main();
		m.start();
	}
	
	BigInteger A[] = new BigInteger[100];
	boolean Zero[] = new boolean[100];
	Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	
	public void start() {
		int n, length;
		while (in.hasNextInt()) {
			length = 0;
			// Read first value different from zero
			while (length == 0 && (n = in.nextInt()) != -999999) {
				if (n != 0)
					A[length++] = BigInteger.valueOf(n);
			}
			
			if (length == 0) {
				System.out.println("0");
			} else {
				// Read integer sequence
				while ((n = in.nextInt()) != -999999) {
					// If value is zero, mark it and continue the product
					if (n == 0) {
						Zero[length] = true;
						A[length] = A[length-1];
					} else {
						Zero[length] = false;
						A[length] = A[length-1].multiply(BigInteger.valueOf(n));
					}
					length++;
				}
			
				// O(n^2) algorithm: check every possible combination
				BigInteger maxProd = A[0];
				for (int i = 0; i < length; ++i) {
					int start = i;
					for (int j = i; j < length; ++j) {
						if (Zero[j]) {
							start = j + 1;
							maxProd = maxProd.max(BigInteger.ZERO);
						} else {
							if (start > 0)
								maxProd = maxProd.max(A[j].divide(A[start-1]));
							else
								maxProd = maxProd.max(A[j]);
						}
					}
				}
				
				System.out.println(maxProd.toString());
			}
		}
		
		in.close();
	}

}
