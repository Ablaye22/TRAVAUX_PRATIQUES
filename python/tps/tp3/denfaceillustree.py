from myrandom import MyRandom
from denface import DeNfaces

class DeNfacesIllustrees(MyRandom):
    def __init__(self, *faces, seed=None):
        super().__init__(seed)
        self.nb_faces = len(faces)
        self.de_interne = DeNfaces(self.nb_faces, seed=seed)
        self.faces = {i + 1: face for i, face in enumerate(faces)}

    def tirer(self, nb_tirs):
        tirages_bruts = self.de_interne.tirer(nb_tirs)
        return [self.faces[valeur] for valeur in tirages_bruts]