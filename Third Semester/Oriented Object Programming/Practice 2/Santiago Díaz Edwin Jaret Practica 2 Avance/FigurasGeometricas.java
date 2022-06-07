// @Autor: Edwin Jaret Santiago Díaz
// Ejemplo de la guia 2

import java.util.Scanner;

public class FigurasGeometricas {
    public static void main(String[] args) {
        float area = 0;
        int opcion;
        final float PI = 3.14159f;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Elige una opcion");
            System.out.println("1.- Area de circulo");
            System.out.println("2.- Area de triangulo");
            System.out.println("3.- Area de cuadrado");
            System.out.println("4.- Salir");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    // Círculo
                    System.out.println("Selecciono el circulo");
                    // Operaciones apra obtener el area
                    float radio = 15;
                    area = PI * radio * radio;
                    break;
                case 2:
                    // Triángulo
                    System.out.println("Selecciono el triangulo");
                    // Operaciones apra obtener el area
                    float base = 8, altura = 5;
                    area = (base * altura) / 2;
                    break;
                case 3:
                    // Cuadrado
                    System.out.println("Selecciono cuadrado");
                    // Operaciones apra obtener el area
                    float lado = 10;
                    area = lado * lado;
                    break;
                default:
                    // Salir
                    System.out.println("Su seleccion no es correcta");
                    break;
            }
            System.out.println("El area es: " + area);
        } while (opcion != 4);
        sc.close();
    }
}
