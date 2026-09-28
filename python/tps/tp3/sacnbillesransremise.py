from myrandom import MyRandom

class SacNBillesSansRemise(MyRandom):
    def __init__(self, n, seed=None):
        super().__init__(seed)
        self.n = n
        self.sac = []

    def _remplir_sac(self):
        self.sac = self.rng.sample(range(1, self.n + 1), self.n)

    def tirer(self, nb_tirs):
        resultats = []
        for _ in range(nb_tirs):
            if not self.sac:
                self._remplir_sac()
            resultats.append(self.sac.pop())
        return resultats