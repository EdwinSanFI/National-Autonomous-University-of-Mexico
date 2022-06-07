interface Valores {
    int a = 10;
    int b = 20;
}

public class Calculadora {
        public static int Sumar(){
            return (Valores.a + Valores.b);
        }
        public static int Restar(){
            return (Valores.a - Valores.b);
        }
        public static int Multiplicar(){
            return (Valores.a * Valores.b);
        }
        public static int Modulo(){
            return (Valores.a % Valores.b);
        }
}

public static void main(String[] args) {
    
}