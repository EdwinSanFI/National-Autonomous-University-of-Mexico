package EjemplosGuia;

public class Persona {
    private String nombre;
    private String apellido;
    private Fecha fNacimiento;


    public Persona(){
        fNacimiento = new Fecha();
    }
    public Persona(String nombre, String apellido, int fDia, int fMes, int fAnio){
        this.nombre = nombre;
        this.apellido = apellido;
        fNacimiento.setDia(fDia);
        fNacimiento.setMes(fMes);
        fNacimiento.setAnio(fAnio);
    }

    public String getNombre(){
        return nombre;
    }
    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public String getApellido(){
        return apellido;
    }
    public void setApellido(String apellido){
        this.apellido = apellido;
    }

    public Fecha getFNacimiento(){
        return fNacimiento;
    }
    public void setFNacimiento(int dia, int mes, int anio){
        fNacimiento.setDia(dia);
        fNacimiento.setMes(mes);
        fNacimiento.setAnio(anio);
    }

}
