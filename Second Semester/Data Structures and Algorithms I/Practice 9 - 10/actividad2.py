def funcion():
    #Se crea una lista de numeros enteros
    lista=[5,6,7,8,9,10,11,12]
    
    #Se crean 2 variables para guardar la suma y la multipliación de los numeros de la lista
    valor1 = 0
    valor2 = 1
    
    # Se recorre la lista, "i" tendra el valor de cada elemento de la lista
    for i in lista:
        # Se le sumara a la variable el valor de i
        valor1 += i
        # ! Aqui seria una manera de mejorar la eficiencia del codigo, pues
        # ! esta operacion se hace en este ciclo for, asi ya no seria necesario
        # ! utilizar el siguiente ciclo for
        #valor2 *= i
    
    # Se recorre la lista, "i" tendra el valor de cada elemento de la lista
    for j in lista:
        #Se multiplicara cada elemento de la lista por la variable
        #Y el valor se guarda en la variable

        valor2 *= j
    
    #Se imprimen las variables
    print(valor1)
    print(valor2)

#Se llama la funcion 
funcion()