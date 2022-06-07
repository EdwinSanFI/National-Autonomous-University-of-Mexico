/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package excepciones;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author Edgar
 */
public class Excepciones2 {
    /** Metodo MAIN */
    public static void main(String[] args) throws IOException {
        manejoDeArchivos();
    }
    /** Metodo que lee los datos del archivo
     * @throws IOException excepcion de lectura de archivo
     * @throws FileNotFoundException excepcion que se lanza cuando no se encuentra el archivo
     */
    private static void manejoDeArchivos() throws FileNotFoundException, IOException {
            BufferedReader fileInput;
            /** Abre el archivo */
            FileReader file = new FileReader("prueba.txt");
            fileInput = new BufferedReader(file);
            /** Recorre las 3 primeras lineas del archivo */
            for (int counter = 0; counter < 3; counter++)  {
                /** Imprime las lineas del archivo */
                System.out.println(fileInput.readLine());
            }
            /** Cierra el archivo */
            fileInput.close();
    }
}