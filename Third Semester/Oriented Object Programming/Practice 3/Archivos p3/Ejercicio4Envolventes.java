public class Ejercicio4Envolventes {
    
	public static void main(String args[]){
            Integer entero1 = new Integer(83);
            Integre entero2 = 50;

            Float flotante1 = new Float(24.333);
            System.out.println(flotante1.isInfinite());
            
            Integer entero3 = Integer("1234");
            Float flotante2 = new Float("12.664");

            Integer envolvente = new Integer (83);
            byte b = envolvente.byteValue();
            short envolvente.shortValue();
            double d = envolvente.doubleValue();
            
            Float envolvente2 = new Float(10.32);
            short s2 = envolvente2.shortValue();
            System.out.println(s2); 

            int otro = Integer.parseInt("10");
            double d3 = Double.parseDouble("50.25");

            Integer wrap = Integer.valueOf("1100");
            Double wrap2 = Double.valueOf("3.141519");
		
	}
}
