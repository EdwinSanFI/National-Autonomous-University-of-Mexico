
import java.text.*;
import java.util.*;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

import java.time.*;

public class Ejercicio4 {
    public static void main(String[] args) {
        System.out.println("Practica 3, ejercicio 4");
        System.out.println("Programa calculador de fechas");
        System.out.println("Puede escoger que metodo ejecutar");
        System.out.println("1.- Escoger la diferencia en dias entre dos fechas");
        System.out.println("2.- Calcular la fecha en 40 dias dada una fecha");
        System.out.println("3.- La diferencia de dias dada una fecha con la actual");
        System.out.println("4.- Metodo epochTime");
        Scanner sc = new Scanner(System.in);
        int opcion = sc.nextInt();
        switch (opcion) {
            case 1:
                primerMetodo();
                break;
            case 2:
                segundoMetodo();
                break;
            case 3:
                tercerMetodo();
                break;
            case 4:
                cuartoMetodo();
                break;
            default:
                System.out.println("Esa opcion no esta disponible D:");
                break;
        }

    }
    static void primerMetodo() {
        // Instanciamos una variable para obtener el formato de fecha deseado
        SimpleDateFormat formateador = new SimpleDateFormat("dd-MM-yy");
        // Se solicita al usuario que ingrese dos fechas
        System.out.println("Ingrese dos fechas con el formado dd-mm-yy para comparar la diferencia de estas");
        // Se instancia una variable de la clase Scanner para obtener datos del usurio
        Scanner sc = new Scanner (System.in);
        // Se solicita y se guarda la primera fecha
        System.out.println("Primera fecha: ");
        String fecha1 = sc.nextLine();
        // Se solicita y se guarda la segunda fecha
        System.out.println("Segunda fecha: ");
        String fecha2 = sc.nextLine();
        // Se puso un try-catch porque era la unica manera de que compilara el codigo
        // Ya que da el error de: exception ParseException
        try {
            // Se cambia la fecha de String a Date
            Date fechaIni = formateador.parse(fecha1);
            Date fechaFinal = formateador.parse(fecha2);
            // Hace la diferencia de segundos entre las fechas
            long diferencia = Math.abs(fechaIni.getTime() - fechaFinal.getTime());
            // Se cambia de segundos a dias
            long diferenciaDias = TimeUnit.DAYS.convert(diferencia, TimeUnit.MILLISECONDS);
            // Se imprime el resultado
            System.out.println("Los dias de diferencia entre "+fecha1+" y "+fecha2+" son: " + diferenciaDias);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    static void segundoMetodo() {
        // Instanciamos una variable para obtener el formato de fecha deseado
        SimpleDateFormat formateador = new SimpleDateFormat("dd-MM-yy");
        System.out.println("Ingrese una fecha con el formado dd-mm-yy para calcular la fecha en 40 dias: ");
        // Se instancia una variable de la clase Scanner para obtener datos del usurio
        Scanner sc = new Scanner (System.in);
        // Se guarda la fecha
        String fecha1 = sc.nextLine();

        try {
            // Se cambia la fecha de String a Date
            Date fechaIni = formateador.parse(fecha1);
            // Se obtiene informacion del calendario
            Calendar calendar = Calendar.getInstance();
            // El calendario guarda la fecha ingresada por el usuario
            calendar.setTime(fechaIni);
            // Se summa 40 dias
            calendar.add(Calendar.DATE, 40);
            // Se guarda la fecha, el dia del año, el mes y el año
            String miFecha ="";
            miFecha += calendar.get(Calendar.DAY_OF_YEAR) +"-";
            miFecha += calendar.get(Calendar.MONTH)+"-";
            miFecha += calendar.get(Calendar.YEAR);
            // De string pasa a Date
            fechaIni= formateador.parse(miFecha);
            // La verdad es que el algoritmo no funciona del todo bien, se pongo el dia 01-12-22 deberia de tener de resultado 10-01-23 pero me da 10-12-22
            // Se imprime el resultado en formato que queremos
            System.out.println("La fecha en 40 dias es: "+formateador.format(fechaIni));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    static void tercerMetodo() {
        // Instanciamos una variable para obtener el formato de fecha deseado
        SimpleDateFormat formateador = new SimpleDateFormat("dd-MM-yy");
        System.out.println("Ingrese una fecha con el formado dd-mm-yy para calcular la diferencia de dias con la fecha actual: ");
        // Se instancia una variable de la clase Scanner para obtener datos del usurio
        Scanner sc = new Scanner (System.in);
        String fecha1 = sc.nextLine();

        // Fecha actual
        Date fechaHoy = new Date();

        try {
            // La fecha ingresada por el usuario se convierte en formato de fecha deseada
            Date fechaIni = formateador.parse(fecha1);
            // La fecha de hoy se convierte en tipo string ya que no puede pasar de tipo Date a SimpleDateFormat
            String fecha = formateador.format(fechaHoy);
            // La fecha de hoy se convierte en formato de fecha deseada
            fechaHoy = formateador.parse(fecha);
            // Se hace la diferencia de fechas en segundos
            long diferenciaSegundos = Math.abs(fechaIni.getTime() - fechaHoy.getTime());
            // De segundos pasa a numeros de dias
            long diferenciaDias = TimeUnit.DAYS.convert(diferenciaSegundos, TimeUnit.MILLISECONDS);
            // Se imprime la diferencia en dias
            System.out.println("La diferencia de dias con la fecha actual "+ fecha +" es de: "+diferenciaDias);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    static void cuartoMetodo() {

        SimpleDateFormat formateador = new SimpleDateFormat("dd-MM-yy");
        // epochTime
        System.out.println("Ingrese una fecha con el formado dd-mm-yy para calcular el epochTime: ");
        // Se instancia una variable de la clase Scanner para obtener datos del usurio
        Scanner sc = new Scanner (System.in);
        // Se guarda la fecha
        String fecha1 = sc.nextLine();
        try {
            Date fechaIni = formateador.parse(fecha1);
            Date fechaFinal = formateador.parse("01-01-70");
            // Hace la diferencia de segundos entre las fechas
            long diferencia = Math.abs(fechaIni.getTime() - fechaFinal.getTime());
            // Se imprime el resultado
            System.out.println("El tiempo epoch con "+fecha1+" es: " + diferencia);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
