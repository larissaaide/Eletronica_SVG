#!/usr/bin/env python 3
import serial
import json
try:
    comunicacaoSerial = serial.Serial('/dev/ttyUSB1', 9600) #substituindo ttyACM0 pelo USB da ESP32
except serial.SerialException as e:
    print("deu ruim")

s = comunicacaoSerial.readline().decode('UTF-8')
#print(s)

while '{' not in s:
    print(s)
    s = comunicacaoSerial.readline().decode('UTF-8')

s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')
s += comunicacaoSerial.readline().decode('UTF-8')

comunicacaoSerial.close()

print(s)

#j = json.loads(s)
#print(j)





#Temperatura
#UmidadeAr
#UmidadeSolo1
#UmidadeSolo2
#UmidadeSolo3
#UmidadeSolo4
#UmidadeSolo5
#UmidadeMediaSolo
#PresencaSementeira
#InicioDeCurso
#FimDeCurso
#Luximetro

