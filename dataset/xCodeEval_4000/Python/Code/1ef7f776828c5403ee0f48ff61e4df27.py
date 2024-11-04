import math

def main():
    CodeForce()

def CodeForce():

    n, k = map(int, input().split())
    cartas = list(map(int, input().split()))
    solucion =Solucion(cartas,k)
    if(solucion == -1):
        print ('-1')
    else:
        print(len(solucion))
        Imprimir(solucion)

def Imprimir (cartas):
    result = ""
    for i in range(len(cartas)):
        result += str( cartas[i]) + " "
    print (result[0:len(result)-1])

def Solucion(cartas, k):
    llenarCombinaciones()
    if k % 2 == 1 and k % 10 != 5:
       return KesImpar().Calcular(cartas, k)
    if k % 2 == 0 and k % 10 != 0:
       return KesPar().Calcular(cartas, k)
    if k % 10 == 5 :
       return KesCinco(cartas, k)
    if k % 10 == 0 :
       return KesCero(cartas, k)

def KesCero (cartas,k):
    Diez = False
    Cinco = False
    Par = False

    for i in range(len(cartas)):
        if (cartas[i] % 2 == 0):Par = True
        if (cartas[i] % 10 == 5): Cinco = True
        if (cartas[i] % 10 == 0): Diez = True
        if (Diez or (Par and Cinco)):
            return cartas
    return -1
def KesCinco(cartas, k):
    result = []
    esMultiploDeCinco = False

    for i in range (len (cartas)):
        if (cartas[i] % 10 == 5):
            esMultiploDeCinco = True
        if (cartas[i] % 2 == 1):
            result.append(cartas[i])
    if (esMultiploDeCinco):
        return result

    return -1

class KesPar:
    def __init__(self):
        pass

    def Calcular(self, cartas, k):
        result = []
        menores = [[-1, -1, -1,-1],[-1, -1, -1,-1],[-1, -1, -1,-1]]

        Numero = 1;
        CantPares = 0;

        for  i in range (len(cartas)):
            temp = cartas[i]
            if (temp % 5 != 0):
                if (temp % 2 == 0):
                    CantPares+=1
                Numero = (temp * Numero) % 10
                result.append(temp)
                menores = self.Actualizar(temp, menores, temp % 10)

        if len(result) == 0:
            return -1
        return self.Resultado(Numero, k, menores, result, CantPares)

    def Actualizar (self, n, menores, resto):
        j = 0

        if (resto == 0 or resto == 1 or resto == 5 or resto == 6): return menores

        if (resto == 2 or resto == 7): j = 0
        if (resto == 3 or resto == 8): j = 1
        if (resto == 4 or resto == 9): j = 2

        a0 = menores[j][0]
        a1 = menores[j][1]
        a2 = menores[j][2]
        a3 = menores[j][3]

        entro = False

        if (n < a0 or a0 == -1):
            a3 = a2
            a2 = a1
            a1 = a0
            a0 = n
            entro = True
        if ((n < a1 or a1 == -1) and entro == False):
            a3 = a2
            a2 = a1
            a1 = n
            entro = True
        if ((n < a2 or a2 == -1) and entro == False):
            a3 = a2
            a2 = n
            entro = True

        if ((n < a3 or a3 == -1) and entro == False):
            a3 = n

        menores[j][0] = a0
        menores[j][1] = a1
        menores[j][2] = a2
        menores[j][3] = a3

        return menores

    def Resultado (self, numero, k, menores, result, CantPares):

        if (numero % 10 == k): return result

        R = numero % 10
        casos = []
        for i in range (len (combinaciones)):
            if R == combinaciones[i][0] and k == combinaciones[i][1]:
                casos.append(combinaciones[i][2])
        temps = []
        tempLists = []

        for i in range(len ( casos)):
            Temporal = self.LlenarCasos( casos[i], menores, CantPares)
            temps.append(Temporal[0])
            tempLists.append(Temporal[1])


        comp = self.Comparar(temps)
        if (comp == len(tempLists)):
            return -1
        for i in range (len(tempLists[comp])):
            result.remove(tempLists[comp][i])

        return result

    def LlenarCasos (self, caso, menores, CantPares):

        tempList = []
        temp1 = 1
        cont2 = 0
        cont3 = 0
        cont4 = 0

        for i in range(3):
            if (caso[i] == 2):
                if (CantPares > 1 or menores[0][cont2] % 2 != 0):
                    if (menores[0][cont2] % 2 == 0):
                        CantPares -=1
                    tempList.append(menores[0][cont2])
                    temp1 *= menores[0][cont2]
                else:
                    while (menores[0][cont2] % 2 == 0 and cont2 < 3):
                        cont2 +=1
                        if (menores[0][cont2] % 2 != 0):
                            tempList.append(menores[0][cont2])
                            temp1 *= menores[0][cont2]
                            break
                        if (menores[0][cont2] == -1):
                            temp1 *= menores[0][cont2]
                            break
                if (temp1 < 0):
                    break
                cont2 +=1

            if (caso[i] == 3):
                if (CantPares > 1 or menores[1][cont3] % 2 != 0):
                    if (menores[1][cont3] % 2 == 0):
                        CantPares -=1
                    tempList.append(menores[1][cont3])
                    temp1 *= menores[1][cont3]
                else:
                    while (menores[1][cont3] % 2 == 0 and cont3 < 3):
                        cont3 +=1
                        if (menores[1][cont3] % 2 != 0):
                            tempList.append(menores[1][cont3])
                            temp1 *= menores[1][cont3]
                            break
                        if (menores[1][cont3] == -1):
                            temp1 *= menores[1][cont3]
                            break
                if (temp1 < 0):
                    break
                cont3 +=1

            if (caso[i] == 4):
                if (CantPares > 1 or menores[2][cont4] % 2 != 0):
                    if (menores[2][cont4] % 2 == 0):
                        CantPares -=1
                    tempList.append(menores[2][cont4])
                    temp1 *= menores[2][cont4]
                else:
                    while (menores[2][cont4] % 2 == 0 and cont4 < 3):
                        cont4 +=1
                        if (menores[2][cont4] % 2 != 0):
                            tempList.append(menores[2][cont4])
                            temp1 *= menores[2][cont4]
                            break
                        if (menores[2][cont4] == -1):
                            temp1 *= menores[2][cont4]
                            break
                if (temp1 < 0):
                    break
                cont4 +=1

        return [temp1, tempList]

    def Comparar(self, temps):
        temp = []
        for i in range(len( temps)):
            if (temps[i] > 0): temp.append(temps[i])

        if (len(temp) == 0):
            return len(temps)

        listTemp = Orden(temp)
        ordenado = listTemp[0]

        for i in range(len( temps)):
            if (temps[i] == ordenado): return i
        return temps.Count
class KesImpar:
    def __init__(self):
        pass
    def Calcular(self, cartas, k):
        result = []
        menores = [[-1, -1, -1],[-1, -1, -1],[-1, -1, -1]]
        numero = 1

        for i in range(len(cartas)):
            temp = cartas[i]
            if temp % 2 != 0 and temp % 5 != 0:
                numero = (temp * numero) % 10
                result.append(temp)
                menores = self.Actualizar(temp, menores, temp % 10)

        if len(result) == 0:
            return -1

        return self.Resultado(numero, k, menores, result)

    def Actualizar(self, n, menores, resto):
        j = 0
        if resto != 3 and resto != 7 and resto != 9: return menores

        if resto == 3: j = 0;
        if resto == 7: j = 1;
        if resto == 9: j = 2;

        a0 = menores[j][0]
        a1 = menores[j][1]
        a2 = menores[j][2]

        entro = False
        if n < a0 or a0 == -1:
            a2 = a1
            a1 = a0
            a0 = n
            entro = True

        if (n < a1 or a1 == -1) and entro == False:
            a2 = a1
            a1 = n
            entro = True

        if (n < a2 or a2 == -1) and entro == False:
            a2 = n

        menores[j][0] = a0
        menores[j][1] = a1
        menores[j][2] = a2
        return menores

    def Resultado(self, Number, k, menores, result):

        if (Number % 10 == k): return result
        caso1 = [-1, -1, -1]
        caso2 = [-1, -1, -1]
        caso3 = [-1, -1, -1]

        R = Number % 10

        for i in range(len(combinaciones)):
            if (R == combinaciones[i][0] and k == combinaciones[i][1]):
                caso1 = combinaciones[i][2]
                caso2 = combinaciones[i + 1][2]
                caso3 = combinaciones[i + 2][2]
                break
        temp1 = 1
        temp2 = 1
        temp3 = 1

        temp1List = []
        temp2List = []
        temp3List = []

        Temporal = self.LlenarCasos(caso1, menores)
        temp1 = Temporal[0]
        temp1List = Temporal[1]
        Temporal = self.LlenarCasos(caso2, menores)
        temp2 = Temporal[0]
        temp2List = Temporal[1]
        Temporal = self.LlenarCasos(caso3, menores)
        temp3 = Temporal[0]
        temp3List = Temporal[1]

        comp = self.Comparar(temp1, temp2, temp3)


        if comp == 1:
            for i in range(len(temp1List)):
                result.remove(temp1List[i])
        if comp == 2:
            for i in range(len(temp2List)):
                result.remove(temp2List[i])
        if comp == 3:
            for i in range(len(temp3List)):
                result.remove(temp3List[i])
        if comp == 4:
            return -1
        return result

    def LlenarCasos(self, caso, menores):

        cont3 = 0
        cont7 = 0
        cont9 = 0
        temp = 1
        tempList = []

        for i in range(3):
            if caso[i] == 3:
                temp *= menores[0][cont3]
                tempList.append(menores[0][cont3])
                if temp < 0:
                    break
                cont3 += 1

            if caso[i] == 7:
                temp *= menores[1][cont7]
                tempList.append(menores[1][cont7])
                if temp < 0:
                    break
                cont7 += 1

            if caso[i] == 9:
                temp *= menores[2][cont9]
                tempList.append(menores[2][cont9])
                if temp < 0:
                    break
                cont9 += 1

        return [temp, tempList]

    def Comparar(self, a, b, c):
        temp = []

        if a > 0: temp.append(a)
        if b > 0: temp.append(b)
        if c > 0: temp.append(c)

        if len(temp) == 0:
            return 4

        ordenado = Orden(temp)[0]

        if ordenado == a: return 1
        if ordenado == b: return 2
        return 3

def Orden(lista):
    for i in range(len(lista)):
        for j in range(i + 1, len(lista)):
            if lista[j] < lista[i]:
                temp = lista[i]
                lista[i] = lista[j]
                lista[j] = temp
    return lista

combinaciones = [[2, 4, [3, -1, -1]]]
def llenarCombinaciones():
    
    
    
    
    

    if len(combinaciones) > 1:
        return
    
    combinaciones.append([2, 4, [4, 2, -1]])
    combinaciones.append([2, 4, [2, 2, 2]])

    combinaciones.append([2, 6, [2, -1, -1]])
    combinaciones.append([2, 6, [3, 4, -1]])
    combinaciones.append([2, 6, [4, 3, -1]])
    combinaciones.append([2, 6, [3, 3, 3]])

    combinaciones.append([2, 8, [4, -1, -1]])
    combinaciones.append([2, 8, [2, 2, -1]])
    combinaciones.append([2, 8, [3, 3, -1]])

    
    combinaciones.append([4, 2, [2, -1, -1]])
    combinaciones.append([4, 2, [3, 4, -1]])
    combinaciones.append([4, 2, [4, 3, -1]])
    combinaciones.append([4, 2, [3, 3, 3]])

    combinaciones.append([4, 6, [4, -1, -1]])
    combinaciones.append([4, 6, [2, 2, -1]])
    combinaciones.append([4, 6, [3, 3, -1]])

    combinaciones.append([4, 8, [3, -1, -1]])
    combinaciones.append([4, 8, [2, 4, -1]])
    combinaciones.append([4, 8, [4, 2, -1]])
    combinaciones.append([4, 8, [2, 2, 2]])

    
    combinaciones.append([6, 2, [3, -1, -1]])
    combinaciones.append([6, 2, [2, 4, -1]])
    combinaciones.append([6, 2, [4, 2, -1]])
    combinaciones.append([6, 2, [2, 2, 2]])

    combinaciones.append([6, 4, [4, -1, -1]])
    combinaciones.append([6, 4, [2, 2, -1]])
    combinaciones.append([6, 4, [3, 3, -1]])

    combinaciones.append([6, 8, [2, -1, -1]])
    combinaciones.append([6, 8, [3, 4, -1]])
    combinaciones.append([6, 8, [4, 3, -1]])
    combinaciones.append([6, 8, [3, 3, 3]])

    
    combinaciones.append([8, 2, [4, -1, -1]])
    combinaciones.append([8, 2, [2, 2, -1]])
    combinaciones.append([8, 2, [3, 3, -1]])

    combinaciones.append([8, 4, [2, -1, -1]])
    combinaciones.append([8, 4, [3, 4, -1]])
    combinaciones.append([8, 4, [4, 3, -1]])
    combinaciones.append([8, 4, [3, 3, 3]])

    combinaciones.append([8, 6, [3, -1, -1]])
    combinaciones.append([8, 6, [2, 4, -1]])
    combinaciones.append([8, 6, [4, 2, -1]])
    combinaciones.append([8, 6, [2, 2, 2]])

    
    combinaciones.append([1, 3, [7, -1, -1]])
    combinaciones.append([1, 3, [9, 3, -1]])
    combinaciones.append([1, 3, [3, 3, 3]])

    combinaciones.append([1, 7, [3, -1, -1]])
    combinaciones.append([1, 7, [7, 9, -1]])
    combinaciones.append([1, 7, [7, 7, 7]])

    combinaciones.append([1, 9, [9, -1, -1]])
    combinaciones.append([1, 9, [3, 3, -1]])
    combinaciones.append([1, 9, [7, 7, -1]])

    
    combinaciones.append([3, 1, [3, -1, -1]])
    combinaciones.append([3, 1, [7, 9, -1]])
    combinaciones.append([3, 1, [7, 7, 7]])

    combinaciones.append([3, 7, [9, -1, -1]])
    combinaciones.append([3, 7, [7, 7, -1]])
    combinaciones.append([3, 7, [3, 3, -1]])

    combinaciones.append([3, 9, [7, -1, -1]])
    combinaciones.append([3, 9, [3, 9, -1]])
    combinaciones.append([3, 9, [3, 3, 3]])

    
    combinaciones.append([7, 1, [7, -1, -1]])
    combinaciones.append([7, 1, [3, 9, -1]])
    combinaciones.append([7, 1, [3, 3, 3]])

    combinaciones.append([7, 3, [9, -1, -1]])
    combinaciones.append([7, 3, [3, 3, -1]])
    combinaciones.append([7, 3, [7, 7, -1]])

    combinaciones.append([7, 9, [3, -1, -1]])
    combinaciones.append([7, 9, [7, 9, -1]])
    combinaciones.append([7, 9, [7, 7, 7]])

    
    combinaciones.append([9, 1, [9, -1, -1]])
    combinaciones.append([9, 1, [7, 7, -1]])
    combinaciones.append([9, 1, [3, 3, -1]])

    combinaciones.append([9, 3, [3, -1, -1]])
    combinaciones.append([9, 3, [7, 9, -1]])
    combinaciones.append([9, 3, [7, 7, 7]])

    combinaciones.append([9, 7, [7, -1, -1]])
    combinaciones.append([9, 7, [3, 9, -1]])
    combinaciones.append([9, 7, [3, 3, 3]])


if __name__ == '__main__':
    main()
