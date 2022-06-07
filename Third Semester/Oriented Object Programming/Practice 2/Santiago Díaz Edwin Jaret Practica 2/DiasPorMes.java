// @Autor: Edwin Jaret Santiago Díaz
// Ejercico 1

// Se importa la libreria para obtener entradas de datos
// a traves con la interaccion del usuario
import java.util.Scanner;

public class DiasPorMes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insertar un mes");
        // Se guarda la entrada del usuario en la variable
        String mes = scanner.nextLine();
        // Se declara la variable donde se guarda el numero de dias del mes
        int dias;
        switch (mes) {
            case "enero":
                dias = 31;
                break;
            case "febrero":
                dias = 28;
                break;
            case "marzo":
                dias = 30;
                break;
            case "abril":
                dias = 31;
                break;
            case "mayo":
                dias = 30;
                break;
            case "junio":
                dias = 31;
                break;
            case "julio":
                dias = 30;
                break;
            case "agosto":
                dias = 31;
                break;
            case "septiembre":
                dias = 30;
                break;
            case "octubre":
                dias = 31;
                break;
            case "noviembre":
                dias = 30;
                break;
            case "diciembre":
                dias = 31;
                break;
            default:
                dias = 0;
                break;
        }
        System.out.println("El mes de " + mes + " tiene " + dias + " dias");
    }
}
