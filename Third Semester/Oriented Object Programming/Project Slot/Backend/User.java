package Backend;
import java.util.*;

import Awards.*;

import java.io.*;
import java.lang.Thread;

public class User{

    static String usuario;
    static String contrasena;
    static float pesos = 0;
    static float creditos = 0;
    static int success = 0;
    String datosUsuario = "";
    PullLever tp = new PullLever();
    String VERDE = "\u001B[32m";
    String ROJO = "\u001B[31m";
    String AZUL = "\u001B[34m";
    String AMARILLO = "\u001B[33m";
    String RESET = "\u001B[0m";

    public void escribir(String datos) {
        // Writing in the file the data of the user when he/she creates an account
        try {
            try {
                BufferedWriter bw = new BufferedWriter(new FileWriter("cuentas.csv",true));
                bw.write(datos);
                bw.close();
            } catch (FileNotFoundException e) {
                e.getMessage();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void crearCuenta() {
        // Variables for the passwords
        char [] contr1;
        char [] contr2;
        Console c = System.console();

        // Creating the account of the user
        System.out.println(AZUL+"\n\tCREAR CUENTA\n"+RESET);

        // Obtaining the name of the user
        System.out.println("\tIngresar Usuario: ");
        System.out.print("\t");
        usuario = c.readLine();

        String[] busquedaUsuario = buscarUsuario(usuario);

        if(busquedaUsuario == null) {
             // Obtaining the password of the user

            System.out.println("\tIngresar contrasena: ");
            System.out.print("\t");
            contr1 = c.readPassword();
            System.out.println("\tIngresa contrasena de nuevo: ");
            System.out.print("\t");
            contr2 = c.readPassword();

            if(!Arrays.equals(contr1, contr2)) {
                while(!Arrays.equals(contr1, contr2)) {
                    System.out.println(ROJO+"\n\tLas contrasenas no coinciden, intente de nuevo\n"+RESET);
                    System.out.println("\tIngresar contrasena: ");
                    System.out.print("\t");
                    contr1 = c.readPassword();
                    System.out.println("\tIngresa contrasena de nuevo: ");
                    System.out.print("\t");
                    contr2 = c.readPassword();
                }
            }

            System.out.println(VERDE+"\n\tCuenta creada con exito!"+RESET);

            // Concatenating the user's name, user's password, user's money and user's credtis to the end of the user's data.
            datosUsuario += usuario + ",";
            datosUsuario += new String(contr1) + ",";
            datosUsuario += "0,";
            datosUsuario += "0\n";

            // Writing the user's data in the file
            escribir(datosUsuario);

            // Clean the string.
            datosUsuario = "";
        } else {
            System.out.println("\n\tEl usuario ya existe, intente con otro nombre\n");
            crearCuenta();
        }
    }

    public String[] iniciarSesion() {
        Console cis = System.console();
        System.out.println(AZUL+"\n\t\tINICIAR SESION\n"+RESET);

        // Asking the user to input a username.
        System.out.println("\tUsuario: ");
        System.out.print("\t");
        String us_is = cis.readLine();

        // Reading the password from the console.
        System.out.println("\tContrasena: ");
        System.out.print("\t");
        char [] con_is = cis.readPassword();
        String con_string = String.valueOf(con_is);

        // Reading a csv file and checking if the username and password are correct.
        try {
            BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
                String line = csvReader.readLine();
                while (line != null && success != 1) {
                    String[] info = line.split(",");
                    if (us_is.equals(info[0]) && con_string.equals(info[1])) {
                        System.out.println(VERDE+"\tInicio de sesion correcto"+RESET);
                        success = 1;
                        return info;
                    }
                    line = csvReader.readLine();
                }
                csvReader.close();
            } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(ROJO+"\tInicio de sesion incorrecto"+RESET);
        main();
        return null;
    }

    public void bienvenida(String[] usuario){
        /** Nombre del usuario */
        System.out.println(AMARILLO+"\nBienvenido, "+usuario[0]);
        /** Saldo del usuario */
        System.out.println("Saldo disponible: "+usuario[2]);
        /** Creditos del usuario */
        System.out.println("Creditos disponibles: "+usuario[3]+RESET);
    }

    public void ingresarPesos(int ingresapesos, String[] usuario) {
        int dineroUsuario = Integer.parseInt(usuario[2]);
        dineroUsuario += ingresapesos;
        System.out.println(VERDE+"\tEl nuevo saldo es: " + dineroUsuario+RESET);

        try {
            String guardarInformacion = "";
            BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
            String line = csvReader.readLine();
            String[] info = line.split(",");
            // Cuando se obtenga la linea del usuario a modificar
            while (!info[0].equals(usuario[0]) ) {
                guardarInformacion += line + "\n";
                line = csvReader.readLine();
                info = line.split(",");
            }
            /** Actualiza el dinero */
            info[2]= Integer.toString(dineroUsuario);

            /** Guarda la informacion del usuario */
            guardarInformacion += info[0]+","+info[1]+","+info[2]+","+info[3]+"\n";

            /** Lee las otras lineas restantes del archivo */
            while ((line = csvReader.readLine()) != null) {
                guardarInformacion += line + "\n";
            }

            /** Update the csvReader file  */
            FileWriter fileWriter = new FileWriter("cuentas.csv");
            fileWriter.append(guardarInformacion);
            fileWriter.close();
            csvReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void pesosACreditos(int pesacred, String[] usuario) {
        int creditosUsuario = Integer.parseInt(usuario[3]);
        int dineroUsuario = Integer.parseInt(usuario[2]);
        if (dineroUsuario != 0 && dineroUsuario >= pesacred) {
            creditosUsuario += pesacred*10;
            System.out.println("\n\tLa nueva cantidad de creditos es: " + VERDE+ creditosUsuario+RESET);
            dineroUsuario -= pesacred;
            System.out.println("\tPesos restantes: "+VERDE + dineroUsuario+RESET);

            try {
                String guardarInformacion = "";
                BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
                String line = csvReader.readLine();
                String[] info = line.split(",");
                // Cuando se obtenga la linea del usuario a modificar
                while (!info[0].equals(usuario[0]) ) {
                    guardarInformacion += line + "\n";
                    line = csvReader.readLine();
                    info = line.split(",");
                }
                /** Actualiza el dinero */
                info[2]= String.valueOf(dineroUsuario);

                /** Actualiza los creditos */
                info[3]= String.valueOf(creditosUsuario);

                /** Guarda la informacion del usuario */
                guardarInformacion += info[0]+","+info[1]+","+info[2]+","+info[3]+"\n";

                /** Lee las otras lineas restantes del archivo */
                while ((line = csvReader.readLine()) != null) {
                    guardarInformacion += line + "\n";
                }

                /** Update the csvReader file  */
                FileWriter fileWriter = new FileWriter("cuentas.csv");
                fileWriter.append(guardarInformacion);
                fileWriter.close();
                csvReader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("No hay pesos suficientes");
        }
    }

    public void creditosAPesos(int credapes, String[] usuario) {
        int creditosUsuario = Integer.parseInt(usuario[3]);
        int dineroUsuario = Integer.parseInt(usuario[2]);
        if (creditosUsuario != 0 && creditosUsuario >= credapes) {
            dineroUsuario += credapes*0.1;
            System.out.println("\tLa nueva cantidad de pesos es: " + VERDE +dineroUsuario+RESET);
            creditosUsuario -= credapes;
            System.out.println("\tCreditos restantes: " +VERDE+ creditosUsuario+RESET);

            try {
                String guardarInformacion = "";
                BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
                String line = csvReader.readLine();
                String[] info = line.split(",");
                // Cuando se obtenga la linea del usuario a modificar
                while (!info[0].equals(usuario[0]) ) {
                    guardarInformacion += line + "\n";
                    line = csvReader.readLine();
                    info = line.split(",");
                }
                /** Actualiza el dinero */
                info[2]= String.valueOf(dineroUsuario);

                /** Actualiza los creditos */
                info[3]= String.valueOf(creditosUsuario);

                /** Guarda la informacion del usuario */
                guardarInformacion += info[0]+","+info[1]+","+info[2]+","+info[3]+"\n";

                /** Lee las otras lineas restantes del archivo */
                while ((line = csvReader.readLine()) != null) {
                    guardarInformacion += line + "\n";
                }

                /** Update the csvReader file  */
                FileWriter fileWriter = new FileWriter("cuentas.csv");
                fileWriter.append(guardarInformacion);
                fileWriter.close();
                csvReader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

        } else {
            System.out.println("No hay creditos suficientes");
        }
    }

    public void retirarPesos (int retpes, String[]usuario) {
        int dineroUsuario = Integer.parseInt(usuario[2]);
        if (dineroUsuario != 0 && dineroUsuario >= retpes) {
    		dineroUsuario -= retpes;
	    	System.out.println("\n\t"+ROJO+retpes+RESET+" pesos retirados. \n\t"+ VERDE+dineroUsuario+RESET+" dinero restante");
            try {
                String guardarInformacion = "";
                BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
                String line = csvReader.readLine();
                String[] info = line.split(",");
                // Cuando se obtenga la linea del usuario a modificar
                while (!info[0].equals(usuario[0]) ) {
                    guardarInformacion += line + "\n";
                    line = csvReader.readLine();
                    info = line.split(",");
                }
                /** Actualiza el dinero */
                info[2]= String.valueOf(dineroUsuario);

                /** Guarda la informacion del usuario */
                guardarInformacion += info[0]+","+info[1]+","+info[2]+","+info[3]+"\n";

                /** Lee las otras lineas restantes del archivo */
                while ((line = csvReader.readLine()) != null) {
                    guardarInformacion += line + "\n";
                }

                /** Update the csvReader file  */
                FileWriter fileWriter = new FileWriter("cuentas.csv");
                fileWriter.append(guardarInformacion);
                fileWriter.close();
                csvReader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
	    } else {
	        System.out.println("No hay dinero suficiente");
	    }
    }

    public void listaPremios () {
        System.out.println(AZUL+"\n\tTabla de premios para apuestas de 5 pesos:\n"+RESET);
        ArrayList<String[]> premios = new ArrayList<>();
        String[] cabecera = {"Nombre    ", " 3 objetos ", " 4 objetos ", " 5 objetos"};
        premios.add(cabecera);

        Awards uvas = new Grape();
    	String [] premiosUvas = {"Uva       ","   "+Integer.toString(uvas.getTres())+"     ", "   "+Integer.toString(uvas.getCuatro())+"    ", "   "+Integer.toString(uvas.getCinco())};
        premios.add(premiosUvas);

        Awards cerezas = new Cherry();
    	String [] premiosCereza = {"Cereza    ","   "+Integer.toString(cerezas.getTres())+"     ", "   "+Integer.toString(cerezas.getCuatro())+"    ", "  "+Integer.toString(cerezas.getCinco())};
        premios.add(premiosCereza);

        Awards comodin = new Comodin();
    	String [] premiosComodin = {"Comodin   ","   "+Integer.toString(comodin.getTres())+"   ", "   "+Integer.toString(comodin.getCuatro())+"   ", "  "+Integer.toString(comodin.getCinco())};
        premios.add(premiosComodin);

        Awards diamante = new Diamond();
    	String [] premiosDiamante = {"Diamante  ","   "+Integer.toString(diamante.getTres())+"    ", "   "+Integer.toString(diamante.getCuatro())+"   ", "   "+Integer.toString(diamante.getCinco())};
        premios.add(premiosDiamante);

        Awards sandia = new Watermelon();
    	String [] premiosSandia = {"Sandia    ","   "+Integer.toString(sandia.getTres())+"     ", "   "+Integer.toString(sandia.getCuatro())+"    ", "   "+Integer.toString(sandia.getCinco())};
        premios.add(premiosSandia);

        Awards siete = new Seven();
    	String [] premiosSiete = {"Siete     ","   "+Integer.toString(siete.getTres())+"   ", "   "+Integer.toString(siete.getCuatro())+"  ", "   "+Integer.toString(siete.getCinco())};
        premios.add(premiosSiete);

        Awards trebol = new Clover();
    	String [] premiosTrebol = {"Trebol    ","   "+Integer.toString(trebol.getTres())+"     ", "   "+Integer.toString(trebol.getCuatro())+"   ", "   "+Integer.toString(trebol.getCinco())};
        premios.add(premiosTrebol);

        for (String[] premio : premios) {
    		System.out.println("\t"+premio[0]+": "+premio[1]+" "+premio[2]+" "+premio[3]);
    	}
    }

    // Este es un metodo que cree para modificar los creditos del usuario una vez que gana
    public void modificarCreditos(int creditos, String[] usuario, int apuestas) {
        try {
            String guardarInformacion = "";
            BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
            String line = csvReader.readLine();
            // Como es una linea de STRING con ",", se separa para que se obtenga en [] y acceder mas facil
            String[] info = line.split(",");
            // Cuando se obtenga la linea del usuario a modificar
            while (!info[0].equals(usuario[0]) ) {
                guardarInformacion += line + "\n";
                line = csvReader.readLine();
                info = line.split(",");
            }
            /** Regla de 3 */
            int creditosActuales = (creditos*apuestas)/5;

            System.out.println("\n\t\t\033[35m"+"Ganaste "+creditosActuales+" creditos"+"\033[0m");

            /** Actualiza los creditos */
            info[3]= String.valueOf(Integer.parseInt(info[3])+creditosActuales);

            /** Guarda la informacion del usuario */
            guardarInformacion += info[0]+","+info[1]+","+info[2]+","+info[3]+"\n";

            /** Lee las otras lineas restantes del archivo */
            while ((line = csvReader.readLine()) != null) {
                guardarInformacion += line + "\n";
            }

            /** Update the csvReader file  */
            FileWriter fileWriter = new FileWriter("cuentas.csv");
            fileWriter.append(guardarInformacion);
            fileWriter.close();
            csvReader.close();

        } catch (FileNotFoundException e) {
            e.getMessage();
        } catch (IOException e) {
            e.getMessage();
        }
    }

    /** Modifica el dinero del usuario */
    public void modificarDinero(int dinero, String[] usuario){
        try {
            String guardarInformacion = "";
            BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
            String line = csvReader.readLine();
            String[] info = line.split(",");
            while (!info[0].equals(usuario[0]) ) {
                guardarInformacion += line + "\n";
                line = csvReader.readLine();
                info = line.split(",");
            }
            info[2]= String.valueOf(Integer.parseInt(info[2])-dinero);
            guardarInformacion += info[0]+","+info[1]+","+info[2]+","+info[3]+"\n";

            while ((line = csvReader.readLine()) != null) {
                guardarInformacion += line + "\n";
            }

            /** Update the csvReader file  */
            FileWriter fileWriter = new FileWriter("cuentas.csv");
            fileWriter.append(guardarInformacion);
            fileWriter.close();
            csvReader.close();
        } catch (FileNotFoundException e) {
            e.getMessage();
        } catch (IOException e) {
            e.getMessage();
        }
    }

    /** Mejora en un futuro */
    public String[] buscarUsuario(String nombreUsuario) {
        try {
            BufferedReader csvReader = new BufferedReader(new FileReader("cuentas.csv"));
            String line = csvReader.readLine();
            String[] info = line.split(",");
            while (line != null) {
                if (info[0].equals(nombreUsuario)) {
                    csvReader.close();
                    return info;
                }
                info = line.split(",");
                line = csvReader.readLine();
            }
            csvReader.close();
        } catch (FileNotFoundException e) {
            e.getMessage();
        } catch (IOException e) {
            e.getMessage();
        }
        return null;
    }

    public boolean tirosAutomaticos(String[] usuario) {
        imprimirDatosUsuario(usuario);
        Scanner sc = new Scanner(System.in);
        int creditosGanados = 0;
        // Mientras que los creditos del usuario no sean 0
        if (Integer.parseInt(usuario[2]) > 0) {
            /** Guarda el dinero a apostar */
            System.out.println("\n\tCuanto desea apostar?");
            System.out.print("\t");
            int apuesta = sc.nextInt();
            System.out.println("\n\tPresione "+AZUL+"T"+RESET+ " para tirar o "+AZUL+"R"+RESET+" para salir");
            System.out.print("\t");
            String tirar = sc.next();
            if (tirar.equals("T")) {
                /** Tira de la palanca y retorna los creditos ganados */
                creditosGanados = tp.Jugar();
                /** Si gana creditos */
                if (creditosGanados > 0) {
                    /** Actualiza los creditos ganados */
                    modificarCreditos(creditosGanados, usuario, apuesta);
                } else {
                    System.out.println("\nNo ganaste nada, suerte para la proxima");
                    System.out.println(ROJO+"\t\t"+"-"+apuesta+RESET);
                    /** Retira el dinero apostado de la cuenta */
                    modificarDinero(apuesta, usuario);
                }
                return true;
            } else if(tirar.equals("R")){
                System.out.println("Saliendo...");
                try {
                    Thread.sleep(800);
                } catch (Exception e) {
                    e.getMessage();
                }
            } else {
                System.out.println("Opcion invalida");
            }
            /** Si no gana creditos, pierde dinero (lo apostado) */
        } else {
            System.out.println("\tNo tienes dinero suficiente");
            System.out.println("\n\tDesea agregar dinero?\n\t( S/N )");
            System.out.print("\t");
            String respuesta = sc.next();
            if (respuesta.equals("S")) {
                System.out.println("\n\tCuanto dinero desea agregar?");
                System.out.print("\t");
                int dinero = sc.nextInt();
                ingresarPesos(dinero, usuario);
                System.out.println(VERDE+"\n\tDinero agregado"+RESET);
            } else if (respuesta.equals("N")) {
                System.out.println("\n\tSaliendo...");
                try {
                    Thread.sleep(800);
                } catch (Exception e) {
                    e.getMessage();
                }
            } else {
                System.out.println("Opcion invalida");
            }
        }
        return false;
    }

    public void imprimirDatosUsuario(String[] usuario) {
        System.out.println(AMARILLO+"\t\t\t\t\t\t\tDinero: "+RESET+VERDE+usuario[2]+RESET);
        System.out.println(AMARILLO+"\t\t\t\t\t\t\tCreditos: "+RESET+VERDE+usuario[3]+RESET);
    }

    // Metodo main
    public void main() {
        // Console s = System.console();
        Scanner sc = new Scanner(System.in);
        int opc = 0;
        int opcInicio = 0;
        int opc2 = 0;
        String usuario[] = null;
        String menu = "\n1. Jugar" +
                "\n2. Modificar cuenta" +
                "\n3. Ver lista de premios" +
                "\n4. Cerrar sesion";

        String menuInicio = "\n1. Crear cuenta"+
                            "\n2. Iniciar sesion";

        String menuModificar = "\n\t1. Ingresar pesos" +
                                "\n\t2. Pesos a creditos" +
                                "\n\t3. Creditos a pesos" +
                                "\n\t4. Retirar pesos" +
                                "\n\t5. Guardar y salir";

        System.out.println("\nElige una opcion: "+menuInicio);
        opcInicio = sc.nextInt();

        while (opcInicio > 0 && opcInicio < 3) {
            switch (opcInicio) {
                case 1:
                /** Se crea la cuenta y se guarda en cuentas.csv con exito */
                    crearCuenta();
                    System.out.println(menuInicio);
                    opcInicio = sc.nextInt();
                    break;
                case 2:
                /** Cuando ingrese el usuario, se guarda su info en un String[] */
                    usuario = iniciarSesion();
                    opcInicio = 3;
            }
        }

        /** 2 */
        if (usuario != null) {
            // Metodo de bienvenida al usuario
            bienvenida(usuario);

            System.out.println("\nElige opcion: " + menu);
            opc = sc.nextInt();
            while (opc > 0 && opc <= 4) {
                usuario = buscarUsuario(usuario[0]);
                switch (opc) {
                    case 1:
                        boolean tirosAutomaticos = true;
                        while(tirosAutomaticos){
                            usuario = buscarUsuario(usuario[0]);
                            tirosAutomaticos = tirosAutomaticos(usuario);
                        }
                        System.out.println("\nElige opcion: " + menu);
                        opc = sc.nextInt();
                        sc.nextLine();
                        break;
                    case 2:
                        System.out.println("\tMODIFICAR CUENTA\n");
                        System.out.println("\tElige una opcion: " + menuModificar);
                        System.out.print("\t");
                        opc2 = sc.nextInt();
                        do {
                            usuario = buscarUsuario(usuario[0]);
                            switch (opc2) {
                                case 1:
                                    System.out.println(AZUL+"\t\tINGRESAR PESOS"+RESET);
                                    System.out.println(AMARILLO+"\n\tDebe ingresar un minimo de 20 o un maximo de 1,000,000 pesos"+RESET);
                                    System.out.println("\tCantidad de pesos a ingresar: ");
                                    System.out.print("\t");
                                    int ingresapesos = sc.nextInt();
                                    if (ingresapesos > 19 && ingresapesos < 1000000) {
                                        ingresarPesos(ingresapesos, usuario);
                                    } else {
                                        System.out.println(ROJO+"\t\tCantidad invalida"+RESET);

                                    }
                                    break;
                                case 2:
                                    System.out.println(AZUL+"\t\tPESOS A CREDITOS"+RESET);
                                    System.out.println("\n\tPesos disponibles: " + VERDE+ usuario[2]+RESET);
                                    System.out.println("\tCantidad de pesos que desea convertir a creditos: ");
                                    System.out.print("\t");
                                    int pesacred = sc.nextInt();
                                    pesosACreditos(pesacred, usuario);
                                    break;
                                case 3:
                                    System.out.println(AZUL+"\t\tCREDITOS A PESOS"+RESET);
                                    System.out.println("\n\tCreditos disponibles: " + VERDE +usuario[3]+RESET);
                                    System.out.println("\n\tIngrese la cantidad de creditos que desea convertir a pesos sin decimal: ");
                                    System.out.print("\t");
                                    int credapes = sc.nextInt();
                                    creditosAPesos(credapes, usuario);

                                    break;
                                case 4:
                                    System.out.println(AZUL+"\t\tRETIRAR PESOS"+RESET);
                                    System.out.println("\n\tPesos disponibles: " + VERDE+usuario[2]+RESET);
                                    System.out.println("\tCuanto desea retirar? ");
                                    System.out.print("\t");
                                    int retpes = sc.nextInt();
                                    retirarPesos(retpes, usuario);
                                    break;
                                case 5:
                                    System.out.println("\nVolviendo...");
                                    try{
                                        Thread.sleep(800);
                                    } catch (Exception e){
                                        e.getMessage();
                                    }
                                    opc2 = 6;
                                    continue;
                                default:
                                    System.out.println("\tElige una opcion correcta" + menuModificar);
                                    opc2 = sc.nextInt();
                                    break;
                            }
                            System.out.println(menuModificar);
                            System.out.print("\t");
                            opc2 = sc.nextInt();
                            sc.nextLine();
                        } while (opc2 > 0 && opc2 < 6);
                        System.out.println("\nElige opcion: " + menu);
                        opc = sc.nextInt();
                        sc.nextLine();
                        break;
                    case 3:
                        listaPremios();
                        System.out.println("\nElige opcion: " + menu);
                        opc = sc.nextInt();
                        sc.nextLine();
                        break;
                    case 4:
                        System.out.println(AMARILLO+"\nGracias por jugar con nostros!!\n"+RESET);
                        try{
                            Thread.sleep(500);
                        } catch (InterruptedException e){
                            e.printStackTrace();
                        }
                        opc += opc;
                        break;
                    default:
                        System.out.println("Escoge una opcion correcta");
                        break;
                }
            }
        }
    }
}
