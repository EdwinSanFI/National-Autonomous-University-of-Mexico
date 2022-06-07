/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author Edgar
 */
public class Persona {
    String nombre;
    String apellidoPaterno;
    String curp;
    int edad;
    String genero;
    Libro libro1;
    
    public void hablar(){
        System.out.println("Hola");
    }
    
    public void caminar(){
        System.out.println("estoy caminando");
    }
    
    public void pensar(){
        System.out.println("Lisa es quien piensa");
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidoPaterno() {
        return apellidoPaterno;
    }

    public void setApellidoPaterno(String apellidoPaterno) {
        this.apellidoPaterno = apellidoPaterno;
    }

    public String getCurp() {
        return curp;
    }

    public void setCurp(String curp) {
        this.curp = curp;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public Libro getLibro1() {
        return libro1;
    }

    public void setLibro1(Libro libro1) {
        this.libro1 = libro1;
    }
    
    public void asociarLibroPersona(Libro libro){
        this.setLibro1(libro);
    }
    @Override
    public String toString() {
        return "Persona{" + "nombre=" + nombre + ", apellidoPaterno=" + apellidoPaterno + ", edad=" + edad + '}';
    }

    public void imprimirLibro(){
        System.out.println("El libro de "+this.nombre + " es " + libro1.toString());
    }
    
  
    
    
    
}








