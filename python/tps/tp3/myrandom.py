from random import Random
import abc

class MyRandom(abc.ABC):
    def __init__(self, seed=None):
        self.rdm = Random(seed)

    @abc.abstractmethod
    def tirer(self, nb_tirs):
        pass

    def __add__(self, other):
        from Travaux_Pratique3.paquetde import PaquetDe
        if isinstance(other, MyRandom):
            return PaquetDe(self, other)
        raise TypeError("Impossible d'additionner un MyRandom avec autre chose qu'un MyRandom")