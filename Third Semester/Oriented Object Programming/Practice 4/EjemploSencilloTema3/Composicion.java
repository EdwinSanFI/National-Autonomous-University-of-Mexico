/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;
/**
 *
 * @author Edgar
 */
public class Composicion {
    
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);
        Persona persona1=new Persona();
        System.out.println("Ingresa el nombre");
        persona1.setNombre(stdIn.nextLine());
        System.out.println("Apellido");
        persona1.setApellidoPaterno(stdIn.nextLine());
        System.out.println("edad");
        persona1.setEdad(stdIn.nextInt());
        System.out.println(persona1.toString());
        Libro.mostrarNumLibros();
        stdIn.nextLine();
        System.out.println("Ingresa el Titulo");
        String titulo = stdIn.nextLine();
        System.out.println("Ingresa el autor");
        String autor = stdIn.nextLine();
        Libro nuevo = new Libro(titulo,autor);
        persona1.asociarLibroPersona(nuevo);
        persona1.imprimirLibro();
        nuevo.vender();
        nuevo.fotocopiar();
        System.out.println(Libro.numLibros);
        
    }
    
    



}
