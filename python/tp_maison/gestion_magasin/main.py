magasin = []
produit = {}
identifiant = 0
def ajouter_produit():
    global magasin
    global identifiant
    nom = input("Nom du produit: ")
    prix = float(input("Prix du prodiut: "))
    stock = int(input("Stock : "))
    categorie = input("Categorie : ")
    produit = {
        "id": identifiant,
        "nom": nom,
        "prix": prix,
        "stock": stock,
        "categorie": categorie
    }
    magasin.append(prodiut)
    identifiant += 1
def afficher_produit(produit):
    print("------------------------------------")
    print(f"ID : {produit['id']}")
    print(f"Nom : {produit['nom']}")
    print(f"Prix : {produit['prix']}")
    print(f"Stock : {produit['stock']}")
    print(f"Categorie : {produit['categorie']}")
    print("------------------------------------")
def afficher_produits():
    global magasin
    print("")
    for produit in magasin:
        afficher_produit(produit)
def rechercher_produit(nom):
    global magasin
    for produit in magasin:
        if produit['nom'].lower() == nom.lower():
            return produit
    return None

def modifier_stock(magasin):
    iden = int(input("ID du produit : "))
    for produit in magasin:
        if produit['id'] == iden:
            print("1. Ajouter du stock")
            print("2. Retirer du stock")
            choix = int(input("Choix : "))
            quantite = int(input("Quantité : "))
            if quantite < 0:
                print("Impossible : la quantite ne peut pas etre negatif")
                return None
            if choix == 1:
                produit['stock'] += quantite
            elif choix == 2:
                if produit['stock'] < quantite :
                    print("QUantite insuffisant : ")
                    return None
                else:
                    produit['stock'] -= quantite
            else:
                print("Choix invalide : ")
                return None
            print("stock mis a jour")
def acheter_produit(iden,quantite):
    global magasin
    for produit in magasin:
        if produit['id'] == iden:
            if produit['stock'] >m= quantite :
                produit['stock'] -= quantite
                print("Achat effectué")
            else:
                print("Impossible stock insuffisant")
            return None
    print("Aucun produit trouvé ")
    return None
def supprimer_produit(iden):
    global magasin
    for produit in magasin:
        if produit['id'] == iden:
            if produit['stock'] == 0:
                magasin.remove(produit)
                print("Le produit a été supprimé avec succèss")
            else:
                print("Impossible le stock doit etre vide ")
            return None
    print("Aucun produit n'est trouvé")
def valeur_magasin():
    global magasin
    valeur = 0.0
    for produit in magasin:
        valeur += produit['prix'] * produit['stock']
    return valeur
def produit_plus_cher():
    global magasin
    plus_cher = magasin[0]
    for produit in magasin:
        if produit['prix'] > prix_cher['prix'] :
            plus_cher = produit
    return plus_cher
def rechercher_categorie(categorie):
    global magasin
    index = 1
    print("")
    print(f"Produit de la catégorie {categorie}")
    print("")
    for produit in magasin:
        if produit['categorie'].lower() == categorie.lower():
            print(f"{index} - {produit['nom']} - {produit['prix']} €")
            index += 1
def plus_grand_stock():
    global magasin
    prod = magasin[0]
    for produit in magasin:
        if produit['stock'] > prod['stock']:
        prod = produit
    return prod
def nb_total_article_en_stock():
    global magasin
    nb_article = 0
    for produit in magasin:
        nb_article += produit['stock']
    return nb_article
def statistiques():
    global magasin
    print("=============== STATISTIQUES ===============")
    print("")
    print(f"Nombre de produits differents : {len(magasin)}")
    print(f"Nombre total d'articles en stock : {nb_total_article_en_stock()} articles")
    print(f"Valeur total du stock : {valeur_magasin()} €")
    print(f"Produit le plus cher : {afficher_produit(produit_plus_cher())}")
    print(f"Produit le plus grand en stock : {afficher_produit(plus_grand_stock())}")

def menu():
    print(" ========== MAGASIN ==========")
    print("1. Ajouter un produit")
    print("2. Afficher les produits")
    print("3. Rechercher un produit")
    print("4. Modifier le stock")
    print("5. Acheter un produit")
    print("6. Supprimer un produit")
    print("7. Rechercher par catégorie")
    print("8. Valeur du stock")
    print("9. Statistiques")
    print("10. Quitter")
    print("Votre choix : ")

