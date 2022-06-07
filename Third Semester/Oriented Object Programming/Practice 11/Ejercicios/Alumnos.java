/**
 * @author Edwin Jaret Santiago Díaz
 */

import java.util.*;
import java.io.*;

public class Alumnos implements java.io.Serializable {
    String domicilio;
    String nombre_apellido;
    String asignaturas;

    ArrayList<Alumnos> listaAlumnos = new ArrayList<Alumnos>();

    /** Metodo constructor */
    public Alumnos(String nombre_apellido, String domicilio, String asignaturas) {
        setAsignaturas(asignaturas);
        setDomicilio(domicilio);
        setNombre_apellido(nombre_apellido);
    }
    public Alumnos() {
    }
    /** Get y set */
    public String getDomicilio() {
        return domicilio;
    }
    public void setDomicilio(String domicilio) {
        this.domicilio = domicilio;
    }
    public String getNombre_apellido() {
        return nombre_apellido;
    }
    public void setNombre_apellido(String nombre_apellido) {
        this.nombre_apellido = nombre_apellido;
    }
    public String getAsignaturas() {
        return asignaturas;
    }
    public void setAsignaturas(String asignaturas) {
        this.asignaturas = asignaturas;
    }
    /** Metodo toString */
    @Override
    public String toString() {
        return "Alumnos{" + "domicilio=" + domicilio + ", nombre_apellido=" + nombre_apellido + ", asignaturas=" + asignaturas + '}';
    }

    /** New Methods */

    void crearAlumno(String archivo) {
        System.out.println("\nCual es el nombre de la lista?");
        String nombreLista = System.console().readLine();
        int opcion = 1;
        ObjectOutputStream oos = null;
        do {
            try {
                oos = new ObjectOutputStream(new FileOutputStream(archivo, true));
                System.out.println("\nIngrese el nombre y apellido del alumno en una sola linea");
                String nombre = System.console().readLine();
                System.out.println("\nIngrese la direccion del alumno");
                String direccion = System.console().readLine();
                System.out.println("\nIngrese las materias del alumno separadas por coma");
                String materias = System.console().readLine();
                Alumnos alumno = new Alumnos(nombre, direccion, materias);
                oos.writeObject(alumno);
                // oos.writeObject(new Alumnos(nombre, direccion, materias));
                System.out.println("\nDesea agregar otro alumno? \n1-Si \n2-No");
                opcion = Integer.parseInt(System.console().readLine());
                oos.writeChars("\n\n");
            } catch (IOException e) {
                System.out.println("Error: " + e.getMessage());
            } catch (Exception e){
                System.out.println("Error: " + e.getMessage());
            } finally {
                try{
                    oos.close();
                } catch (IOException e){
                    System.out.println("Error: " + e.getMessage());
                }
            }
        } while (opcion != 2);
    }
    void verLista(String archivo) {
        ArrayList<Alumnos> listaAlumnos = new ArrayList<Alumnos>();
        System.out.println("Lista de alumnos");
        ObjectInputStream ois;
        Alumnos alumno;
        try {
            ois = new ObjectInputStream(new FileInputStream(archivo));
            alumno = (Alumnos) ois.readObject();
            System.out.println(alumno.toString());
            
            ois.close();
        } catch (EOFException e) {
            System.out.println("Fin de archivo");
        } catch (IOException e) {
            System.out.println("IOException: " + e.getMessage());
        } catch (ClassNotFoundException e) {
            System.out.println("ClassNotFound: " + e.getMessage());
        }
    }
}
