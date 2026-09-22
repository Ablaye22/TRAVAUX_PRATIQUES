import string
from encodage import Encodeur
import sys
class Decodeur(Encodeur):
    def __init__(self,pwd):
        r = zip(list(pwd),list(string.ascii_lowercase))
        password  = list(string.ascii_lowercase)
        for e in r:
            password[string.ascii_lowercase.index(e[0])] = e[1]
        super().__init__(password)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage : python3 decodage.py fichier_entree.txt mot_de_passe fichier_sortie.txt")
        sys.exit(1)
    fichier_entree = sys.argv[1]
    password = sys.argv[2]
    fichier_sortie = sys.argv[3]
    decodeur = Decodeur(password)
    decodeur.encode_file(fichier_entree, fichier_sortie)