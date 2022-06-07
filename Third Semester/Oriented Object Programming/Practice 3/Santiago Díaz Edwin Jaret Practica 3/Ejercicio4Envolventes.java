public class Ejercicio4Envolventes {
    	public static void main(String args[]){
                Integer entero1 = 83;
                Integer entero2 = 50;
    
                System.out.println("Al comparar "+entero1+" y "+entero2 +" se obtiene: "+entero1.compareTo(entero2));

                Float flotante1 = 24.333f;
                System.out.println(flotante1.isInfinite());
    
                Integer entero3 = 1234;
                Float flotante2 = 12.664f;
    
                Integer envolvente = 83;
                byte b = envolvente.byteValue();
                short c= envolvente.shortValue();
                double d = envolvente.doubleValue();
    
                Float envolvente2 = 10.32f;
                short s2 = envolvente2.shortValue();
                System.out.println(s2);
    
                int otro = Integer.parseInt("10");
                double d3 = Double.parseDouble("50.25");
    
                Integer wrap = Integer.valueOf("1100");
                Double wrap2 = Double.valueOf("3.141519");
    	}
    }
    