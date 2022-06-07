import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Fechas {
    public static void main(String[] args) {
        // Se guarda la fecha actual
        Date fecha = new Date();
        // Se imprime la fecha en string
        System.out.println(fecha.toString());
        // Se crea un formato de fecha
        SimpleDateFormat formateador = new SimpleDateFormat("dd-MM-yyyy");
        // Se imprime la fecha conforme al formato previo
        System.out.println(formateador.format(fecha));

        // Se obtiene informacion del calendario
        Calendar calendario = Calendar.getInstance();
        // Se crea una varaible de tipo String en donde guardara los datos de la fecha
        String miFecha = "Hoy es dia ";
        // Obtiene el dia del mes
        miFecha += calendario.get(Calendar.DAY_OF_MONTH) + " del mes ";
        // Obtiene el mes
        miFecha += calendario.get(Calendar.MONTH) + 1 + " de ";
        // Obtiene el año
        miFecha += calendario.get(Calendar.YEAR);
        // Imprime el string concatenado con la fecha
        System.out.println(miFecha);
    }
}
