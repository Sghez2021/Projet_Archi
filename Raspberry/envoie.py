#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
Reception des données émise par un Arduino branché
à un port USB.
'''

import serial
import serial.tools.list_ports
import os

print("Recherche d'un port serie...")

ports = serial.tools.list_ports.comports(include_links=False)

if (len(ports) != 0): # on a trouvé au moins un port actif

    if (len(ports) > 1):     # affichage du nombre de ports trouvés
        print (str(len(ports)) + " ports actifs ont ete trouves:") 
    else:
        print ("1 port actif a ete trouve:")

    ligne = 1

    for port in ports :  # affichage du nom de chaque port
        print(str(ligne) + ' : ' + port.device)
        ligne = ligne + 1

    portChoisi = int(input('Ecrivez le numero du port desire:'))

    print('1: 9600   2: 38400    3: 115200')

    baud = int(input('Ecrivez le baud rate desire:'))

    if (baud == 1):
        baud = 9600
    if (baud == 2):
        baud = 38400
    if (baud == 3):
        baud = 115200

    # on établit la communication série
    print(ports[portChoisi - 1].device)
    print(baud)
    arduino = serial.Serial(ports[portChoisi - 1].device, baud, timeout=1)
    
    print('Connexion a ' + arduino.name + ' a un baud rate de ' + str(baud))

  #On récupère le contenue du fichier envoie puis on l'envoie au port connecté
    fichier = './play.txt'
    derniere_modification = os.path.getmtime(fichier)

with open('derniere_modification.txt', 'w') as f:
    f.write(str(derniere_modification))

# Vérifier si la date de modification a changé depuis la dernière fois
with open('derniere_modification.txt', 'r') as f:
    derniere_modification_sauvegardee = float(f.read().strip())

if derniere_modification > derniere_modification_sauvegardee:
    # Le fichier a été modifié, lire son contenu
    with open('./play.txt') as etat:          
        arduino.write(etat.readLines())
    # Faire quelque chose avec le contenu du fichier
        


else: # on n'a pas trouvé de port actif
    print("Aucun port actif n'a ete trouve")
