panier = []

def ajouter_panier():
    nom = input("Nom du produit : ")
    prix = float(input("Prix : "))
    qte = int(input("Quantite : "))
    produit = {
        "nom":nom,
        "prix":prix,
        "quantite":qte
    }
    panier.append(produit)

def afficher_panier():
    if len(panier) == 0:
        print("Panier vide : ")
        return None
    print("====== PANIER =====")
    for produit in panier:
        print("")
        print(f"Produit : {produit['nom']}")
        print(f"Prix : {produit['prix']}")
        print(f"Quantite : {produit['quantite']}")
        print("")
        print("----------------")
def modifier_quantite():
    nom_prod = input("Produit à modifier : ")
    qte = int(input("Nouvelle quantite : "))
    for produit in panier:
        if produit['nom'].lower() == nom_prod.lower():
            produit['quantite'] = qte
            print("quantite modifier avec succès")
            return None
    print("Produit introuvable.")

def supprimer_produit():
    nom_prod = input("Nom du produit à supprimer")
    for produit in panier:
        if produit['nom'].lower() == nom_prod.lower():
            panier.remove(produit)
            print("Produit supprimer avec succès.")
            return None
    print("Produit introuvable.")

def calculer_total():
    total = 0.0
    for produit in panier:
        total += produit['prix'] * produit['quantite']
    print("")
    print(f"Total : {total} €")

def menu():
    print("")
    print("+++++ MON PANIER +++++")
    print("")
    print("1. Ajouter un produit")
    print("2. Afficher le panier")
    print("3. Modifier une quantité")
    print("4. Supprimer un produit")
    print("5. Calculer le total")
    print("6. Vider le panier")
    print("7. Quitter")
    print("")

while True:
    print("")
    menu()
    choix = int(input("Votre choix : "))
    print("")
    match choix:
        case 1:
            ajouter_panier()
        case 2:
            afficher_panier()
        case 3: 
            modifier_quantite()
        case 4:
            supprimer_produit()
        case 5:
            calculer_total()
        case 6:
            panier.clear()
        case 7:
            print("Au revoir.")
            break
        case _:
            print("Choix invalide")



