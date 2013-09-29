public class UseStringBuilder { 
	public static void main(String[] args) { 
		StringBuilder strBuilder = new StringBuilder("Knowledge is power!");
 
		System.out.println("內容: " + strBuilder); 
		System.out.println("長度: " + strBuilder.length()); 
		System.out.println("容量: " + strBuilder.capacity()); 
	} 
}
