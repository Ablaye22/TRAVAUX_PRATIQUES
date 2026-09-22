bibliotheque = []
indice = 0

def generer_id():
    global indice
    indice += 1 
    return indice

def ajouter_livre():
    print("Veuillez renseigner les information suivant")
    titre = input("Titre : ")
    auteur = input("Auteur : ")
    annee = int(input("Année de publication : "))
    livre = {
        "id":generer_id(),
        "titre": titre,
        "auteur": auteur,
        "annee": annee,
        "disponible": True
    }
    bibliotheque.append(livre)

def afficher_livres():
    if len(bibliotheque) == 0:
        print("AUcun livre n'est disponible")
        return None
    for livre in bibliotheque:
        print(f"ID : {livre['id']}")
        print(f"Titre : {livre['titre']}")
        print(f"Auteur : {livre['auteur']}")
        print(f"Année de publication : {livre['annee']}")
        if livre['disponible'] == True:
            print("Status : Disponible")
        else:
            print("Status : Emprunter")
        print("")
        print("------------------------")
        print("")

def rechercher_livre():
    titre = input("Titre à rechercher : ")
    for livre in bibliotheque:
        if livre['titre'] == titre:
            print("Livre trouvé !")
            print(f"ID : {livre['id']}")
            print(f"Titre : {livre['titre']}")
            print(f"Auteur : {livre['auteur']}")
            return None
    print("Livre introuvable.")

def emprunter_livre():
    global bibliotheque
    ID = int(input("ID du livre à emprunter : "))
    for livre in bibliotheque:
        if livre['id'] == ID:
            if livre['disponible']:
                livre['disponible'] = False
                print("Livre emprunter avec succès")
                return None
            else:
                print("Ce livre est déjà emprunter")
                return None
    print("Livre introuvable.")

def retourner_livre():
    global bibliotheque
    ID = int(input("ID du livre à retourner"))
    for livre in bibliotheque:
        if livre['id'] == ID:
            if livre['disponible'] == False:
                livre['disponible'] = True
                print("Livre retouner avec succés")
                return None
            else:
                print("Ce livre n'est pas emprunter. On ne peut pas retourner un livre non emprunter")
                return None
    print("Livre introuvable.")

def supprimer_livre():
    ID = int(input("ID du livre à supprimer : "))
    for livre in bibliotheque:
        if livre['id'] == ID:
            bibliotheque.remove(livre)
            print("Livre supprimer avec succés")
            return None
    print("Livre introuvable")

def menu():
    print("===== BIBLIOTHEQUE  =====")
    print("1. Ajouter un livre")
    print("2. Afficher les livres")
    print("3. Rechercher un livre")
    print("4. Emprunter un livre")
    print("5. Retourner un livre")
    print("6. Supprimer un livre")
    print("7. Quitter")
    print("")

while True:
    print("")
    menu()
    choix = int(input("Votre choix : "))
    print("")
    match choix:
        case 1:
            ajouter_livre()
        case 2:
            afficher_livres()
        case 3:
            rechercher_livre()
        case 4:
            emprunter_livre()
        case 5:
            retourner_livre()
        case 6:
            supprimer_livre()
        case 7:
            print("Au revoir")
            break
        case _:
            print("Choix invalide")