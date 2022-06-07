# -*- coding: utf-8 -*-
"""
Created on Wed Jul 14 18:25:51 2021

@author: Edwin San
"""

def run():
    #Se guarda la contraseña
    CONTRASEÑA = 'Kf#23dh-3'
    #Guarda el numero de intentos realizados
    i = 1
    #Indica si se consigue pasar o no
    pasar = False
    while i != 5:
        contraIngresada = input('Ingrese la contraseña: ')
        #Si lo que ingreso el usuario es igual a la CONTRASEÑA
        if contraIngresada == CONTRASEÑA:
            #Se consigue pasar
            pasar = True
            #Se rompe el ciclo While
            break
        else:
            #Se imrpime la cantidad de intentos que le restan
            print('Le queda {} intentos'.format(4-i))
            #Se aumenta una unidad debido a que se realizó un intento
            i += 1
    #Como lo ingresado por el usuario era la contraseña correcta
    if pasar == True:
        print('Bienvenido')
    else:
        #Al no cambiar la variable pasar, se ejecuta esta parte
        print('Se acabaron los intentos')

#Aqui inicia el programa
if __name__ == '__main__':
    #Al iniciar, se ejecuta la función
    run()