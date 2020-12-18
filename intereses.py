total = 650
# 100,200,300,400,500,600
bijio = [i for i in range(total)]
import math

def gananciaTotal(bi,at,porcent,fusion):
	#ganancia bijio a 20 dias, 2% diario
	ganancia_bi = (porcent*bi)
	
	for i in range(30):
		#gancia_dia = 0.01*(at + ganancia_bi) 
		# 500+1,600+0
		print(at)
		if not (i%7==5 or i%7==6):
			at = at + 0.01*at + ganancia_bi
		else:
			at = at + 0.01*at
		at = at + fusion
		#print("ganancia dia " + str(i) + str(': ') + str(gancia_dia))
	#se deja el resto de los dias
	total = at
	print(at)
	return total
atton1 =650
ganancia1 = gananciaTotal(773,atton1,0.015,8)
print('-'*10)
atton2 = 650+739
ganancia2 = gananciaTotal(0,atton2,0.3,0)
print('-'*10)
print(ganancia1-atton1)
print(ganancia2-atton2)
#print(ganancia1)
#print(ganancia2)
#print(str(math.pow(1.01,30)*1393))
#Ver posibles ganancias
'''print("-"*10)
maxGanancia = 0
maxBijio = 0
maxAtton = 0
for curr_bijio in bijio:
	curr_aton = total - curr_bijio
	curr_ganancia = gananciaTotal(curr_bijio,curr_aton)
	if curr_ganancia > maxGanancia:
		maxGanancia = curr_ganancia
		maxBijio = curr_bijio
		maxAtton = curr_aton
print("Maxima ganancia: " +str(maxGanancia))
print("Maxima bijio: " +str(maxBijio))
print("Maxima atton: " +str(maxAtton))'''
