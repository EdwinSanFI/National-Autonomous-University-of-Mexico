// @Autor: Edwin Jaret Santiago Díaz
// Ejercico 2
// Se transcriben 2 sentencias if a operadores ternarios

public class OperadorTernario {
    public static void main(String[] args) {
        //Operador ternario inciso A
        int x = 6;
        int y = 8;
        int z = x <= 10 && y <= 10 ? x < 50 && y < 5 ? 200 : 100 : 50;
        System.out.println("X = " + x + " Y = " + y);
        System.out.println("El resultado de este operador ternario es: " + z);

        //Operador ternario inciso B
        float a = 9;
        String b = a > 6 ? a < 8.4 ? "buen trabajo" : "excelente" : "Lo siento, deberas recursar";
        System.out.println("A = " + a);
        System.out.println("El resultado del segundo operador tenrario es: " + b);
    }
}
