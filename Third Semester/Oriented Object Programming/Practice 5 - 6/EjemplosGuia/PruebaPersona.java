package EjemplosGuia;

public class PruebaPersona {
    Persona per1 = new Persona();
    // Error de la practica, no viene con parametros pero DEBE DE SER con parametros
    Fecha nac = new Fecha(15,8,1950);
    per1.setNombre("Juan");
    per1.setApellido("Perez");

    per1.setFNacimiento(nac);
    System.out.println("Nombre: "+per1.getNombre());
    System.out.println("Apellido: "+per1.getApellido());
    System.out.println("Fecha Nacimiento: "+per1.getFNacimiento().getDia()+"/"+per1.getFNacimiento().getMes()+"/"+per1.getFNacimiento().getAnio());
}
