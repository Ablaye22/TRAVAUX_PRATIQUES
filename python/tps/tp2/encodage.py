import string
import random
import sys
class Encodeur:
    def __init__(self, pwd=None):
        if pwd is None:
            self.password = list(string.ascii_lowercase)
            random.shuffle(self.password)
        else:
            self.password = list(pwd)

    def encode_string(self, input_string):
        crypted_string = "".join([self.password[string.ascii_lowercase.index(c)] if c.islower() else self.password[
            string.ascii_lowercase.index(c.lower())].upper() if c.isupper() else c for c in input_string])
        return crypted_string

    def encode_file(self, input_file, output_file):
        try:
            text_file1 = open(input_file, "r")
            text_file2 = open(output_file, "w")
            text_file2.write(self.encode_string(text_file1.read()))
            text_file1.close()
            text_file2.close()
        except IOError:
            print("Impossible d'ouvrir les fichiers:")
            return

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage : python3 encodage.py fichier_entree.txt mot_de_passe fichier_sortie.txt")
        sys.exit(1)
    fichier_entree = sys.argv[1]
    password = sys.argv[2]
    fichier_sortie = sys.argv[3]
    encodeur = Encodeur(password)
    encodeur.encode_file(fichier_entree, fichier_sortie)