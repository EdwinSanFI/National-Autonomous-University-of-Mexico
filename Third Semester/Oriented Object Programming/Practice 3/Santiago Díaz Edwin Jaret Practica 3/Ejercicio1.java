public class Ejercicio1{
	public static void main(String[] args) {
		// Guarda la primera cadena de texto que recibe el programa
		String cadena1 = args[0];
		// Guarda la segunda cadena de texto que recibe el programa
		String cadena2 = args[1];
		// Guarda el tercer parametro de tipo entero que recibe el programa
		float entero =Float.parseFloat(args[2]);

		// Imprime mensajes concatenando las variables
		System.out.println("Hola "+cadena1);

		System.out.println("Tu nombre es: "+cadena1);
		System.out.println("tu apellido es:"+cadena2);
		System.out.println("Tu edad: "+entero);
	}
}