import csv


def format_phone_number(number):
    numero = [i for i in list(number) if i.isdigit() or i == '+']
    numero = "".join(numero)
    if numero.startswith("+33"):
        numero = list(numero)[3:]
        numero.insert(0,"0")
        numero = "".join(numero)
    elif numero.startswith("0033"):
        numero = list(numero)[4:]
        numero.insert(0,"0")
        numero = "".join(numero)
    numero = [i for i in numero if i.isdigit()]
    numero = "".join(numero)
    if len(numero) != 10 or not numero.startswith("0"):
        return False,None
    numero = [numero[i]+numero[i+1] for i in range(0,len(numero),2)]
    numero = "-".join(numero)
    return True,numero

if __name__ == '__main__':
    try:
        f = open("liste_numeros.txt","r")
        r = list(csv.reader(f,delimiter=":"))
        l1,l2 = zip(*r)
        r = [(i[1]," "+i[0][1]) for i in  zip(map(format_phone_number,l2),l1) if i[0][0]]
        t = [(i[1],i[0][1]) for i in  zip(map(format_phone_number,l2),l1) if not i[0][0]]
        g = open("output.txt","w")
        s = csv.writer(g,delimiter=":")
        s.writerows(r)
        print("les scélérats : ")
        for i in t:
            print(i[0])
        print()
        print("Les bons numéros de téléphone sont : ")
        l = [i[1] for i in list(map(format_phone_number,l2)) if i[0]]
        k = list(set([i for i in l if l.count(i) >1]))
        noms = [i[0] for i in r if i[1] == " "+ k[0]]
        noms = [i[0] for i in r if i[1] == " "+ k[1]] + noms
        print(noms)
        f.close()
        g.close()
    except FileNotFoundError:
        print("fichier n'existe pas")
        exit(0)


