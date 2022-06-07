/**
 *
 * @author Chapis, Alejandra
 */
import java.time.Duration;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Scanner;

public class P3 {

    Scanner sc = new Scanner(System.in);

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        P3 o = new P3();
        o.Menu();
    }

    /**
     * Menú de opciones para fechas
     */
    public void Menu(){
        int op = 0;
        while(op!=5){
            System.out.println("__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __");
            System.out.println("\n\t\t\tF E C H A S\n");
            System.out.println("    1) Diferencia de días entre dos fechas");
            System.out.println("    2) Calculo de fecha posterior después de n días a otra fecha");
            System.out.println("    3) Calculo de días desde una fecha a la fecha actual");
            System.out.println("    4) epochTime calculando hasta la fecha que ingrese el usuario");
            System.out.println("    5) Salir \n");
            System.out.print("  -> Elige una opción: ");

            op = sc.nextInt();

            switch(op){
                case 1:
                    System.out.println("\n.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tD I F E R E N C I A    D E    D I A S");
                    System.out.println("\t  E N T R E    D O S    F E C H A S\n");
                    case1();
                    break;
                case 2:
                    System.out.println("\n.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tF E C H A    D E S P U E S    D E    N    D I A S\n");
                    case2();
                    break;
                case 3:
                    System.out.println("\n.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tD E    U N A    F E C H A    A     L A    A C T U A L\n");
                    case3();
                    break;
                case 4:
                    System.out.println("\n.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tE P O C H    T I M E\n");
                    case4();
                    break;
                case 5:
                    System.out.println("\n.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tBaaaaeeeeee (:\n");
                    break;
                default:
                    System.out.println("\n.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .\n");
                    System.out.println("\tSorry, not sorry ):\n");
                    break;
            }
        }

    }

    public void case1(){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yy");
        String fecha1, fecha2;
        sc.nextLine();

        System.out.println("  **  NOTA: Ingresa las fechas en formato dd/MM/yy  **\n");

        try{
            System.out.print("Primera fecha: ");
            fecha1 = sc.nextLine();
            LocalDate localDate = LocalDate.parse(fecha1, formatter);

            System.out.print("Segunda fecha: ");
            fecha2 = sc.nextLine();
            LocalDate localDate2 = LocalDate.parse(fecha2, formatter); 

            Duration diferencia = Duration.between(localDate.atStartOfDay(), localDate2.atStartOfDay());
            long dias = diferencia.toDays();
            System.out.println("\n  -- La diferencia en días entre ambas fechas es de: " + dias + " --");
            System.out.println("");

        }catch(DateTimeParseException e){
            System.out.println("\n. _ . _ . _ . _ . _ . _ . _ . _ . _ . _ .\n");
            System.out.println("  No ingresaste los datos correctamente");
            System.out.println("  Intentalo de nuevo (:\n");
        }
    }

    public void case2(){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yy");
        String fecha;
        long dias;
        sc.nextLine();

        System.out.println("  **  NOTA: Ingresa las fecha en formato dd/MM/yy  **\n");

        try{
            System.out.print("Fecha: ");
            fecha = sc.nextLine();
            LocalDate localDate = LocalDate.parse(fecha, formatter);

            System.out.print("¿La fecha después de cuantos días quieres calcular?: ");
            dias = sc.nextLong();

            System.out.println("\n  -- La nueva fecha después de " + dias + " días es: " + formatter.format(localDate.plusDays(dias)) + " --");
            System.out.println("");

        }catch(DateTimeParseException e){
            System.out.println("\n. _ . _ . _ . _ . _ . _ . _ . _ . _ . _ .\n");
            System.out.println("  No ingresaste los datos correctamente");
            System.out.println("  Intentalo de nuevo (:\n");
        }

    }

    public void case3(){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yy");
        String fecha1, fecha2;
        sc.nextLine();

        System.out.println("  **  NOTA: Ingresa las fechas en formato dd/MM/yy  **\n");

        try{
            System.out.print("Primera fecha: ");
            fecha1 = sc.nextLine();
            LocalDate localDate = LocalDate.parse(fecha1, formatter);

            fecha2 = formatter.format(localDate.now());
            LocalDate localDate2 = LocalDate.parse(fecha2, formatter); 

            Duration diferencia = Duration.between(localDate.atStartOfDay(), localDate2.atStartOfDay());
            long dias = diferencia.toDays();
            System.out.println("\n  -- La diferencia en días entre la fecha elegida y el día de hoy es de: " + dias + " --");
            System.out.println("");

        }catch(DateTimeParseException e){
            System.out.println("\n. _ . _ . _ . _ . _ . _ . _ . _ . _ . _ .\n");
            System.out.println("  No ingresaste los datos correctamente");
            System.out.println("  Intentalo de nuevo (:\n");
        }
    }

    public void case4(){
        long currentTimestamp = System.currentTimeMillis();
        System.out.println("Marca de tiempo en milisegundos: " + currentTimestamp);
    }
}
