/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package excepciones;
import java.util.*;
/**
 *
 * @author Edgar
 */
public class Excepciones4 {
    private static final String CLASS_TO_LOAD = "java.util.Calendar2";
    // Método Main
    public static void main(String[] args){
        Entrada();
    }

    // Método que lee los datos
    public static void Entrada(){
        System.out.println("Bienvenido al programa");
        System.out.println("vamos a buscar la clase");
        /**
         * Llama al metodo buscarClase y en caso de que no exista lanza una excepcion y entra al catch
         */
        try {
            buscarClase();
        } catch (ClassNotFoundException e) {
            System.out.println("No se encontro la clase");
        }
    }

    // Método que busca la clase
    /**
     * Lanza una excepción en caso de que no se encuentra el archivo
     * @throws ClassNotFoundException
     */
    private static void buscarClase() throws ClassNotFoundException{
        Class loadedClass = Class.forName(CLASS_TO_LOAD);
        System.out.println("Class " + loadedClass + " found successfully!");
    }

}
