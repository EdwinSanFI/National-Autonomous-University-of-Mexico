// *** POINT OF SALE ***
// *** OF 100 PRODUCTS WITH PROMOTIONS ***

#include <stdio.h>
void main (void)
{
    //Size of the array "multi"
    #define SIZE 100
    //Number of promotions
    #define PROMOTIONS 30

    // Defining the sizes of the arrays
    float multi[SIZE], totalDePago;
    int  totalpro, codigo, productos[SIZE], promocion[30], division[30], residuo[30], i, pago, totalDeProductos;
    // Special caracters to use accents
    char aa = 160, ae = 130, ai = 161, ao = 162, aoo = 224, au = 163, an = 164, ap = 168, ii = 173, ac = 39, p = 37;

    //Welcome message
    printf("---------------------------------------------------------------------------------------------------------------------------------------");
    printf ("\n\t\t\t\t\t\t\t BIENVENIDO \n");

    printf ("\t El programa calcular%c el precio junto con las cantidades ingresadas del producto seleccionado\n",aa);
    printf ("\t\t\t Deber%c de ingresar el c%cdigo de barras con respecto al producto \n",aa,ao); 

    printf ("\n\n\t\t\t %cPROMOCI%cN SOLO POR HOY!  \n\t\t %c3x2 LLevese 3 y Pague 2!",ii,aoo,ii);
    printf ("\n\t S%clo productos seleccionados, del 20 al 29\n",ao);

    printf ("\n\n\t\t\t %cPROMOCI%cN SOLO POR HOY!  \n\t\t %c2x1 LLevese 2 y Pague 1! ",ii,aoo,ii);
    printf ("\n\t S%clo productos seleccionados, del 30 al 40\n\t",ao);

    printf ("\n\n\t\t\t EN ESTE BUEN FIN APROVECHE \n\t\t %cNUESTROS DESCUENTOS DE HASTA 25%c DE MENOS!",ii,p);
    printf ("\n\t S%clo productos seleccionados, del 41 al 50\n",ao);

    printf("---------------------------------------------------------------------------------------------------------------------------------------");
    // Iniciamos cada lugar de los arreglos en 0.
        for (i = 0; i < 101; i++)
            {
                multi[i] = 0;
                productos[i] = 0;
            }
        for (i = 0; i < 31; i++)
            {
                promocion[i] = 0;
                division[i] = 0;
                residuo[i] = 0;
            }
    //El ciclo Do es para que el usuario pueda ingresar más de un producto
    do 
    {
        printf("\n\n\t Presione 111 para conocer el total a pagar");
        printf ("\n\t Ingrese el c%cdigo de barras \n\t",ao);
        scanf ("%d",&codigo); 
        //El código que ingrese el usuario se guardará en la variable "codigo", el cual acepta del 1 al 100
        //Si se supera el valor de 100 es porque se quiere conocer el total a pagar, o solo ingresando 111
        switch (codigo)
        {
            // Cada caso es un producto con su Nombre, Descripción, precio sin IVA y las operaciones matemáticas correspondientes
            // las cuales definen el monto a pagar y las PROMOTIONS aplicadas (en productos con PROMOTIONS)
            /*
                En los productos "normales" que no tienen PROMOTIONS, se va a multiplicar el precio sin IVA
                por 1.16, dando el precio con IVA y al final se multiplicará por la cantidad de productos que ingrese
                el usuario.
            */
            
            case 1:
                printf ("\n\tRefresco Coca-Cola de 600 ml \n\t");
                printf ("Con el refresco se sentir%c bien hidratado \n\t",aa);
                printf ("El precio es de $10.00 (sin IVA) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[1]);
                multi[1]=(10*1.16)*productos[1];
                printf ("\n\n\t El total con IVA es de $%.2f",multi[1]); 
                break;

            case 2:
                printf ("\n\tRefesco Coca-Cola de 1 litro \n\t");
                printf ("El refresco te puede refrescar y dura m%cs tiempo \n\t",aa);
                printf ("El precio del producto es de $14.00 (sin IVA) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[2]);
                multi[2]=(14*1.16)*productos[2];
                printf ("\n\n\t El total con IVA es de $%.2f",multi[2]);
                break;

            case 3:
                printf ("\n\tRefresco Coca-Cola de 3 Litros  \n\t");
                printf ("Con este refresco te puede refrescar y alcanza hasta para compartir \n\t"); 
                printf ("El precio del producto es de $35.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[3]);
                multi[3]=(35*1.16)*productos[3];
                printf ("\n\n\t El total con IVA es de $%.2f",multi[3]);
                break;

            case 4:
                printf ("\n\tGatorade de 600 ml \n\t");
                printf ("Este es una bebida energ%ctica que te ofrece minerales fundamentales para el cuerpo humano \n\t",ae);
                printf ("El precio del producto es de $16.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[4]);
                multi[4]=(16*1.16)*productos[4];
                printf ("\n\n\t El total con IVA es de $%.2f", multi[4]);
                break;

            case 5:
                printf ("\n\tGatorade de 1 Litro \n\t");
                printf ("Con el Gatorade te da m%cs minerales que son esenciales para el cuerpo humano mientras lo hidrata \n\t",aa);
                printf ("El precio del producto es de $20.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[5]);
                multi[5]=(20*1.16)*productos[5];
                printf ("\n\n\t El total con IVA es de $%.2f", multi[5]);
                break;

            case 6:
                printf ("\n\tAceite Nutrioli de 946 ml \n\t");
                printf ("%cEl mejor aceite que existe! Bajo en colesterol \n\t",ii);
                printf ("El precio del producto es de $25.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[6]);
                multi[6]=(25*1.16)*productos[6];
                printf ("\n\n\t El total con IVA es de $%.2f", multi[6]);
                break;

            case 7:
                printf ("\n\tAceite capullo de 845 ml \n\t");
                printf ("El aceite Capullo siempre est%c cuidando de tu coraz%cn, est%c hecho 100 porciento de Canola \n\t",aa,ao,aa);
                printf ("El precio del producto es de $30.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[7]);
                multi[7]=(30*1.16)*productos[7];
                printf ("\n\n\t El total con IVA es de $%.2f", multi[7]);
                break;

            case 8:
                printf ("\n\tMayone McCormick con jugo de lim%cn de 320 gr \n\t",ao);
                printf ("Siendo la mejor mayonesa de aderezos para la comida que usted guste \n\t");
                printf ("El precio del producto es de $30.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[8]);
                multi[8]=(30*1.16)*productos[8];
                printf ("\n\n\t El total con IVA es de $%.2f", multi[8]);
                break;

            case 9:
                printf ("\n\tMayonesa Hellmanns%cs 325 gr \n\t",ac);
                printf ("Usada conmunmente en sandwiches y todo tipo de tortas \n\t");
                printf ("El precio del producto es de $26.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[9]);
                multi[9]=(30*1.16)*productos[9];
                printf ("\n\n\t El total con IVA es de $%.2f", multi[9]);
                break;

            case 10:
                printf ("\n\tKetchup Heinz 397 gr \n\t");
                printf ("%cDisfruta este inigualable sabor de Ketchup Heinz!, Sin conservadores, sin colorantes \n\t",ii);
                printf ("El precio del producto es de $17.00 (sin iva) \n\t");
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[10]);
                multi[10]=(17*1.16)*productos[10];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[10]);
                break;

            case 11:
                printf ("\n\tCaldo de Riko Pollo 8 Cubos \n\t"); 
                printf ("El nuevo Riko Pollo tiene menos grasa pero mayor sabor \n\t"); 
                printf ("El precio del producto es de $10.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[11]);
                multi[11]=(10*1.16)*productos[11];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[11]);
                break;

            case 12:
                printf ("\n\tCaldo de Pollo Knorr  frasco en pollo 450 gr \n\t"); 
                printf ("En knorr estamos convencidos que para que un platillo tenga un gran sabor \n\t"); 
                printf ("El precio del producto es de $75.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[12]);
                multi[12]=(75*1.16)*productos[12];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[12]);
                break;

            case 13:
                printf ("\n\tBebida Hidratante Suerox 630ml de Sabores \n\t"); 
                printf ("Bebida Hidratante que contiene 8 iones, vitam%cna C y electrolitos orales \n\t",ai); 
                printf ("El precio del producto es de $20.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                productos[13] = 0;
                scanf ("%i", &productos[13]);
                multi[13]=20*1.16*productos[13];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[13]);
                break; 

            case 14:
                printf ("\n\tSuero Electrolit de Sabores 365ml \n\t"); 
                printf ("Contiene minerales y electrol%ctos que regulan al cuerpo humano \n\t",ai); 
                printf ("El precio del producto es de $20.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[14]);
                multi[14]=20*1.16*productos[14];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[14]);
                break; 

            case 15:
                printf ("\n\tKilo de Comida para Perros \n\t"); 
                printf ("La mejor comida para tus mascotas, les encantar%c\n\t",aa); 
                printf ("El precio del producto es de $30.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[15]);
                multi[15]=75*1.16*productos[15];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[15]);
                break; 

            case 16:
                printf ("\n\tCaldo de Pollo Knorr  frasco en pollo 450 gr \n\t"); 
                printf ("En knorr estamos convencidos que lo necesitas para que platillo tenga un gran sabor \n\t"); 
                printf ("El precio del producto es de $75.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[16]);
                multi[16]=75*1.16*productos[16];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[16]);
                break;

            case 17:
                printf ("\n\tCaf%c molido legal con az%ccar 200 gr\n\t",ae,au); 
                printf ("Disfruta de la m%cs rica y antigua tradici%cn mexicana. Ya sea s%clo, con un amigo, en pareja \n\t \
                o acompa%cado de tu familia. Caf%c Legal es la opci%cn perfecta para disfrutar cada momento del d%ca \n\t",aa,ao,ao,an,ae,ao,ai); 
                printf ("El precio del producto es de $27.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[17]);
                multi[17]=17.50*1.16*productos[17];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[17]);
                break; 

            case 18:
                printf("\n\tCaf%c Soluble Nescaf%c cl%csico 225 gr \n\t",ae,ae,aa); 
                printf("Si lo que quieres es comenzar tu d%ca con la energ%ca suficiente para realizar tu \n\t \
                actividades al m%cximo, este caf%c es para ti.  \n\t",ai,ai,aa,ae); 
                printf("El precio del producto es de $82.00 (sin iva) \n\t");  
                printf("¿Cuantos desea llevar? \n\t");
                scanf("%i", &productos[18]);
                multi[18]=82*1.16*productos[18];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[18]);
                break;

            case 19:
                printf("\n\tAz%ccar mascabado 500 gr \n\t",au); 
                printf("El az%ccar mascabado, tambi%cn conocido como az%ccar moreno, es una versi%cn menos refinada \n\t \
                del az%ccar obtenido de la ca%ca de az%ccar. \n\t",au,ae,au,ao,au,an,au); 
                printf("El precio del producto es de $18.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf("%i", &productos[19]);
                multi[19]=18*1.16*productos[19];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[19]);
                break; 
            /*
                En el caso de la promoción de 3x2, lo que hace el programa es 
                dividir la cantidad de productos que ingresa el usuario entre 3 
                y obtener el cociente y el residuo. 
            */
            case 20:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo); 
                printf("\n\tEndulzante Splenda 100 sobres de 1 g c/u \n\t"); 
                printf("Con Splenda Original, sigue disfrutando lo dulce que tanto te gusta, sin las calor%c­as del  \n\t \
                az%ccar. Su delicioso sabor, lo ha hecho ganador del Sabor del a%co durante 4 a%cos seguidos \n\t",ai,au,an,an); 
                printf("El precio del producto es de $60.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf("%i", &productos[20]);
                promocion[1]=(productos[20]%3);
                division[1]=(productos[20]/3);
                /*
                    Si el residuo da 0 significa que
                    el número es divisible entre 3, y la cantidad de productos ingresados
                    se le restará el coeficiente de la división y ese valor será la cantidad de productos
                    a pagar
                    Por ejemplo si el usuario ingresa 3, al dividirlo entre 3 se obtiene coeficiente de 1
                    y 3 - 1 da 2, esa cantidad son por las que va a pagar
                */
                if (promocion[1] == 0)
                {
                    residuo[1]=productos[20]-division[1];
                    multi[20]=(60*1.16)*residuo[1];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[20]);
                    printf ("\n\n");
                }
                /*
                    Si el residuo da 1 sucede lo mismo, pero con la diferencia que se va a aplicar 
                    la promoción de 3x2 + coeficiente del producto que no entra en la promoción 
                    Si se ingresa 4, al dividirlo entre 3, se obtiene un coeficiente de 1 y se le restará
                    4 - 1, esto da 3 y será la cantidad de productos a pagar 
                    Aplicando la promoción 3x2 más 1 productos que no entran en promoción
                */
                else if (promocion[1]==1)
                {
                    residuo[1]=productos[20]-division[1];
                    multi[20]=(60*1.16)*residuo[1];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[20]);
                    printf ("\n\n");
                }
                /*
                    Si el residuo da 2 sucede lo mismo, pero con la diferencia que se va a aplicar 
                    la promoción de 3x2 + coeficiente del producto que no entra en la promoción 
                    Si se ingresa 5, al dividirlo entre 3, se obtiene un coeficiente de 1 y se le restará
                    5 - 1, esto da 4 y será la cantidad de productos a pagar 
                    Aplicando la promoción 3x2 más 2 productos que no entran en promoción
                */
                else if (promocion[1]==2)
                {
                    residuo[1]=productos[20]-division[1];
                    multi[20]=(60*1.16)*residuo[1];
                    printf ("\\n\n\t El total con IVA es de  $%.2f", multi[20]);
                    printf ("\n\n");
                }
                break;
            
            case 21:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo); 
                printf ("\n\tCereal Kellogg%cs Choco Krispis sabor chocolate 800 gr \n\t",ac); 
                printf ("Disfruta de un desayuno completo y balanceado todos los d%cas con Choco Krispis y su agradable \n \
                \t sabor chocolate. Exquisitos granos de arroz inflados con sabor chocolate.  \n\t",ai); 
                printf ("El precio del producto es de $53.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf("%i",&productos[21]);
                promocion[2]=productos[21]%3;
                division[2]=productos[21]/3;
                if (promocion[2] == 0)
                {
                    residuo[2] = productos[21]-division[2];
                    multi[21] = (53*1.16)*residuo[2];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[21]);
                    printf ("\n\n");
                }
                else if (promocion[2] == 1)
                {
                    residuo[2] = productos[21]-division[2];
                    multi[21] = (53*1.16)*residuo[2];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[21]);
                    printf ("\n\n");
                }
                else if (promocion[2] == 2)
                {
                    residuo[2] = productos[21]-division[2];
                    multi[21] = (53*1.16)*residuo[2];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[21]);
                    printf ("\n\n");
                }
                break;

            case 22:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo); 
                printf ("\n\tCereal Kelloggs Zucaritas 490 gr \n\t"); 
                printf ("Un buen desayuno es la clave para rendir al m%cximo diariamente. Gracias a Cereales Kellogg%cs \n\t \
                Zucaritas, podras tener un desayuno saludable, llenandote de sabor y energi%ca por las ma%canas. \n\t",aa,ac,ai,an); 
                printf ("El precio del producto es de $54.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[22]);
                promocion[3]=(productos[22]%3);
                division[3]=(productos[22]/3);
                if (promocion[3] == 0)
                {
                    residuo[3] = productos[22]-division[3];
                    multi[22] = (54*1.16)*residuo[3];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[22]);
                    printf ("\n\n");
                }
                else if (promocion[3]==1)
                {
                    residuo[3] = productos[22]-division[3];
                    multi[22] = (54*1.16)*residuo[3];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[22]);
                    printf ("\n\n");
                }
                else if (promocion[3]==2)
                {
                    residuo[3] = productos[22]-division[3];
                    multi[22] = (54*1.16)*residuo[3];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[22]);
                    printf ("\n\n");
                }
                break; 

            case 23:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo);
                printf ("\n\tCereal Kellogg%cs All Bran original 465 gr\n\t",ac); 
                printf ("Para ese desayuno nutritivo que tanto buscas. Kellogg%cs tiene para ti el Cereal Kellogg%cs \n\
                All Bran original de 465 gramos. Para comenzar el d%ca lleno de energ%ca con un buen desayuno. \n\t",ac,ac,ai,ai); 
                printf ("El precio del producto es de $50.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[23]);
                promocion[4]=(productos[23]%3);
                division[4]=(productos[23]/3);
                if (promocion[4]==0)
                {
                    residuo[4] = productos[23]-division[4];
                    multi[23] = (50*1.16)*residuo[4];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[23]);
                    printf ("\n\n");
                }
                else if (promocion[4]==1)
                {
                    residuo[4] = productos[23]-division[4];
                    multi[23] = (50*1.16)*residuo[4];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[23]);
                    printf ("\n\n");
                }
                else if (promocion[4]==2)
                {
                    residuo[4] = productos[23]-division[4];
                    multi[23] = (50*1.16)*residuo[4];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[23]);
                    printf ("\n\n");
                }
                break;

            case 24:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo);
                printf ("\n\tChilito Piqu%cn la Coste%ca en polvo 130 gr \n\t",ai,an); 
                printf ("Agrega a todas tus botanas y antojos favoritos el chilito en polvo de la Coste%ca \n\t \
                que es perfecto porque va con todo, como con unos frescos pepinos con lim%cn o con unas j%ccamas rayadas. \n\t",an,ao,ai); 
                printf ("El precio del producto es de $18.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[24]);
                promocion[5]=(productos[24]%3);
                division[5]=(productos[24]/3);
                if (promocion[5]==0)
                {
                    residuo[5] = productos[24]-division[5];
                    multi[24] = (18*1.16)*residuo[5];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[24]);
                    printf ("\n\n");
                }
                else if (promocion[5]==1)
                {
                    residuo[5] = productos[24]-division[5];
                    multi[24] = (18*1.16)*residuo[5];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[24]);
                    printf ("\n\n");
                }
                else if (promocion[5]==2)
                {
                    residuo[5] = productos[24]-division[5];
                    multi[24] = (18*1.16)*residuo[5];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[24]);
                    printf ("\n\n");
                }
                    break;

            case 25:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo);
                printf ("\n\tCaldo de Pollo Knorr  frasco en pollo 450 gr \n\t"); 
                printf ("El mejor caldo de pollo para la familia\n\t"); 
                printf ("El precio del producto es de $75.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[25]);
                promocion[6]=(productos[25]%3);
                division[6]=(productos[25]/3);
                if (promocion[6]==0)
                {
                    residuo[6] = productos[25]-division[6];
                    multi[25] = (18*1.16)*residuo[6];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[25]);
                    printf ("\n\n");
                }
                else if (promocion[6]==1)
                {
                    residuo[6] = productos[25]-division[6];
                    multi[25] = (18*1.16)*residuo[6];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[25]);
                    printf ("\n\n");
                }
                else if (promocion[6]==2)
                {
                    residuo[6] = productos[25]-division[6];
                    multi[25] = (18*1.16)*residuo[6];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[25]);
                    printf ("\n\n");
                }
                break;

            case 26:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo);
                printf ("\n\tGelatina de agua Dany 6 pack \n\t"); 
                printf ("Consiente y nutre a tus hijos con las gelatinas de agua de sabores de la marca Dany\n\t"); 
                printf ("El precio del producto es de $24.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i",& promocion[26]);
                promocion[7]=(productos[26]%3);
                division[7]=(productos[26]/3);
                if (promocion[7]==0)
                {
                    residuo[7] = productos[26]-division[7];
                    multi[26] = (24*1.16)*residuo[7];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[26]);
                    printf ("\n\n");
                }
                else if (promocion[7]==1)
                {
                    residuo[7] = productos[26]-division[7];
                    multi[26] = (24*1.16)*residuo[7];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[26]);
                    printf ("\n\n");
                }
                else if (promocion[7]==2)
                {
                    residuo[7] = productos[26]-division[7];
                    multi[26] = (24*1.16)*residuo[7];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[26]);
                    printf ("\n\n");
                }
                break; 

            case 27:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo);
                printf ("\n\tPolvo para gelatina de agua D%cGari sabores 120 gr \n\t",ac); 
                printf ("Sorprende todos los d%cas a tu familia con la gelatina de sabores de la marca D%cGari, \n\t \
                un producto en polvo que te ayudar%c a preparar tus recetas de gelatina favoritas con incre%cbles sabores. \n\t",ai,ac,aa,ai); 
                printf ("El precio del producto es de $9.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[27]);
                promocion[8]=(productos[27]%3);
                division[8]=(productos[27]/3);
                if (promocion[8]==0)
                {
                    residuo[8] = productos[27]-division[8];
                    multi[27] = (9*1.16)*residuo[8];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[27]);
                    printf ("\n\n");
                }
                else if (promocion[8]==1)
                {
                    residuo[8] = productos[27]-division[8];
                    multi[27] = (9*1.16)*residuo[8];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[27]);
                    printf ("\n\n");
                }
                else if (promocion[8]==2)
                {
                    residuo[8] = productos[27]-division[8];
                    multi[27] = (9*1.16)*residuo[8];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[27]);
                    printf ("\n\n");
                }
                break;

            case 28:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo);
                printf ("\n\tHarina de Tr%cco Selecta 1 kg \n\t",ai); 
                printf ("La harina de tr%cgo Selecta es una excelente opción para cocinar tus recetas de postres  \n\t \
                favoritos, util%czala para preparar desde un pastel de cumplea%cos hasta unas tortillas de har%cna \n\t",ai,ai,an,ai); 
                printf ("El precio del producto es de $12.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[28]);
                promocion[9]=(productos[28]%3);
                division[9]=(productos[28]/3);
                if (promocion[9]==0)
                {
                    residuo[9] = productos[28]-division[9];
                    multi[28] = (12*1.16)*residuo[9];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[28]);
                    printf ("\n\n");
                }
                else if (promocion[9]==1)
                {
                    residuo[9] = productos[28]-division[9];
                    multi[28] = (12*1.16)*residuo[9];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[28]);
                    printf ("\n\n");
                }
                else if (promocion[9]==2)
                {
                    residuo[9] = productos[28]-division[9];
                    multi[28] = (12*1.16)*residuo[9];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[28]);
                    printf ("\n\n");
                }
                break;

            case 29:
                printf("\n\n\t\t\t %c PROMOCI%cN  3x2 !",ii,aoo);
                printf ("\n\tHarina de trigo Tres Estrellas San Antonio extra fina 1 kg \n\t"); 
                printf ("Un producto imprescindible en cualquier cocina, es la harina de trigo y la de las Tres Estrellas \n\t  \
                extra fina es una buena opción para t%c. Las harinas refinadas te permitir%cn hacer un gran n%cmero de platillos \n\t",ai,aa,au); 
                printf ("El precio del producto es de $18.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[29]);
                promocion[10]=(productos[29]%3);
                division[10]=(productos[29]/3);
                if (promocion[10]==0)
                {
                    residuo[10] = productos[29]-division[10];
                    multi[29] = (18*1.16)*residuo[10];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[29]);
                    printf ("\n\n");
                }
                else if (promocion[10]==1)
                {
                    residuo[10] = productos[29]-division[10];
                    multi[29] = (18*1.16)*residuo[10];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[29]);
                    printf ("\n\n");
                }
                else if (promocion[10]==2)
                {
                    residuo[10] = productos[29]-division[10];
                    multi[29] = (18*1.16)*residuo[10];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[29]);
                    printf ("\n\n");
                }
                break; 
            /*
                En el caso de la promoción de 2x1, lo que hace el programa es 
                dividir la cantidad de productos que ingresa el usuario entre 2 
                y obtener el cociente y el residuo. 
            */
            case 30:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tSal La Fina refinada fluorada 1 kg \n\t"); 
                printf ("En tu despensa b%csica no puede faltar la sal de mesa, es el ingrediente que \n\t \
                te ayudar%c a resaltar el sabor de tus recetas de comida mexicana.  \n\t",aa,aa); 
                printf ("El precio del producto es de $14.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[30]);
                promocion[11]=(productos[30]%2);
                division[11]=(productos[30]/2);
                /*
                    Si el residuo da 0 significa que
                    el número es divisible entre 2, y la cantidad de productos ingresados
                    se le restará el coeficiente de la división y ese valor será la cantidad de productos
                    a pagar
                    Por ejemplo si el usuario ingresa 2, al dividirlo entre 2 se obtiene coeficiente de 1
                    y 2 - 1 da 1, esa es la cantidad de productos por las que va a pagar
                */
                if (promocion[11]==0)
                {
                    residuo[11] = productos[30]-division[11];
                    multi[30] = (14.5*1.16)*residuo[11];
                    printf ("\n\n\tEl total con IVA es de  $%.2f", multi[30]);
                    printf ("\n\n");
                }
                /*
                    Si el residuo da 2 sucede lo mismo, pero con la diferencia que se va a aplicar 
                    la promoción de 2x1 + el coeficiente que es el producto que no entra en la promoción 
                    Si se ingresa 5, al dividirlo entre 2, se obtiene un coeficiente de 2 y se le restará
                    5 - 2, esto da 3 y será la cantidad de productos a pagar 
                    Aplicando la promoción 2 veces 2x1 más 1 productos que no entran en promoción
                */
                else if (promocion[11]==1)
                {
                    residuo[11] = productos[30]-division[11];
                    multi[30] = (14.5*1.16)*residuo[11];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[30]);
                    printf ("\n\n");
                }
                break;

            case 31:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tCajeta Coronado quemada 370 g \n\t"); 
                printf ("Cajeta quemada Coronado. Elaborada con de leche de cabra. Buena fuente de c%clcio. \n\t",aa); 
                printf ("El precio del producto es de $46.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[31]);
                promocion[12]=(productos[31]%2);
                division[12]=(productos[31]/2);
                if (promocion[12]==0)
                {
                    residuo[12] = productos[31]-division[12];
                    multi[31] = (46*1.16)*residuo[12];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[31]);
                    printf ("\n\n");
                }
                else if (promocion[12]==1)
                {
                    residuo[12] = productos[31]-division[12];
                    multi[31] = (46*1.16)*residuo[12];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[31]);
                    printf ("\n\n");
                }
                break;
            

            case 32:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tProducto l%ccteo Nestl%c Carnation Clavel deslactosado 360 g \n\t",aa,ae); 
                printf ("Conoce la variedad de Carnation Clavel. Se trata de un producto l%ccteo deslactosado, esterilizado, \n\t \
                adicionado con vitaminas A y D \n\t",aa); 
                printf ("El precio del producto es de $16.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[32]);
                promocion[13]=(productos[32]%2);
                division[13]=(productos[32]/2);
                if (promocion[13]==0)
                {
                    residuo[13] = productos[32]-division[13];
                    multi[32] = (16*1.16)*residuo[13];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[32]);
                    printf ("\n\n");
                }
                else if (promocion[12]==1)
                {
                    residuo[13] = productos[32]-division[13];
                    multi[32] = (16*1.16)*residuo[13];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[32]);
                    printf ("\n\n");
                }
                break;

            case 33:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tLeche evaporada Nestl%c Carnation Clavel 360 g \n\t",ae); 
                printf ("Carnation Clavel es una leche parcialmente descremada evaporada, esterilizada y adicionada \n\t \
                con vitam%cnas A y D, elaborada con 100%c leche de vaca \n\t",ai,p); 
                printf ("El precio del producto es de $13.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[33]);
                promocion[14]=(productos[33]%2);
                division[14]=(productos[33]/2);
                if (promocion[14]==0)
                {
                    residuo[14] = productos[33]-division[14];
                    multi[33] = (13.5*1.16)*residuo[14];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[33]);
                    printf ("\n\n");
                }
                else if (promocion[14]==1)
                {
                    residuo[14] = productos[33]-division[14];
                    multi[33] = (13.5*1.16)*residuo[14];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[33]);
                    printf ("\n\n");
                }
                break; 

            case 34:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tCrema de avellanas Nutella 350 g \n\t"); 
                printf ("Hay infinidad de recetas con nutella que puedes preparar para realizar ricos postres ya \n\t \
                sean fr%cos o calientes puedes estar seguro de que tendr%cn un gran sabor a crema de avellanas.\n\t",ai,aa); 
                printf ("El precio del producto es de $59.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[34]);
                promocion[15]=(productos[34]%2);
                division[15]=(productos[34]/2);
                if (promocion[15]==0)
                {
                    residuo[15] = productos[34]-division[15];
                    multi[34] = (59*1.16)*residuo[15];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[34]);
                    printf ("\n\n");
                }
                else if (promocion[15]==1)
                {
                    residuo[15] = productos[34]-division[15];
                    multi[34] = (59*1.16)*residuo[15];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[34]);
                    printf ("\n\n");
                }
                break;

            case 35:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tLeche condensada Nestl%c La Lechera original 387 g \n\t",ae); 
                printf ("La leche condensada LA LECHERA, es desde 1936, la original hecha con 100 por ciento leche \n\t \
                de vaca, para darle mejor consistencia y m%cs sabor a tus postres. \n\t",aa); 
                printf ("El precio del producto es de $19.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[35]);
                promocion[16]=(productos[35]%2);
                division[16]=(productos[35]/2);
                if (promocion[16]==0)
                {
                    residuo[16] = productos[35]-division[16];
                    multi[35] = (19*1.16)*residuo[16];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[35]);
                    printf ("\n\n");
                }
                else if (promocion[16]==1)
                {
                    residuo[16] = productos[35]-division[16];
                    multi[35] = (19*1.16)*residuo[16];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[35]);
                    printf ("\n\n");
                }
                break;

            case 36: 
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tMermelada de fresa McCormick 980 g \n\t"); 
                printf ("La mermelada McCormick de fresa, es parte de la tradici%cn de McCormick y desde hace 70 a%cos \n\t \
                vive en el coraz%cn de las familias mexicanas \n\t",ao,an,ao); 
                printf ("El precio del producto es de $55.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[36]);
                promocion[17]=(productos[36]%2);
                division[17]=(productos[36]/2);
                if (promocion[17]==0)
                {
                    residuo[17] = productos[36]-division[17];
                    multi[36] = (55*1.16)*residuo[17];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[36]);
                    printf ("\n\n");
                }
                else if (promocion[16]==1)
                {
                    residuo[17] = productos[36]-division[17];
                    multi[36] = (55*1.16)*residuo[17];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[36]);
                    printf ("\n\n");
                }
                break;

            case 37: 
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tMermelada de fresa Fresa McCormick 670 g \n\t"); 
                printf ("Disfruta en cada bocado la mermelada de fresa con la fruta m%cs dulce, ya que McCormick \n\t \
                selecciona las mejores fresas para una mermelada de la m%cs alta calidad. \n\t",aa,aa); 
                printf ("El precio del producto es de $39.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[37]);
                promocion[18]=(productos[37]%2);
                division[18]=(productos[37]/2);
                if (promocion[18]==0)
                {
                    residuo[18] = productos[37]-division[18];
                    multi[37] = (39*1.16)*residuo[18];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[37]);
                    printf ("\n\n");
                }
                else if (promocion[18]==1)
                {
                    residuo[18] = productos[37]-division[18];
                    multi[37] = (39*1.16)*residuo[18];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[37]);
                    printf ("\n\n");
                }
                break;

            case 38:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tMiel de abeja Great Value l%cquida 300 g \n\t",ai); 
                printf ("La miel de abeja es conocida por sus m%cltiples cualidades ya que es un edulcorante natural \n\t \
                y sirve para remedios caseros, es un alimento puro, que no se descompone.\n\t",au); 
                printf ("El precio del producto es de $34.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[38]);
                promocion[19]=(productos[38]%2);
                division[19]=(productos[38]/2);
                if (promocion[19]==0)
                {
                    residuo[19] = productos[38]-division[19];
                    multi[38] = (34.5*1.16)*residuo[19];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[38]);
                    printf ("\n\n");
                }
                else if (promocion[19]==1)
                {
                    residuo[19] = productos[38]-division[19];
                    multi[38] = (34.5*1.16)*residuo[19];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[38]);
                    printf ("\n\n");
                }
                break;

            case 39:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tMiel de abeja Carlota 300 g \n\t"); 
                printf ("La miel Carlota cuenta con todas esas cualidades de pureza por lo que podr%cs disfrutarla \n\t \
                en donde m%cs la necesites, ya que se puede usar como un sustituto de az%ccar para tus bebidas \n\t",aa,aa,au); 
                printf ("El precio del producto es de $52.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[39]);
                promocion[20]=(productos[39]%2);
                division[20]=(productos[39]/2);
                if (promocion[20]==0)
                {
                    residuo[20] = productos[39]-division[20];
                    multi[39] = (52.5*1.16)*residuo[20];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[39]);
                    printf ("\n\n");
                }
                else if (promocion[20]==1)
                {
                    residuo[20] = productos[39]-division[20];
                    multi[39] = (52.5*1.16)*residuo[20];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[39]);
                    printf ("\n\n");
                }
                break;

            case 40:
                printf("\n\n\t\t\t %c PROMOCI%cN  2x1 !",ii,aoo);
                printf ("\n\tVinagre blanco Clemente Jacques 1 l \n\t"); 
                printf ("Derivado de costumbres y tradiciones que se han generado a lo largo del tiempo,tiene muchas \n\t \
                funciones, sus principales son el aderezar cualquier ensalada y preparar diferentes tipos de platillos \n\t"); 
                printf ("El precio del producto es de $10.90 (sin iva) \n\t"); 
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[40]);
                promocion[21]=(productos[40]%2);
                division[21]=(productos[40]/2);
                if (promocion[21]==0)
                {
                    residuo[21] = productos[40]-division[21];
                    multi[40] = (10.9*1.16)*residuo[21];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[40]);
                    printf ("\n\n");
                }
                else if (promocion[21]==1)
                {
                    residuo[21] = productos[40]-division[21];
                    multi[40] = (10.9*1.16)*residuo[21];
                    printf ("\n\n\t El total con IVA es de  $%.2f", multi[40]);
                    printf ("\n\n");
                }
                break;
            /*
                En el caso de la promoción del 25% de descuento, se va a multiplicar el precio sin iva, por
                1.16 que da el precio más el iva y por 0,75, que esto da el resultado del precio con iva aplicadole
                un 25 por ciento de descuento, al final se multiplicará por la cantidad de productos
            */
            case 41:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tVinagre de manzana Clemente Jacques 1 l \n\t"); 
                printf ("Adquiere este pr%cctico y saludable vinagre de manzana que Clemente Jacques.Es un  \n\t \
                complemento saludable, ideal para a%cadir a tus recetas de ensaladas verdes, platillos saludables \n\t",aa,an); 
                printf ("El precio del producto es de $16.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[41]);
                multi[41]=((16.50*1.16)*.75)*productos[41];
                printf ("\n\n\tEl total con IVA es de  $%.2f", multi[41]);
                break;

            case 42:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tT%c Therbal surtido de frutas 25 sobres de 1.8 g c/u\n\t",ae); 
                printf ("No olvides llevarte el t%c de la marca Therbal surtido de frutas con varios sabores de \n\t \
                t%c que tenemos en presentaci%cn de 25 sobres, podr%cs preparar varias infusiones de t%c que  \n\t \
                podr%cs disfrutar en una rica bebida caliente.  \n\t",ae,ae,ao,aa,ae,aa); 
                printf ("El precio del producto es de $35.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[42]);
                multi[42]=((35.50*1.16)*.75)*productos[42];
                printf ("\n\n\tEl total con IVA es de  $%.2f", multi[42]);
                break;

            case 43:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tSurtido de T%c Vitte 85 pzas \n\t",ae); 
                printf ("Si a los miembros de tu familia les gustan distintos sabores de t%c, dale gusto a todos \n\t \
                con el surtido de T%c Vitte. Funciona como practico despachador y cuenta con 85 bolsas de t%c de \n\t \
                distintos sabores \n\t",ae,ae,ae); 
                printf ("El precio del producto es de $79.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[43]);
                multi[43]=((79*1.16)*.75)*productos[43];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[43]);
                break;

            case 44:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tT%c Davenport surtido frutal 25 sobres \n\t",ae); 
                printf ("El t%c de frutas Davenport te dar%c distintos beneficios, ya que estas bebidas calientes \n\t \
                contienen ingredientes naturales ideales para acabar con varias dolencias, %c pruebalas !\n\t",ae,aa,ii); 
                printf ("El precio del producto es de $54.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[44]);
                multi[44]=((54*1.16)*.75)*productos[44];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[44]);
                break;

            case 45:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tHuevo blanco Guadalupe 1 paquete con 12 pzas \n\t"); 
                printf ("Prepara recetas de comida saludable con el huevo blanco Guadalupe. Viene en \n\t \
                un empaque que contiene 12 piezas de este alimento de origen animal. \n\t"); 
                printf ("El precio del producto es de $29.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[45]);
                multi[45]=((29*1.16)*.75)*productos[45];
                printf ("\n\n\tEl total con IVA es de  $%.2f", multi[45]);
                break; 

            case 46:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tT%c chai McCormick 25 pzas de 2 g c/u \n\t",ae); 
                printf ("%cDisfruta de una taza de te despues de la comida! El t%c chai de McCormick te \n\t \
                encantara. Ya sea que te sirvas un t%c chai latte o simplemente un t%c caliente, para esos \n\t \
                d%cas lluviosos y de fr%co \n\t",ii,ae,ae,ae,ai,ai); 
                printf ("El precio del producto es de $39.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[46]);
                multi[46]=((39*1.16)*.75)*productos[46];
                printf ("\n\n\tEl total con IVA es de  $%.2f", multi[46]);
                break; 

            case 47:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tHuevo blanco Gena emplaye 30 pzas \n\t"); 
                printf ("Lleva lo mejor de huevo banco a tu hogar en presentaciones de \n\t \
                30 emplayada de la Marca GENA, ya que es un alimento rico en prote%cnas \n\t",ai); 
                printf ("El precio del producto es de $45.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[47]);
                multi[47]=((45.5*1.16)*.75)*productos[47];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[47]);
                break;

            case 48:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tHuevo blanco San Juan 30 pzas \n\t"); 
                printf ("%cHaz de huevo san juan el protagonista de tus platillos! Lleva a \n\t \
                casa la mejor nutrici%cn para que hagas todas tus recetas con Huevo San Juan de 30 piezas \n\t",ap,ao); 
                printf ("El precio del producto es de $64.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[48]);
                multi[48]=((64*1.16)*.75)*productos[48];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[48]);
                break;

            case 49:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tPasta Great Value spaghetti 500 g \n\t"); 
                printf ("Disfruta su versatilidad dentro de la cocina mexicana y prepara \n\t \
                las recetas preferidas de tu familia \n\t"); 
                printf ("El precio del producto es de $11.35 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[49]);
                multi[49]=((11.35*1.16)*.75)*productos[49];
                printf ("\n\n\t El total con IVA es de  $%.2f", multi[49]);
                break;

            case 50:
                printf("\n\n\t\t\t %c PROMOCI%cN  25%c !",ii,aoo,p);
                printf ("\n\tFusilli Barilla 1 kg \n\t"); 
                printf ("Crea una receta de cocina que deje sorprendida a toda la familia \n\t \
                con fusilli que Barilla tiene para ti. Su presentaci%cn de 1 kilogramo es ideal para \n\t \
                preparar la comida completa de cada integrante de tu familia \n\t",ao); 
                printf ("El precio del producto es de $26.90 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[50]);
                multi[50]=((29.9*1.16)*.75)*productos[50];
                printf("\n\n\t El total con IVA es de  $%.2f", multi[50]);
                break;

            case 51:
                printf ("\n\tPenne rigate Barilla 500 g \n\t"); 
                printf ("Prepara el delicioso sabor del penne rigate de Barilla en cuestion \n\t \
                de minutos, con las diversas recetas de comida de la cocina italiana \n\t"); 
                printf ("El precio del producto es de $18.90 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[51]);
                multi[51]=(18.9*1.16)*productos[51];
                printf("\n\t El total con IVA es de  $%.2f", multi[51]);
                break;

            case 52:
                printf ("\n\tLomo de atun Tuny aleta amarilla en aceite lim%cn y pimienta 75 g \n\t",ao); 
                printf ("La linea Gourmet trae para ti una presentaci%cn de Lomo de atun aleta \n\t \
                amarilla en aceite, limon y pimienta gourmet de 75 g, es en trozos ligeros con un rico \n\t \
                sabor para su mejor degustacion \n\t",ao); 
                printf ("El precio del producto es de $19.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[52]);
                multi[52]=(19*1.16)*productos[52];
                printf("\n\t El total con IVA es de  $%.2f", multi[52]);
                break;
            break;

            case 53:
                printf ("\n\tLomo de atun Dolores aleta amarilla en aceite 140 g \n\t"); 
                printf ("Presume en tu despensa la calidad que solo el lomo de at%cn Dolores \n\t \
                aleta amarilla en aceite te ofrece. Cada lata de at%cn contiene 140 g de la mejor selecci%cn \n\t \
                y sabor dispuestos para ti \n\t",au,au,ao); 
                printf ("El precio del producto es de $17.90 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[53]);
                multi[53]=(17.9*1.16)*productos[53];
                printf("\n\t El total con IVA es de  $%.2f", multi[53]);
                break;

            case 54:
                printf ("\n\tLeche Santa Clara sabor helado de triple chocolate 250 ml \n\t"); 
                printf ("Consiente tu paladar con la leche sabor helado de triple chocolate de \n\t \
                la marca Santa Clara y disfruta de un momento solo para ti \n\t"); 
                printf ("El precio del producto es de $13.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[54]);
                multi[54]=(13*1.16)*productos[54];
                printf("\n\t El total con IVA es de  $%.2f", multi[54]);
                break;

            case 55:
                printf ("\n\tLeche Santa Clara semidescremada 1 l \n\t"); 
                printf ("La leche descremada es una opcion para desayuno saludable, ya que esta reducida \n\t \
                en grasas; sin embargo, mantiene los mismos nutrientes que la leche entera que son la lactosa, \n\t \
                las proteinas y el calcio \n\t"); 
                printf ("El precio del producto es de $21.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[55]);
                multi[55]=(21.5*1.16)*productos[55];
                printf("\n\t El total con IVA es de  $%.2f", multi[55]);
                break;

            case 56:
                printf ("\n\tLeche Santa Clara light 1 l\n\t"); 
                printf ("La leche light es una opcion para desayuno saludable, ya que esta reducida en grasas \n\t"); 
                printf ("El precio del producto es de $15.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[56]);
                multi[56]=(15*1.16)*productos[56];
                printf("\n\t El total con IVA es de  $%.2f", multi[56]);
                break;

            case 57:
                printf ("\n\tLeche Alpura Cl%csica entera 1.5 l \n\t",aa); 
                printf ("Alto contenido en calcio, vitam%cnas y proteinas son algunas de las propiedades \n\t \
                de la leche de vaca, por lo que es una buena opcion para acompaniar un desayuno nutritivo \n\t",ai); 
                printf ("El precio del producto es de $21.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[57]);
                multi[57]=(21.5*1.16)*productos[57];
                printf("\n\t El total con IVA es de  $%.2f", multi[57]);
                break;

            case 58:
                printf ("\n\tLeche fresca Alpura Clasica entera 1.89 l \n\t"); 
                printf ("Leche Alpura Clasica entera. Leche pasteurizada, adicionada con vitaminas \n\t \
                A y D3. Aporta calcio y vitaminas. Certificacion Kosher. \n\t"); 
                printf ("El precio del producto es de $32.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[58]);
                multi[58]=(32.5*1.16)*productos[58];
                printf("\n\t El total con IVA es de  $%.2f", multi[58]);
                break;

            case 59: 
                printf ("\n\tLeche Santa Clara light deslactosada 1 l \n\t"); 
                printf ("%cEres intolerante a la lactosa? %cNo te preocupes! Leche Santa Clara Deslactosada \n\t \
                en presentaci%cn de 1 litro, ayudara a restaurar tu flora intestinal \n\t",ap,ii,ao); 
                printf ("El precio del producto es de $23.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[59]);
                multi[59]=(23*1.16)*productos[59];
                printf("\n\t El total con IVA es de  $%.2f", multi[59]);
                break;

            case 60:
                printf ("\n\tLeche Santa Clara entera 1 l \n\t"); 
                printf ("La leche entera Santa Clara es pura de vaca adicionada con calcio y vitamina \n\t \
                A que fortalecen los huesos y ayudan a mantener saludable la vista \n\t"); 
                printf ("El precio del producto es de $21.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[60]);
                multi[60]=(21.5*1.16)*productos[60];
                printf("\n\t El total con IVA es de  $%.2f", multi[60]);
                break;

            case 61:
                printf ("\n\tLeche Lala entera 250 ml\n\t"); 
                printf ("Leche entera Lala ademas de ser deliciosa, es una opcion ideal para toda la \n\t \
                familia ya que la leche aporta nutrimentos indispensables como proteinas \n\t"); 
                printf ("El precio del producto es de $7.60 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[61]);
                multi[61]=(7*1.16)*productos[61];
                printf("\n\t El total con IVA es de  $%.2f", multi[61]);
                break;

            case 62:
                printf ("\n\tQueso parmesano Belgioioso por kg\n\t"); 
                printf ("El queso parmesano es de origen italiano, esta elaborado con leche cruda sin \n\t \
                ningun tipo de aditivos, es de una consistencia dura y granular \n\t"); 
                printf ("El precio del producto es de $294.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[62]);
                multi[62]=(294*1.16)*productos[62];
                printf("\n\t El total con IVA es de  $%.2f", multi[62]);
                break; 

            case 63:
                printf ("\n\tQueso crema Philadelphia original 190 g \n\t"); 
                printf ("El queso crema es un ingrediente estrella en multiples recetas de cocina. Su \n\t \
                consistencia suave y cremosa lo hace ideal para preparar platillos dulces y salados \n\t"); 
                printf ("El precio del producto es de $29.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[63]);
                multi[63]=(29*1.16)*productos[63];
                printf("\n\t El total con IVA es de  $%.2f", multi[63]);
                break;

            case 64:
                printf ("\n\tQueso cottage Lyncott 4 por ciento grasa 380 g \n\t"); 
                printf ("El queso cottage de la marca Lyncott, el cual cuenta con 4 por ciento grasa en \n\t \
                su presentacion de 380 g \n\t"); 
                printf ("El precio del producto es de $37.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[64]);
                multi[64]=(37.5*1.16)*productos[64];
                printf("\n\t El total con IVA es de  $%.2f", multi[64]);
                break;

            case 65:
                printf ("\n\tMargarina sin sal Iberia 4 en 1 en barra 500 g \n\t"); 
                printf ("Margarina pasteurizada sin sal de barra en presentaci%cn de 500 gramos, esta elaborada\n\t \
                con ingredientes de origen vegetal por lo que no contiene grasas trans y tampoco colesterol \n\t",ao); 
                printf ("El precio del producto es de $38.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[65]);
                multi[65]=(38.5*1.16)*productos[65];
                printf("\n\t El total con IVA es de  $%.2f", multi[65]);
                break;

            case 66:
                printf ("\n\tMantequilla Great Value reducida en grasa sin sal 225 g \n\t"); 
                printf ("Nos encanta llevar a tu mesa productos y alimentos de alta calidad. Prueba la \n\t \
                mantequilla reducida en grasa sin sal perfecta para incluir en tus recetas de cocina \n\t"); 
                printf ("El precio del producto es de $35.90 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[66]);
                multi[66]=(35.9*1.16)*productos[66];
                printf("\n\t El total con IVA es de  $%.2f", multi[66]);
                break;

            case 67:
                printf ("\n\tMargarina sin sal Iberia 4 en 1 en barra 90 g \n\t"); 
                printf ("Con esta margarina pasteurizada sin sal de 90 gramos consiente a tu familia sin \n\t \
                remordimientos, ya que por origen vegetal no contiene colesterol \n\t"); 
                printf ("El precio del producto es de $8.30 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[67]);
                multi[67]=(8.3*1.16)*productos[67];
                printf("\n\t El total con IVA es de  $%.2f", multi[67]);
                break;

            case 68:
                printf ("\n\tYoghurt bebible Lala con fresa 240 g \n\t"); 
                printf ("Yoghurt Lala Cl%csico, con su tradicional sabor y consistencia que encanta a tu \n\t \
                familia, ya que est%c hecho con leche y fruta natural, contiene calcio y prote%cna. \n\t",aa,aa,ai); 
                printf ("El precio del producto es de $9.40 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[68]);
                multi[68]=(9.4*1.16)*productos[68];
                printf("\n\t El total con IVA es de  $%.2f", multi[68]);
                break;

            case 69:
                printf ("\n\tYoghurt bebible Alpura varios sabores 10 pack de 250 g c/u \n\t"); 
                printf ("Consiente a los m%cs peque%cos del hogar con los deliciosos yoghurt bebibles  \n\t \
                que Alpura trae para ti. Por su pr%cctico empaque puedes llevarlos a todos lados \n\t",aa,an,aa); 
                printf ("El precio del producto es de $64.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[69]);
                multi[69]=(64*1.16)*productos[69];
                printf("\n\t El total con IVA es de  $%.2f", multi[69]);
                break;

            case 70:
                printf ("\n\t\n\t Yoghurt Oikos estilo griego natural 150 g \n\t"); 
                printf ("\n\t Consi%cntete con un buen desayuno acompa%cado del yogurt estilo griego \n\t",ae,an); 
                printf ("\n\t El precio del producto es de $12.00 (sin iva) \n\t");  
                printf ("\n\t ¿Cuantos desea llevar? \n\t");
                scanf ("%i", &productos[70]);
                multi[70]=(12*1.16)*productos[70];
                printf("\n\t El total con IVA es de  $%.2f", multi[70]);
                break;

            case 71:
                printf ("\n\tYoghurt Yoplait Griego natural bajo en grasa 750 g \n\t"); 
                printf ("Para que cumplas tu prop%csito de a%co nuevo de bajar de peso, lleva una alimentaci%cn \n\t \
                balanceada con productos saludables que te proporcionen la energ%ca que tu cuerpo necesita para rendir\n\t \
                en sus actividades diarias \n\t",ao,an,ao,ai); 
                printf ("El precio del producto es de $45.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[71]);
                multi[71]=(45*1.16)*productos[71];
                printf("\n\t El total con IVA es de  $%.2f", multi[71]);
                break;

            case 72:
                printf ("\n\tYoghurt bebible Danone sabor fresa 220 g \n\t"); 
                printf ("Lo cl%csico nunca pasa de moda por eso te ofrecemos el yogurt bebible Danone sabor \n\t \
                fresa. Adquiere la botella de 220 gramos \n\t",aa); 
                printf ("El precio del producto es de $8.30 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[72]);
                multi[72]=(8.3*1.16)*productos[72];
                printf("El total con IVA es de  $%.2f", multi[72]);
                break;

            case 73:
                printf ("\n\tYoghurt Yoplait con fresas 1 kg \n\t"); 
                printf ("Consiente a los integrantes de casa con un desayuno nutritivo. D%ctalos \n\t \
                de los nutrientes esenciales para el sano crecimiento y desarrollo intelectual con el yogurt \n\t \
                de fresa Yoplait de 1 Kg. \n\t",ao); 
                printf ("El precio del producto es de $33.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[73]);
                multi[73]=(33*1.16)*productos[73];
                printf("\n\t El total con IVA es de  $%.2f", multi[73]);
                break;

            case 74:
                printf ("\n\tN%cctar Del Valle de mango 1 l \n\t",ae); 
                printf ("A cualquier hora del d%ca, disfruta de este delicioso n%cctar de mango que Del \n\t \
                Valle tiene para ti. Deleita el sabor a fruta de temporada con este n%cctar \n\t",ai,ae,ae); 
                printf ("El precio del producto es de $20.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[74]);
                multi[74]=(20*1.16)*productos[74];
                printf("\n\t El total con IVA es de  $%.2f", multi[74]);
                break;

            case 75:
                printf ("\n\tN%cctar Del Valle de guayaba 413 ml \n\t",ae); 
                printf ("Si est%cs buscando m%cs que solo una bebida refrescante para saciar la sed,  \n\t \
                Del Valle tiene para ti el n%cctar de guayaba de 413 ml. Un producto que sorprender%c tu paladar \n\t \
                desde el primer sorbo \n\t",aa,aa,ae,aa); 
                printf ("El precio del producto es de $11.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[75]);
                multi[75]=(111.16)*productos[75];
                printf("\n\t El total con IVA es de  $%.2f", multi[75]);
                break;

            case 76:
                printf ("\n\tPapas Sabritas original 45 g \n\t"); 
                printf ("Papas Sabritas Sal: la botana m%cs deliciosa, gracias al sabor a papa natural con el \n\t \
                toque exacto de sal que te permite disfrutarlas sin saturaci%cn \n\t",aa,ao); 
                printf ("El precio del producto es de $12.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[76]);
                multi[76]=(12*1.16)*productos[76];
                printf("\n\t El total con IVA es de  $%.2f", multi[76]);
                break;

            case 77:
                printf ("\n\tPapas Sabritas sabor lim%cn 170 g \n\t",ao); 
                printf ("Dale a tu vida un poco de sabor con las Papas Sabritas Lim%cn: la botana m%cs deliciosa, \n\t \
                al sabor a papa natural con el toque exacto de lim%cn que te permite disfrutarlas por si solas \n\t",ao,aa,ao); 
                printf ("El precio del producto es de $37.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[77]);
                multi[77]=(37.5*1.16)*productos[77];
                printf("\n\t El total con IVA es de  $%.2f", multi[77]);
                break; 

            case 78:
                printf ("\n\tPapas Sabritas original 240 g \n\t"); 
                printf ("Papas Sabritas con sal: la botana m%cs deliciosa, gracias al sabor a papa natural \n\t \
                con el toque exacto de sal que te permite disfrutarlas sin saturaci%cn. \n\t",aa,ao); 
                printf ("El precio del producto es de $49.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[78]);
                multi[78]=(49.5*1.16)*productos[78];
                printf("\n\t El total con IVA es de  $%.2f", multi[78]);
                break;

            case 79:
                printf ("\n\tDoritos Doritos Nacho 150 g \n\t"); 
                printf ("Doritos Nacho es la mejor opci%cn para disfrutar en todo momento por su delicioso \n\t \
                sabor queso y chile. Son ideales para fiestas y reuniones \n\t",ao); 
                printf ("El precio del producto es de $26.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[79]);
                multi[79]=(26.5*1.16)*productos[79];
                printf("\n\t El total con IVA es de  $%.2f", multi[79]);
                break;

            case 80:
                printf ("\n\tDoritos Nacho con chile sabor queso 245 g \n\t"); 
                printf ("Doritos Nacho sabor a queso y un toque ligeramente picoso son la mejor opci%cn \n\t \
                para disfrutar en todo momento. Es una botana crujiente ideal para completar las opciones de \n\t \
                botanas para fiestas  \n\t",ao); 
                printf ("El precio del producto es de $37.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[80]);
                multi[80]=(37*1.16)*productos[80];
                printf("\n\t El total con IVA es de  $%.2f", multi[80]);
                break;

            case 81:
                printf ("\n\tCheetos Torciditos sabor queso y chile 370 g \n\t"); 
                printf ("Para esos momentos de diversi%cn, botana Cheetos Torciditos es la perfecta elecci%cn, \n\t \
                por su delicioso sabor, puedes compartirlos con todos tus amigos y familiares \n\t",ao,ao); 
                printf ("El precio del producto es de $52.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[81]);
                multi[81]=(52*1.16)*productos[81];
                printf("\n\t El total con IVA es de  $%.2f", multi[81]);
                break;

            case 82:
                printf ("\n\tCheetos Cheetos Flamin Hot xtra sabor queso y chile 150 g \n\t"); 
                printf ("Botana Cheetos Flamin%cHot es una deliciosa opci%cn hecha de cereal de ma%cz con \n\t \
                el sabor a queso, chile y lim%cn. Para esos momentos de fiesta la botana que Cheetos \n\t \
                tiene para ti ser%c perfecta \n\t",ac,ao,ai,ao,aa); 
                printf ("El precio del producto es de $25.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[82]);
                multi[82]=(25.5*1.16)*productos[82];
                printf("\n\t El total con IVA es de  $%.2f", multi[82]);
                break;

            case 83:
                printf ("\n\tCheetos Poffs sabor queso 100 g \n\t"); 
                printf ("Botana Cheetos Poffs es una deliciosa opci%cn hecha de cereal de ma%cz con \n\t \
                el sabor a queso que tanto te gusta. Conoce su sabor y consiente a tu paladar desde el primer bocado \n\t",ao,ai); 
                printf ("El precio del producto es de $26.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[83]);
                multi[83]=(26*1.16)*productos[83];
                printf("\n\t El total con IVA es de  $%.2f", multi[83]);
                break;

            case 84:
                printf ("\n\tCheetos horneados bolitas sabor queso y chile 100 g \n\t"); 
                printf ("Botana Cheetos Bolitas es una deliciosa opci%cn hecha de cereal de ma%cz con \n\t \
                el sabor a queso y chile que tanto te gusta. Para esos momentos familiares y divertidos, botana \n\t \
                Cheetos%c Bolitas es la perfecta elecci%cn \n\t",ao,ai,ac,ao); 
                printf ("El precio del producto es de $23.30 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[84]);
                multi[84]=(53.3*1.16)*productos[84];
                printf("\n\t El total con IVA es de  $%.2f", multi[84]);
                break;

            case 85:
                printf ("\n\tPalomitas ACT II sabor chile y lim%cn 110 g \n\t",ao); 
                printf ("Es la perfecta botana para fiestas, con crujiente textura y sabor exquisito. Viene \n\t \
                en pr%cctico empaque para llevar a donde desees, adem%cs de tener una preparaci%cn especial a base de aire \n\t \
                para conseguir una forma perfecta \n\t",aa,aa,ao); 
                printf ("El precio del producto es de $29.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[85]);
                multi[85]=(29.5*1.16)*productos[85];
                printf("\n\t El total con IVA es de  $%.2f", multi[85]);
                break;

            case 86:
                printf ("\n\tPalomitas ACT II sabor caramelo 235 g \n\t"); 
                printf ("Listas para comer, esponjosas, deliciosas, explotadas con aire... %cListas para Todo! \n\t \
                %cA qui%cn no se le antojan unas palomitas as%c? S%c el h%croe y abre unas palomitas ACT II sabor Caramelo \n\t",ii,ap,ae,ai,ae,ae); 
                printf ("El precio del producto es de $29.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[86]);
                multi[86]=(29.5*1.16)*productos[86];
                printf("\n\t El total con IVA es de  $%.2f", multi[86]);
                break;

            case 87:
                printf ("\n\tPalomitas ACT II sabor mantequilla 3 bolsas de 80 g c/u \n\t"); 
                printf ("Disfruta ese sabor mantequilla de tus palomitas ACT II y d%cjate consentir con su textura a \n\t \
                cualquier hora del d%ca, estas palomitas de microondas en presentaci%cn con 3 bolsas de 80 g \n\t",ae,ai,ao); 
                printf ("El precio del producto es de $29.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[87]);
                multi[87]=(29*1.16)*productos[87];
                printf("\n\t El total con IVA es de  $%.2f", multi[87]);
                break;

            case 88:
                printf ("\n\tMazap%cn De la Rosa tama%co gigante 50 g \n\t",aa,an); 
                printf ("Disfruta del cl%csico y delicioso sabor del mazap%cn De la Rosa, ahora \n\t \
                con gran tama%co que podr%cs disfrutar en donde sea. \n\t",aa,aa,an,aa); 
                printf ("\n\t El precio del producto es de $6.90 (sin iva) \n\t");  
                printf ("\n\t %cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[88]);
                multi[88]=(6.9*1.16)*productos[88];
                printf("\n\t El total con IVA es de  $%.2f", multi[88]);
                break;

            case 89:
                printf ("\n\tSurtido de paletas Vero mix dulce club 20 pzas \n\t"); 
                printf ("Para una fiesta infantil no debes dejar de comprar el surtido de \n\t \
                paletas Vero, ya que contiene chupa dedo, tarrito, cupido, manita, pinta azul \n\t"); 
                printf ("El precio del producto es de $32.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[89]);
                multi[89]=(32*1.16)*productos[89];
                printf("\n\t El total con IVA es de  $%.2f", multi[89]);
                break;

            case 90:
                printf("\n\tBubulubu Ricolino mini 15 pzas \n\t"); 
                printf("El delicioso sabor del malvavisco con jalea y cubierto de chocolate que no \n\t \
                debe faltar en tus fiestas infant%cles es el mini Bubulubu Ricolino \n\t",ai); 
                printf("El precio del producto es de $49.50 (sin iva) \n\t");  
                printf("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf("%d",&productos[90]);
                multi[90]=(49.5*1.16)*productos[90];
                printf("\n\t El total con IVA es de  $%.2f", multi[90]);
                break;

            case 91:
                printf ("\n\t Tamborines enchilados 30 pzas \n\t"); 
                printf ("Un dulce sabor tamarindo y chile con az%ccar que sorprender%c tu paladar. Lleva esta \n\t \
                presentaci%cn en bolsa con 30 piezas a casa \n\t",au,aa,ao); 
                printf ("El precio del producto es de $15.50 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                productos[91] = 0;
                scanf ("%i",&productos[91]);
                multi[91]=(15.5*1.16)*productos[91];
                printf("\n\t El total con IVA es de  $%.2f", multi[91]);
                break;

            case 92:
                printf ("\n\tDulce enchilado Skwinkles rellenos sabor pi%ca con tamarindo 26 g \n\t",an); 
                printf ("Los divertidos Skwinkles rellenos, un dulce enchilado en forma de tiras sabor \n\t \
                pi%ca con relleno sabor tamarindo \n\t",an); 
                printf ("El precio del producto es de $6.70 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                productos[92] = 0;
                scanf ("%i", &productos[92]);
                multi[92]=(6.7*1.16)*productos[92];
                printf("\n\t El total con IVA es de  $%.2f", multi[92]);
                break;

            case 93:
                printf ("\n\tPulparindo De la Rosa De la Rosa gigante con fruta natural 28 g\n\t"); 
                printf ("No dejes de probar el cl%csico y delicioso sabor de Pulparindo De La Rosa. \n\t \
                Ahora m%cs grande y con el mismo sabor de tamarindo salado y enchilado que siempre hemos disfrutado \n\t",aa,aa); 
                printf ("El precio del producto es de $6.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[93]);
                multi[93]=(6*1.16)*productos[93];
                printf("\n\t El total con IVA es de  $%.2f", multi[93]);
                break;

            case 94:
                printf ("\n\tPulparindo De la Rosa 20 pzas de 14 g c/u \n\t"); 
                printf ("Si eres fan de los dulces picositos con sabor tamarindo, no puedes dejar de \n\t \
                probar el delicioso sabor de Pulparindo De la Rosa, ahora en presentaci%cn de 20 piezas con 14 g c/u \n\t",ao); 
                printf ("El precio del producto es de $42.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[94]);
                multi[94]=(42*1.16)*productos[94];
                printf("\n\t El total con IVA es de  $%.2f", multi[94]);
                break;

            case 95:
                printf ("\n\tPaketaxo Sabritas Mezcladito 170 g \n\t"); 
                printf ("Mezcladito Familiar es nuestra combinaci%cn original que te invita a armarla \n\t \
                donde sea. Cuenta con la combinaci%cn perfecta y el delicioso sabor de las mejores botanas que ya \n\t \
                conoces; Rancheritos, Cheetos, Bolita, Sabritones y Frit-os \n\t",ao,ao); 
                printf ("El precio del producto es de $23.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[95]);
                multi[95]=(23*1.16)*productos[95];
                printf("\n\t El total con IVA es de  $%.2f", multi[95]);
                break;

            case 96:
                printf ("\n\tBotana surtida Paketaxo sabor quexo 215 g \n\t"); 
                printf ("Botana Paketaxo Quexo es nuestra combinaci%cn ideal que te invita a armarla \n\t \
                donde sea. Cuenta con la combinaci%cn perfecta y el delicioso sabor de las mejores botanas que \n\t \
                ya conoces: Crujitos, Poffets Cheetos, Doritos 3Ds y Cheetos \n\t",ao,ao); 
                printf ("El precio del producto es de $33.90 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[96]);
                multi[96]=(33.9*1.16)*productos[96];
                printf("\n\t El total con IVA es de  $%.2f", multi[96]);
                break;

            case 97:
                printf ("\n\tBotana surtida Paketaxo Sabritas botanero 270 g \n\t"); 
                printf ("Botana Paketaxo Botanero es nuestra combinaci%cn original que te invita a botanear donde sea. \n\t \
                La combinaci%cn perfecta y el delicioso sabor de las mejores botanas que ya conoces: Churrumais, \n\t \
                Rodajas Crujitos Flamin Hot y Cheetos \n\t",ao,ao); 
                printf ("El precio del producto es de $39.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[97]);
                multi[97]=(39*1.16)*productos[97];
                printf("\n\t El total con IVA es de  $%.2f", multi[97]);
                break;

            case 98:
                printf ("\n\tGoma de mascar Bubli Bubli sabores surtidos 600 gr \n\t"); 
                printf ("Compra la bolsa de Bubli Bubli con la goma de mascar con 100 piezas. Son peque%cos chicles \n\t \
                de sabores surtidos como frutas, manzana verde, menta, platano, uva \n\t",an); 
                printf ("El precio del producto es de $63.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[98]);
                multi[98]=(63*1.16)*productos[98];
                printf("\n\t El total con IVA es de  $%.2f", multi[98]);
                break;

            case 99:
                printf ("\n\tGoma de mascar Bubbaloo stick sabor fresa 5 pzas \n\t"); 
                printf ("Prueba Bubbaloo, el nuevo integrante de la familia Bubbaloo. Es una barra con 5 mega chicles \n\t \
                con sabor a fresa, el mismo delicioso sabor que Bubbaloo siempre te ha dado \n\t"); 
                printf ("El precio del producto es de $14.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%i", &productos[99]);
                multi[99]=(14*1.16)*productos[99];
                printf("\n\t El total con IVA es de  $%.2f", multi[99]);
                break;


            case 100:
                printf ("\n\tDulce enchilado Pelon mini sabor tamarindo 18 pzas de 13 g c/u \n\t"); 
                printf ("Sin perder el aut%cntico y divertido sabor de Pel%cn pelo rico, llega en su versi%cn mini,Pel%cn \n\t \
                pelo rico mini sabor a tamarindo, conservando su sabor original enchilado  \n\t",ae,ao,ao,ao); 
                printf ("El precio del producto es de $49.00 (sin iva) \n\t");  
                printf ("%cCu%cntos desea llevar? \n\t",ap,aa);
                scanf ("%d", &productos[100]);
                multi[100]=(49*1.16)*productos[100];
                printf("\n\t El total con IVA es de  $%.2f", multi[100]);
                break; 

            default:
                printf("\n\n\t Ha decidido conocer el total \n");
                break;
        }
        
    }
    while(codigo = 1 && codigo <= 100);
    // Una vez que se ejecuta otro número fuera del rango del 1 y del 100 se ejecuta esta parte
    // En este primer ciclo for, se hace la suma de las cantidades que se han ingresado de cada producto
    for (i = 1; i < 101; i++)
    {
        totalDeProductos = totalDeProductos + productos[i]; 
    }
    //Y aquí se hace la suma de la cantidad a pagar de cada producto
    for (i = 1; i < 101; i++)
    {
        totalDePago = totalDePago + multi[i]; 
    }
    //Esta es la parte de un pie de página, el cual imprime el total de productos, el precio
    //Y la opción si desea pagar el monto o cancelar la compra
    printf("\n\t\tEl total de productos es: %d", totalDeProductos);
    printf("\n\t\tEl total de a pagar es: $%.2f", totalDePago);
    printf("\n\t\tDesea realizar el pago?");
    printf("\n\t\tPresione 1 para continuar");
    printf("\n\t\tPresione 2 para cancelar \n\t\t");
    scanf("%d", &pago);
    //Si decide terminar la compra, se va a ejecutar esta parte
    if (pago == 1)
    {
        printf("\t\t\t\t\tSe ha realizado la compra\n");
        printf("\t\t\t\t\tGracias, vuelva pronto!\n\n");
        // Como se ha decido pagar, se crea un archivo que es la simulación de un ticket
        //En el cual, el archivo contiene la cantidad de productos y la cantidad a pagar
        FILE *ticket;
        ticket = fopen("ticket.txt", "a");
        if (ticket != NULL)
        {
            fprintf(ticket, "%s", "\nAquí está su ticket.");
            fprintf(ticket, "\n\t Total de productos: %i", totalDeProductos);
            fprintf(ticket, "\n\t Total a pagar: $%.2f", totalDePago);
            fprintf(ticket, "\nGracias y vuelva pronto :)");
            fprintf(ticket, "\n\n\n");
        } else {
            printf("El archivo no existe");
        }
        //Y aquí se cierra el archivo de ticket
        fclose(ticket);
    }
    //Si desea cancelar, simplemente imprimirá esto, sin detalles del precio ni cantidad de productos.
    else {
        printf("\t\t\t\t\t\tCompra cancelada");
    }
}
