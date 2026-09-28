from denfacetruque import DeNfacestruque
import sys

class DeNfaces(DeNfacestruque):
    def __init__(self,nb_faces, seed= None):
        super().__init__(nbfaces=nb_faces,seed=seed)

if __name__ == "__main__":
    if len(sys.argv) not in {3,4}:
        print("Usage: denface.ph nb_face nb_tirages [seed]")
        sys.exit(1)
    nb_faces = int(sys.argv[1])
    nb_tirages = int(sys.argv[2])
    if len(sys.argv) == 4:
        seed  = int(sys.argv[3])
    else:
        seed = None
    de = DeNfaces(nb_faces,seed)
    res = de.tirer(nb_tirages)
    for r in res:
        print(r)
    sys.exit(0)



