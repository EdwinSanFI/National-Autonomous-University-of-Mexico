public final class primerParical {
    static int contador = 0;
    staticint atributo1;
    double atributo2;
    String atributo3;

    public void primerParical(){
        contador++;
    }
    public void primerParcial(int atributo1) {
        contador++;
        this.atributo1=atributo1;
    }
    public static int metodo1() {
        int a=23;
        metodo2(a,10);
        System.out.println("Hola,\"a\"vale:"+a);
        return a;
    }
    public static int metodo2(int a, int b){
        System.out.println("Vamos a sumar");
        int c =a+b;
        return c;
    }
    public String metodo2(int var, int var2){
        String mensaje ="Hola mundo"+var;
        System.out.println(var2);
        return mensaje;
    }
    public static void main(String[] args) {
        primerParical prueba=new primerParical();
        prueba.atributo3="reprobado";
        prueba.atributo1=10;
        metodo1();
        System.out.println(primerParical.atributo1);
    }
}
