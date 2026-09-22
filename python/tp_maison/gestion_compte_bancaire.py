indice = 0
compte = {}
def generer_numero():
    global indice 
    indice += 1
    return indice

def creer_compte():
    global compte
    numero = generer_numero()
    titulaire = input("Entrer le nom du titulaire: ")
    solde = 0.0
    compte ={
        "numero": numero,
        "titulaire": titulaire,
        "solde": solde
    }
    print("Compte crée avec succès.")

def afficher_compte(compte):
    print(f"Numéro : {compte['numero']}")
    print(f"Titulaire : {compte['titulaire']}")
    print(f"Solde : {compte['solde']} €")

def deposer(compte):
    montant = float(input("Monttant à déposer : "))
    if montant < 0 :
        print("le montant ne peut pas etre negatif")
        return None
    compte['solde'] += montant
    print("Dépot effectué.")

def retirer(compte):
    montant = float(input("Montant à retirer : "))
    if montant < 0 :
        print("Le montant ne peut pas etre negatif")
        return None
    if compte['solde'] < montant :
        print("Impossible solde insuffissant: ")
        return None
    compte['solde'] -= montant
    print("Retrait effectué.")

def afficher_solde(compte):
    print(f"Solde actuel : {compte['solde']} €")

def menu():
    print("===== GESTION BANCAIRE =====")
    print()
    print("1. Créer un compte")
    print("2. Afficher le compte")
    print("3. Déposer de l'argent")
    print("4. Retirer de l'argene")
    print("5. Afficher solde ")
    print("6. Quitter")
    print("")
    choix = int(input("Votre choix : "))
    return choix
choix = menu()
while choix != 6:
    if choix == 1 :
        creer_compte()
    elif choix == 2:
        afficher_compte(compte)
    elif choix == 3:
        deposer(compte)
    elif choix == 4:
        retirer(compte)
    elif choix == 5:
        afficher_solde(compte)
    elif choix == 5:
        afficher_solde(compte)
    elif choix == 6:
       break
    else :
        print("Choix invalide ")
        print("Au revoir")
        break
    print("")
    choix = int(input("Votre choix: "))
    print("")
