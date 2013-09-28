public class AdvancedArray { 
	public static void main(String[] args) { 
		int[] arr1 = {1, 2, 3, 4, 5}; 
		int[] tmp1; 
		int[] tmp2;
		int[] tmp3 = {1, 2, 3, 4, 5}; 
		
		tmp1 = arr1; 
		tmp2 = arr1;
		for(int i = 0; i < tmp1.length; i++)
			System.out.print(tmp1[i] + " "); 
		System.out.println(); 
 
		for(int i = 0; i < tmp2.length; i++) 
			System.out.print(tmp2[i] + " "); 
		System.out.println();

		for(int i = 0; i < tmp3.length; i++)
			System.out.print(tmp3[i] + " ");
		System.out.println();
		System.out.println();
 
		tmp1[2] = 9; 
		for(int i = 0; i < tmp1.length; i++) 
			System.out.print(tmp1[i] + " "); 
		System.out.println(); 
 
		for(int i = 0; i < tmp2.length; i++) 
			System.out.print(tmp2[i] + " "); 
		System.out.println();

		for(int i = 0; i < tmp3.length; i++)
			System.out.print(tmp3[i] + " ");
		System.out.println();
	}
}
