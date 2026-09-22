import csv
import math
import random
import string

from decodage import Decodeur
from encodage import Encodeur
import sys


class CodeBreaker:
    def __init__(self, file):
        try:
            f = open(file, "r")
            self.quadgrams = {i[0]: i[1] for i in list(csv.reader(f, delimiter=" "))}
            f.close()
        except IOError:
            print("Impossible d'ouvrir le fichier: ")
            return

    def formate_text(self, input_string):
        return "".join([c if c.islower() else c.lower() if c.isupper() else "" for c in input_string])

    def permuter(self, alphabet, i=None, j=None):
        if i is None or j is None:
            i = random.randrange(26)
            j = random.randrange(26)
            while j == i:
                j = random.randrange(26)
        alphabet = list(alphabet)
        alphabet[i], alphabet[j] = alphabet[j], alphabet[i]
        return "".join(alphabet), i, j

    def score(self, data):
        list_quadgrams = [data[i] + data[i + 1] + data[i + 2] + data[i + 3] for i in range(0, len(data) - 3)]
        list_scores = [float(self.quadgrams.get(i)) if str(self.quadgrams.get(i)).isdigit() else 1 for i in
                       list_quadgrams]
        return sum(list(map(math.log, list_scores)))

    def hack_text(self, data):
        data_formated = self.formate_text(data)
        encodeur = Encodeur(string.ascii_lowercase)
        best_score = self.score(encodeur.encode_string(data_formated))
        nb_echecs = 0
        while nb_echecs < 1000:
            new_password, i, j = self.permuter(encodeur.password)
            encodeur.password = new_password
            current_score = self.score(encodeur.encode_string(data_formated))
            if current_score > best_score:
                best_score = current_score
                nb_echecs = 0
            else:
                encodeur.password = self.permuter(encodeur.password, i, j)[0]
                nb_echecs += 1
        return encodeur

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage : python3 cassercode.py fichier_entree.txt fichier_quadgrams.txt fichier_sortie.txt")
        sys.exit(1)
    fichier_entree = sys.argv[1]
    fichier_quadgrams = sys.argv[2]
    fichier_sortie = sys.argv[3]
    password_breaker = CodeBreaker(fichier_quadgrams)
    try:
        f = open(fichier_entree,"r")
        data = f.read()
        f.close()
        enc = password_breaker.hack_text(data)
        enc.encode_file(fichier_entree, fichier_sortie)
    except IOError:
        print("Impossible d'ouvrir le fichier")
        sys.exit(2)


