iden = 0

bibliotheque = []
livre = {}
def ajouter_livre(bibliotheque):
    global iden
    titre = input("Entrer le titre : ")
    auteur = input("Entrer le nom du l'auteur : ")
    annee = input("Entrer l'annee de publication : ")
    livre = {
        "id": iden,
        "titre": titre,
        "auteur": auteur,
        "annee": annee,
        "disponible": True
    }
    iden += 1
    bibliotheque.append(livre)
def afficher_livres(bibliotheque):
    for livre in bibliotheque:
        print("")
        print(f"ID : {livre['id']}")
        print(f"Titre : {livre['titre']}")
        print(f"Auteur : {livre['auteur']}")
        print(f"Année : {livre['annee']}")
        print(f"Status : {livre['disponible']}")
        print("-----------------------------------")
def rechercher_livre(bibliotheque):
    titre = input("Entrer le titre à rechercher: ")
    titre = titre.lower()
    for livre in bibliotheque:
        if titre in livre['titre']:
            return livre
    return None
def emprunter_livre(bibliotheque):
    idn = int(input("Entrer l'identifiant du livre"))
    for livre in bibliotheque:
        if livre['id'] == idn:
            if livre['disponible']:
                print("Le livre a été emprunté")
                livre['disponible'] = False
            else:
                print("Livre déjà emprunté")
            return None
    print("Livre introuvable")
def rendre_livre(bibliotheque):
    idn = int (input("ID du livre: "))
    for livre in bibliotheque:
        if livre['id'] == idn:
            print("Le livre a été rendu Merci à Bientôt")
            livre['disponible'] = True
            return None
    print("aucun livre ne correspond à l'identifiant")
def supprimer_livre(bibliotheque):
    idn = int(input("ID du livre: "))
    for livre in bibliotheque:
        if livre['id'] == idn:
            if livre['disponible'] == True:
                print("Le Livre a été supprimé avec succées")
                bibliotheque.remove(livre)
            else:
                print("Impossible de supprimer le livre. Il est actuellement emprunté")
            return None
    print("Livre introuvable:")
def statistique(bibliotheque):
    nb_livre = len(bibliotheque)
    nb_emprunte = 0
    for livre in bibliotheque:
        if livre['disponible'] == False:
            nb_emprunte += 1
    print(f"Nombre de livre : {nb_livre}")
    print(f"Livres disponible : {nb_livre - nb_emprunte}")
    print(f"Livres emprunté : {nb_emprunte}")

def menu_principale():
    print("========== BIBLIOTHEQUE ==========")
    print("")
    print("1. Afficher les livres")
    print("2. Ajoute un livre")
    print("3. Rechercher un livre")
    print("4. Emprunter un livre")
    print("5. Rendu un livre")
    print("6. Supprimer un livre")
    print("7. Statistique")
    print("8. Quitter")
    print("")
    choice = int(input("Votre choice: "))
    return choice
choice = menu_principale()
while(choice != 8):
    match choice:
        case 1 :
            afficher_livres(bibliotheque)
        case 2 :
            ajouter_livre(bibliotheque)
        case 3 :
            rechercher_livre(bibliotheque)
        case 4 :
            emprunter_livre(bibliotheque)
        case 5 :
            rendre_livre(bibliotheque)
        case 6 :
            supprimer_livre(bibliotheque)
        case 7 :
            statistique(bibliotheque)
    choice = menu_principale()



