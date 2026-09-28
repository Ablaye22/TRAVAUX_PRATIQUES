from myrandom import MyRandom
import sys

class DeNfacestruque(MyRandom):
    def __init__(self, nbfaces, poids=None, seed=None):
        super().__init__(seed)
        self.nbfaces = nbfaces
        if poids is None:
            self.poids = [1 for i in range(nbfaces)]
        elif len(poids) == nbfaces:
            self.poids = poids
        else:
            raise ValueError("la taille de la liste des poids ne convient pas")

    def tirer(self, nb_tirs):
        return self.rdm.choices([i for i in range(1, self.nbfaces + 1)], self.poids, k=nb_tirs)



if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Usage: denfacetruque.py nb_face nb_tirages poids_face_1 poids_face_2 ... poids_derniere_face")
        sys.exit(1)

    nb_face = int(sys.argv[1])
    nb_tirages = int(sys.argv[2])
    poids_str = sys.argv[3:]

    if len(poids_str) != nb_face:
        print(f"Erreur : {nb_face} poids attendus, {len(poids_str)} fournis")
        sys.exit(1)

    poids = [int(p) for p in poids_str]

    de = DeNfacestruque(nb_face, poids)
    res = de.tirer(nb_tirages)
    for r in res:
        print(r)

    sys.exit(0)