# -*- coding: utf-8 -*-
"""
Created on Wed Jul 14 18:25:51 2021

@author: Edwin San
"""

def run():
    #Se guarda la contraseña
    CONTRASEÑA = 'Kf#23dh-3'
    #Guarda el numero de intentos realizados
    #Indica si se consigue pasar o no
    pasar = False
    while pasar == False:
        contraIngresada = input('Ingrese la contraseña: ')
        #Si lo que ingreso el usuario es igual a la CONTRASEÑA
        if contraIngresada == CONTRASEÑA:
            #Se consigue pasar
            pasar = True
            #Se rompe el ciclo While
            break
    #Debido a que se finalizo el ciclo while al ingresar la contraseña
    #Correcta, se imprime el mensaje de bienvenido
    print('Bienvenido')

#Aqui inicia el programa
if __name__ == '__main__':
    #Al iniciar, se ejecuta la función
    run()