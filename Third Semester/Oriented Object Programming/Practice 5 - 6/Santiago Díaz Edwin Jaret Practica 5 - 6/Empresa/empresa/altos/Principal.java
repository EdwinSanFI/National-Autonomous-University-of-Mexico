package altos;

import otros.*;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Edgar
 */
public class Principal {
      public static void main(String args[]){

        Directivo directivo1 = new Directivo("Jhon","Smith");
        directivo1.setPuesto("CEO");
        directivo1.setSalarioBase(50_000);


        Gerente gerente1 = new Gerente("Juan","Perez");
        gerente1.setPuesto("G de Ventas");
        gerente1.setNumSubordinados(5);

        Gerente gerente2 = new Gerente("Luis","garcia");
        gerente2.setPuesto("G de Ingenieria");
        gerente2.setNumSubordinados(3);


        Operativo operativo1 = new Operativo("Luis","gomez");
        operativo1.setJornadaLaboral(10);
        operativo1.setTurno("matutino");


        Operativo operativo2 = new Operativo("david","faitelson");
        operativo2.setJornadaLaboral(12);
        operativo2.setTurno("vespertino");


        directivo1.setSalarioAdicional(100_000);
        directivo1.setSalarioOtro(gerente1,20_000);
        directivo1.setSalarioOtro(gerente2,20_000);
        directivo1.setSalarioOtro(operativo1, 5_000);
        directivo1.setSalarioOtro(operativo2, 5_500);



        System.out.println("desde operativo 1 "+operativo1.getsalarioBase());
        System.out.println("desde operativo 2 "+operativo2.getsalarioBase());
        System.out.println("desde gerente, salario gerente "+gerente1.getsalarioBase());
        System.out.println("desde gerente, salario operativo "+gerente1.getSalarioSubordinado(operativo1));
        System.out.println("desde directivo, salario gerente"+directivo1.getSalarioOtro(gerente1));
        System.out.println("desde directivo, salario operaivo "+directivo1.getSalarioOtro(operativo2));
      //  sirectivo1.

        // operativo1.setSalarioBase(300000);   //queremos evitar esto

    }
}
