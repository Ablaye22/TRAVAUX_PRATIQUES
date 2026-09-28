from myrandom import MyRandom
from denface import DeNfaces

class Piece(MyRandom):
    def __init__(self, seed=None):
        super().__init__(seed)
        self.de_interne = DeNfaces(2, seed=seed)
        self.faces = {1: "pile", 2: "face"}

    def tirer(self, nb_tirs):
        tirages_bruts = self.de_interne.tirer(nb_tirs)
        return [self.faces[valeur] for valeur in tirages_bruts]