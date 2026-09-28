from myrandom import MyRandom
from denface import DeNfaces
from copy import deepcopy
import sys

class PaquetDe:
    def __init__(self,*list_de):
        for de in list_de:
            if not isinstance(de, MyRandom):
                raise TypeError("Tous les éléments doivent hériter de MyRandom")
        self.list_de = list(deepcopy(list_de))

    def __add__(self,other):
        if isinstance(other,MyRandom):
            return PaquetDe(*self.list_de, other)
        elif isinstance(other,PaquetDe):
            return PaquetDe(*self.list_de,*other.list_de)
        else:
            raise TypeError("Not a MyRandom")

    def tirer(self, nb_tirs):
        resultats = [de.tirer(nb_tirs) for de in self.list_de]
        return list(zip(*resultats))



if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 paquetde.py nb_tirages nb_face_de1 nb_face_de2 ... nb_face_dernier_de")
        sys.exit(1)

    nb_tirages = int(sys.argv[1])
    nb_faces_list = [int(n) for n in sys.argv[2:]]

    des = [DeNfaces(n) for n in nb_faces_list]
    paquet = PaquetDe(*des)

    res = paquet.tirer(nb_tirages)
    for tirage in res:
        print(" ".join(str(v) for v in tirage))

    sys.exit(0)

