/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
// package excepciones;

import java.util.*;

/**
 *
 * @author Edgar
 */
public class Excepciones {

    private  Scanner teclado;
    /**
     * Método Main
     */
    public static void main(String[] args) {
        /** Instancia un objeto de la clase Excepciones */
        Excepciones prueba = new Excepciones();
        /** Llama al método leerDatos con parametro 0, esto es de numero de intentos*/
        prueba.leerDatos(0);
    }
    /**
     * Metodo que lee los datos, el divisor y dividiendo
     * @param intentos numero de intentos
     */
    private void leerDatos(int intentos){
        teclado=new Scanner(System.in);
        int dividendo=1;
        int divisor=1;
        /** El usuario tiene un maximo de 3 intentos para volver a ingresar los valores */
        if (intentos<3){
            /** Bloque try-catch para manejar la excepcion que ingrese un valor numerico */
            try {
                System.out.println("Introduce dividendo");
                dividendo=teclado.nextInt();
                teclado.nextLine();
                System.out.println("Introduce divisor");
                divisor=teclado.nextInt();
                teclado.nextLine();
                /** LLama al metodo para dividir los numeros */
                metodoDividir(dividendo,divisor, intentos+1);
            } catch (InputMismatchException e) {
                /** En caso de que no ingrese un valor numero
                 * se llama recursivamente aumentando el numero de intentos */
                System.out.println("No ingresaste un numero, intente de nuevo");
                leerDatos(intentos+1);
            }
        }
        /** En caso de que haya superado el numero de intentos */
        else{
            System.out.println("Has superado el numero de intentos");
        }
    }

    private void metodoDividir(int dividendo, int divisor, int intentos){
        int resultado=0;
        /** Bloque Try-catch para manejar la excepcion de division entre 0 */
        try{
            /** Se realiza la division y finaliza el programa */
            resultado=dividendo/divisor;
            System.out.println("El resultado es: "+resultado);
        }
        catch(ArithmeticException e){
                /** En caso de que se ingrese divisor 0, el usuairo puede ingresar los numeros de nuevo */
                System.out.println("Error de usuario, no se puede dividir entre cero");
                leerDatos(intentos+1);
        }
    }
}
