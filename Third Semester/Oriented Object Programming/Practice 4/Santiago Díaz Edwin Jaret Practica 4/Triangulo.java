/**
 * @author: Edwin Santiago
 */

// La clase guarda atributos de un Triangulo y crea 3 métodos
// Para calcular el área (cada método es distinto)
public class Triangulo {
    // Valores de un triángulo
    float base, altura;

    // Calcula el área usando this
    public float area(){
        return (float)((this.base*this.altura)/2.0);
    }

    // Calcula el area recibiendo parametros de tipo flotante en la funcion
    public float area(float base, float altura) {
        return (float)((base*altura)/2.0);
    }

    // Calcula el area recibiendo parámetros de tipo entero en la función
    public float area(int base, int altura){
        return(float)((base*altura)/2.0);
    }
}